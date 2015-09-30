/*
 * Copyright (c) 2015 The NW1 Group
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

/*
 * EEPROM I2C implementation include file
 *
 * Implementation requires:
 *  I2C
 *  I2C interrupt
 *  DMA channels 2 (only when block transmitting), and 3 (only when block receiving)
 *  a millisecond counter
 *
 */

#if !defined(ACB_EEPROM_TYPE)
#error ACB_EEPROM_TYPE must be defined before including this file
#elif ACB_EEPROM_TYPE == ACB_EEPROM_24AA16
#define ACB_EEPROM_SIZE                 2048
#define ACB_EEPROM_WRITE_BUFFER         16
#define ACB_EEPROM_ADDRESS              0xA0
#define ACB_EEPROM_WRITETIME            5
#else
#error Unsupported ACB_EEPROM_TYPE type
#endif

#if !defined(ACB_EEPROM_I2C_AHBENR) || !defined(ACB_EEPROM_I2C_GPIOBASE) || !defined(ACB_EEPROM_I2C_SDA)\
    || !defined(ACB_EEPROM_I2C_SCL) || !defined(ACB_EEPROM_I2C_TIMING)
#error ACB_EEPROM_I2C_AHBENR, ACB_EEPROM_I2C_GPIOBASE, ACB_EEPROM_I2C_SDA, ACB_EEPROM_I2C_SCL and ACB_EEPROM_I2C_TIMING must all be defined to use this file
#endif

#if ACB_EEPROM_I2C_SCL > 7
#define ACB_EEPROM_I2C_AFR_SCL          (ACB_EEPROM_I2C_SCL-8)
#define ACB_EEPROM_I2C_AFR_SCL_OFFSET   (GPIO_AFR_OFFSET+4)
#else
#define ACB_EEPROM_I2C_AFR_SCL          (ACB_EEPROM_I2C_SCL)
#define ACB_EEPROM_I2C_AFR_SCL_OFFSET   (GPIO_AFR_OFFSET)
#endif

#if ACB_EEPROM_I2C_SDA > 7
#define ACB_EEPROM_I2C_AFR_SDA          (ACB_EEPROM_I2C_SDA-8)
#define ACB_EEPROM_I2C_AFR_SDA_OFFSET   (GPIO_AFR_OFFSET+4)
#else
#define ACB_EEPROM_I2C_AFR_SDA          (ACB_EEPROM_I2C_SDA)
#define ACB_EEPROM_I2C_AFR_SDA_OFFSET   (GPIO_AFR_OFFSET)
#endif

#if !defined(EepromDrv_init)
#define EepromDrv_init               EepromI2C_init
#define EepromDrv_readByte           EepromI2C_readByte
#define EepromDrv_writeByte          EepromI2C_writeByte
#define EepromDrv_readBlock          EepromI2C_readBlock
#define EepromDrv_writeBlock         EepromI2C_writeBlock
#define EepromDrv_asyncInProgress    EepromI2C_asyncInProgress
#define EepromDrv_getLastAsyncStatus EepromI2C_getLastAsyncStatus
#define EepromDrv_setHint            EepromI2C_setHint
#define EepromDrv_getHint            EepromI2C_getHint
#endif
