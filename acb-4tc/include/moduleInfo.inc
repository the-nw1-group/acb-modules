/*
 * Copyright (c) 2015 The NW1 Group
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

/*
 * Define this module as application code
 * (as opposed to bootloader code)
 */

#define ACB_APPLICATION

#include "stm/stm32f0xx.inc"
#include "stm/startup_stm32f0xx.inc"
#include "stm/system_stm32f0xx.inc"

#include "cmsis/core_cm0.inc"

#include "acb/functionHeaders.inc"
#include "acb/errorHandler.inc"
#include "cbusNodeParameters.inc"

/*
 * Private ACB-4TC include file
 *
 */

/*
 * Pin functions are
 *
 *  | Pin | Function | Type | Description               || Pin | Function | Type | Description               |
 *  |:---:| -------- | ---- | ------------------------- ||:---:| -------- | ---- | ------------------------- |
 *  | 1   | VDD      | S    | 3.3v power supply         || 17  | VDDIO2   | S    | 3.3v power supply         |
 *  | 2   | OSC_IN   | I/O  | 8Mhz Oscillator           || 18  | PA8      | I/O  | (OUT) Relay 1             |
 *  | 3   | OSC_OUT  | I/O  | 8Mhz Oscillator           || 19  | PA9      | I/O  | (OUT) Relay 2             |
 *  | 4   | NRST     | RST  | SWD - RST                 || 20  | PA10     | I/O  | (OUT) Relay 3             |
 *  | 5   | VDDA     | S    | 3.3v power supply         || 21  | PA11     | I/O  | (IN) CANRX                |
 *  | 6   | PA0      | I/O  | (IN) Detect 1a            || 22  | PA12     | I/O  | (OUT) CANTX               |
 *  | 7   | PA1      | I/O  | (IN) Detect 1b            || 23  | PA13     | I/O  | SWD - SWDIO               |
 *  | 8   | PA2      | I/O  | (IN) Detect 2a            || 24  | PA14     | I/O  | SWD - SWCLK               |
 *  | 9   | PA3      | I/O  | (IN) Detect 2b            || 25  | PA15     | I/O  | (OUT) Relay 4             |
 *  | 10  | PA4      | I/O  | (IN) Detect 3a            || 26  | PB3      | I/O  | (OUT) Servo Power Enable+ |
 *  | 11  | PA5      | I/O  | (IN) Detect 3b            || 27  | PB4      | I/O  | (OUT) Servo 1             |
 *  | 12  | PA6      | I/O  | (IN) Detect 4a            || 28  | PB5      | I/O  | (OUT) Servo 2             |
 *  | 13  | PA7      | I/O  | (IN) Detect 4B            || 29  | PB6      | I/O  | I2C SCL - EEPROM          |
 *  | 14  | PB0      | I/O  | (OUT) Servo 3             || 30  | PB7      | I/O  | I2C SDA - EEPROM          |
 *  | 15  | PB1      | I/O  | (OUT) Servo 4             || 31  | PB8      | I/O  | (IN) FLiM Switch          |
 *  | 16  | VSS      | S    | Ground                    || 32  | VSS      | S    | Ground                    |
 *  |:---:| -------- | ---- | ------------------------- ||:---:| -------- | ---- | ------------------------- |
 *
 *  + This isn't present on revision 1.0 of the boards
 *
 */

/*
 * Define which port/pins the CAN module uses. Define port as either CAN_USEPORTA, CAN_USEPORTB, or CAN_USEOTHER
 * If CAN_USEOTHER then you must supply the definition manually
 * CAN_USEPORTA CAN on PA11/PA12
 *
 */

#define ACB_CAN_USEPORTA                0
#define ACB_CANPORT                     ACB_CAN_USEPORTA
#define ACB_CAN_REQUIRES_SYSCONFIG      1

/*
 * Define EEPROM type, driver and connection to device
 *
 */

#define ACB_EEPROM_24AA16               0
#define ACB_EEPROM_TYPE                 EEPROM_24AA16
#define ACB_EEPROM_I2C_AHBENR           RCC_AHBENR_GPIOBEN
#define ACB_EEPROM_I2C_GPIOBASE         GPIOB_BASE
#define ACB_EEPROM_I2C_SDA              7
#define ACB_EEPROM_I2C_SCL              6
#define ACB_EEPROM_I2C_TIMING           0x00901850                  /* See STSW-STM32126 for details */
#define ACB_EEPROM_ALARM_SLOT           0

#include "acb/eepromI2C.inc"
#include "acb/eepromCache.inc"
#include "acb/eeprom.inc"

#define ACB_CONFIGURATION_VERSION       0x0001                      /* Configuration is version 0.1 */

/*
 * Configure error handler to capture default handler, and all faults
 */

#define ACB_ERRORHANDLER_DEFAULTHANDLER
#define ACB_ERRORHANDLER_HANDLEFAULTS
