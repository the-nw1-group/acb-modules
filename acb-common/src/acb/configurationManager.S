/*
 * Copyright (c) 2015 The NW1 Group
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#include "moduleInfo.inc"

@ public ACB configuration type routines

#ifdef ACB_USE_CONFIG_MANAGER

    module(ConfigurationManager)

    .extern         Eeprom_getHint                                  @ Get a hint from the EEPROM sub system

/*
 * Standard configuration is stored with 2K, with the following ranges predefined:
 *
 *      +-------------+
 *      | 0x800-0x400 | 1024    Event Definitions, space for 64 events (see eventHandler for more deails)
 *      +-------------+
 *      | 0x3FF-0x3E0 |   32    Event control data (see eventHandler for more deails)
 *      +-------------+
 *      | 0x3DF-0x300 |         Reserved
 *      +-------------+
 *      | 0x2FF-0x200 |  256    Application reserved space
 *      +-------------+
 *      | 0x1FF-0x100 |  256    Node variables, space for 256 node variables (see nodeVariables for more details)
 *      +-------------+
 *      |  0xFF-0xC0  |   64    ACB transport #3 data (see various transport drivers for details)
 *      +-------------+
 *      |  0xBF-0x80  |   64    ACB transport #2 data (see various transport drivers for details)
 *      +-------------+
 *      |  0x7F-0x40  |   64    ACB transport #1 data (see various transport drivers for details)
 *      +-------------+
 *      |  0x3F-0x20  |   32    ACB configuration data (see below)
 *      +-------------+
 *      |  0x1F-0x00  |   32    Configuration Manager private data (see below)
 *      +-------------+
 *
 * Configuration Manager private data:
 *  stored @ 0x00 to 0x1F
 *
 *      0x1F-0x06   Reserved (unused)
 *      0x05-0x04   Eeprom data version: 0x05 stores major version, 0x04 stores minor version
 *      0x03-0x00   Reserved (for possible CRC in the future)
 *
 * ACB configuration data:
 *  stored @ 0x20 to 0x3F
 *
 *      0x3F-0x24   Reserved (unused)
 *      0x23-0x22   Node Number
 *      0x21-0x20   Module status
 *
 */

/*
 * Private offsets into the configration space
 *
 */

__cfgMgr_CRC_Offset     = 0x00                                      @ CRC offset
__cfgMgr_Version_Offset = 0x04                                      @ Version offset

@ Current implementation requires a cached EEPROM

#if !defined(ACB_CACHE_EEPROM)
#error This version of the configuration manager requires a cached eeprom implementation
#endif

@ public configuration manager routines

    module(ConfigurationManager)

@ Configuration manager private data

    private_data(ConfigurationManager_private)

ConfigurationManagerCacheAddress:
                    .int            0                               @ location of the cache

    public_function(ConfigurationManager_init)

@ void ConfigurationManager_init()
@   init the ACB common library, including:
@       initialise the configuration manager implementation. Checks the configuration is initialised and is the correct
@       version. If it's not initialised (ie a blank EEPROM), the configuration is initialised (along with help from
@       the event manager/node variable manager/etc). If it's an incorrect version number then this is upgraded, again
@       with help from other modules that use the configuration manager.

ConfigurationManager_init:
                    push            {r7, lr}
                    movs            r0, #EepromCache_getStatusHint  @ Check it the EEPROM cache has been loaded
                    bl              Eeprom_getHint
                    movs            r1, #1<<EepromCache_StatusCacheError @ check for error
                    tst             r0, r1
                    bne             __cfgMgr_init_raiseError
                    movs            r1, #1<<EepromCache_StatusCacheLoaded   @ if the cache has loaded, then continue
                    tst             r0, r1                          @ otherwise, wait until it's loaded, or there's an
                    bne             __cfgMgr_init_cacheLoaded       @ error
0:
                    bl              EepromDrvImpl_asyncInProgress   @ has the last async process finished (which is
                    cmp             r0, #FALSE                      @ populating the cache at this point...)
                    bne             0b
                    bl              EepromCache_getLastAsyncStatus  @ once finished, was it a success
                    cmp             r0, #SUCCESS
                    bne             __cfgMgr_init_raiseError        @ no, so raise an error
__cfgMgr_init_cacheLoaded:
                    movs            r0, #EepromCache_getBaseAddressHint @ get the cache base address
                    bl              Eeprom_getHint                  @ if this is zero, then something has gone wrong
                    cmp             r0, #0                          @ so throw an error
                    beq             __cfgMgr_init_raiseError
                    ldr             r1, = #ConfigurationManagerCacheAddress @ otherwise store it for later
                    str             r0, [r1]
                    ldrh            r1, [r0, #__cfgMgr_Version_Offset] @ get the version stored in EEPROM
                    ldr             r2, =#0xFFFF                    @ if it's 0xFFFF that means the EEPROM is blank
                    cmp             r1, r2
                    bne             0f
                    bl              ConfigurationManager_initEeprom
0:
                    ldrh            r1, [r0, #__cfgMgr_Version_Offset]  @ check that we have the expected version no.
                    ldr             r2, = #ACB_CONFIGURATION_VERSION    @ this code only handles the current version
                    cmp             r1, r2                          @ number, so this just errors
                    bne             __cfgMgr_init_incorrectVersion

                    pop             {r7, pc}
__cfgMgr_init_raiseError:
                    movs            r0, #ACB_CONFIG_LOAD_FAIL       @ raise an error that the configuration failed to
                    swi             ACB_FATAL_ERROR                 @ load - this doesn't return.
__cfgMgr_init_incorrectVersion:
                    movs            r0, #ACB_CONFIG_WRONG_VERSION   @ wrong version number in the EEPROM, and we can't
                    swi             ACB_FATAL_ERROR                 @ convert it - this doesn't return.

    private_function(ConfigurationManager_initEeprom)

@ int ConfigurationManager_initEeprom(int cacheBaseAddress)
@   initialise the EEPROM to valid values on a blank EEPROM device. The parameter is the cacheBaseAddress, and this is
@   also returned from this function. Calls the various sub systems to initialise their data, then writes back to the
@   EEPROM (via the cache)

ConfigurationManager_initEeprom:
                    push            {r7, lr}
                    movs            r7, r0                          @ save off the base address

                    bl              Acb_initConfiguration
                    movs            r0, r7
    @               bl              AcbTansport_initConfiguration
                    movs            r0, r7
    @               bl              AcbNodeVars_initConfiguration
                    movs            r0, r7
    @               bl              Application_initConfiguration
                    movs            r0, r7
    @               bl              AcbEvents_initConfiguration
                    movs            r0, r7

                    ldr             r1, =#ACB_CONFIGURATION_VERSION @ set the config version, last so if the above
                    strh            r1, [r7, #__cfgMgr_Version_Offset] @ has gone wrong, then on next boot, we'll try
                    movs            r1, #0                          @ again.
                    ldr             r2, =#ACB_EEPROM_SIZE
                    movs            r0, #EepromCache_setRegionDirtyHint
                    bl              EepromImpl_setHint              @ tell the cache that the whole eeprom is dirty
                    movs            r0, r7                          @ restore the base address
                    pop             {r7, pc}

#endif

    .end
