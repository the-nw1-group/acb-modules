/*
 * Copyright (c) 2015 The NW1 Group
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#include "moduleInfo.inc"
#include "acb/common.inc"

@ public ACB configuration type routines

    module(ConfigurationManager)

/*
 * Standard configuration is stored with 2K, with the following ranges predefined:
 *
 *      +-------------+
 *      | 0x800-0x400 |     Event Definitions, space for 64 events (see eventHandler for more deails)
 *      +-------------+
 *      | 0x3FF-0x3E0 |     Event control data (see eventHandler for more deails)
 *      +-------------+
 *      | 0x3DF-0x200 |     Reserved
 *      +-------------+
 *      | 0x1FF-0x100 |     Node variables, space for 256 node variables (see nodeVariables for more details)
 *      +-------------+
 *      |  0xFF-0xC0  |     Reserved
 *      +-------------+
 *      |  0xBF-0x40  |     ACB transport #2 data (see various transport drivers for details)
 *      +-------------+
 *      |  0x7F-0x40  |     ACB transport #1 data (see various transport drivers for details)
 *      +-------------+
 *      |  0x3F-0x20  |     ACB configuration data (see below)
 *      +-------------+
 *      |  0x1F-0x00  |     Configuration Manager private data (see below)
 *      +-------------+
 *
 * Configuration Manager private data:
 *  stored @ 0x00 to 0x1F
 *
 *      0x1F-0x00   Reserved (unused)
 *      0x05-0x04   Eeprom data version: 0x05 stores major version, 0x04 stores minor version
 *      0x03-0x00   Reserved (for possible CRC in the future)
 *
 * ACB configuration data:
 *  stored @ 0x20 to 0x3F
 *
 *      0x3F-0x23   Reserved (unused)
 *      0x23-0x22   Node Number
 *      0x21-0x20   Module status
 *
 */

@ Current implementation requires a cached EEPROM

#if !defined(ACB_CACHE_EEPROM)
#error This version of the configuration manager requires a cached eeprom implementation
#endif




    .end
