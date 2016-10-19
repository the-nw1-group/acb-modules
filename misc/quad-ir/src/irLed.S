/*
 * Copyright (c) 2015 The NW1 Group
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#include "moduleInfo.inc"

/*
 * Control the IR LED, using Timer 17 with PWM output. The PWM frequency is 2Khz, with a 50% duty cycle
 *
 */

    module(IrLed)

    public_function(IrLed_init)

@ void IrLed_init(void)
@   Init the timer, and setup the port for AF mode, etc...

IrLed_init:
                    push            {r7, lr}
__irled_gpio:
                    ldr             r2, = #QUADIR_IRLED_GPIOBASE    @ setup IR LED output pin to be alternate
                    ldr             r0, [r2, #GPIO_MODER_OFFSET]    @ function, controlled by timer 17; set medium
                    ldr             r1, = #3<<(QUADIR_IRLED<<1)     @ speed
                    bics            r0, r0, r1
                    ldr             r1, = #2<<(QUADIR_IRLED<<1)
                    orrs            r0, r0, r1
                    str             r0, [r2, #GPIO_MODER_OFFSET]
                    ldr             r0, [r2, #GPIO_OSPEEDR_OFFSET]
                    ldr             r1, = #3<<(QUADIR_IRLED<<1)
                    bics            r0, r0, r1
                    ldr             r1, = #2<<(QUADIR_IRLED<<1)
                    orrs            r0, r0, r1
                    str             r0, [r2, #GPIO_OSPEEDR_OFFSET]
                    ldr             r0, [r2, #QUADIR_AF]
                    ldr             r1, =#0xf<<(QUADIR_IRLED<<2)
                    bics            r0, r0, r1
                    ldr             r1, = #QUADIR_AF_VALUE
                    orrs            r0, r0, r1
                    str             r0, [r2, #QUADIR_AF]
__irled_timer:
                    ldr             r7, = #TIM17_BASE               @ setup timer to generate a 2Khz square wave,
                    movs            r0, #0                          @ with 50% duty cycle. PWM is half the period
                    str             r0, [r7, #TIM_PSC_OFFSET]       @ preload, PWM mode 1 with fast update, enable
                    ldr             r0, = #3999                     @ output to GPIO pin. Enable update and capture/
                    str             r0, [r7, #TIM_ARR_OFFSET]       @ compare interrupts
                    lsrs            r0, r0, #1
                    str             r0, [r7, #TIM_CCR1_OFFSET]
                    movs            r0, #TIM_CCMR1_OC1FE | TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC1M_1
                    str             r0, [r7, #TIM_CCMR1_OFFSET]
                    movs            r0, #TIM_CCER_CC1E
                    str             r0, [r7, #TIM_CCER_OFFSET]
                    ldr             r0, = #TIM_BDTR_MOE
                    str             r0, [r7, #TIM_BDTR_OFFSET]
                    movs            r0, #TIM_DIER_UIE | TIM_DIER_CC1IE
                    str             r0, [r7, #TIM_DIER_OFFSET]
                    movs            r0, #TIM17_IRQn
                    bl              NVIC_enableIRQ
                    ldr             r0, [r7, #TIM_CR1_OFFSET]
                    movs            r0, #TIM_CR1_ARPE               @ enable auto-preload
                    str             r0, [r7, #TIM_CR1_OFFSET]
                    pop             {r7, pc}

    public_function(IrLed_startDetection)

@ void IrLed_startDetection(void)
@   start the timer running

IrLed_startDetection:
                    ldr             r2, = #TIM17_BASE               @ set the PWM mode 1
                    ldr             r0, [r2, #TIM_CCMR1_OFFSET]
                    movs            r1, #TIM_CCMR1_OC1M
                    bics            r0, r0, r1
                    movs            r1, #TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC1M_1
                    orrs            r0, r0, r1
                    str             r0, [r2, #TIM_CCMR1_OFFSET]
                    ldr             r0, [r2, #TIM_CR1_OFFSET]       @ enable timer
                    movs            r1, #TIM_CR1_CEN
                    orrs            r0, r0, r1
                    str             r0, [r2, #TIM_CR1_OFFSET]
                    bx              lr

    public_function(IrLed_stopDetection)

@ void IrLed_stopDetection(void)
@   stop the timer

IrLed_stopDetection:
                    push            {r7, lr}
                    ldr             r2, = #TIM17_BASE               @ set the PWM mode - force low
                    ldr             r0, [r2, #TIM_CCMR1_OFFSET]
                    movs            r1, #TIM_CCMR1_OC1M
                    bics            r0, r0, r1
                    movs            r1, #TIM_CCMR1_OC1M_2
                    orrs            r0, r0, r1
                    str             r0, [r2, #TIM_CCMR1_OFFSET]
                    ldr             r0, [r2, #TIM_CR1_OFFSET]       @ disable timer
                    movs            r1, #TIM_CR1_CEN
                    bics            r0, r0, r1
                    str             r0, [r2, #TIM_CR1_OFFSET]
                    movs            r0, #TIM17_IRQn
                    bl              NVIC_clearPendingIRQ
                    pop             {r7, pc}

    public_function(__tim17IRQHandler)

@ void __tim17IRQHandler(void)
@   timer 17 ISR, called when PWM transitions from low to high, or high to low

__tim17IRQHandler:
                    push            {r5-r7, lr}
                    ldr             r7, = #TIM17_BASE
                    ldr             r5, [r7, #TIM_SR_OFFSET]
                    movs            r6, #TIM_SR_UIF                 @ is it the update event, if so then start the
                    tst             r5, r6                          @ ADC reading onSamples
                    beq             0f
                    movs            r0, #1
                    b               2f
0:
                    movs            r6, #TIM_SR_CC1IF               @ otherwise, is if the capture/compare interrupt, if
                    tst             r5, r6                          @ so, then start the ADC reading offSamples
                    beq             1f
                    movs            r0, #0
2:
                    bl              Analog_start
                    bics            r5, r5, r6                      @ clear flag
                    str             r5, [r7, #TIM_SR_OFFSET]
1:
                    pop             {r5-r7, pc}

    .end
