/*
 * Copyright (c) 2015 The NW1 Group
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

@ option byte setting routines

#include "stm32f0xx.inc"
#include "moduleInfo.inc"
#include "acb_common.inc"

	module(OptionByte)

	.extern			Flash_unlockWrite
	.extern			Flash_unlockOptionByteWrite
	.extern			Flash_erase
	.extern			Flash_enableOptionByteProgramming
	.extern			Flash_disableOptionByteProgramming
	.extern			Flash_waitForOperation

	public_function(OptionByte_write)

@ bool OptionByte_write(uint32 address, uint32 newValue, uint32 mask)
@	write the new value (masked with mask) to the option byte identified by the address parameter
@	returns true (SUCCESS) on success or false (ERROR) on failure; but see below
@	note:
@   	the HSI clock must be running for this function to work
@   	the system calculates the inverted values in the odd bytes (see section 4 in RM0091)
@		full 32 bit access is available via this function
@		address must be word aligned
@	    if option bytes are written the controller is reset, and this function doesn't return

OptionByte_write:
					push			{r3-r7, lr}						@ we don't need to store r3, but the stack must
																	@ keep double word aligned
					sub				sp, #16							@ store the current option byte values (stack frame)

					ldr				r3, = #OB_BASE					@ check address is in range
					cmp				r0, r3
					blt				__obWriteFail
					adds			r3, r3, #0xC
					cmp				r0, r3
					bgt				__obWriteFail
																	@ check if current value at the address is
					mvns			r2, r2							@ negate the mask
					ldr				r3, [r0]						@ already the correct value
					movs			r4, r3
					ands			r4, r4, r2
					orrs			r4, r4, r1
					cmp				r3, r4
					beq				__obWriteOK						@ value is the same, so just return OK

					mov				r12, r2							@ save off r2 (r12 is ip scratch reg)
					mov				r2, sp
					ldr				r3, = #OB_BASE					@ on the stack frame, as it's not possible to change
					ldmia			r3!, {r4-r7}					@ one value, we must copy the option bytes, erase
					stmia			r2!, {r4-r7}					@ the option bytes, change an in memory version
																	@ and then write them all out again.
					mov				r2, r12							@ restore r2
					ldr				r3, = #OB_BASE					@ change the appropriate value to the newValue within
					subs			r0, r0, r3						@ the stack frame. r0 is now an offset into the stack
					mov				r3, sp
					ldr				r4, [r3, r0]
					ands			r4, r4, r2
					orrs			r4, r4, r1
					str				r4, [r3, r0]

					bl				Flash_waitForOperation			@ wait for any pending write operations to complete
					bl				Flash_unlockWrite
					cmp				r0, #SUCCESS
					bne				__obWriteFail
					bl				Flash_unlockOptionByteWrite
					cmp				r0, #SUCCESS
					bne				__obWriteFail
					movs			r0, #0
					movs			r1, #FLASH_CR_OPTER
					bl				Flash_erase
					cmp				r0, #SUCCESS
					bne				__obWriteFail
					bl				Flash_enableOptionByteProgramming
					cmp				r0, #SUCCESS
					bne				__obWriteFail
																	@ program the option bytes, a half word at a time
					ldr				r4, = #OB_BASE
					mov				r5, sp
					movs			r6, #14							@ write 16 bytes, in half words
__obProgram:
					ldrh			r3, [r5, r6]					@ read the saved value from the stack
					strh			r3, [r4, r6]					@ write the value to the option bytes
					bl				Flash_waitForOperation
					subs			r6, r6, #2
					bpl				__obProgram
																	@ disable programming
					bl				Flash_disableOptionByteProgramming
					cmp				r0, #SUCCESS
					bne				__obWriteFail
																	@ reload the option bytes, and reset the processor
					ldr				r7, = #FLASH_R_BASE
					ldr				r0, [r7, #FLASH_CR_OFFSET]
					ldr				r1, = #FLASH_CR_OBL_LAUNCH
					orrs			r0, r0, r1
					str				r0, [r7, #FLASH_CR_OFFSET]
					b				.								@ shouldn't get here

__obWriteOK:
					movs			r0, #SUCCESS
__obWriteReturn:
					add				sp, #16							@ delete the stack frame
					pop				{r3-r7, pc}
__obWriteFail:
					movs			r0, #ERROR
					b				__obWriteReturn

	.end
