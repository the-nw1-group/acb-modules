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

MEMORY
{
  RAM (xrw) : ORIGIN = 0x200000C0, LENGTH = 5952
  FLASH (rx) : ORIGIN = 0x08000C00, LENGTH = 29K
}

_ram_origin = ORIGIN(RAM);
_ram_length = LENGTH(RAM);
_ram_lastLocation = _ram_origin + _ram_length;