/*
 * Copyright (c) 2015 The NW1 Group
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#include "moduleInfo.inc"
#include "stm32f0xx.inc"
#include "acb_common.inc"

@ flash writing and reading routines

	module(Flash)

	public_function(Flash_unlockWrite)

@ bool Flash_unlockWrite(void)
@	unlock writing to the flash area. Returns true on success or false (ERROR) on failure

Flash_unlockWrite:
					ldr				r3, = #FLASH_R_BASE
					ldr				r0, [r3, #FLASH_CR_OFFSET]		@ does the flash access need unlocking?
					movs			r1, #FLASH_CR_LOCK
					tst				r0, r1
					beq				0f								@ flash is already unlocked

					ldr				r0, = #FLASH_FKEY1				@ unlock sequence
					ldr				r1, = #FLASH_FKEY2
					str				r0, [r3, #FLASH_KEYR_OFFSET]
					str				r1, [r3, #FLASH_KEYR_OFFSET]
0:
					movs			r0, #SUCCESS
					bx				lr

	public_function(Flash_lockWrite)

@ bool flash_lockWrite(void)
@	Lock writing to the flash area. Returns true on success or false (ERROR) on failure

Flash_lockWrite:
					ldr				r3, = #FLASH_R_BASE
					ldr				r0, [r3, #FLASH_CR_OFFSET]		@ lock flash by writing the LOCK bit in the
					movs			r1, #FLASH_CR_LOCK				@ CR register
					orrs			r0, r0, r1
					str				r0, [r3, #FLASH_CR_OFFSET]
					movs			r0, #SUCCESS
					bx				lr

	public_function(Flash_unlockOptionByteWrite)

@ bool Flash_unlockOptionByteWrite(void)
@	unlock writing to the option bytes. Returns true on success or false (ERROR) on failure

Flash_unlockOptionByteWrite:
					ldr				r3, = #FLASH_R_BASE
					ldr				r0, [r3, #FLASH_CR_OFFSET]		@ does writes to the option bytes needs unlocking
					ldr				r1, = #FLASH_CR_OPTWRE
					tst				r0, r1
					bne				0f								@ writes to option byte already enabled

					ldr				r0, = #FLASH_OPTKEY1			@ unlock sequence
					ldr				r1, = #FLASH_OPTKEY2
					str				r0, [r3, #FLASH_OPTKEYR_OFFSET]
					str				r1, [r3, #FLASH_OPTKEYR_OFFSET]
0:
					movs			r0, SUCCESS
					bx				lr

	public_function(Flash_erase)

@ bool Flash_erase(uint32 address, uint32 eraseType)
@	erase an area of flash memory; required before writing to that area.
@	address is the base address of the page to erase when erasing in page mode.
@	eraseType should be one off: FLASH_CR_PER, FLASH_CR_MER, or FLASH_CR_OPTER
@	returns true on success or false (ERROR) on failure

Flash_erase:
					push			{r7, lr}
					ldr				r7, = #FLASH_R_BASE
					cmp				r1, #FLASH_CR_PER				@ ensure only the allowed options are specified
					beq				__fEraseOptionOK
					cmp				r1, #FLASH_CR_MER
					beq				__fEraseOptionOK
					cmp				r1, #FLASH_CR_OPTER
					beq				__fEraseOptionOK
__fEraseError:
					movs			r0, #ERROR
					b				0f

__fEraseOptionOK:
					ldr				r4, [r7, #FLASH_CR_OFFSET]
					movs			r2, #(FLASH_CR_PER | FLASH_CR_MER | FLASH_CR_OPTER)
					bics			r4, r4, r2
					orrs			r4, r4, r1
					str				r4, [r7, #FLASH_CR_OFFSET]
					cmp				r1, #FLASH_CR_PER
					bne				__fEraseStart
					str				r0, [r7, #FLASH_AR_OFFSET]		@ store the address to erase, must be done after
																	@ setting the PER bit in the CR register

__fEraseStart:														@ start erase operation
					ldr				r0, [r7, #FLASH_CR_OFFSET]		@ reload as set operation above, may have changed
					movs			r1, FLASH_CR_STRT				@ CR, start the erase operation
					orrs			r0, r0, r1
					str				r0, [r7, #FLASH_CR_OFFSET]
					bl				Flash_waitForOperation
																	@ clear erase flags
					ldr				r0, [r7, #FLASH_CR_OFFSET]
					movs			r2, #(FLASH_CR_PER | FLASH_CR_MER | FLASH_CR_OPTER)
					bics			r0, r0, r2
					str				r0, [r7, #FLASH_CR_OFFSET]
																	@ check for write protect errors
					ldr				r0, [r7, #FLASH_SR_OFFSET]
					movs			r1, #FLASH_SR_WRPRTERR
					tst				r0, r1
					bne				__fEraseError
					movs			r0, #SUCCESS
0:
					pop				{r7, pc}

	public_function(Flash_enableFlashProgramming)

@ bool Flash_enableFlashProgramming(void)
@	enable programming to the flash. Returns true on success or false (ERROR) on failure

Flash_enableFlashProgramming:
					ldr				r3, = #FLASH_R_BASE
					ldr				r0, [r3, #FLASH_CR_OFFSET]		@ Set the PG bit in the FLASH_CR register to enable
					movs			r1, #FLASH_CR_PG				@ programming
					orrs			r0, r0, r1
					str 			r0, [r3, #FLASH_CR_OFFSET]
					movs			r0, #SUCCESS
					bx				lr

	public_function(Flash_disableFlashProgramming)

@ bool Flash_disableFlashProgramming(void)
@	disable programming to the flash. Returns true on success or false (ERROR) on failure

Flash_disableFlashProgramming:
					ldr				r3, = #FLASH_R_BASE
					ldr				r0, [r3, #FLASH_CR_OFFSET]		@ Clear the PG bit in the FLASH_CR register to
					movs			r1, #FLASH_CR_PG				@ enable programming
					bics			r0, r0, r1
					str 			r0, [r3, #FLASH_CR_OFFSET]
					movs			r0, #SUCCESS
					bx				lr

	public_function(Flash_enableOptionByteProgramming)

@ bool Flash_enableProgramming(void)
@	enable programming to the flash and option bytes. Returns true on success or false (ERROR) on failure

Flash_enableOptionByteProgramming:
					ldr				r3, = #FLASH_R_BASE
					ldr				r0, [r3, #FLASH_CR_OFFSET]		@ Set the PG bit in the FLASH_CR register to enable programming
					movs			r1, #FLASH_CR_OPTPG
					orrs			r0, r0, r1
					str 			r0, [r3, #FLASH_CR_OFFSET]
					movs			r0, #SUCCESS
					bx				lr

	public_function(Flash_disableOptionByteProgramming)

@ bool Flash_disableProgramming(void)
@	disable programming to the flash and option bytes. Returns true on success or false (ERROR) on failure

Flash_disableOptionByteProgramming:
					ldr				r3, = #FLASH_R_BASE
					ldr				r0, [r3, #FLASH_CR_OFFSET]		@ Clear the PG bit in the FLASH_CR register to enable programming
					movs			r1, #FLASH_CR_OPTPG
					bics			r0, r0, r1
					str 			r0, [r3, #FLASH_CR_OFFSET]
					movs			r0, #SUCCESS
					bx				lr

	public_function(Flash_waitForOperation)

@ void Flash_waitForOperation(void)
@	wait for a flash operation to finish

Flash_waitForOperation:
					ldr				r3, = #FLASH_R_BASE
					movs			r0, #FLASH_SR_BSY				@ wait for the write to complete
0:
					ldr				r1, [r3, #FLASH_SR_OFFSET]
					tst				r0, r1
					bne				0b

					ldr				r1, [r3, #FLASH_SR_OFFSET]		@ Clear the EOP flag if not already cleared
					movs			r0, #FLASH_SR_EOP
					tst				r0, r1
					beq				1f
					orrs			r1, r1, r0
					str				r1, [r3, #FLASH_SR_OFFSET]
1:
					bx				lr

	.end
