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
    .extern         FsmCommon_dispatch                              @ call into the FSM
    .extern         SimpleInputDebounce_getState                    @ get debounced inputs

@ main code for CBUS Network Analyser

    module(Main)

    private_data(Main_private)

Main_thisEncPos:    .short          0
Main_thisButtons:   .byte           0
Main_thisStatus:    .byte           0

Main_lastEncPos:    .short          0
Main_lastButtons:   .byte           0
Main_lastStatus:    .byte           0

    public_function(main)

@ void main() - doesn't return
@   main code for module

main:
                    bl              Setup_setup

__mainLoop:
                    movs            r0, #MAINLOOP_DELAY             @ wait for n ms before calling the FSM
                    bl              MsCounter_waitFor

                    ldr             r0, = #Main_thisEncPos
                    bl              Main_getInputState              @ get button/CAN state
                    ldr             r4, = #Main_thisEncPos
                    ldrh            r0, [r4, #4]
                    ldrh            r1, [r4, #0]
                    ldrh            r2, [r4, #2]
                    bl              FsmCommon_dispatch              @ then dispatch to the next FSM state
                    bl              IWDG_reset                      @ reset the watchdog
                    b               __mainLoop

    private_function(Main_getInputState)

@ void Main_getInputState(short* stateData)
@   Get the current input state and CAN state. stateData parameters is a pointer to 1 short for this rotary encoder
@   position value, 1 short of combined button and state information. Followed by the same but used for the previous
@   values. Making a total of 4 shorts

Main_getInputState:
                    push            {r5-r7, lr}
                    movs            r7, r0
                    movs            r6, #0
                    ldr             r1, [r7]                        @ copy over current values to last values
                    str             r1, [r7, #4]

                    bl              SimpleInputDebounce_getState    @ get button values (it's already in the correct place
                    orrs            r6, r6, r0                      @ for the state change, but needs to be shifted
                    lsrs            r0, r0, #(CBUSNA_BUTTON_PIN-FSM_BUTTON_BIT) @ for the button state
                    strb            r0, [r7, #2]

                    bl              RotaryEncoder_getValue          @ get rotary encoder value
                    strh            r0, [r7, #0]
                    ldrh            r1, [r7, #4]                    @ get last rotary encode value
                    cmp             r0, r1
                    beq             2f
                    bgt             1f
                    movs            r0, #FSM_STATE_ROTENC_CHANGED   @ encoder value has changed, but it's less than the
                    orrs            r6, r6, r0                      @ previous value
                    b               2f
1:
                    movs            r0, #FSM_STATE_ROTENC_CHANGED | FSM_STATE_ROTENC_INC @ encoder value has changed,
                    orrs            r6, r6, r0                      @ and it's greater than the previous values
2:
                    bl              CanMessageLog_getStatus         @ get CAN message and error status
                    lsls            r0, r0, #FSM_STATE_CAN_MSG_BIT
                    orrs            r6, r6, r0
                    strb            r6, [r7, #3]                    @ save state
                    pop             {r5-r7, pc}

    .end
