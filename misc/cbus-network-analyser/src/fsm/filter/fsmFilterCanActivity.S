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

@ Finite State Machine filter function for implementing a CAN activity monitor

    module(FsmFilterCanActivity)

    private_data(FsmFilterCanActivity_privateData)

FsmFilterCanActivity_messageIndicator:
                    .word           CBUSNA_LED2_TIMBASE             @ which timer
                    .word           CBUSNA_LED2_GPIOBASE            @ which GPIO
                    .word           0
                    .word           CBUSNA_LED2_DIM                 @ when to start dimming
                    .byte           CBUSNA_LED2_PIN                 @ which PIN
                    .byte           CBUSNA_LED2_AFNO                @ which AF
                    .byte           CBUSNA_LED2_DIMSHIFT            @ how much to dim
                    .byte           0

    .align 4

FsmFilterCanActivity_errorIndicator:
                    .word           CBUSNA_LED1_TIMBASE             @ which timer
                    .word           CBUSNA_LED1_GPIOBASE            @ which GPIO
                    .word           0
                    .word           CBUSNA_LED1_DIM                 @ when to start dimming
                    .byte           CBUSNA_LED1_PIN                 @ which PIN
                    .byte           CBUSNA_LED1_AFNO                @ which AF
                    .byte           CBUSNA_LED1_DIMSHIFT            @ how much to dim
                    .byte           0

    public_function(FsmFilterCanActivity_setup)

@ void fsmFilterCanActivity_setup()
@   setup the CAN activity monitor.

FsmFilterCanActivity_setup:
                    push            {r7, lr}
                    ldr             r0, = #FsmFilterCanActivity_messageIndicator
                    bl              LedPwm_setup
                    ldr             r0, = #FsmFilterCanActivity_errorIndicator
                    bl              LedPwm_setup
                    pop             {r7, pc}

    public_function(FsmFilterCanActivity_filter)

@ void FsmFilterCanActivity_filter(short oldRotEnc, short newRotEnc, short buttonsAndStatus)
@   called before the main FSM dispatch routine. This checks for CAN activity/error, and displays this through the
@   LED pwm module

FsmFilterCanActivity_filter:
                    push            {r7, lr}
                    rev16           r7, r2
                    movs            r1, #FSM_STATE_CAN_MSG          @ check if we had any CAN messages
                    ands            r1, r1, r7
                    ldr             r0, = #FsmFilterCanActivity_messageIndicator
                    bl              LedPwm_pulse
                    movs            r1, #FSM_STATE_CAN_ERR          @ check if we had any CAN errors
                    ands            r1, r1, r7
                    ldr             r0, = #FsmFilterCanActivity_errorIndicator

                    bl              LedPwm_pulse
                    pop             {r7, pc}

    .end
