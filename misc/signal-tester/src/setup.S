/*
 * Copyright (c) 2015 The NW1 Group
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#include "moduleInfo.inc"

@ setup code for Signal/Servo Tester

    module(Setup)

    .extern         Eeprom_init                                     @ Setup EEPROM
    .extern         MsCounter_init                                  @ Setup millisecond counter
    .extern         IWDG_setup                                      @ Setup the watchdog timer
    .extern         Analog_init                                     @ Setup the ADCs
    .extern         Display_init                                    @ Setup the Display
    .extern         SimpleInputDebounce_setup                       @ Setup the input debouncer
    .extern         Ws2812_init                                     @ Setup the WS2812 driver
    .extern         Ws2812_setBufferSizes                           @ Set the WS2812 buffer sizes

    public_function(Setup_setup)

@ void Setup_setup()
@   Setup all major peripherals and their clocks

Setup_setup:
                    push            {r7, lr}
__setupCounter:
                    ldr             r0, =#System_coreClock
                    ldr             r0, [r0]
                    bl              MsCounter_init

                                                                    @ it "seems" (i.e. I could be wrong), that with the
                                                                    @ ST-LINK and/or OpenOCD the processor isn't held in
                                                                    @ reset (unlike PICs for example), and some code might
                                                                    @ run before the debugger is attached, which then
                                                                    @ breaks whatever the processor was doing. This might
                                                                    @ cause issues with both the CAN and I2C interfaces
                                                                    @ so we delay here whilst the debugger attaches
#if defined(DEBUG)
                    movs            r0, #250                        @ delay for 250ms - only when running under the
                    bl              MsCounter_waitFor               @ debugger (which we can't tell on an M0, so for all
                                                                    @ debug builds)
#endif
                    bl              Setup_setupGPIO
                    bl              Configuration_init
                    bl              Setup_setupTimers
                    bl              Analog_init
                    bl              Display_init
                    cmp             r0, #ERROR
                    beq             __setupDisplayFail
                    bl              Ws2812_init

#if !defined(DEBUG)
                    movs            r0, #4                          @ only enable the watchdog on non-debug builds
                    ldr             r1, = #625                      @ prescaler=64, count down of 625 is a timeout
                    bl              IWDG_setup                      @ of 1 second
#endif
                    bl              SimpleInputDebounce_setup       @ setup debounce
                    pop             {r7, pc}

__setupDisplayFail:
                    movs            r0, #SIGTEST_DISPLAY_INIT_FAIL
                    svc             ACB_FATAL_ERROR

    private_function(Setup_setupGPIO)

@ void Setup_setupGPIO()
@   Setup all GPIO's (except I2C)

Setup_setupGPIO:
                    ldr             r2, = #_RCC_AHBENR              @ enable port A and B peripheral clocks
                    ldr             r1, [r2]
                    ldr             r0, = #RCC_AHBENR_GPIOAEN | RCC_AHBENR_GPIOBEN | RCC_AHBENR_GPIOFEN
                    orrs            r0, r0, r1
                    str             r0, [r2]

                    ldr             r2, = #SIGTEST_LCD_RES_GPIOBASE @ set LCD_RES# to be an output, medium speed
                    ldr             r0, [r2, #GPIO_MODER_OFFSET]
                    ldr             r1, = #1<<(SIGTEST_LCD_RES<<1)
                    orrs            r0, r0, r1
                    str             r0, [r2, #GPIO_MODER_OFFSET]
                    ldr             r0, [r2, #GPIO_OSPEEDR_OFFSET]
                    ldr             r1, = #1<<(SIGTEST_LCD_RES<<1)
                    orrs            r0, r0, r1
                    str             r0, [r2, #GPIO_OSPEEDR_OFFSET]

                    ldr             r2, = #SIGTEST_BUTTON_GPIOBASE  @ set BUT_* as inputs, pullups, slow
                    ldr             r0, [r2, #GPIO_PUPDR_OFFSET]    @ inputs and slow are defaults...
                    ldr             r1, = #(1<<(SIGTEST_BUTTON_LEFT<<1)) | (1<<(SIGTEST_BUTTON_ACTION<<1)) | (1<<(SIGTEST_BUTTON_RIGHT<<1))
                    orrs            r0, r0, r1
                    str             r0, [r2, #GPIO_PUPDR_OFFSET]

                    ldr             r2, = #SIGTEST_OUTPUT_GPIOBASE  @ set output as AF, fast output, with pulldowns
                    ldr             r0, [r2, #GPIO_MODER_OFFSET]
                    ldr             r1, = #2<<(SIGTEST_OUTPUT<<1)
                    orrs            r0, r0, r1
                    str             r0, [r2, #GPIO_MODER_OFFSET]
                    ldr             r0, [r2, #GPIO_OSPEEDR_OFFSET]
                    ldr             r1, = #3<<(SIGTEST_OUTPUT<<1)
                    orrs            r0, r0, r1
                    str             r0, [r2, #GPIO_OSPEEDR_OFFSET]
                    ldr             r0, [r2, #GPIO_PUPDR_OFFSET]
                    ldr             r1, = #2<<(SIGTEST_OUTPUT<<1)
                    orrs            r0, r0, r1
                    str             r0, [r2, #GPIO_PUPDR_OFFSET]
                    ldr             r0, [r2, #SIGTEST_AF_OFFSET]    @ Set the AF function for this pin
                    ldr             r1, = #SIGTEST_AF<<(SIGTEST_OUTPUT<<2)
                    orrs            r0, r0, r1
                    str             r0, [r2, #SIGTEST_AF_OFFSET]

                    ldr             r2, = #SIGTEST_RGB_GPIOBASE     @ set RGB as input analog
                    ldr             r0, [r2, #GPIO_MODER_OFFSET]
                    ldr             r1, = #(3<<(SIGTEST_R<<1)) | (3<<(SIGTEST_G<<1)) | (3<<(SIGTEST_B<<1))
                    orrs            r0, r0, r1
                    str             r0, [r2, #GPIO_MODER_OFFSET]
                    bx              lr

    private_function(Setup_setupTimers)

@ void Setup_setupTimers()
@   Setup all timers used in this application
@       TIM3_CH4 outputs on SIGTEST_OUTPUT in any output mode
@       Another timer is used to trigger the ADCs, but this is configured with the Analog "class"

Setup_setupTimers:
                    ldr             r2, = #_RCC_APB1ENR             @ enable Timer 3 clock
                    ldr             r1, [r2]
                    movs            r0, #RCC_APB1ENR_TIM3EN
                    orrs            r0, r0, r1
                    str             r0, [r2]
                    bx              lr

    .end
