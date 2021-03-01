/*
 * Copyright (c) 2021 The NW1 Group
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#include "moduleInfo.inc"

@ main code for the CAN based bootloader
@ this is based on Microchip's AN247 (since withdrawn) - modified by MERG for their CBUS modules

    module(Main)

    .extern         CAN_initForExtendedFrames                       @ init the CAN module for bootloader use
    .extern         Can_getMsgEx                                    @ get the next extended CAN message and free CAN FIFO slot
    .extern         Bootloader_init                                 @ init the bootloader class
    .extern         Bootloader_dispatchMsg                          @ dispatch boot loader messages
    .extern         Acb_init                                        @ init the ACB library
    .extern         Acb_showLeds                                    @ show Leds

@ private variables - NOTE the bootloader doesn't have code to automatically initialise any RAM based
@ values

    private_data(main_vars)

@ incoming message
msgBuffer:          .space      ACB_MSGEX_SIZE

@ bootloader response (MSGEX structure)
bootLoaderResponse: .int        0x00080004                          @ msgex.info.exid - matches value from CBUS modules
                    .byte       (1<<ACB_MSG_LEN_OFFSET)|(1<<ACB_MSG_IDE_OFFSET) @ msgex.info.dlc_status IDE=1, DLC=1
                    .space      3, 0                                @ msgex.info.reserved
txMessageData:      .space      8, 0                                @ msgex.data

    public_function(main)

@ void main() - doesn't return
@   main code for bootloader. Setup ports/CAN, and waits for messages and then dispatches them

main:
__mainCalcMaxFlash:
                    ldr             r0, = #_DES_SIZE
                    ldrh            r0, [r0]
                    lsls            r0, #10                         @ size is stored in K, we need it in bytes
                    adds            r0, r0, #FLASH_BASE
__mainCalcPageSize:                                                 @ page size is always 2K
                    movs            r1, #11                         @ 11 bits = 2K
__initBootloader:
                    bl              Bootloader_init                 @ initialise the boot loader "class"
__mainSetupGPIOA:
                    ldr             r6, = #_RCC_AHB2ENR             @ enable port A peripheral clock
                    ldr             r1, [r6]
                    orrs            r0, r1, #RCC_AHB2ENR_GPIOAEN
                    str             r0, [r6]
#if ACB_CAN_AHBENR != RCC_AHBENR_GPIOAEN
                    ldr             r0, = #_CAN_AHBENR              @ enable CAN port, if it's not PORT A
                    orrs            r0, r0, r1
                    str             r0, [r6]
#endif

#if ACB_LED_USE
                    bl              Acb_init
#endif

__mainSetupCAN:
                    bl              CAN_initForExtendedFrames

#if ACB_LED_USE
__mainShowLEDs:
                    movs            r0, #3                          @ display both green and yellow to indicate
                    movs            r1, r0                          @ we're in bootloader mode
                    bl              Acb_showLeds
#endif

mainLoop:
                    ldr             r0,= #msgBuffer
                    bl              Can_getMsgEx                    @ have we got a message pending...
                    cmp             r0, #0                          @ no, just loop round
                    beq             mainLoop
                    ldr             r0,= #msgBuffer
                    bl              Bootloader_dispatchMsg          @ let the bootloader code handle the message
                    cmp             r0, #0                          @ status of 0, no message to send...
                    beq             mainLoop
                    subs            r1, r0, #1                      @ method status is message status + 1
                    ldr             r0, = #bootLoaderResponse
                    strb            r1, [r0, #ACB_MSGEX_DATA_OFFSET]
                    bl              Can_sendMessageEx               @ send the message
                    b               mainLoop

    .end
