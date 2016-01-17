/*
 * Copyright (c) 2015 The NW1 Group
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#include "moduleInfo.inc"

@ Common Finite State Machine functions

    module(FsmCommon)

    .extern         Setup_setup                                     @ setup hardware and peripherals
    .extern         Display_drawAlignedString                       @ draw a aligned single line characters
    .extern         Display_blitDisplayBuffer                       @ draw the display buffer onto the display

    private_data(FsmCommon_private)

Fsm_state:          .int            FsmCommon_showSplash            @ Current FSM State
FsmCommon_splashCount:
                    .int            (2 * 1000) / MAINLOOP_DELAY     @ show splash screen for 2s

    static_data(FsmCommon_const)

FsmCommon_const:
FsmCommon_title:
welcome:            .string         "Signal / Servo Tester"
version:            .string         "Version 0.00"

                    .global         FsmCommon_title                 @ Application title

    public_function(FsmCommon_dispatch)

@ void FsmCommon_dispatch(short redValue, short blueValue, short greenValue, int buttonsAndStatus)
@   Dispatch message to the current state.

FsmCommon_dispatch:
                    push            {r5-r7, lr}
                    ldr             r7, = #Fsm_state                @ load the current FSM state
                    ldr             r5, [r7]
                    blx             r5                              @ call the current FSM state
                    cmp             r0, #0                          @ has the state changed?
                    beq             9f                              @ nope...
                    str             r0, [r7]                        @ otherwise store the new state
9:
                    pop             {r5-r7, pc}

    private_function(FsmCommon_showSplash)

@ int FsmCommon_showSplash(short redValue, short blueValue, short greenValue, int buttonsAndStatus)
@   FSM Routine for showing the splash screen. Returns the next state, or 0 to remain in the same state

FsmCommon_showSplash:
                    push            {r7, lr}
                    movs            r0, #DISPLAY_CENTER_ALIGN
                    ldr             r1, = #(0 | DISPLAY_ROW)
                    movs            r2, #1
                    ldr             r3, = #welcome
                    bl              Display_drawAlignedString
                    movs            r0, #DISPLAY_CENTER_ALIGN
                    ldr             r1, = #(1 | DISPLAY_ROW)
                    movs            r2, #1
                    ldr             r3, = #version
                    bl              Display_drawAlignedString
                    bl              Display_blitDisplayBuffer
                    ldr             r0, = #FsmCommon_splashTimeout
                    pop             {r7, pc}

    public_function(FsmCommon_splashTimeout)

@ int FsmCommon_splashTimeout(short redValue, short blueValue, short greenValue, int buttonsAndStatus)
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
                    ldr             r0, = #FsmMenus_initMainMenu
                    bx              lr

    .end
