/*
 * Copyright (c) 2015 The NW1 Group
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

/*
 * EEPROM implementation include file
 *
 */

#define ACB_USE_EEPROM

#if !defined(EepromDrv_init) || !defined(EepromDrv_readByte) || !defined(EepromDrv_writeByte)\
    || !defined(EepromDrv_readBlock) || !defined(EepromDrv_writeBlock) || !defined(EepromDrv_asyncInProgress)\
    || !defined(EepromDrv_getLastAsyncStatus)
#error EepromDrv_init, EepromDrv_readByte, EepromDrv_writeByte, EepromDrv_readBlock, EepromDrv_writeBlock, EepromDrv_asyncInProgress and EepromDrv_getLastAsyncStatus must all be defined to use this file
#endif

/*
 * EEPROM Interface definition
 */

#define Eeprom_init                 EepromImpl_init
#define Eeprom_readByte             EepromImpl_readByte
#define Eeprom_writeByte            EepromImpl_writeByte
#define Eeprom_readBlock            EepromImpl_readBlock
#define Eeprom_writeBlock           EepromImpl_writeBlock
#define Eeprom_asyncInProgress      EepromImpl_asyncInProgress
#define Eeprom_getLastAsyncStatus   EepromImpl_getLastAsyncStatus
#define Eeprom_readBlockEx          EepromImpl_readBlockEx
#define Eeprom_writeBlockEx         EepromImpl_writeBlockEx
#define Eeprom_setHint              EepromImpl_setHint
#define Eeprom_getHint              EepromImpl_getHint

