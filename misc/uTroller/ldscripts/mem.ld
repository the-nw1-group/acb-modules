/*
 * Copyright (c) 2018 The NW1 Group
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

MEMORY
{
  RAM (xrw)    : ORIGIN = 0x20000000, LENGTH = 6K
  FLASH (rx)   : ORIGIN = 0x08000000, LENGTH = 31K
  EEPROM (xrw) : ORIGIN = 0x08007C00, LENGTH = 1K
}

_boot_ram_orgin     = ORIGIN(RAM);
_boot_ram_length    = LENGTH(RAM);
_boot_flash_orgin   = ORIGIN(FLASH);
_boot_flash_length  = LENGTH(FLASH);
_boot_eeprom_origin = ORIGIN(EEPROM);
_boot_eeprom_length = LENGTH(EEPROM);

_application_orgin          = ORIGIN(FLASH) + LENGTH(FLASH); 
