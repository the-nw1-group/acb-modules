/*
 * Copyright (c) 2018 The NW1 Group
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
#include "acb/math.inc"
#include "acb/flash.inc"

/*
 * Private PWM DC Controller include file
 *
 */

/*
 * Pin functions are
 *
 * | Pin | Function | Type         | Description           |
 * |:---:| -------- | ------------ | --------------------- |
 * | 1   | BOOT0    | I/P - IN     | Tied to ground        |
 * | 2   | PF0      | I/O - N/A    | Not Used              |
 * | 3   | PF1      | I/O - OUT    | nSLEEP    (DRV8816)   |
 * | 4   | NRST     | RST - RST    | SWD - RST             |
 * | 5   | VDDA     | S   - PWR    | 3.3v power supply     |
 * | 6   | PA0      | I/O - OUT    | PWM IN1   (DRV8816)   |
 * | 7   | PA1      | I/O - OUT    | PWM EN1   (DRV8816)   |
 * | 8   | PA2      | I/O - OUT    | PWM IN2   (DRV8816)   |
 * | 9   | PA3      | I/O - OUT    | PWM EN1   (DRV8816)   |
 * | 10  | PA4      | I/O - Analog | Vpropi (DRV8816)      |
 * | 11  | PA5      | I/O - Analog | Speed Control         |
 * | 12  | PA6      | I/O - IN     | Tied to analog ground |
 * | 13  | PA7      | I/O - OUT    | PWM Power LED         |
 * | 14  | PB1      | I/O - OUT    | PWM Track LED         |
 * | 15  | VSS      | S   - PWR    | Ground                |
 * | 16  | VDD      | S   - PWR    | 3.3v power supply     |
 * | 17  | PA9      | I/O - IN     | Config #1             |
 * | 18  | PA10     | I/O - IN     | Config #0             |
 * | 19  | PA13     | I/O - DBG    | SWD - SWDIO           |
 * | 20  | PA14     | I/O - DBG    | SWD - SWCLK           |
 * |:---:| -------- | ------------ | --------------------- |
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

#include "acb/errorHandler.inc"

/*
 * Defines for I/Os
 *
 */

#define CONCAT2(a, b) a ## b
#define CONCAT(a, b) CONCAT2(a, b)

/*
 * macro to define a data stored in "eeprom" emulation (i.e. FLASH)
 */

#define eeprom_data(secname)\
    .section        .eeprom_emulation.##secname, "a", %progbits;\
    .type           .eeprom_emulation.##secname, %function;\
    .size           secname, .-secname;\
    .balign         2;\
    .align          2;

/*
 * Defines for various functions
 *
 */

/*
 * Defines for various pins
 *
 */

/* Digital Pins */
#define UTROLLER_SLEEP_GPIOBASE         GPIOF_BASE
#define UTROLLER_SLEEP                  1
#define UTROLLER_CONFIG_GPIOBASE        GPIOA_BASE
#define UTROLLER_CONFIG0                10
#define UTROLLER_CONFIG1                9
#define UTROLLER_TRACK_GPIOBASE         GPIOB_BASE
#define UTROLLER_TRACK                  1
#define UTROLLER_POWER_GPIOBASE         GPIOA_BASE
#define UTROLLER_POWER                  7

/* Timer 2 based Pins */
#define UTROLLER_MOTOR_EN1              1
#define UTROLLER_MOTOR_IN1              2
#define UTROLLER_MOTOR_EN2              3
#define UTROLLER_MOTOR_IN2              4

/* Timer 3 based Pins - overlaps with TRACK above */
#define UTROLLER_TRACK_CH               4

/* Timer 14 based Pins - overlaps with POWER above */
#define UTROLLER_POWER_CH               1

/* Analog Channels */
#define UTROLLER_VPROPI                 4
#define UTROLLER_SPEED                  5
