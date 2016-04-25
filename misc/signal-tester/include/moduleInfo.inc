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

/*#define ACB_APPLICATION*/

#include "constants.inc"

#include "stm/stm32f0xx.inc"
#include "stm/startup_stm32f0xx.inc"

#include "cmsis/core_cm0.inc"

#include "acb/functionHeaders.inc"
#include "acb/errorHandler.inc"
#include "acb/math.inc"
#include "acb/watchdog.inc"

#include "errorCodes.inc"

/*
 * Private Signal/Servo tester include file
 *
 */

/*
 * Pin functions are
 *
 * | Pin | Function | Type | Description               |
 * |:---:| -------- | ---- | ------------------------- |
 * | 1   | BOOT0    | I/P  | Tied to ground            |
 * | 2   | PF0      | I/O  | I2C SDA                   |
 * | 3   | PF1      | I/O  | I2C SCL                   |
 * | 4   | NRST     | RST  | SWD - RST                 |
 * | 5   | VDDA     | S    | 3.3v power supply         |
 * | 6   | PA0      | I/O  | (Analog) Blue Input       |
 * | 7   | PA1      | I/O  | (Analog) Green Input      |
 * | 8   | PA2      | I/O  | (Analog) Red Input        |
 * | 9   | PA3      | I/O  | Not Used                  |
 * | 10  | PA4      | I/O  | (OUT) Display #RESET      |
 * | 11  | PA5      | I/O  | Not Used                  |
 * | 12  | PA6      | I/O  | Not Used                  |
 * | 13  | PA7      | I/O  | (IN) Button Back          |
 * | 14  | PB1      | I/O  | (OUT) Signal/Servo Output |
 * | 15  | VSS      | S    | Ground                    |
 * | 16  | VDD      | S    | 3.3v power supply         |
 * | 17  | PA9      | I/O  | (IN) Button Action        |
 * | 18  | PA10     | I/O  | (IN) Button Forward       |
 * | 19  | PA13     | I/O  | SWD - SWDIO               |
 * | 20  | PA14     | I/O  | SWD - SWCLK               |
 * |:---:| -------- | ---- | ------------------------- |
 *
 */

/*
 * Define Display type
 *
 */

#define ACB_DISPLAY_I2C_AHBENR          RCC_AHBENR_GPIOFEN
#define ACB_DISPLAY_I2C_GPIOBASE        GPIOF_BASE
#define ACB_DISPLAY_I2C_SDA             0
#define ACB_DISPLAY_I2C_SCL             1
#define ACB_DISPLAY_I2C_TIMING          0x00901850                   /* See STSW-STM32126 for details */

#include "display/ssd1306.inc"
#include "display/displayDriverI2C.inc"
#include "display/display.inc"

/*
 * Define EEPROM type, driver and connection to device
 *
 */

#define ACB_EEPROM_24AA16               0
#define ACB_EEPROM_TYPE                 EEPROM_24AA16
#define ACB_EEPROM_I2C_AHBENR           RCC_AHBENR_GPIOFEN
#define ACB_EEPROM_I2C_GPIOBASE         GPIOF_BASE
#define ACB_EEPROM_I2C_SDA              0
#define ACB_EEPROM_I2C_SCL              1
#define ACB_EEPROM_I2C_TIMING           0x00901850                   /* See STSW-STM32126 for details */
#define ACB_EEPROM_IRQ_REDIRECT_FN      FsmCommon_interceptIsr
#define ACB_EEPROM_ALARM_SLOT           1

#include "acb/eepromI2C.inc"
#include "acb/eepromCache.inc"
#include "acb/eeprom.inc"

/*
 * Configure ws2812 driver
 */

#define ACB_WS2812_DRIVER                   3
#define ACB_WS2812_IRQ_REDIRECT_FN          FsmCommon_interceptIsr
#include "acb/ws2812.inc"

/*
 * Define the number of alarm slots required
 *
 */

#define ACB_ALARM_SLOTS 2

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

#define SIGTEST_BUTTON_GPIOBASE         GPIOA_BASE
#define SIGTEST_BUTTON_LEFT             7
#define SIGTEST_BUTTON_ACTION           9
#define SIGTEST_BUTTON_RIGHT            10

#define SIGTEST_LCD_RES_GPIOBASE        GPIOA_BASE
#define SIGTEST_LCD_RES                 4

#define SIGTEST_RGB_GPIOBASE            GPIOA_BASE
#define SIGTEST_R                       0
#define SIGTEST_G                       1
#define SIGTEST_B                       2

#define SIGTEST_OUTPUT_GPIOBASE         GPIOB_BASE
#define SIGTEST_OUTPUT                  1
#define SIGTEST_AF_OFFSET               GPIO_AFR_OFFSET
#define SIGTEST_AF                      1

/*
 * Simple input debounce Constants
 *
 */

#define ACB_SIB_GPIOBASE        SIGTEST_BUTTON_GPIOBASE
#define ACB_SIB_MASK            ((1<<SIGTEST_BUTTON_LEFT)|(1<<SIGTEST_BUTTON_ACTION)|(1<<SIGTEST_BUTTON_RIGHT))
#define ACB_SIB_STATE_DEPTH     8
#define ACB_SIB_INVERT          1
#define ACB_SID_ALARM_SLOT      2

#include "acb/simpleInputDebounce.inc"

/*
 * Display Constants
 *
 */

#define DISPLAY_ADDR                    0x78
#define DISPLAY_WIDTH                   128
#define DISPLAY_HEIGHT                  32

/*
 * Defines for various functions
 *
 */

#define MAINLOOP_DELAY                  5
#define FSM_STATE_ANALOG_CHANGED_BIT    0
#define FSM_STATE_BUTTONS_CHANGED_BIT   1

#define FSM_STATE_RED_CHANGED_BIT       2
#define FSM_STATE_GREEN_CHANGED_BIT     3
#define FSM_STATE_BLUE_CHANGED_BIT      4
#define FSM_STATE_LEFT_CHANGED_BIT      5
#define FSM_STATE_ACTION_CHANGED_BIT    6
#define FSM_STATE_RIGHT_CHANGED_BIT     7

#define FSM_STATE_ANALOG_CHANGED        (1<<FSM_STATE_ANALOG_CHANGED_BIT)
#define FSM_STATE_BUTTONS_CHANGED       (1<<FSM_STATE_BUTTONS_CHANGED_BIT)

#define FSM_STATE_RED_CHANGED           (1<<FSM_STATE_RED_CHANGED_BIT)
#define FSM_STATE_GREEN_CHANGED         (1<<FSM_STATE_GREEN_CHANGED_BIT)
#define FSM_STATE_BLUE_CHANGED          (1<<FSM_STATE_BLUE_CHANGED_BIT)
#define FSM_STATE_LEFT_CHANGED          (1<<FSM_STATE_LEFT_CHANGED_BIT)
#define FSM_STATE_ACTION_CHANGED        (1<<FSM_STATE_ACTION_CHANGED_BIT)
#define FSM_STATE_RIGHT_CHANGED         (1<<FSM_STATE_RIGHT_CHANGED_BIT)

#define FSM_ANALOG_STATE_MASK           (FSM_STATE_RED_CHANGED | FSM_STATE_GREEN_CHANGED | FSM_STATE_BLUE_CHANGED)
#define FSM_BUTTON_STATE_MASK           (FSM_STATE_LEFT_CHANGED | FSM_STATE_ACTION_CHANGED | FSM_STATE_RIGHT_CHANGED)

#define FSM_BUTTON_LEFT_BIT             0
#define FSM_BUTTON_ACTION_BIT           1
#define FSM_BUTTON_RIGHT_BIT            2

#define FSM_BUTTON_LEFT                 (1<<FSM_BUTTON_LEFT_BIT)
#define FSM_BUTTON_ACTION               (1<<FSM_BUTTON_ACTION_BIT)
#define FSM_BUTTON_RIGHT                (1<<FSM_BUTTON_RIGHT_BIT)

#define FSM_BUTTON_MASK                 (FSM_BUTTON_LEFT | FSM_BUTTON_ACTION | FSM_BUTTON_RIGHT)
