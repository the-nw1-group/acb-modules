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

#include "stm/stm32l4xx.inc"
#include "stm/startup_stm32l431xx.inc"
#include "stm/system_stm32l431xx.inc"
#include "cmsis/core_cm4.inc"

#include "acb/common.inc"
#include "acb/functionHeaders.inc"
#include "acb/msCounter.inc"

/*
 * Private ACB 2.0 Development Board
 *
 */

/*
 * Pin functions are
 *
 * | Pin | Function  | Type             | Description                 |
 * |:---:| --------- | ---------------- | --------------------------- |
 * | 1   | VDD       | S   - PWR        | 3.3v power supply           |
 * | 4   | NRST      | RST - RST        | SWD - RST                   |
 * | 5   | VDDA      | S   - PWR        | 3.3v power supply           |
 * | 6   | PA0       | I   - RCC_CLK_IN | Clock In (12mhz Oscillator) |
 * | 7   | PA1       | I/O - Analog     | ADC1_IN6 - ADC1             |
 * | 8   | PA2       | I/O - Analog     | ADC1_IN7 - ADC2             |
 * | 12  | PA6       | I/O - IN         | IN1                         |
 * | 13  | PA7       | I/O - IN         | IN2                         |
 * | 16  | VSS       | S   - PWR        | Ground                      |
 * | 17  | VDD       | S   - PWR        | 3.3v power supply           |
 * | 18  | PA8       | I/O - OUT        | TIM1_CH1 - OUT1             |
 * | 19  | PA9       | I/O - OUT        | TIM1_CH2 - OUT2             |
 * | 21  | PA11      | I/O - IN         | CAN1_RX                     |
 * | 22  | PA12      | I/O - OUT        | CAN1_TX                     |
 * | 23  | PA13      | I/O - DBG        | SWD - SWDIO                 |
 * | 24  | PA14      | I/O - DBG        | SWD - SWCLK                 |
 * | 25  | PA15      | I/O - OUT        | EEPROM nCS                  |
 * | 26  | PB3       | I/O - OUT        | SPI3_CLK - EEPROM SPI Clock |
 * | 27  | PB4       | I/O - IN         | SPI3_MISO - EEPROM MISO     |
 * | 28  | PB5       | I/O - OUT        | SPI3_MOSI - EEPROM MOSI     |
 * | 31  | PH3-BOOT0 | I/O - IN         | User Switch                 |
 * | 32  | VSS       | S   - PWR        | Ground                      |
 * |:---:| --------- | ---------------- | --------------------------- |
 *
 * Others are unused
 *
 */

/*
 * Configure error handler to capture default handler, and all faults
 */

#define ACB_ERRORHANDLER_DEFAULTHANDLER
#define ACB_ERRORHANDLER_HANDLEFAULTS

#include "acb/errorHandler.inc"
