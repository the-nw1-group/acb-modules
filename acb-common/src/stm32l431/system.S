/*
 * Copyright (c) 2021 The NW1 Group
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

/*
 * (c) COPYRIGHT 2012 STMicroelectronics
 *
 * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
 * You may not use this file except in compliance with the License.
 * You may obtain a copy of the License at:
 *
 *        http://www.st.com/software_license_agreement_liberty_v2
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

@ System Timing functions
@ -----------------------------------------------------------------------------
@         System Clock source                    | MSI
@ -----------------------------------------------------------------------------
@         SYSCLK(Hz)                             | 4000000
@ -----------------------------------------------------------------------------
@         HCLK(Hz)                               | 4000000
@ -----------------------------------------------------------------------------
@         AHB Prescaler                          | 1
@ -----------------------------------------------------------------------------
@         APB1 Prescaler                         | 1
@ -----------------------------------------------------------------------------
@         APB2 Prescaler                         | 1
@ -----------------------------------------------------------------------------
@         PLL_M                                  | 1
@ -----------------------------------------------------------------------------
@         PLL_N                                  | 8
@ -----------------------------------------------------------------------------
@         PLL_P                                  | 7
@ -----------------------------------------------------------------------------
@         PLL_Q                                  | 2
@ -----------------------------------------------------------------------------
@         PLL_R                                  | 2
@ -----------------------------------------------------------------------------
@         PLLSAI1_P                              | NA
@ -----------------------------------------------------------------------------
@         PLLSAI1_Q                              | NA
@ -----------------------------------------------------------------------------
@         PLLSAI1_R                              | NA
@ -----------------------------------------------------------------------------
@         PLLSAI2_P                              | NA
@ -----------------------------------------------------------------------------
@         PLLSAI2_Q                              | NA
@ -----------------------------------------------------------------------------
@         PLLSAI2_R                              | NA
@ -----------------------------------------------------------------------------
@         Require 48MHz for USB OTG FS,          | Disabled
@         SDIO and RNG clock                     |
@ -----------------------------------------------------------------------------

@ Translated from auto generated code from MCD Application Team

#include "moduleInfo.inc"

#ifdef __STM32L431XX_SYSTEM

    module(System)

    .extern         System_onClockFail                              @ call when it's not possible to set the system
                                                                    @ clock. Default implementation stalls the processor
@ public variables

    public_data(system_globals)
    .global         SystemCoreClock
    .global         System_coreClock

SystemCoreClock:
System_coreClock:   .word           40000000

@ private static data

    private_data(system_private)

System_ahbPrescale: .byte           0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 6, 7, 8, 9
System_apbPrescale: .byte           0, 0, 0, 0, 1, 2, 3, 4
System_msiRange:    .word           100000, 200000, 400000, 800000, 1000000,  2000000, 4000000, 8000000, 16000000, 24000000, 32000000, 48000000

    public_function(System_init)

@ void System_init(void)
@   Initialize the Embedded Flash Interface, the PLL and update the SystemCoreClock variable.

System_init:

#if (__FPU_PRESENT == 1) && (__FPU_USED == 1)
                    ldr             r7, = #SCB_CPACR                @ set CP10/CP11 for full access
                    ldr             r0, =#(3 << 10*2) | (3 << 11*2)
                    str             r0, [r7]
#endif

                    ldr             r1, =#RCC_BASE                  @ Reset the RCC clock configuration to the default reset state
                    ldr             r0, [r1, #RCC_CR_OFFSET]        @ Set MSION bit
                    orrs            r0, r0, #RCC_CR_MSION
                    str             r0, [r1, #RCC_CR_OFFSET]
                    movs            r2, #0                          @ Reset CFG register
                    str             r2, [r1, #RCC_CFGR_OFFSET]
                    ldr             r2, =#RCC_CR_HSEON | RCC_CR_CSSON | RCC_CR_HSION | RCC_CR_PLLON
                    ldr             r0, [r1, #RCC_CR_OFFSET]
                    bics            r0, r0, r2
                    str             r0, [r1, #RCC_CR_OFFSET]
                    ldr             r2, =#0x00001000                @ Reset PLLCFGR register
                    str             r2, [r1, #RCC_PLLCFGR_OFFSET]
                    ldr             r2, =#RCC_CR_HSEBYP             @ Reset HSEBYP bit
                    ldr             r0, [r1, #RCC_CR_OFFSET]
                    bics            r0, r0, r2
                    str             r0, [r1, #RCC_CR_OFFSET]
                    movs            r2, #0                          @ Disable all RCC interrupts
                    str             r2, [r1, #RCC_CIER_OFFSET]

                    ldr             r1, =#SCB_VTOR
#ifdef VECT_TAB_SRAM
                    ldr             r0, =#_application_orgin        @ location of the app vector table
#else
                    ldr             r0, =#SRAM_BASE                 @ location of the app vector table in SRAM
#endif
                    str             r0, [r1]
                    dsb                                             @ ensure new vector table is used in subsequent exceptions

                    bx              lr

    public_function(System_coreClockUpdate)

@ void System_coreClockUpdate(void)
@   Update SystemCoreClock according to Clock Register Values
@   The SystemCoreClock variable contains the core clock (HCLK), it can
@   be used by the user application to setup the SysTick timer or configure
@   other parameters.

@ Note: Each time the core clock (HCLK) changes, this function must be called
@       to update SystemCoreClock variable value. Otherwise, any configuration
@       based on this variable will be incorrect.

SystemCoreClockUpdate:
System_coreClockUpdate:
                    push            {r5-r7, lr}
                    ldr             r7, = #RCC_BASE                 @ get the clock source
                    ldr             r0, [r7, #RCC_CR_OFFSET]
                    tst             r0, #RCC_CR_MSIRGSEL
                    beq             0f
                    ldr             r0, [r7, #RCC_CSR_OFFSET]
                    ands            r0, r0, #RCC_CSR_MSISRANGE
                    lsrs            r5, r0, #8
                    b               1f
0:
                    ands            r0, r0, #RCC_CR_MSIRANGE
                    lsrs            r5, r0, #4
1:
                    ldr             r1, =#System_msiRange
                    ldr             r5, [r1, r5, LSL #2]

                    ldr             r0, [r7, #RCC_CFGR_OFFSET]
                    ands            r0, r0, #RCC_CFGR_SWS
                    cmp             r0, #0x00
                    beq             _msi
                    cmp             r0, #0x04
                    beq             _hsi
                    cmp             r0, #0x08
                    beq             _hse
                    cmp             r0, #0x0C
                    beq             _pll
                                                                    @ fallthrough/default to msi
_msi:
                    movs            r6, r5
                    b               9f
_hsi:
                    ldr             r6, =#HSI_VALUE
                    b               9f
_hse:
                    ldr             r6, =#HSE_VALUE
                    b               9f
_pll:
                    ldr             r0, [r7, #RCC_PLLCFGR_OFFSET]
                    ands            r1, r0, #RCC_PLLCFGR_PLLSRC
                    ands            r2, r0, #RCC_PLLCFGR_PLLM
                    lsrs            r2, r0, #4
                    adds            r2, r0, #1
                    cmp             r1, #0x02
                    beq             _pllhsi
                    cmp             r1, #0x03
                    beq             _pllhse
                    udiv            r6, r5, r2
                    b               8f
_pllhsi:
                    ldr             r6, =#HSI_VALUE
                    udiv            r6, r5, r2
                    b               8f
_pllhse:
                    ldr             r6, =#HSI_VALUE
                    udiv            r6, r5, r2
8:
                    ands            r2, r0, #RCC_PLLCFGR_PLLN
                    lsrs            r2, r2, #8
                    muls            r6, r6, r2
                    ands            r0, r0, #RCC_PLLCFGR_PLLR
                    lsrs            r0, r0, #25
                    adds            r0, r0, #1
                    lsls            r0, r0, #1
                    udiv            r6, r6, r0
9:
                    ldr             r0, [r7, #RCC_CFGR_OFFSET]
                    ands            r0, r0, #RCC_CFGR_HPRE
                    lsrs            r0, r0, #4
                    ldr             r1, =#System_ahbPrescale
                    ldrb            r2, [r1, r0]
                    lsrs            r5, r5, r2
                    ldr             r0, =#System_coreClock
                    str             r5, [r0]
                    pop             {r5-r7, pc}

#endif

    .end
