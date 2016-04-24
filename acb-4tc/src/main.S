/*
 * Copyright (c) 2015 The NW1 Group
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#include "moduleInfo.inc"

    .extern         Setup_setup                                     @ setup hardware and peripherals

@ some constants

TMR3_PRESCALE = 74                                                  @ timer runs every 100ms
TMR3_PRELOAD  = 63999

@ main code for ACB-4TC (4 Turnout control)

    module(Main)

    private_data(Main_private)

canMessageEx:
                    .int            0xF7654321                      @ EXID
                    .byte           0x21                            @ DLC|IDE|RTR
                    .byte           0x0, 0x0, 0x0                   @ Reserved
                    .int            0x88                            @ Data
                    .int            0x00                            @ Data 2

canMessage:
                    .short          0x0                             @ STDID
                    .byte           0x21                            @ DLC|IDE|RTR
                    .byte           0x0                             @ Reserved
                    .int            0x030201FE                      @ Data
                    .int            0x07060504                      @ Data 2

currentOpCode:      .byte           0x20

                    .align          4
@ eepromTestBlock:
@                   .space          2048

count:              .int            0
fail:               .int            0

    public_function(main)

@ void main() - doesn't return
@   main code for module

stall:

    nop
    nop
    b           .

stall1:

    nop
    nop
    bkpt        #1
    b           .

stall2:

    nop
    nop
    b           .

stall3:

    nop
    nop
    b           .

stall4:

    nop
    nop
    b           .

stall5:

    nop
    nop
    b           .

main:

@ stack testing...

/*
    movs    r0, #0
    movs    r1, #1
    movs    r2, #2
    movs    r3, #3
    movs    r4, #4
    movs    r5, #5
    movs    r6, #6
    movs    r7, #7

    push    {r0-r2, r4-r7}

    ldr     r0, [sp, #4]
    ldr     r1, [sp, #8]

    pop     {r0-r2}
    pop     {r4-r7}
*/

                    bl              Setup_setup

/*
    nop
    nop
    nop
    movs    r0, #1
    ldr     r0, [r0]

*//*
    movs    r0, #ACB_CONFIG_LOAD_FAIL
    svc     ACB_FATAL_ERROR
*/
/*
    movs            r0, #0
    bl              Eeprom_getHint

0:
    bl              EepromImpl_asyncInProgress
    nop
    nop
    cmp             r0, #0
    beq             0b
*/
/*
    ldr             r4, = #MsCounter_milliseconds
    ldr             r5, [r4]
    adds            r5, r5, #255
0:
    ldr             r0, [r4]
    cmp             r5, r0
    bne             0b
*/
/*
    movs            r0, #0xbb
    bl              Eeprom_readByte
    movs            r7, r0
    nop
    nop
    nop
    movs            r0, #0xbb
    movs            r1, #0xcc
    bl              Eeprom_writeByte
    movs            r6, r0
    nop
    nop
    nop
    movs            r0, #0xbb
    bl              Eeprom_readByte
    movs            r5, r0
*/

@@@ Last Eeprom_cache test !!
/*
    movs            r0, #1
    movs            r1, #33
    ldr             r2, = #eepromTestBlock
    bl              Eeprom_readBlock

    movs            r1, #32
    ldr             r2, = #eepromTestBlock
0:
    ldrb            r0, [r2, r1]
    mvns            r0, r0
    strb            r0, [r2, r1]
    subs            r1, r1, #1
    bcs             0b

    movs            r0, #1
    movs            r1, #32
    bl              Eeprom_writeBlock
*/

/*
    movs            r0, #EepromCache_getBaseAddressHint             @ re-init the EEPROM
    bl              Eeprom_getHint
    cmp             r0, #0
    beq             stall
    ldr             r1, = #ACB_EEPROM_SIZE
    movs            r2, #0xFF
0:
    strb            r2, [r0, r1]
    subs            r1, r1, #1
    bcs             0b
    movs            r3, r0
    movs            r0, #0
    ldr             r1, = #ACB_EEPROM_SIZE
    bl              Eeprom_writeBlockEx
    cmp             r0, #ERROR
    beq             stall1
*/

    nop
    nop
/*
    bl              EepromImpl_getLastAsyncStatus
    nop
    nop
    nop
*/
/*
    movs            r0, #1
    bl              Eeprom_readByte
    cmp             r0, #ERROR
    beq             stall
*/
/*
    ldr             r6, = #count
0:
*/
/*
    movs            r0, #0
    ldr             r1, = #2048
    ldr             r2, = #eepromTestBlock
    bl              Eeprom_readBlockEx

    cmp             r0, #ERROR
    beq             1f

    ldr             r0, [r6]
    adds            r0, r0, #1
    str             r0, [r6]
    b               0b

1:
    ldr             r0, [r6, #4]
    adds            r0, r0, #1
    str             r0, [r6, #4]
    b               0b
*/
/*

    ldr             r1, = #2048
    ldr             r2, = #eepromTestBlock
0:
    ldrb            r0, [r2, r1]
    mvns            r0, r0
    strb            r0, [r2, r1]
    subs            r1, r1, #1
    bcs             0b
*/
/*
    movs            r0, #0
    ldr             r1, = #2048
    ldr             r2, = #eepromTestBlock
    bl              Eeprom_readBlockEx

    ldr             r1, = #2048
    ldr             r2, = #eepromTestBlock
0:

    movs            r3, #0xFF
    strb            r3, [r2, r1]
    subs            r1, r1, #1
    bcs             0b

    movs            r0, #0
    ldr             r1, = #2048
    ldr             r2, = #eepromTestBlock
    bl              Eeprom_writeBlockEx
    cmp             r0, #ERROR
    beq             stall1
*/
/*
    ldr             r7, = #2047
0:
    movs            r0, r7
    movs            r1, r7
    movs            r2, #0x0F
    ands            r1, r1, r2
    lsrs            r2, r0, #4
    movs            r3, 0xF0
    ands            r2, r2, r3
    orrs            r1, r1, r2
    bl              Eeprom_writeByte
@    bl              Eeprom_readByte
    cmp             r0, #ERROR
    beq             stall
    subs            r7, r7, #1
    bcs             0b
*/
/*
     nop
     nop
    ldr            r0, = #2047
    bl              Eeprom_readByte
     nop
     nop
*/
/*
    movs            r0, #1
    movs            r1, #0x55
    bl              Eeprom_writeByte
    cmp             r0, #ERROR
    beq             stall
    movs            r0, #1
    bl              Eeprom_readByte
    cmp             r0, #ERROR
    beq             stall2

@    movs            r0, #2
@    movs            r1, #0xAA
@    bl              Eeprom_writeByte
@    cmp             r0, #ERROR
@    beq             stall3
    movs            r0, #2
    bl              Eeprom_readByte
    cmp             r0, #ERROR
    beq             stall5

@    ldr r0, = #canMessage
@    bl  CBUS_handleMessage

@       ldr             r0, = #System_coreClock
@       ldr             r0, [r0]
@       bl              Math_divu1000


@        ldr             r0, = #4096
@        bl              Eeprom_readByte
*/
/*
__setupTimer3:

        ldr             r2, = #GPIOA_BASE               @ enable a bits for high speed output
        ldr             r1, [r2, #GPIO_MODER_OFFSET]
        ldr             r3, = #(3<<(0<<1))
        bics            r1, r1, r3
        ldr             r3, = #(1<<(0<<1))
        orrs            r3, r3, r1
        str             r3, [r2, #GPIO_MODER_OFFSET]
        ldr             r1, [r2, #GPIO_OSPEEDR_OFFSET]
        ldr             r3, = #(3<<(0<<1))
        orrs            r1, r1, r3
        str             r1, [r2, #GPIO_OSPEEDR_OFFSET]

                    ldr             r6, = #_RCC_APB1ENR             @ enable timer 3 clock
                    ldr             r1, [r6]
                    movs            r0, #RCC_APB1ENR_TIM3EN
                    orrs            r0, r0, r1
                    str             r0, [r6]

                    ldr             r6, = #TIM3_BASE
                    movs            r0, #0                          @ turn off timer 3 whilst we modify the values
                    str             r0, [r6, #TIM_CR1_OFFSET]
                    ldr             r0, = #TMR3_PRESCALE            @ set the prescale
                    str             r0, [r6, #TIM_PSC_OFFSET]
                    ldr             r0, = #TMR3_PRELOAD             @ set the preload
                    str             r0, [r6, #TIM_ARR_OFFSET]

                    movs            r0, #TIM3_IRQn                  @ enable timer 3 interrupts through NVIC
                    bl              NVIC_enableIRQ

                    movs            r0, #(1<<0)                     @ enable timer 3 interrupts through peripheral
                    str             r0, [r6, #TIM_DIER_OFFSET]
                    movs            r0, #(1<<0)                     @ turn the timer on
                    str             r0, [r6, #TIM_CR1_OFFSET]

                    ldr             r6, = #SCB_SCR                  @ enable sleep on exit, so that
                    ldr             r1, [r6]                        @ the device will go back to sleep
                    movs            r0, #SCB_SCR_SLEEPONEXIT_Msk    @ after the interrupt is handled
                    orrs            r1, r1, r0
                    str             r1, [r6]
*/
__mainLoop:

/*
    ldr r3, =#GPIOB_BASE
    ldr r2, [r3, #GPIO_IDR_OFFSET]
    ldr r1, =#1<<8
    tst r1, r2
    beq 0f
*/

                    dsb                                             @ ensure all pending memory operations complete
                    wfi                                             @ before entering sleep
9:
    nop
    nop
/*
                    bl              Acb_readyForFLiM
                    cmp             r0, #TRUE
                    beq             0f

                    bl              Acb_shortFLiMPress
                    cmp             r0, #TRUE
                    beq             1f
*/

                    b               __mainLoop                      @ do nothing for now

0:
    nop
    nop
    nop
    nop
    b   9b

1:
    nop
    nop
    nop
    nop
    b   9b

/*
                    bl              Setup_setup
                    b               .                               @ do nothing for now
*/

@ Timer 3 IRQ handler

    public_function(__tim3IRQHandler)

__tim3IRQHandler:
                    nop
                    nop
                    nop
                    push            {r7, lr}

                    ldr             r1, = #_TIM3_SR                 @ acknowledge the interrupt
                    movs            r0, #0
                    str             r0, [r1]

                    ldr             r3, = #GPIOA_BASE
                    ldr             r2, [r3, #GPIO_ODR_OFFSET]
                    movs            r1, #1
                    tst             r2, r1
                    beq             0f
                    str             r1, [r3, #GPIO_BRR_OFFSET]
                    b               __irqReturn
0:
                    str             r1, [r3, #GPIO_BSRR_OFFSET]
                    b               __irqReturn

@                    ldr             r0, = #canMessage               @ send a can message
@                    ldrh            r1, [r0]                        @ keep incrementing the id
@                    adds            r1, r1, #1
@                    strh            r1, [r0]
@                    bl              Can_postMessage

@                    bl              CBUS_sendRSTAT

@                    movs            r0, # 0x99
@                    movs            r1, # 0x34
@                    movs            r2, # 0x05
@                    bl              CBUS_sendERR_raw

@                    bl              test_fn7

/*
                    sub             sp, sp, #8
                    ldr             r0, = 0x04030201
                    str             r0, [sp]
                    ldr             r0, = 0x00070605
                    str             r0, [sp, #4]
                    ldr             r1, = currentOpCode
                    ldrb            r0, [r1]
                    adds            r0, r0, #1
                    strb            r0, [r1]
                    mov             r1, sp
                    bl              CBUS_sendMessage
                    add             sp, sp, #8
*/
/*
                    @ CBUS_sendMessage_S
                    ldr             r0, = #0x1122
                    bl              CBUS_sendRLOC

                    @ CBUS_sendMessage_SS
                    ldr             r0, = #0x1122
                    ldr             r1, = #0x3344
                    bl              CBUS_sendACON

                    @ CBUS_sendMessage_SSS
                    ldr             r0, = #0x1122
                    ldr             r1, = #0x3344
                    ldr             r2, = #0x5566
                    bl              CBUS_sendACON2
*/
/*
                    @ CBUS_sendMessage_BSB
                    movs            r0, #0x11
                    ldr             r1, = #0x2233
                    movs            r2, #0x44
                    bl              CBUS_sendWCVO

                    @ CBUS_sendMessage_BSBB
                    movs            r0, #0x11
                    ldr             r1, = #0x2233
                    movs            r2, #0x44
                    movs            r3, #0x55
                    bl              CBUS_sendWCVS

                    @ CBUS_sendMessage_BSBBBB
                    movs            r0, #0x11
                    ldr             r1, = #0x2233
                    movs            r2, #0x44
                    sub             sp, sp, #8
                    movs            r3, #0x77
                    str             r3, [sp, #4]
                    movs            r3, #0x66
                    str             r3, [sp]
                    movs            r3, #0x55
                    bl              CBUS_sendPLOC
                    add             sp, sp, #8
*/
@                   bl              test_fnPLOC
/*
                    @ CBUS_sendMessage_SB
                    ldr             r0, = #0x1122
                    movs            r1, 0x33
                    bl              CBUS_sendGLOC

                    @ CBUS_sendMessage_SBB
                    ldr             r0, = #0x1122
                    movs            r1, 0x33
                    movs            r2, 0x44
                    bl              CBUS_sendNVSET

                    @ CBUS_sendMessage_SBBB
                    ldr             r0, = #0x1122
                    movs            r1, 0x33
                    movs            r2, 0x44
                    movs            r3, 0x55
                    bl              CBUS_sendNEVAL

                    @ CBUS_sendMessage_SBBBBB
                    ldr             r0, = #0x1122
                    movs            r1, 0x33
                    movs            r2, 0x44
                    sub             sp, sp, #8
                    movs            r3, #0x77
                    str             r3, [sp, #4]
                    movs            r3, #0x66
                    str             r3, [sp]
                    movs            r3, #0x55
                    bl              CBUS_sendENRSP
                    add             sp, sp, #8
*/
/*
                    @ CBUS_sendMessage_SSB
                    ldr             r0, = #0x1122
                    ldr             r1, = #0x3344
                    movs            r2, 0x55
                    bl              CBUS_sendACON1

                    @ CBUS_sendMessage_SSBB
                    ldr             r0, = #0x1122
                    ldr             r1, = #0x3344
                    movs            r2, 0x55
                    movs            r3, 0x66
                    bl              CBUS_sendWCVOA

                    @ CBUS_sendMessage_SSBBB
                    ldr             r0, = #0x1122
                    ldr             r1, = #0x3344
                    movs            r2, 0x55
                    sub             sp, sp, #8
                    movs            r3, #0x77
                    str             r3, [sp]
                    movs            r3, #0x66
                    bl              CBUS_sendACON3
                    add             sp, sp, #8
*/
__irqReturn:
                    pop             {r7, pc}                        @ return from handler

    .end
