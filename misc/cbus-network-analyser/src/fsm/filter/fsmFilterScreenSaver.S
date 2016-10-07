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

@ Finite State Machine filter function for implementing a screen saver

    module(FsmFilterScreenSaver)


    private_data(FsmFilterScreenSaver_privateData)

FsmFilterScreenSaver_counter:                                       @ how many times we've been called without any
                    .word           0                               @ action
FsmFilterScreenSaver_defaultContrast:                               @ default "running" contrast
                    .byte           0

    public_function(FsmFilterScreenSaver_setup)

@ void FsmFilterScreenSaver_setup(byte defaultContrast)
@   setup the screen saver. Supply the default constrast value, which is used for running.

FsmFilterScreenSaver_setup:
                    push            {r7, lr}
                    ldr             r1, = #FsmFilterScreenSaver_defaultContrast
                    strb            r0, [r1]
                    bl              Display_setContrast
                    pop             {r7, pc}

    public_function(FsmFilterScreenSaver_filter)

@ void FsmFilterScreenSaver_filter(short oldRotEnc, short newRotEnc, short buttonsAndStatus)
@   called before the main FSM dispatch routine. This checks for activity, and dims the screen on a timeout, and
@   eventually turns the screen off.

FsmFilterScreenSaver_filter:
                    push            {r7, lr}
                    ldr             r0, = #FsmFilterScreenSaver_counter
                    movs            r3, #FSM_STATE_CHANGED          @ check if anything has changed...
                    rev16           r2, r2
                    tst             r3, r2
                    beq             1f
                    ldr             r7, [r0]                        @ get current count
                    movs            r1, #0                          @ and store the reset value
                    str             r1, [r0]
                    ldr             r1, = #CBUSNA_SCNSAVE_DIM_TIMEOUT @ if not passed dim timeout, then just quit
                    cmp             r7, r1
                    ble             9f
                    ldrb            r0, [r0, #4]                    @ restore contrast
                    bl              Display_setContrast
                    ldr             r1, = #CBUSNA_SCNSAVE_OFF_TIMEOUT @ check if we need to show the display
                    cmp             r7, r1
                    ble             9f
                    bl              Display_showDisplay
                    b               9f
1:
                    ldr             r1, [r0]                        @ nothing has changed...
                    adds            r1, r1, #1
                    str             r1, [r0]
                    ldr             r2, = #CBUSNA_SCNSAVE_DIM_TIMEOUT   @ should we dim?
                    cmp             r1, r2
                    beq             2f
                    ldr             r2, = #CBUSNA_SCNSAVE_OFF_TIMEOUT   @ should we turn off the display?
                    cmp             r1, r2
                    bne             9f
                    bl              Display_hideDisplay
                    b               9f
2:
                    ldrb            r1, [r0, #4]                    @ get the default constrast and dim it
                    lsrs            r0, r1, #CBUSNA_SCNSAVE_DIM_SHIFT
                    bl              Display_setContrast
9:
                    pop             {r7, pc}

    .end
