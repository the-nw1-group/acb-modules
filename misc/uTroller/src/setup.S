/*
 * Copyright (c) 2018 The NW1 Group
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#include "moduleInfo.inc"

@ setup code for uTroller

    module(Setup)

    .extern         MsCounter_init                                  @ Setup millisecond counter
    .extern         Analog_init                                     @ Setup the ADCs

    public_function(Setup_setup)

@ void Setup_setup()
@   Setup all major peripherals and their clocks

Setup_setup:
                    push            {r7, lr}
__setupCounter:
                    ldr             r0, =#System_coreClock
                    ldr             r0, [r0]
                    bl              MsCounter_init
                    bl              Setup_clocks

                                                                    @ it "seems" (i.e. I could be wrong), that with
                                                                    @ ST-LINK and/or OpenOCD, the processor isn't held in
                                                                    @ reset (unlike PICs for example), and some code might
                                                                    @ run before the debugger is attached, which then
                                                                    @ breaks whatever the processor was doing. This might
                                                                    @ cause issues with both the CAN and I2C interfaces
                                                                    @ so we delay here whilst the debugger attaches
#if defined(DEBUG)
                    movs            r0, #250                        @ delay for 250ms - only when running under the
                    bl              MsCounter_waitFor               @ debugger (which we can't tell on an M0, so for all
                                                                    @ debug builds)

                    ldr             r0, = #_DBGMCU_CR               @ enable debugging through stop/sleep
                    movs            r1, #DBGMCU_CR_DBG_STANDBY | DBGMCU_CR_DBG_STOP
                    str             r1, [r0]
                    ldr             r0, = #_DBGMCU_APB2FZ
                    ldr             r1, = #DBGMCU_APB2_FZ_DBG_TIM17_STOP
                    str             r1, [r0]
#endif
                    bl              Setup_setupGPIO
                    bl              Analog_init

                    pop             {r7, pc}

    private_function(Setup_clocks)

@ void Setup_clocks()
@   Enable various peripheral clocks required by this project

Setup_clocks:
                    ldr             r2, = #RCC_BASE

                    ldr             r1, [r2, #RCC_AHBENR_OFFSET]    @ enable port A, B, F and DMA peripheral clocks
                    ldr             r0, = #RCC_AHBENR_GPIOAEN | RCC_AHBENR_GPIOBEN | RCC_AHBENR_GPIOFEN | RCC_AHBENR_DMAEN
                    orrs            r0, r0, r1
                    str             r0, [r2, #RCC_AHBENR_OFFSET]

                    ldr             r1, [r2, #RCC_APB1ENR_OFFSET]
                    ldr             r1, = #RCC_APB1ENR_PWREN | RCC_APB1ENR_TIM2EN | RCC_APB1ENR_TIM3EN | RCC_APB1ENR_TIM14EN
                    orrs            r0, r0, r1
                    str             r0, [r2, #RCC_APB1ENR_OFFSET]   @ enable the power clock, timer 2, timer 3, timer 14

                    ldr             r1, [r2, #RCC_APB2ENR_OFFSET]   @ enable ADC, SYSCONFIG clocks (and debug clock, in debug)
#if defined(DEBUG)
                    ldr             r0, = #RCC_APB2ENR_ADCEN | RCC_APB2ENR_SYSCFGEN | RCC_APB2ENR_DBGMCUEN
#else
                    ldr             r0, = #RCC_APB2ENR_ADCEN | RCC_APB2ENR_SYSCFGEN
#endif
                    orrs            r0, r0, r1
                    str             r0, [r2, #RCC_APB2ENR_OFFSET]

                    bx              lr

@ void Setup_setupGPIO()
@   Setup all GPIO's - only those that are just inputs or outputs, and for outputs set sensible defaults
@   Other GPIO's (Analogs, and alternate functions, are set up in more specific routines)

Setup_setupGPIO:
                    ldr             r2, = #UTROLLER_SLEEP_GPIOBASE  @ set up sleep - output, push/pull, low speed,
                    ldr             r0, [r2, #GPIO_MODER_OFFSET]    @ no pull up/downs; inital setting low
                    ldr             r1, = #3<<(UTROLLER_SLEEP<<1)
                    bics            r0, r0, r1
                    ldr             r1, = #1<<(UTROLLER_SLEEP<<1)
                    orrs            r0, r0, r1
                    str             r0, [r2, #GPIO_MODER_OFFSET]
                    ldr             r0, = #1<<UTROLLER_SLEEP
                    str             r0, [r2, #GPIO_BRR_OFFSET]

                    ldr             r2, = #UTROLLER_CONFIG_GPIOBASE @ set up config - input, push/pull, low speed, pull
                    ldr             r0, [r2, #GPIO_PUPDR_OFFSET]    @ up
                    ldr             r1, = #3<<(UTROLLER_CONFIG0<<1) | 3<<(UTROLLER_CONFIG1<<1)
                    bics            r0, r0, r1
                    ldr             r1, = #1<<(UTROLLER_CONFIG0<<1) | 1<<(UTROLLER_CONFIG1<<1)
                    orrs            r0, r0, r1
                    str             r0, [r2, #GPIO_PUPDR_OFFSET]

                    ldr             r2, = #UTROLLER_TRACK_GPIOBASE  @ set up track - output, push/pull, med. speed,
                    ldr             r0, [r2, #GPIO_MODER_OFFSET]    @ no pull up/downs; inital setting low
                    ldr             r1, = #3<<(UTROLLER_TRACK<<1)   @ maybe reconfigured as PWM timer output later
                    bics            r0, r0, r1
                    ldr             r1, = #1<<(UTROLLER_TRACK<<1)
                    orrs            r0, r0, r1
                    str             r0, [r2, #GPIO_MODER_OFFSET]
                    ldr             r0, [r2, #GPIO_OSPEEDR_OFFSET]
                    ldr             r1, = #3<<(UTROLLER_TRACK<<1)
                    bics            r0, r0, r1
                    ldr             r1, = #1<<(UTROLLER_TRACK<<1)
                    orrs            r0, r0, r1
                    str             r0, [r2, #GPIO_OSPEEDR_OFFSET]
                    ldr             r0, = #1<<UTROLLER_TRACK
                    str             r0, [r2, #GPIO_BRR_OFFSET]

                    ldr             r2, = #UTROLLER_POWER_GPIOBASE  @ set up power - output, push/pull, med. speed,
                    ldr             r0, [r2, #GPIO_MODER_OFFSET]    @ no pull up/downs; inital setting low
                    ldr             r1, = #3<<(UTROLLER_POWER<<1)   @ maybe reconfigured as PWM timer output later
                    bics            r0, r0, r1
                    ldr             r1, = #1<<(UTROLLER_POWER<<1)
                    orrs            r0, r0, r1
                    str             r0, [r2, #GPIO_MODER_OFFSET]
                    ldr             r0, [r2, #GPIO_OSPEEDR_OFFSET]
                    ldr             r1, = #3<<(UTROLLER_POWER<<1)
                    bics            r0, r0, r1
                    ldr             r1, = #1<<(UTROLLER_POWER<<1)
                    orrs            r0, r0, r1
                    str             r0, [r2, #GPIO_OSPEEDR_OFFSET]
                    ldr             r0, = #1<<UTROLLER_POWER
                    str             r0, [r2, #GPIO_BRR_OFFSET]

                    bx              lr

    .end
