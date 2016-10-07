/*
 * Copyright (c) 2015 The NW1 Group
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#include "moduleInfo.inc"
#include "cbusNetworkAnalyser.inc"

@ Common Finite State Machine functions

    module(FsmCommon)

    .extern         Setup_setup                                     @ setup hardware and peripherals
    .extern         Display_drawAlignedString                       @ draw a aligned single line characters
    .extern         Display_blitDisplayBuffer                       @ draw the display buffer onto the display
    .extern         Display_fillRow                                 @ fill a row in the display buffer
    .extern         Display_drawString                              @ draw a string into the display buffer
    .extern         NVIC_disableIRQ                                 @ disable interrupt
    .extern         NVIC_enableIRQ                                  @ enable interrupt

    private_data(FsmCommon_private)

INSTRUCTION_DELAY  = (2 * 1000) / MAINLOOP_DELAY                    @ how long to show the instructions for

Fsm_state:          .int            FsmCommon_showSplash            @ Current FSM State
FsmCommon_splashCount:
                    .int            INSTRUCTION_DELAY               @ show splash screen for 2s

FsmCommon_instructionTablePtr:                                      @ data for the instruction table
                    .int            0
FsmCommon_afterInstructionsState:
                    .int            0
FsmCommon_displayCount:
                    .short          INSTRUCTION_DELAY
FsmCommon_currentInstruction:
                    .byte           0
FsmCommon_maxInstructions:
                    .byte           0

FsmCommon_delayNext:
                    .int            0
FsmCommon_delayCount:
                    .short          0

    static_data(FsmCommon_const)

FsmCommon_const:
version:
#if !defined(__DEBUG)
                    .string         "Version 0.00D"
#else
                    .string         "Version 0.00"
#endif

    public_function(FsmCommon_dispatch)

@ void FsmCommon_dispatch(short oldRotEnc, short newRotEnc, short buttonsAndStatus)
@   Call filters, and then dispatch message to the current state.

FsmCommon_dispatch:
                    push            {r4-r7, lr}
                    movs            r4, r0                          @ call the filters
                    movs            r5, r1
                    movs            r6, r2
                    bl              FsmFilterScreenSaver_filter
                    movs            r0, r4
                    movs            r1, r5
                    movs            r2, r6
                    bl              FsmFilterCanActivity_filter
                    movs            r0, r4
                    movs            r1, r5
                    movs            r2, r6

                    ldr             r7, = #Fsm_state                @ load the current FSM state
                    ldr             r5, [r7]
                    blx             r5                              @ call the current FSM state
                    cmp             r0, #0                          @ has the state changed?
                    beq             9f                              @ nope...
                    str             r0, [r7]                        @ otherwise store the new state
9:
                    pop             {r4-r7, pc}

    public_function(FsmCommon_delayFor)

@ int FsmCommon_delayFor(short delayFor, fn* handler)
@   delay for delayFor * 5ms, and then set the handler as the next state. Returns the next state, or 0 to remain in the
@   same state

FsmCommon_delayFor:
                    ldr             r2, = #FsmCommon_delayNext
                    str             r1, [r2]
                    strh            r0, [r2, #4]
                    ldr             r0, = #FsmCommon_delay
                    bx              lr

    private_function(FsmCommon_delay)

@ int FsmCommon_delay(short oldRotEnc, short newRotEnc, short buttonsAndStatus)
@   FSM Routine for delaying. Returns the next state, or 0 to remain in the same state

FsmCommon_delay:
                    ldr             r2, = #FsmCommon_delayNext
                    ldrh            r0, [r2, #4]
                    subs            r0, r0, #1
                    bcc             0f
                    strh            r0, [r2, #4]
                    movs            r0, #0
                    bx              lr
0:
                    ldr             r0, [r2]
                    bx              lr

    private_function(FsmCommon_showSplash)

@ int FsmCommon_showSplash(short oldRotEnc, short newRotEnc, short buttonsAndStatus)
@   FSM Routine for showing the splash screen. Returns the next state, or 0 to remain in the same state

FsmCommon_showSplash:
                    push            {r7, lr}
                    movs            r0, #0                          @ display splash image
                    movs            r1, #0
                    ldr             r2, = #__splash_data
                    bl              Display_drawBitmap

                    movs            r0, #6                          @ overlay version string onto image
                    movs            r1, #45
                    movs            r2, #1
                    ldr             r3, = #version
                    bl              Display_drawString
                    bl              Display_blitDisplayBuffer
                    ldr             r0, = #FsmCommon_splashTimeout
                    pop             {r7, pc}

    private_function(FsmCommon_splashTimeout)

@ int FsmCommon_splashTimeout(short oldRotEnc, short newRotEnc, short buttonsAndStatus)
@   FSM Routine for showing the splash screen. Returns the next state, or 0 to remain in the same state

FsmCommon_splashTimeout:
                    ldr             r1, = #FsmCommon_splashCount
                    ldr             r0, [r1]
                    subs            r0, r0, #1
                    str             r0, [r1]
                    beq             8f
                    movs            r0, #0
                    bx              lr
8:
                    push            {r7, lr}
                    ldr             r0, = #FsmStatistics_initStats  @ show first tab
                    pop             {r7, pc}

    .end
