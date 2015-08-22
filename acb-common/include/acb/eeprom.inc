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
 */

#if !defined(EepromDrv_init) || !defined(EepromDrv_readByte) || !defined(EepromDrv_writeByte)
    || !defined(EepromDrv_readBlock) || !defined(EepromDrv_writeBlock)
#error EepromDrv_init, EepromDrv_readByte, EepromDrv_writeByte, EepromDrv_readBlock and EepromDrv_writeBlock must all be defined to use this file
#endif

/*
 * A set of hints that can be supplied to the EEPROM system via the Eeprom_setHint call. These may or may not be ignored
 * by the EEPROM system or the underlying driver.
 *
 *  ACB_EEPROM_BEGIN_MULTI_WRITE_HINT               hint that the application is going to make multiple writes and it
 *                                                  might be faster for the EEPROM system not to update the physical
 *                                                  device until the corresponding end hint is set.
 *  ACB_EEPROM_END_MULTI_WRITE_HINT                 hint that the application has finished a set of updates that can
 *                                                  now be committed to the underlying device.
 */

#define ACB_EEPROM_BEGIN_MULTI_WRITE_HINT   0x01
#define ACB_EEPROM_END_MULTI_WRITE_HINT     0x02
