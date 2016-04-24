/*
 * Copyright (c) 2015 The NW1 Group
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

/*
 * EEPROM cache implementation include file. To use the cache, include the source
 * file into your source, and #include this file in between your EEPROM driver include
 * the the public EEPROM include, for example:
 *
 *  #include "eepromMyDriver.inc"
 *  #include "eepromCache.inc"
 *  #include "eeprom.inc"
 *
 */

/*
 * Keep a reference to the underlying EEPROM driver
 *
 */

#define ACB_USE_EEPROMCACHE

#define EepromDrvImpl_init               EepromDrv_init
#define EepromDrvImpl_readByte           EepromDrv_readByte
#define EepromDrvImpl_writeByte          EepromDrv_writeByte
#define EepromDrvImpl_readBlock          EepromDrv_readBlock
#define EepromDrvImpl_writeBlock         EepromDrv_writeBlock
#define EepromDrvImpl_asyncInProgress    EepromDrv_asyncInProgress
#define EepromDrvImpl_getLastAsyncStatus EepromDrv_getLastAsyncStatus
#define EepromDrvImpl_setHint            EepromDrv_setHint
#define EepromDrvImpl_getHint            EepromDrv_getHint

#if !defined(ACB_SKIP_CACHE_REDEFINES)

/*
 * Undefine the driver interface
 *
 */

#undef EepromDrv_init
#undef EepromDrv_readByte
#undef EepromDrv_writeByte
#undef EepromDrv_readBlock
#undef EepromDrv_writeBlock
#undef EepromDrv_asyncInProgress
#undef EepromDrv_getLastAsyncStatus
#undef EepromDrv_setHint
#undef EepromDrv_getHint

/*
 * Redefine the caching interface as the driver
 *
 */

#define EepromDrv_init               EepromCache_init
#define EepromDrv_readByte           EepromCache_readByte
#define EepromDrv_writeByte          EepromCache_writeByte
#define EepromDrv_readBlock          EepromCache_readBlock
#define EepromDrv_writeBlock         EepromCache_writeBlock
#define EepromDrv_asyncInProgress    EepromCache_asyncInProgress
#define EepromDrv_getLastAsyncStatus EepromCache_getLastAsyncStatus
#define EepromDrv_setHint            EepromCache_setHint
#define EepromDrv_getHint            EepromCache_getHint

#endif

#define ACB_CACHE_EEPROM

/*
 * Cache status error bits
 *
 */

EepromCache_StatusCacheLoaded = 0
EepromCache_StatusCacheError  = 1

/*
 * Supported get hints
 *  EepromCache_getBaseAddressHint - get the base address of the cache
 *  EepromCache_getStatus          - get the caching system status; don't poll this value as it's only updated through
 *                                   calls to read/write byte/block. Use a combination of asyncInProgress and
 *                                   getLastAsyncStatus which can be polled.
 */

EepromCache_getBaseAddressHint      = 0
EepromCache_getStatusHint           = 1

/*
 * Supported set hints
 *  EepromCache_setRegionDirtyHint - indicate the region from address (arg0) for length (arg1) is dirty, and should be
 *                                   persisted
 */

EepromCache_setRegionDirtyHint      = 3
