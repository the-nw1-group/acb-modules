/*
 * Copyright (c) 2015 The NW1 Group
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#if !defined(ACB_DISPLAY_I2C_AHBENR) || !defined(ACB_DISPLAY_I2C_GPIOBASE) || !defined(ACB_DISPLAY_I2C_SDA)\
    || !defined(ACB_DISPLAY_I2C_SCL) || !defined(ACB_DISPLAY_I2C_TIMING)
#error ACB_DISPLAY_I2C_AHBENR, ACB_DISPLAY_I2C_GPIOBASE, ACB_DISPLAY_I2C_SDA, ACB_DISPLAY_I2C_SCL and ACB_DISPLAY_I2C_TIMING must all be defined to use this file
#endif

#if ACB_DISPLAY_I2C_SCL > 7
#define ACB_DISPLAY_I2C_AFR_SCL         (ACB_DISPLAY_I2C_SCL-8)
#define ACB_DISPLAY_I2C_AFR_SCL_OFFSET  (GPIO_AFR_OFFSET+4)
#else
#define ACB_DISPLAY_I2C_AFR_SCL         (ACB_DISPLAY_I2C_SCL)
#define ACB_DISPLAY_I2C_AFR_SCL_OFFSET  (GPIO_AFR_OFFSET)
#endif

#if ACB_DISPLAY_I2C_SDA > 7
#define ACB_DISPLAY_I2C_AFR_SDA         (ACB_DISPLAY_I2C_SDA-8)
#define ACB_DISPLAY_I2C_AFR_SDA_OFFSET  (GPIO_AFR_OFFSET+4)
#else
#define ACB_DISPLAY_I2C_AFR_SDA         (ACB_DISPLAY_I2C_SDA)
#define ACB_DISPLAY_I2C_AFR_SDA_OFFSET  (GPIO_AFR_OFFSET)
#endif


#define DisplayDrv_init                     DisplayDriverI2C_init
#define DisplayDrv_sendCommands             DisplayDriverI2C_sendCommands
#define DisplayDrv_sendCommand              DisplayDriverI2C_sendCommand
#define DisplayDrv_sendCommandAndParameter  DisplayDriverI2C_sendCommandAndParameter
#define DisplayDrv_sendData                 DisplayDriverI2C_sendData
