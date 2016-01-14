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
    .extern         MsCounter_waitFor                               @ wait for a number of milliseconds

@ main code for Signal/Servo Tester

    module(Main)

    private_data(Main_private)

Main_thisRed:       .short          0
Main_thisGreen:     .short          0
Main_thisBlue:      .short          0
Main_thisButtons:   .byte           0
Main_thisStatus:    .byte           0

Main_lastRed:       .short          0
Main_lastGreen:     .short          0
Main_lastBlue:      .short          0
Main_lastButtons:   .short          0

    public_function(main)

@ void main() - doesn't return
@   main code for module

main:

                    bl              Setup_setup

__mainLoop:
                    movs            r0, #MAINLOOP_DELAY             @ wait for n ms before calling the FSM
                    bl              MsCounter_waitFor

                    ldr             r0, = #Main_thisRed
                    bl              Main_getInputState              @ get button/analog state
                    ldr             r4, = #Main_thisRed
                    ldrh            r0, [r4, #0]
                    ldrh            r1, [r4, #2]
                    ldrh            r2, [r4, #4]
                    ldrh            r3, [r4, #6]
                    bl              FsmCommon_dispatch              @ then dispatch to the next FSM state
                    b               __mainLoop

    private_function(Main_getInputState)

@ void Main_getInputState(short* stateData)
@   Get the current input state. stateData parameters is a pointer to 3 shorts for this rgb values, 1 short of combined
@   button and state information. Followed by the same but used for the previous values. Making a total of 8 shorts

Main_getInputState:
                    push            {r7, lr}
                    ldr             r1, [r0]                        @ copy over current values to last values
                    str             r1, [r0, #8]
                    ldr             r1, [r0, #4]
                    str             r1, [r0, #12]

                    ldr             r3, = #Analog_redValue          @ get the current RGB values
                    ldr             r1, [r3, #0]                    @ get R and G
                    str             r1, [r0, #0]                    @ and store
                    ldrh            r1, [r3, #4]                    @ get b
                    uxth            r1, r1                          @ zero extend
                    strh            r1, [r0, #4]

                    movs            r3, #0
                    ldrh            r1, [r0, #0]                    @ compare R with old R
                    ldrh            r2, [r0, #8]
                    cmp             r1, r2
                    beq             0f
                    ldr             r3, =#(FSM_STATE_ANALOG_CHANGED | FSM_STATE_RED_CHANGED)
0:
                    ldrh            r1, [r0, #2]                    @ compare G with old G
                    ldrh            r2, [r0, #10]
                    cmp             r1, r2
                    beq             1f
                    ldr             r7, =#(FSM_STATE_ANALOG_CHANGED | FSM_STATE_GREEN_CHANGED)
                    orrs            r3, r3, r7
1:
                    ldrh            r1, [r0, #2]                    @ compare B with old B
                    ldrh            r2, [r0, #10]
                    cmp             r1, r2
                    beq             2f
                    ldr             r7, =#(FSM_STATE_ANALOG_CHANGED | FSM_STATE_BLUE_CHANGED)
                    orrs            r3, r3, r7
                    strb            r3, [r0, #7]
2:
    @TODO: Still need some software debouncing here...

                    ldr             r3, = #SIGTEST_BUTTON_GPIOBASE  @ get button values
                    ldr             r2, [r3, #GPIO_IDR_OFFSET]
                    mvns            r2, r2                          @ invert, as the buttons have pullups
                    ldr             r7, = #(1<<SIGTEST_BUTTON_LEFT)|(1<<SIGTEST_BUTTON_ACTION)|(1<<SIGTEST_BUTTON_RIGHT)
                    ands            r2, r2, r7
                    movs            r7, #1
                    lsrs            r3, r2, #(SIGTEST_BUTTON_LEFT)  @ shift button states into their various places
                    ands            r3, r3, r7
                    movs            r7, #3
                    lsrs            r1, r2, #(SIGTEST_BUTTON_ACTION-1)
                    ands            r1, r1, r7
                    orrs            r3, r3, r1
                    movs            r7, #7
                    lsrs            r1, r2, #(SIGTEST_BUTTON_RIGHT-2)
                    ands            r1, r1, r7
                    orrs            r3, r3, r1
                    strb            r3, [r0, #6]                    @ store current button state
                    ldrb            r2, [r0, #16]                   @ get last button state, and compare
                    movs            r3, #0
                    eors            r1, r1, r2
                    beq             3f
                    ldr             r3, = #1<<FSM_STATE_BUTTONS_CHANGED_BIT
                    lsls            r1, r1, #FSM_STATE_LEFT_CHANGED_BIT
                    orrs            r3, r3, r1                      @ store which buttons changed
3:
                    ldrb            r2, [r0, #7]                    @ get analog state, and merge
                    orrs            r3, r3, r2
                    strb            r3, [r0, #7]
                    pop             {r7, pc}

    .end
