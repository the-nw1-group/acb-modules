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

@ setup code for Signal/Servo Tester

    module(Setup)

    .extern         MsCounter_init                                  @ Setup millisecond counter
    .extern         IWDG_setup                                      @ Setup the watchdog timer
    .extern         Display_init                                    @ Setup the Display
    .extern         SimpleInputDebounce_setup                       @ Setup the input debouncer

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
__setupOptionBytes:
                    ldr             r0, = #OB_BASE                  @ turn set BOOT_SEL to 0, so that BOOT0 pin
                    movs            r1, #0                          @ becomes PB8
                    ldr             r2, = #OB_USER_BOOT_SEL
                    bl              OptionByte_write
__setupPeripherals:
                    bl              Setup_setupGPIO
                    bl              Setup_setupTimers
                    bl              Setup_setupOtherClocks
                    bl              RotaryEncoder_setup
                    bl              Display_init
                    cmp             r0, #ERROR
                    beq             __setupDisplayFail
                    ldr             r0, = #__smallFont_data         @ set the font
                    bl              Display_setFont
                    movs            r0, #0x60                       @ enable the screensaver
                    bl              FsmFilterScreenSaver_setup
#if !defined(DEBUG)
                    movs            r0, #4                          @ only enable the watchdog on non-debug builds
                    ldr             r1, = #625                      @ prescaler=64, count down of 625 is a timeout
                    bl              IWDG_setup                      @ of 1 second
#endif
                    bl              SimpleInputDebounce_setup       @ setup debounce
                    bl              AcbTransport_init
                    bl              CanMessageLog_setup
                    bl              FsmFilterCanActivity_setup
                    pop             {r7, pc}
__setupDisplayFail:
                    movs            r0, #CBUSNA_DISPLAY_INIT_FAIL
                    svc             ACB_FATAL_ERROR

    private_function(Setup_setupGPIO)

@ void Setup_setupGPIO()
@   Setup all GPIO's (except SPI)

Setup_setupGPIO:
                    ldr             r2, = #_RCC_AHBENR              @ enable port A and B peripheral clocks
                    ldr             r1, [r2]
                    ldr             r0, = #RCC_AHBENR_GPIOAEN | RCC_AHBENR_GPIOBEN
                    orrs            r0, r0, r1
                    str             r0, [r2]

                    ldr             r2, = #CBUSNA_BUTTON_GPIOBASE   @ set BUT_* as inputs, pullups, slow
                    ldr             r0, [r2, #GPIO_PUPDR_OFFSET]    @ inputs and slow are defaults...
                    ldr             r1, = #(1<<(CBUSNA_BUTTON_PIN<<1))
                    orrs            r0, r0, r1
                    str             r0, [r2, #GPIO_PUPDR_OFFSET]
                    bx              lr

    private_function(Setup_setupTimers)

@ void Setup_setupTimers()
@   Setup all timers used in this application
@       TIM2_CH1/CH2 inputs from the rotary encoder
@       TIM14_CH1 PWM output for LED #2
@       TIM16_CH1 PWM output for LED #1

Setup_setupTimers:
                    ldr             r2, = #RCC_BASE                 @ enable Timers clocks
                    ldr             r1, [r2, #RCC_APB1ENR_OFFSET]
                    ldr             r0, = #(CBUSNA_ROTENC_AHBENR | CBUSNA_LED2_AHBENR)
                    orrs            r0, r0, r1
                    str             r0, [r2, #RCC_APB1ENR_OFFSET]
                    ldr             r1, [r2, #RCC_APB2ENR_OFFSET]
                    ldr             r0, = #(CBUSNA_LED1_AHBENR)
                    orrs            r0, r0, r1
                    str             r0, [r2, #RCC_APB2ENR_OFFSET]

    @ This is temp, to turn off the s*dding LEDs

    ldr     r0, =#GPIOA_BASE
    ldr     r1, [r0, #GPIO_MODER_OFFSET]
    ldr     r2, = #(1<<(4<<1))
    orrs    r1, r1, r2
    str     r1, [r0, #GPIO_MODER_OFFSET]
    movs    r1, #1<<4
    str     r1, [r0, #GPIO_BSRR_OFFSET]


    ldr     r0, =#GPIOB_BASE
    ldr     r1, [r0, #GPIO_MODER_OFFSET]
    ldr     r2, = #(1<<(8<<1))
    orrs    r1, r1, r2
    str     r1, [r0, #GPIO_MODER_OFFSET]
    ldr     r1, = #1<<8
    str     r1, [r0, #GPIO_BSRR_OFFSET]


                    bx              lr

    private_function(Setup_setupOtherClocks)

@ void Setup_setupOtherClocks()
@   Setup up any other peripheral clocks used by this project
@       SPI
@       DMA

Setup_setupOtherClocks:
                    ldr             r2, = #RCC_BASE
                    ldr             r1, [r2, #RCC_AHBENR_OFFSET]
                    movs            r0, #RCC_AHBENR_DMAEN
                    orrs            r1, r1, r0
                    str             r1, [r2, #RCC_AHBENR_OFFSET]
                    ldr             r1, [r2, #RCC_APB2ENR_OFFSET]
                    ldr             r0, = #RCC_APB2ENR_SPI1EN
                    orrs            r1, r1, r0
                    str             r1, [r2, #RCC_APB2ENR_OFFSET]
                    bx              lr

    .end
