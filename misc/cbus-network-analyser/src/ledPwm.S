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

@ LED PWM control

    module(LedPwm)

@ First argument to all methods takes a LedPwmData structure, with the following fields:
@   All counts are 5ms based

LedPwmData_timBase  = 0                                             @ word, timer to use
LedPwmData_gpioBase = 4                                             @ word, gpio of output
LedPwmData_count    = 8                                             @ word, counter
LedPwmData_dimCount = 12                                            @ word, when to start diming the output
LedPwmData_pin      = 16                                            @ byte, gpio pin of output
LedPwmData_af       = 17                                            @ byte, af number of timer/pin combination
LedPwmData_dimShift = 18                                            @ byte, right shift PWM value when dimming
LedPwmData_state    = 19                                            @ byte, state of LED PWM

LedPwmState_off     = 0                                             @ LED PWM is off (Timer running, but output not enabled
LedPwmState_full    = 1                                             @ LED PWM is on full brightness
LedPwmState_dim     = 2                                             @ LED PWM is on, but dimmed to some level

    public_function(LedPwm_setup)

@ void LedPwm_setup(LedPwmData* data)
@   setup the LED pwm. This assumes both the timer and the GPIO clocks have been enabled

LedPwm_setup:
                    push            {r5-r7, lr}
lps_configGPIO:
                    ldr             r1, [r0, #LedPwmData_gpioBase]
                    ldrb            r2, [r0, #LedPwmData_pin]
                    lsls            r6, r2, #1
                    movs            r3, #3                          @ select AF for gpio pin
                    lsls            r3, r3, r6
                    ldr             r7, [r1, #GPIO_MODER_OFFSET]
                    bics            r7, r7, r3
                    movs            r3, #2
                    lsls            r3, r3, r6
                    orrs            r7, r7, r3
                    str             r7, [r1, #GPIO_MODER_OFFSET]
                    ldr             r7, [r1, #GPIO_OSPEEDR_OFFSET]  @ set high speed for gpio pin
                    movs            r3, #3
                    lsls            r3, r3, r6
                    orrs            r7, r7, r3
                    str             r7, [r1, #GPIO_OSPEEDR_OFFSET]
                    cmp             r2, #8                          @ set AF
                    bge             0f
                                                                    @ AF for pins 0-7
                    movs            r7, #GPIO_AFR_OFFSET
                    b               1f
0:                                                                  @ AF for pins 8-15
                    subs            r2, r2, #8
                    movs            r7, #(GPIO_AFR_OFFSET+4)
1:
                    lsls            r6, r2, #2
                    ldr             r5, [r1, r7]
                    movs            r3, 0xf
                    lsls            r3, r3, r6
                    bics            r5, r5, r3
                    ldrb            r3, [r0, #LedPwmData_af]
                    lsls            r3, r3, r6
                    orrs            r3, r3, r5
                    str             r3, [r1, r7]
lps_configTimer:
                    ldr             r1, [r0, #LedPwmData_timBase]   @ configure for 100hz PWM, inverting the output
                    movs            r2, #TIM_CR1_ARPE               @ with the output initially off
                    str             r2, [r1, #TIM_CR1_OFFSET]
                    movs            r2, #TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1PE | TIM_CCMR1_OC1FE
                    str             r2, [r1, #TIM_CCMR1_OFFSET]
                    movs            r2, #TIM_CCER_CC1P | TIM_CCER_CC1E
                    str             r2, [r1, #TIM_CCER_OFFSET]
                    ldr             r2, = #TIM_BDTR_MOE | TIM_BDTR_AOE
                    str             r2, [r1, #TIM_BDTR_OFFSET]
                    movs            r2, #3
                    str             r2, [r1, #TIM_PSC_OFFSET]
                    ldr             r2, = #59999
                    str             r2, [r1, #TIM_ARR_OFFSET]
                    movs            r2, #0
                    str             r2, [r1, #TIM_CNT_OFFSET]
                    str             r2, [r1, #TIM_CCR1_OFFSET]
                    ldr             r2, [r1, #TIM_CR1_OFFSET]
                    movs            r3, #TIM_CR1_CEN
                    orrs            r2, r2, r3
                    str             r3, [r1, #TIM_CR1_OFFSET]
lps_initData:
                    movs            r1, #0
                    str             r1, [r0, #LedPwmData_count]
                    strb            r1, [r0, #LedPwmData_state]
                    pop             {r5-r7, pc}

    public_function(LedPwm_pulse)

@ void LedPwm_setup(LedPwmData* data, uint pulse)
@   pulse the LED if pulse is non-zero, otherwise fade the LED if required

LedPwm_pulse:
                    cmp             r1, #0
                    beq             lpp_noPulse
lpp_withPulse:
                    movs            r1, #LedPwmState_full           @ indicate that the LED is full on, and reset the
                    strb            r1, [r0, #LedPwmData_state]     @ counter
                    movs            r1, #0
                    str             r1, [r0, #LedPwmData_count]
                    ldr             r1, [r0, #LedPwmData_timBase]
                    ldr             r2, [r1, #TIM_ARR_OFFSET]       @ full brightness on the LED
                    str             r2, [r1, #TIM_CCR1_OFFSET]
                    b               9f
lpp_noPulse:
                    ldrb            r1, [r0, #LedPwmData_state]     @ no pulse, and already off, then just return
                    cmp             r1, #LedPwmState_off
                    beq             9f
                    ldr             r1, [r0, #LedPwmData_count]     @ see if we need to dim
                    ldr             r2, [r0, #LedPwmData_dimCount]
                    cmp             r1, r2
                    beq             lpp_dim
                    adds            r1, r1, #1                      @ no, just inc the count
                    str             r1, [r0, #LedPwmData_count]
                    b               9f
lpp_dim:
                    movs            r1, #0
                    str             r1, [r0, #LedPwmData_count]     @ yes, reset the count
                    ldrb            r2, [r0, #LedPwmData_dimShift]  @ get the shift
                    ldr             r3, [r0, #LedPwmData_timBase]
                    ldr             r1, [r3, #TIM_CCR1_OFFSET]      @ dim LED, by reducing the cycle rate
                    lsrs            r1, r1, r2
                    str             r1, [r3, #TIM_CCR1_OFFSET]
                    cmp             r1, #0
                    beq             1f
                    movs            r1, #LedPwmState_dim            @ set dim state if CCR1 > 0
                    b               2f
1:
                    movs            r1, #LedPwmState_off            @ otherwise it's now off
2:
                    strb            r1, [r0, #LedPwmData_state]
9:
                    bx              lr


    public_function(LedPwm_forceReset)

@ void LedPwm_forceReset(LedPwmData* data)
@   turn off LED, and reset state data to off

LedPwm_forceReset:
                    movs            r1, #0
                    str             r1, [r0, #LedPwmData_count]
                    strb            r1, [r0, #LedPwmData_state]
                    ldr             r2, [r0, #LedPwmData_timBase]
                    str             r1, [r2, #TIM_CCR1_OFFSET]
                    bx              lr


    .end
