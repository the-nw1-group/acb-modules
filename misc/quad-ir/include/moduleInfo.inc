/*
 * Copyright (c) 2015 The NW1 Group
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#include "constants.inc"

#include "stm/stm32f0xx.inc"
#include "stm/startup_stm32f0xx.inc"

#include "cmsis/core_cm0.inc"

#include "acb/functionHeaders.inc"
#include "acb/errorHandler.inc"
#include "acb/math.inc"

#include "errorCodes.inc"

/*
 * Private Signal/Servo tester include file
 *
 */

/*
 * Pin functions are
 *
 * | Pin | Function | Type | Description                |
 * |:---:| -------- | ---- | -------------------------- |
 * | 1   | BOOT0    | I/P  | Tied to ground             |
 * | 2   | PF0      | I/O  | (IN) Device Enable         |
 * | 3   | PF1      | I/O  | (OUT) Detect 4 Output      |
 * | 4   | NRST     | RST  | SWD - RST                  |
 * | 5   | VDDA     | S    | 3.3v power supply          |
 * | 6   | PA0      | I/O  | (OUT) Detect 3 Output      |
 * | 7   | PA1      | I/O  | Not Used                   |
 * | 8   | PA2      | I/O  | (Analog) Sense Threshold   |
 * | 9   | PA3      | I/O  | (Analog) Sense from Head 4 |
 * | 10  | PA4      | I/O  | (Analog) Sense from Head 3 |
 * | 11  | PA5      | I/O  | (Analog) Sense from Head 2 |
 * | 12  | PA6      | I/O  | (Analog) Sense from Head 1 |
 * | 13  | PA7      | I/O  | (OUT) IR LED Enable        |
 * | 14  | PB1      | I/O  | (OUT) LED Status           |
 * | 15  | VSS      | S    | Ground                     |
 * | 16  | VDD      | S    | 3.3v power supply          |
 * | 17  | PA9      | I/O  | (OUT) Detect 2 Output      |
 * | 18  | PA10     | I/O  | (OUT) Detect 1 Output      |
 * | 19  | PA13     | I/O  | SWD - SWDIO                |
 * | 20  | PA14     | I/O  | SWD - SWCLK                |
 * |:---:| -------- | ---- | -------------------------- |
 *
 */

/*
 * Define the number of alarm slots required
 *
 */

#define ACB_ALARM_SLOTS 4

#include "acb/msCounter.inc"

/*
 * Configure error handler to capture default handler, and all faults
 */

#define ACB_ERRORHANDLER_DEFAULTHANDLER
#define ACB_ERRORHANDLER_HANDLEFAULTS

/*
 * Defines for I/Os
 *
 */

#define QUADIR_EN_GPIOBASE              GPIOF_BASE
#define QUADIR_EN                       0
#define QUADIR_EN_EXTICR                SYSCFG_EXTICR_OFFSET
#define QUADIR_EN_EXTICR_MASK           SYSCFG_EXTICR1_EXTI0_PF
#define QUADIR_EN_EXTICR_VALUE          SYSCFG_EXTICR1_EXTI0_PF
#define QUADIR_EN_IMR                   QUADIR_EN
#define QUADIR_EN_IRQn                  EXTI0_1_IRQn
#define QUADIR_EN_ISR                   EXTI0_1_IRQHandler

#define QUADIR_OUT4_GPIOBASE            GPIOF_BASE
#define QUADIR_OUT4                     1
#define QUADIR_OUT3_GPIOBASE            GPIOA_BASE
#define QUADIR_OUT3                     0
#define QUADIR_OUT2_GPIOBASE            GPIOA_BASE
#define QUADIR_OUT2                     9
#define QUADIR_OUT1_GPIOBASE            GPIOA_BASE
#define QUADIR_OUT1                     10

#define QUADIR_ANALOG_GPIOBASE          GPIOA_BASE
#define QUADIR_SENSE                    2
#define QUADIR_IN4                      3
#define QUADIR_IN3                      4
#define QUADIR_IN2                      5
#define QUADIR_IN1                      6

#define CONCAT2(a, b) a ## b
#define CONCAT(a, b) CONCAT2(a, b)

#define QUADIR_ADC_SENSE                CONCAT(ADC_CHSELR_CHSEL, QUADIR_SENSE)
#define QUADIR_ADC_IN4                  CONCAT(ADC_CHSELR_CHSEL, QUADIR_IN4)
#define QUADIR_ADC_IN3                  CONCAT(ADC_CHSELR_CHSEL, QUADIR_IN3)
#define QUADIR_ADC_IN2                  CONCAT(ADC_CHSELR_CHSEL, QUADIR_IN2)
#define QUADIR_ADC_IN1                  CONCAT(ADC_CHSELR_CHSEL, QUADIR_IN1)

#define QUADIR_IRLED_GPIOBASE           GPIOA_BASE
#define QUADIR_IRLED                    7
#define QUADIR_AF                       GPIO_AFR_OFFSET
#define QUADIR_AF_VALUE                 (0x5<<(QUADIR_IRLED<<2))

#define QUADIR_STATUS_GPIOBASE          GPIOB_BASE
#define QUADIR_STATUS                   1

/*
 * Defines for various functions
 *
 */

#define QUADIR_STARTUP_LEDFLASH_COUNT   8
#define QUADIR_STARTUP_LED_ON           500

#define QUADIR_NO_SAMPLES               49
#define QUADIR_NO_VALUES                4
#define QUADIR_USE_SAMPLES              8
#define QUADIR_LOG2_USE_SAMPLES         3

#define QUAD_IR_DEBOUNCE                1000
