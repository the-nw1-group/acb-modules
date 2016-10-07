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

@ rotary encoder code

    module(RotaryEncoder)

    public_function(RotaryEncoder_setup)
@ void RotaryEncoder_setup()
@   setup the timer for rotary encoder use

RotaryEncoder_setup:
                    ldr             r3, = #CBUSNA_ROTENC_GPIOBASE   @ setup CH1/CH2 on port/pins defined in header
                    ldr             r1, [r3, #GPIO_MODER_OFFSET]    @ file
                    ldr             r0, = #(2<<(CBUSNA_ROTENC_A<<1))|(2<<(CBUSNA_ROTENC_B<<1))
                    orrs            r0, r0, r1
                    str             r0, [r3, #GPIO_MODER_OFFSET]
                    ldr             r1, [r3, #CBUSNA_ROTENC_GPIO_AFR_OFFSET]
                    ldr             r0, = #(CBUSNA_ROTENC_A_AF<<(CBUSNA_ROTENC_A<<2))|(CBUSNA_ROTENC_B_AF<<(CBUSNA_ROTENC_B<<2))
                    orrs            r0, r0, r1
                    str             r0, [r3, #CBUSNA_ROTENC_GPIO_AFR_OFFSET]  @ set AF function

                    ldr             r3, = #CBUSNA_ROTENC_TIMBASE
                    ldr             r1, = #(1<<16)-1
                    str             r1, [r3, #TIM_ARR_OFFSET]
                                                                    @ trigger on TI2 edges, filter /8 N=6
                    ldr             r1, = #TIM_SMCR_ETF_0 | TIM_SMCR_TS_2 | TIM_SMCR_TS_1 | TIM_SMCR_SMS_0
                    str             r1, [r3, #TIM_SMCR_OFFSET]
                                                                    @ CH1=TI1, and CH2=TI2 (filtered) both input capture
                    ldr             r1, = #TIM_CCMR1_CC2S_1 | TIM_CCMR1_CC2S_0 | TIM_CCMR1_CC1S_0
                    str             r1, [r3, #TIM_CCMR1_OFFSET]
                                                                    @ invert OC1
                    movs            r1, #TIM_CCER_CC1P
                    str             r1, [r3, #TIM_CCER_OFFSET]
                                                                    @ enable the timer
                    movs            r1, #TIM_CR1_CEN
                    str             r1, [r3, #TIM_CR1_OFFSET]
                    bx              lr

    public_function(RotaryEncoder_getValue)

@ int RotaryEncoder_getValue()
@   get the current rotary encoder value. Returns the current rotary encoder value

RotaryEncoder_getValue:
                    ldr             r3, = #CBUSNA_ROTENC_TIMBASE
                    ldr             r0, [r3, #TIM_CNT_OFFSET]
                    lsrs            r0, r0, #1                      @ our encoder outputs 2 pulses per "click"
                    bx              lr                              @ shift right to just get 1 pulse per "click"

    .end
