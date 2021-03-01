/*
 * Copyright (c) 2015 The NW1 Group
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

MEMORY
{
RAM   (xrw)     : ORIGIN = 0x20000000, LENGTH = 64K
FLASH (rx)      : ORIGIN = 0x08000000, LENGTH = 256K
}


_boot_ram_orgin 	= ORIGIN(RAM);
_boot_ram_length 	= LENGTH(RAM);
_boot_flash_orgin	= ORIGIN(FLASH);
_boot_flash_length 	= LENGTH(FLASH);

_application_orgin			= ORIGIN(FLASH) + LENGTH(FLASH); 
