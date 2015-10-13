/*
 * Memory Spaces Definitions.
 *
 * Need modifying for a specific board. 
 *   FLASH.ORIGIN: starting address of flash
 *   FLASH.LENGTH: length of flash
 *   RAM.ORIGIN: starting address of RAM bank 0
 *   RAM.LENGTH: length of RAM bank 0
 *
 * The values below can be addressed in further linker scripts
 * using functions like 'ORIGIN(RAM)' or 'LENGTH(RAM)'.
 */

/*
 * Location of CBUS module parameter block. This needs to be within the main application code, and after the
 * vector table. non-M0 devices vector tables contain upto 81 entries (324 bytes), plus an additional 16 entries (64
 * bytes) for the exception and core peripherial devices,  and usually have 4K pages (unlike the low density M0 devices
 * that have 1K pages). So the location of the CBUS parameter block needs to be at least 4488 bytes from the nominal
 * application origin (0x08000000). The parameter block is therefore placed at location 0x1188 (4488) after the
 * application origin, so that it's in a common location across all cortex devices.
 *
 * This does mean that this creates a gap in the application image on m0 devices (as they only have a 32 entry vector 
 * table, or 128 bytes, with the same set of exception handlers as the other cortex devices, making 192 bytes), in
 * addition to the flash image starting at 3K, rather than 4K. This leaves a gap of 1224 bytes. Therefore we allocate
 * a "vtor" flash area, where some routines can be placed. These need to be defined in code, to be placed in the
 * after_vectors section, as the linker won't flow sections around the fixed CBUS module parameters block.
 *
 * Note the offset here, is from the _flash_origin as defined above.
 */


MEMORY
{
  RAM (xrw)         : ORIGIN = 0x200000C0, LENGTH = 5952
  FLASH_VTOR(rx)    : ORIGIN = 0x08000C00, LENGTH = 4488
  CBUS_MOD_VARS(rx) : ORIGIN = 0x08001188, LENGTH = 40
  FLASH (rx)        : ORIGIN = 0x080011B0, LENGTH = 28240
}

_ram_origin   = ORIGIN(RAM);
_ram_length   = LENGTH(RAM);
_ram_lastLocation = _ram_origin + _ram_length;

_flash_origin = ORIGIN(FLASH);
_flash_length = LENGTH(FLASH);
