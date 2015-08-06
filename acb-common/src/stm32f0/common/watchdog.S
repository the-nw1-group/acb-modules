/*
 * Copyright (c) 2015 The NW1 Group
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

@ watch dog access functions

#include "stm32f0xx.inc"
#include "moduleInfo.inc"
#include "acb_common.inc"

	module(Watchdog)

IWDG_REFRESH 		= 0x0000AAAA
IWDG_WRITE_ACCESS	= 0x00005555
IWDG_START			= 0x0000CCCC

	public_function(IWDG_setup)

@ void IWDG_setup(uint32 prescaler, uint32 reload)
@	setup the IWDG timer, timeout based on prescaler and the reload value

IWDG_setup:
					push			{r7, lr}
					ldr				r2, = #_RCC_CSR					@ enable the RTC clock
					movs			r3, #RCC_CSR_LSION
					str				r3, [r2]

					movs			r7, #RCC_CSR_LSIRDY				@ wait for the RTC to be ready
1:
					ldr				r3, [r2]
					tst				r3, r7
					bne				1b

#if defined(DEBUG)
																	@ if debugging, stop the IWDG when stepping through
					ldr				r7, = #_RCC_APB2ENR				@ enable the clock the to MCU debug component
					ldr				r2, [r7]
					ldr				r3, = #RCC_APB2ENR_DBGMCUEN
					orrs			r3, r3, r2
					str				r3, [r7]

					ldr				r7, = #_DBGMCU_APB1FZ			@ Debug independent watchdog stopped when core
					ldr				r2, [r7]						@ is halted
					ldr				r3, = #DBGMCU_APB1_FZ_DBG_IWDG_STOP
					orrs			r3, r3, r2
					str				r3, [r7]
#endif

					ldr				r7, = #IWDG_BASE
					ldr				r2, = #IWDG_START				@ activate IWDG
					str				r2, [r7, #IWDG_KR_OFFSET]
					ldr				r2, = 0x00005555				@ enable write access
					str				r2, [r7, #IWDG_KR_OFFSET]
					str				r0, [r7, #IWDG_PR_OFFSET]		@ write the prescaler value
					str				r1, [r7, #IWDG_RLR_OFFSET]		@ write the reload value
2:
					ldr				r0, [r7, #IWDG_SR_OFFSET]		@ wait until the status is clear
					tst				r0, r0
					beq				2b

					ldr				r0, = #IWDG_REFRESH 			@ refresh the watchdog timer
					str				r0, [r7, #IWDG_KR_OFFSET]
					pop				{r7, pc}

	public_function(IWDG_reset)

@ void IWDG_reset (void)
@	reset the IWDG timer

IWDG_reset:
					ldr				r0, = #IWDG_REFRESH			 	@ refresh the IWDG timer
					ldr				r1, = #_IWDG_KR
					str				r0, [r1]
					bx				lr
	.end
