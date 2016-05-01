/*
 * Copyright (c) 2015 The NW1 Group
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#define ACB_USE_DISPLAYDRIVER_SPI

#if !defined(ACB_DISPLAY_SPI_BASE) || !defined(ACB_DISPLAY_SPI_GPIOBASE) || !defined(ACB_DISPLAY_SPI_ALARM_SLOT)\
    || !defined(ACB_DISPLAY_SPI_CLK) || !defined(ACB_DISPLAY_SPI_MOSI) || !defined(ACB_DISPLAY_SPI_PRESCALER)
#error ACB_DISPLAY_SPI_BASE, ACB_DISPLAY_SPI_GPIOBASE, ACB_DISPLAY_SPI_ALARM_SLOT, ACB_DISPLAY_SPI_CLK, ACB_DISPLAY_SPI_MOSI and ACB_DISPLAY_SPI_PRESCALER must all be defined to use this file
#endif

#if !defined(ACB_DISPLAY_SPI_ISR) || !defined(ACB_DISPLAY_SPI_IRQ)
#error ACB_DISPLAY_SPI_ISR and ACB_DISPLAY_SPI_IRQ must all be defined to use this file
#endif

#if !defined(ACB_DISPLAY_SPI_DMA_CHANNEL)
#error ACB_DISPLAY_SPI_DMA_CHANNEL must all be defined to use this file
#endif

#if !defined(ACB_DISPLAY_RES_GPIOBASE) || !defined(ACB_DISPLAY_RES_PIN)
#error ACB_DISPLAY_RES_GPIOBASE and ACB_DISPLAY_RES_PIN must all be defined to use this file
#endif

#if !defined(ACB_DISPLAY_DC_GPIOBASE) || !defined(ACB_DISPLAY_DC_PIN)
#error ACB_DISPLAY_DC_GPIOBASE and ACB_DISPLAY_DC_PIN must all be defined to use this file
#endif

#if !defined(ACB_DISPLAY_CS_GPIOBASE) || !defined(ACB_DISPLAY_CS_PIN)
#error ACB_DISPLAY_CS_GPIOBASE and ACB_DISPLAY_CS_PIN must all be defined to use this file
#endif

#define DisplayDrv_init                     DisplayDriverSPI_init
#define DisplayDrv_sendCommands             DisplayDriverSPI_sendCommands
#define DisplayDrv_sendCommand              DisplayDriverSPI_sendCommand
#define DisplayDrv_sendCommandAndParameter  DisplayDriverSPI_sendCommandAndParameter
#define DisplayDrv_sendData                 DisplayDriverSPI_sendData
