/*
 * Copyright (c) 2015 The NW1 Group
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

@ bootloader message handling code for the CAN based bootloader
@ this is based on Microchip's AN247 (since withdrawn) - modified by MERG for their CBUS modules

#include "core_cm0.inc"
#include "stm32f0xx.inc"
#include "moduleInfo.inc"
#include "acb_functionHeaders.inc"
#include "acb_can.inc"

    module(Bootloader)

    .extern         Can_sendMessageEx                               @ transmits an extended frame CAN message - blocking
    .extern         OptionByte_write                                @ write a value to the option bytes
    .extern         NVIC_SystemReset                                @ initiates a system reset request to reset the MCU
    .extern         Flash_unlockWrite                               @ unlock writing to the flash area
    .extern         Flash_lockWrite                                 @ lock writing to the flash area
    .extern         Flash_erase                                     @ erase an area of flash memory
    .extern         Flash_enableFlashProgramming                    @ enable programming to the flash
    .extern         Flash_disableFlashProgramming                   @ disable programming to the flash
    .extern         Flash_waitForOperation                          @ wait for a flash operation to finish

    .extern         _application_orgin                              @ where the application starts

/*
 *
 * Bootloader is based on extended frames, with the following structure:
 *      Put commands received from source (Master --> Slave)
 *      The count (DLC) can vary.
 *          XXXXXXXXXXX 0 0 8 XXXXXXXX XXXXXX00 ADDRL ADDRH ADDRU ADDRT CTLBT SPCMD CPDTL CPDTH
 *          XXXXXXXXXXX 0 0 8 XXXXXXXX XXXXXX01 DATA0 DATA1 DATA2 DATA3 DATA4 DATA5 DATA6 DATA7
 *
 *      ADDRL   Bits 0 to 7 of the memory pointer.
 *      ADDRH   Bits 8 - 15 of the memory pointer.
 *      ADDRU   Bits 16 - 23 of the memory pointer.
 *      ADDRT   Bits 24 - 32 of the memory pointer.
 *      CTLBT   Control bits.
 *      SPCMD   Special command.
 *      CPDTL   Bits 0 - 7 of 2s complement checksum
 *      CPDTH   Bits 8 - 15 of 2s complement checksum
 *      DATAx   General data.
 *
 * Control bits:
 *      MODE_WRT_UNLCK      Set this to allow write and erase operations to memory.
 *      MODE_ERASE_ONLY     Set this to only erase Program Memory on a put command. Must be on 64-byte boundary.
 *      MODE_AUTO_ERASE     Set this to automatically erase Program Memory while writing data.
 *      MODE_AUTO_INC       Set this to automatically increment the pointer after writing.
 *      MODE_ACK            Set this to generate an acknowledge after a 'put' (PG Mode only)
 *
 * Checksum is 16 bit addition of all programmable bytes.
 * User sends 2s complement of addition at end of program in command 0x03 (16 bits only)
 *
 * Special Commands:
 *      CMD_NOP         0x00    Do nothing
 *      CMD_RESET       0x01    Issue a soft reset
 *      CMD_RST_CHKSM   0x02    Reset the checksum counter and verify
 *      CMD_CHK_RUN     0x03    Add checksum to special data, if verify and zero checksum
 *      CMD_BOOT_TEST   0x04    Just sends a message frame back to verify boot mode.
 *
 * Only writing to FLASH is supported, specifically writing to configuration/option bytes and EEPROM is not
 * supported.
 *
 * The user program must start at address 0x08000C00 and the size reduced by 3K,
 * and the RAM region must start from 0x200000C0 and the size reduced by 192 bytes
 *
 */

#define BL_CONTROL_BIT          0
#define BL_DIRECTION_BIT        1

#define BL_MODE_WRT_UNLCK_BIT   0
#define BL_MODE_ERASE_ONLY_BIT  1
#define BL_MODE_AUTO_ERASE_BIT  2
#define BL_MODE_AUTO_INC_BIT    3
#define BL_MODE_ACK_BIT         4

#define BL_MODE_WRT_UNLCK       1<<BL_MODE_WRT_UNLCK_BIT
#define BL_MODE_ERASE_ONLY      1<<BL_MODE_ERASE_ONLY_BIT
#define BL_MODE_AUTO_ERASE      1<<BL_MODE_AUTO_ERASE_BIT
#define BL_MODE_AUTO_INC        1<<BL_MODE_AUTO_INC_BIT
#define BL_MODE_ACK             1<<BL_MODE_ACK_BIT

#define BL_CMD_NOP              0x00
#define BL_CMD_RESET            0x01
#define BL_CMD_RST_CHKSM        0x02
#define BL_CMD_CHK_RUN          0x03
#define BL_CMD_BOOT_TEST        0x04

#define BL_ACK_CMD_OK           0x01
#define BL_ACK_CMD_FAIL         0x00
#define BL_ACK_CMD_TEST         0x02

#define BL_CMD_ADDR_OFFSET      0x00
#define BL_CMD_CTLBT_OFFSET     0x04
#define BL_CMD_SPCMD_OFFSET     0x05
#define BL_CMD_CPDT_OFFSET      0x06


#define BL_ERROR_STATUS_VERIFY  0x01

@ private variables - NOTE the bootloader doesn't have code to automatically initialise any RAM based
@ values

    private_data(bootldr_vars)

@ Note: This block matches the incoming data bytes in a command type message, just mapped into seperate variables
commandData:
addressPtr:         .int        0                                   @ address in first 4 bytes (uses reserved byte)
controlBits:        .byte       BL_MODE_AUTO_ERASE|BL_MODE_AUTO_INC|BL_MODE_ACK
specialCommand:     .byte       0
expectedChecksum:   .short      0

@ page erase map
pageEraseMap:       .int        0, 0, 0, 0                          @ map of pages currently erased (bit for each page)

@ other private variables
memoryMaxAddress:   .int        0                                   @ max flash address, calc @ runtime
checksum:           .short      0                                   @ calculated checksum
errorStatus:        .byte       0
pageShift:          .byte       0                                   @ number of bits to shift address right, to get
                                                                    @ it's page

    public_function(Bootloader_init)

@ void Bootloader_init(uint32 memoryMaxAddress, uint8 pageShift)
@   initialise the boot loader, memoryMaxAddress is top of the flash address, pageShift is the number of bits to shift
@   address right, to get it's page

Bootloader_init:                                                    @ init variables
                    ldr             r2, = #memoryMaxAddress
                    str             r0, [r2]
                    strb            r1, [r2, #7]
                    bx              lr

    public_function(Bootloader_dispatchMsg)

@ uint32 Bootloader_dispatchMsg(MSGEX* msg) - main not return depending on command
@   main message handler for the bootloader - message to dispatch is supplied in first parameter
@   returns the following status:
@       0 - no message
@       1 - send a nOK
@       2 - send a OK
@       3 - send a TEST (response)

Bootloader_dispatchMsg:
                    push            {r7, lr}
__blCheckMsgSize:                                                   @ make sure the message has at least 1 byte
                    ldrb            r3, [r0, #ACB_MSGEX_INFO_DLC_OFFSET]
                    movs            r1, #ACB_MSG_DLC_MASK
                    ands            r1, r1, r3
                    beq             __blReturn
__blCheckMsgType:
                    ldr             r3, [r0, #ACB_MSGEX_INFO_EXID_OFFSET]
                    movs            r2, #(1<<BL_CONTROL_BIT)        @ command message, 1 is data message
                    tst             r3, r2
                    bne             __blRxData
__blRxCommand:
                    bl              Bootloader_handleCommandMsg
                    b               __blReturnWithStatus
__blRxData:
                    bl              Bootloader_handleDataMsg
__blReturn:
                    movs            r0, #0
__blReturnWithStatus:
                    pop             {r7, pc}

    private_function(Bootloader_handleCommandMsg)

@ uint32 Bootloader_handleCommandMsg(MSGEX* msg, uint32 msgLen)
@   command handler for the bootloader - message to handle is supplied in first parameter
@   returns the following status:
@       0 - no message
@       1 - send a nOK
@       2 - send a OK
@       3 - send a TEST (response)

@ TODO @ TODO @ TODO @ TODO - send response back to callee about sending message to client

Bootloader_handleCommandMsg:
                    push            {r5-r7, lr}
                    movs            r5, r1                          @ save data length
                    movs            r1, #ACB_MSGEX_DATA_OFFSET      @ control data. Needs to be a bytewise copy
                    adds            r1, r1, r0                      @ as we don't know that all 8 bytes where copied
                    ldr             r2, = #commandData
                    subs            r0, r5, #1
0:                                                                  @ copy data over
                    ldrb            r7, [r1, r0]
                    strb            r7, [r2, r0]
                    subs            r0, r0, #1
                    bpl             0b
_hcCheckForWriteEnableDisable:
                    cmp             r5, #5                          @ if data length < 4 then can't change options
                    blt             __hcReturn                      @ so just return
                    ldrb            r0, [r2, #BL_CMD_CTLBT_OFFSET]
                    movs            r1, #(BL_MODE_WRT_UNLCK|BL_MODE_AUTO_ERASE)
                    tst             r0, r1                          @ do we need to unlock?
                    beq             1f                              @ nope, then lock
                    bl              Flash_unlockWrite
                    b               5f
1:
                    bl              Flash_lockWrite
5:
                    cmp             r5, #6                          @ if data length < 5 then no new command to action
                    blt             __hcReturn                      @ so just return
__hcDoCommand:
                    ldr             r0, = #specialCommand           @ perform the command
                    ldrb            r0, [r0]
                    cmp             r0, #BL_CMD_NOP                 @ nop?
                    beq             __hcReturn                      @ yes don't do anything

                    cmp             r0, #BL_CMD_RESET               @ reset command?
                    bne             2f
                    ldr             r0, = #BOOTLOAD_OPTION_BYTE     @ reset bootloader flag
                    movs            r1, #1<<BOOTLOAD_OPTION_BIT
                    movs            r2, r1
                    bl              OptionByte_write                @ doesn't return if the option byte is changed
                    bl              NVIC_SystemReset                @ otherwise reset anyhow
2:
                    cmp             r0, #BL_CMD_RST_CHKSM           @ reset checksum command
                    bne             3f
                    movs            r0, #0
                    ldr             r1, = #checksum                 @ clear error status and checksum
                    strh            r0, [r1]
                    ldr             r1, = #errorStatus
                    strb            r0, [r1]
                    ldr             r1, = #pageEraseMap             @ clear the page erase map
                    str             r0, [r1]
                    str             r0, [r1, #4]
                    str             r0, [r1, #8]
                    str             r0, [r1, #12]
                    b               __hcReturn
3:
                    cmp             r0, #BL_CMD_CHK_RUN             @ The checksum is verified, and the self-write
                    bne             4f                              @ verification bit is checked. If both pass, send
                    ldr             r1, = #checksum                 @ an OK message sent, otherwise send an nOK.
                    ldrh            r1, [r1]
                    ldr             r2, = #expectedChecksum         @ expectedChecksum should be 65536-checksum
                    ldrh            r2, [r2]
                    adds            r1, r1, r2                      @ added together they should equal short(0), but
                    uxth            r1, r1                          @ could overflow in the 32bit world, so zero extend
                    cmp             r1, #0
                    beq             __hcCheckSelfVerify
__hcSendFail:
                    movs            r0, #(BL_ACK_CMD_FAIL+1)        @ return a nOK status back
                    b               __hcReturnWithStatus
__hcCheckSelfVerify:
                    ldr             r1, = #errorStatus              @ check the self verify error flag
                    ldrb            r1, [r1]
                    movs            r0, #BL_ERROR_STATUS_VERIFY
                    tst             r0, r1
                    bne             __hcSendFail
__hcSendOK:
                    movs            r0, #(BL_ACK_CMD_OK+1)          @ return a OK status back
                    b               __hcReturnWithStatus
4:
                    cmp             r0, #BL_CMD_BOOT_TEST           @ send a message frame back to verify boot mode
                    bne             __hcReturn                      @ all other commands are treated as a NOP
                    movs            r0, #(BL_ACK_CMD_TEST+1)        @ return a ack. test status back
                    b               __hcReturnWithStatus
__hcReturn:
                    movs            r0, #0
__hcReturnWithStatus:
                    pop             {r5-r7, pc}

    private_function(Bootloader_handleDataMsg)

@ void Bootloader_handleDataMsg(MSGEX* msg, uint32 msgLen)
@   data handler for the bootloader - message to handle is supplied in first parameter

Bootloader_handleDataMsg:
                    mov             r2, r8
                    push            {r2, r4-r7, lr}
                    ldr             r7, = #addressPtr               @ r7 is the address to write now
                    ldr             r7, [r7]
                    ldr             r6, = #controlBits              @ r6 is the control bits
                    ldrb            r6, [r6]
                    movs            r5, r1                          @ r5 is the message/data length
                    adds            r0, r0, #ACB_MSGEX_DATA_OFFSET  @ we only care about the data here, not the rest
                    mov             r8, r0                          @ of the message structure; r8 is the incoming data

                    movs            r0, #BL_MODE_AUTO_INC           @ auto inc set?
                    tst             r0, r6
                    beq             __hdCheckAddressRange
                    add             r1, r1, r7                      @ yes, then inc the address pointer ready for the
                    ldr             r0, = #addressPtr
                    str             r1, [r0]                        @ next set of data
__hdUpdateChecksum:                                                 @ add the data to the checksum (byte-wise)
                    subs            r0, r5, #1                      @ do it here, as the client doesn't get a response
                    ldr             r1, = #checksum                 @ on whether we wrote the data to flash, and would
                    ldrh            r2, [r1]                        @ be calculating the checksum all the same.
                    mov             r4, r8
0:
                    ldrb            r3, [r4, r0]
                    adds            r2, r3
                    subs            r0, r0, #1
                    bge             0b
                    strh            r2, [r1]
__hdCheckAddressRange:                                              @ check address range, if less then _application_orgin
                    ldr             r0, = #_application_orgin       @ or greater than memoryMaxAddress then just return
                    cmp             r7, r0
                    bmi             __hdReturn
                    ldr             r0, = #memoryMaxAddress
                    ldr             r0, [r0]
                    cmp             r7, r0
                    bpl             __hdReturn
__hdCheckForWriteLock:
                    movs            r0, #BL_MODE_WRT_UNLCK
                    tst             r6, r0
                    beq             __hdReturn
__hdCheckForWholeHalfWords:
                    movs            r0, #1                          @ must program memory in whole half words (short)
                    tst             r5, r0
                    bne             __hdReturn
__hdCheckForErase:
                    movs            r0, #BL_MODE_AUTO_ERASE
                    tst             r6, r0                          @ if not auto erase, then skip to writting the data
                    beq             __hdWriteData
                    ldr             r0, = #pageShift                @ work out which page we're on
                    ldrb            r0, [r0]
                    ldr             r2, = #FLASH_BASE               @ subtract the flash base address
                    subs            r1, r7, r2
                    lsrs            r1, r1, r0
                    movs            r0, #0                          @ work out which pageEraseMap int to check
0:
                    cmp             r1, #32
                    blt             1f
                    adds            r0, r0, #4
                    subs            r1, r1, #32
                    b               0b
1:
                    movs            r2, #1
                    lsls            r2, r2, r1
                    ldr             r1, = #pageEraseMap             @ check if we've already erased this page?
                    ldr             r3, [r1, r0]
                    ands            r3, r3, r2
                    bne             _hdCheckForEraseOnly
                    orrs            r3, r3, r2
                    str             r3, [r1, r0]
__hdErasePage:                                                      @ get erased. TODO: Sort this (page bitmap, and check
                    movs            r0, r7                          @ in there?)
                    movs            r1, #FLASH_CR_PER
                    bl              Flash_erase
_hdCheckForEraseOnly:
                    movs            r0, #BL_MODE_ERASE_ONLY         @ if we are just erasing, then return
                    tst             r6, r0
                    bne             __hdReturn
__hdWriteData:
__hdWriteFlash:                                                     @ write the data!
                    bl              Flash_enableFlashProgramming
                    subs            r4, r5, #2                      @ r4 is our counter in bytes
                    mov             r6, r8
1:
                    ldrh            r0, [r6, r4]
                    strh            r0, [r7, r4]                    @ no need for memory barrier sync. here as we
                    bl              Flash_waitForOperation          @ aren't running the just written code anytime
                    subs            r4, r4, #2                      @ soon
                    bpl             1b
                    bl              Flash_disableFlashProgramming
__hdVerifyFlash:
                    subs            r4, r5, #2
2:
                    ldrh            r0, [r6, r4]
                    ldrh            r1, [r7, r4]
                    cmp             r0, r1
                    bne             __hdVerifyFail
                    subs            r4, r4, #2
                    bpl             2b
__hdReturn:
                    pop             {r2, r4-r7, pc}
                    mov             r8, r2
__hdVerifyFail:
                    ldr             r1, =#errorStatus
                    ldrb            r0, [r1]
                    movs            r2, #BL_ERROR_STATUS_VERIFY
                    orrs            r0, r0, r2
                    strb            r0, [r1]
                    b               __hdReturn

    .end
