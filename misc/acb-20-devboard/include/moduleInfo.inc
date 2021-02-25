/*
 * Copyright (c) 2018 The NW1 Group
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#define ACB_APPLICATION

#include "constants.inc"

#include "stm/stm32l431xx.inc"
#include "stm/startup_stm32l431xx.inc"

#include "cmsis/core_cm4.inc"

#include "acb/functionHeaders.inc"


/*
 * Private ACB 2.0 Development Board
 *
 */


// THE REST **TODO**

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
 * | 10  | PA4      | I/O - Analog | Vpropi    (DRV8816)   |
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
