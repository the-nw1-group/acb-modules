/*
 * Copyright (c) 2015 The NW1 Group
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

/*
 * Define the tab positions
 *  @ measurements screens:
    @   number of: messages received; various error conditions from CAN peripheral in total, and per minute.
    @   graph of messages recieved, per minute.
    @   number of messages per type (a page per message length)
    @   logs of received messages, including detail
    @   transmit menu (i.e. send some test messages...)
 *
 */

#define StatTab          0
#define ActivityGraphTab 1
#define MessageTab       2
#define LogTab           3
#define TxTab            4

#define CBUSNA_MAX_TAB   TxTab

/*
 * Display constants
 *
 */

#define DISPLAY_ROW_HEIGHT              9
#define DISPLAY_ROW_FLAG                (DISPLAY_ROW_HEIGHT<<DISPLAY_ROW_SHIFT)

#define DISPLAY_TAB_HEIGHT              8
#define DISPLAY_TAB_FLAG                (DISPLAY_TAB_HEIGHT<<DISPLAY_ROW_SHIFT)

/*
 * Rotary Encoder constants
 *
 */

#define CBUSNA_ROTENC_AHBENR            RCC_APB1ENR_TIM2EN
#define CBUSNA_ROTENC_GPIOBASE          GPIOA_BASE
#define CBUSNA_ROTENC_TIMBASE           TIM2_BASE
#define CBUSNA_ROTENC_A                 1
#define CBUSNA_ROTENC_B                 0
#define CBUSNA_ROTENC_GPIO_AFR_OFFSET   GPIO_AFR_OFFSET
#define CBUSNA_ROTENC_A_AF              2
#define CBUSNA_ROTENC_B_AF              2

/*
 * Defines for I/Os
 *  LED1 error indicator, LED2 message indicator
 */

#define CBUSNA_LED1_AHBENR              RCC_APB2ENR_TIM16EN
#define CBUSNA_LED1_GPIOBASE            GPIOB_BASE
#define CBUSNA_LED1_TIMBASE             TIM16_BASE
#define CBUSNA_LED1_PIN                 8
#define CBUSNA_LED1_AFNO                2
#define CBUSNA_LED1_DIM                 8
#define CBUSNA_LED1_DIMSUB              512

#define CBUSNA_LED2_AHBENR              RCC_APB1ENR_TIM14EN
#define CBUSNA_LED2_GPIOBASE            GPIOA_BASE
#define CBUSNA_LED2_TIMBASE             TIM14_BASE
#define CBUSNA_LED2_PIN                 4
#define CBUSNA_LED2_AFNO                4
#define CBUSNA_LED2_DIM                 4
#define CBUSNA_LED2_DIMSUB              16384

/*
 * Defines for the Screen Saver
 *
 */

#define CBUSNA_SCNSAVE_DIM_SHIFT        2
#define CBUSNA_SCNSAVE_DIM_TIMEOUT      12000
#define CBUSNA_SCNSAVE_OFF_TIMEOUT      60000
