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

#include "constants.inc"

#include "stm/stm32f0xx.inc"
#include "stm/startup_stm32f0xx.inc"
#include "stm/system_stm32f0xx.inc"

#include "cmsis/core_cm0.inc"

#include "acb/functionHeaders.inc"
#include "acb/errorHandler.inc"
#include "acb/math.inc"
#include "acb/watchdog.inc"
#include "acb/flash.inc"
#include "acb/optionBytes.inc"

#define CBUS_USE_MESSAGE_ACRONYM_DECODE

#include "cbus/cbus_defs.inc"
#include "cbus/cbusMessages.inc"

#include "errorCodes.inc"

/*
 * Private CBUS Network Analyser tester include file
 *
 */

/*
 * Pin functions are
 *
 * | Pin | Function | Type | Description                |
 * |:---:| -------- | ---- | -------------------------- |
 * | 1   | PB8      | O    | LED 1 Output (Timer 16)    |
 * | 2   | PF0      | I/O  | 8Mhz Crystal               |
 * | 3   | PF1      | I/O  | 8Mhz Crystal               |
 * | 4   | NRST     | RST  | SWD - RST                  |
 * | 5   | VDDA     | S    | 3V power supply            |
 * | 6   | PA0      | I    | Rotary Encoder B Input     |
 * | 7   | PA1      | I    | Rotary Encoder A Input     |
 * | 8   | PA2      | I    | Rotary Encode Switch Input |
 * | 9   | PA3      | O    | Display Data/#Command      |
 * | 10  | PA4      | O    | LED 2 Output (Timer 14)    |
 * | 11  | PA5      | O    | SPI Clock                  |
 * | 12  | PA6      | O    | Display #Reset             |
 * | 13  | PA7      | O    | SPI MOSI                   |
 * | 14  | PB1      | I/O  | Display #CS                |
 * | 15  | VSS      | S    | Ground                     |
 * | 16  | VDD      | S    | 3V power supply            |
 * | 17  | PA11     | I    | CAN RX                     |
 * | 18  | PA12     | O    | CAN TX                     |
 * | 19  | PA13     | I/O  | SWD - SWDIO                |
 * | 20  | PA14     | I/O  | SWD - SWCLK                |
 * |:---:| -------- | ---- | -------------------------- |
 *
 */

/*
 * Define Display type
 *
 */

#define ACB_DISPLAY_SPI_BASE            SPI1_BASE
#define ACB_DISPLAY_SPI_GPIOBASE        GPIOA_BASE
#define ACB_DISPLAY_SPI_CLK             5
#define ACB_DISPLAY_SPI_MOSI            7
#define ACB_DISPLAY_SPI_PRESCALER       1
#define ACB_DISPLAY_SPI_ALARM_SLOT      0

#define ACB_DISPLAY_SPI_DMA_CHANNEL     DMA1_Channel3_BASE
#define ACB_DISPLAY_DMA_ISR             __dma1Channel23IRQHandler
#define ACB_DISPLAY_DMA_IRQ             DMA1_Channel2_3_IRQn
#define ACB_DISPLAY_DMA                 DMA1_BASE
#define ACB_DISPLAY_DMA_DONE            DMA_ISR_TCIF3
#define ACB_DISPLAY_DMA_CLEAR           DMA_IFCR_CGIF3

#define ACB_DISPLAY_RES_GPIOBASE        GPIOA_BASE
#define ACB_DISPLAY_RES_PIN             6
#define ACB_DISPLAY_DC_GPIOBASE         GPIOA_BASE
#define ACB_DISPLAY_DC_PIN              3
#define ACB_DISPLAY_CS_GPIOBASE         GPIOB_BASE
#define ACB_DISPLAY_CS_PIN              1

/*
 * Other Display Constants
 *
 */

#define ACB_DISPLAY_WIDTH               128
#define ACB_DISPLAY_HEIGHT              64

#include "acb/ssd1306.inc"
#include "acb/displayDriverSPI.inc"
#include "acb/display.inc"
#include "acb/font.inc"
#include "acb/smallFont.inc"

/*
 * Define which port/pins the CAN module uses. Define port as either CAN_USEPORTA, CAN_USEPORTB, or CAN_USEOTHER
 * If CAN_USEOTHER then you must supply the definition manually
 * CAN_USEPORTA CAN on PA11/PA12
 *
 */

#define ACB_CAN_USEPORTA                0
#define ACB_CANPORT                     ACB_CAN_USEPORTA
#define ACB_CAN_REQUIRES_SYSCONFIG      1

#include "acb/can.inc"

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
 * Simple input debounce Constants
 *
 */

#define CBUSNA_BUTTON_GPIOBASE          GPIOA_BASE
#define CBUSNA_BUTTON_PIN               2

#define ACB_SIB_GPIOBASE        CBUSNA_BUTTON_GPIOBASE
#define ACB_SIB_MASK            (1<<CBUSNA_BUTTON_PIN)
#define ACB_SIB_STATE_DEPTH     8
#define ACB_SIB_INVERT          1
#define ACB_SID_ALARM_SLOT      1

#include "acb/simpleInputDebounce.inc"

/*
 * Defines for various functions
 *
 */

#define MAINLOOP_DELAY                  5

#define FSM_STATE_ROTENC_CHANGED_BIT    0
#define FSM_STATE_ROTENC_INC_BIT        1
#define FSM_STATE_BUTTON_CHANGED_BIT    2
#define FSM_STATE_CAN_MSG_BIT           3
#define FSM_STATE_CAN_ERR_BIT           4

#define FSM_STATE_ROTENC_CHANGED        (1<<FSM_STATE_ROTENC_CHANGED_BIT)
#define FSM_STATE_ROTENC_INC            (1<<FSM_STATE_ROTENC_INC_BIT)
#define FSM_STATE_BUTTON_CHANGED        (1<<FSM_STATE_BUTTON_CHANGED_BIT)
#define FSM_STATE_CAN_MSG               (1<<FSM_STATE_CAN_MSG_BIT)
#define FSM_STATE_CAN_ERR               (1<<FSM_STATE_CAN_ERR_BIT)

#define FSM_STATE_CHANGED               (FSM_STATE_ROTENC_CHANGED|FSM_STATE_BUTTON_CHANGED|FSM_STATE_CAN_MSG|FSM_STATE_CAN_ERR)
#define FSM_STATE_INPUT                 (FSM_STATE_ROTENC_CHANGED|FSM_STATE_BUTTON_CHANGED)

#define FSM_BUTTON_BIT                  0

#define FSM_BUTTON                      (1<<FSM_BUTTON_BIT)
