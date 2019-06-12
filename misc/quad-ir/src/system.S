/*
 * Copyright (c) 2015 The NW1 Group
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
@ Note: Inclusion of this file in a build assumes that the processor is clocked via an external 8Mhz crystal or
@       resonator with the PLL configured to give system clock frequency of 48Mhz

@       =============================================================================
@       System Clock source                    | PLL (HSI)
@       -----------------------------------------------------------------------------
@       SYSCLK(Hz)                             | 8000000
@       -----------------------------------------------------------------------------
@       HCLK(Hz)                               | 8000000
@       -----------------------------------------------------------------------------
@       AHB Prescaler                          | 1
@       -----------------------------------------------------------------------------
@       APB Prescaler                          | 1
@       -----------------------------------------------------------------------------
@       HSE Frequency(Hz)                      | NA
@       -----------------------------------------------------------------------------
@       PLLMUL                                 | 12
@       -----------------------------------------------------------------------------
@       PREDIV                                 | 2
@       -----------------------------------------------------------------------------
@       Flash Latency(WS)                      | 1
@       -----------------------------------------------------------------------------
@       Prefetch Buffer                        | ON
@       -----------------------------------------------------------------------------

@ Translated from auto generated code from MCD Application Team

#include "moduleInfo.inc"

    module(System)

    .extern         System_onClockFail                              @ call when it's not possible to set the system
                                                                    @ clock. Default implementation stalls the processor
    .extern         __aeabi_uidiv

@ public variables

    public_data(system_globals)
    .global         SystemCoreClock
    .global         System_coreClock

SystemCoreClock:
System_coreClock:   .word           8000000

@ private static data

    static_data(System_ahbPrescale)

System_ahbPrescale: .byte           0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 6, 7, 8, 9

    public_function(System_init)

@ void System_init(void)
@   Initialize the Embedded Flash Interface, the PLL and update the SystemCoreClock variable.

System_init:
                    push            {r7, lr}
                    ldr             r7, = #RCC_BASE
                    ldr             r2, [r7, #RCC_CR_OFFSET]        @ turn on HSI (even though we use HSE, flash
                    movs            r1, #RCC_CR_HSION               @ operations, need HSI for example)
                    orrs            r2, r2, r1
                    str             r2, [r7, #RCC_CR_OFFSET]
                                                                    @ reset SW[1:0], HPRE[3:0], PPRE[2:0], ADCPRE and MCO[3:0] bits
                    ldr             r3, [r7, RCC_CFGR_OFFSET]
                    ldr             r1, = #~(RCC_CFGR_SW | RCC_CFGR_HPRE | RCC_CFGR_PPRE | RCC_CFGR_ADCPRE | RCC_CFGR_MCO)
                    ands            r3, r3, r1
                    str             r3, [r7, #RCC_CFGR_OFFSET]
                                                                    @ reset HSEON, CSSON and PLLON bits, reset HSEBYP bit
                    ldr             r1, = #~(RCC_CR_HSEON | RCC_CR_CSSON | RCC_CR_PLLON | RCC_CR_HSEBYP)
                    ands            r2, r2, r1
                    str             r2, [r7, #RCC_CR_OFFSET]
                                                                    @ reset PLLSRC, PLLXTPRE and PLLMUL[3:0] bits
                    ldr             r1, = #~(RCC_CFGR_PLLSRC | RCC_CFGR_PLLXTPRE | RCC_CFGR_PLLMUL)
                    ands            r3, r3, r1
                    str             r3, [r7, #RCC_CFGR_OFFSET]
                                                                    @ reset PREDIV1[3:0] bits
                    ldr             r0, [r7, #RCC_CFGR2_OFFSET]
                    movs            r1, #RCC_CFGR2_PREDIV1
                    bics            r0, r0, r1
                    str             r0, [r7, #RCC_CFGR2_OFFSET]
                                                                    @ reset USARTSW[1:0], I2CSW, CECSW and ADCSW bits
                    ldr             r0, [r7, #RCC_CFGR3_OFFSET]
                    ldr             r1, = #~(RCC_CFGR3_USART1SW | RCC_CFGR3_I2C1SW | RCC_CFGR3_CECSW | RCC_CFGR3_ADCSW)
                    ands            r0, r0, r1
                    str             r0, [r7, #RCC_CFGR3_OFFSET]
                                                                    @ reset HSI14 bit
                    ldr             r0, [r7, #RCC_CR2_OFFSET]
                    ldr             r1, = #~(RCC_CR2_HSI14ON)
                    ands            r0, r0, r1
                    str             r0, [r7, #RCC_CR2_OFFSET]
                                                                    @ disable all interrupts
                    movs            r1, #0
                    str             r0, [r7, #RCC_CIR_OFFSET]
                                                                    @ set the system clock
                    bl              _setSysClock
                    cmp             r0, #ERROR                      @ did that fail? If so call System_onClockFail
                    beq             __init_callFailHandler
                    bl              System_coreClockUpdate          @ Update clock variable
                    pop             {r7, pc}

__init_callFailHandler:                                             @ use to this to overcome the -/+ 256 byte limit
                    bl              System_onClockFail              @ of a beq instuction. This is a BL so we can
                    b               .                               @ address all 4M, although we don't expect to
                                                                    @ return (otherwise we have a -/+ 2K limit)

    public_override(System_onClockFail)

@ void System_onClockFail(void)
@   Called when unable to set system clock

System_onClockFail:
                    b               .

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
                    ldr             r0, [r7, #RCC_CFGR_OFFSET]
                    movs            r2, #RCC_CFGR_SWS
                    ands            r2, r2, r0
                    movs            r1, #RCC_CFGR_SWS_PLL
                    cmp             r2, r1
                    beq             _ccu_HSI
                    movs            r1, #RCC_CFGR_SWS_HSE
                    cmp             r2, r1
                    beq             _ccu_HSE
                    movs            r1, #RCC_CFGR_SWS_HSI48
                    cmp             r2, r1
                    beq             _ccu_HSI48
_ccu_HSI:                                                           @ uses the define HSI_VALUE
                    ldr             r1, = #HSI_VALUE
                    b               _ccu_calcHCLK
_ccu_HSE:                                                           @ uses the define HSE_VALUE
                    ldr             r1, = #HSE_VALUE
                    b               _ccu_calcHCLK
_ccu_HSI48:                                                         @ uses the define HSI48_VALUE
                    ldr             r1, = #HSI48_VALUE
                    b               _ccu_calcHCLK
_ccu_PLL:                                                           @ calcuates the values based on the running
                    ldr             r1, = #RCC_CFGR_PLLSRC          @ PLL
                    ands            r1, r1, r0
                    movs            r2, r1
                    ldr             r1, = #RCC_CFGR_PLLMULL
                    ands            r1, r1, r0
                    lsrs            r1, r1, #18
                    adds            r1, r1, #2
                                                                    @ is the PLL source HSI/2
                    movs            r3, #RCC_CFGR_PLLSRC_HSI_DIV2
                    tst             r3, r2
                    beq             _ccu_notHSI2
                                                                    @ yes source is HSI/2
                    ldr             r3, = #HSI_VALUE
                    lsrs            r3, r3, #1
                    muls            r1, r1, r3
                    b               _ccu_calcHCLK
_ccu_notHSI2:                                                       @ value = (HSE_VALUE / prediv1factor) * pllmull
                    movs            r6, r1                          @ prediv1factor = r1
                    ldr             r0, [r7, #RCC_CFGR2_OFFSET]     @ pllmull moved from r1 into r3
                    movs            r2, #RCC_CFGR2_PREDIV1
                    ands            r0, r0, r2
                    adds            r1, r0, #1
                    ldr             r0, = #HSE_VALUE
                    bl              __aeabi_uidiv
                    muls            r0, r0, r6
                    mov             r1, r0
_ccu_calcHCLK:                                                      @ calc HCLK, incoming value is in r1
                    movs            r2, #RCC_CFGR_HPRE
                    ands            r0, r0, r2
                    lsrs            r0, r0, #4
                    ldr             r7, = #System_ahbPrescale
                    ldrb            r0, [r7, r0]
                    lsrs            r1, r1, r0
                    ldr             r7, = #System_coreClock
                    str             r1, [r7]

                    pop             {r5-r7, pc}

    private_function(_setSysClock)

@ bool _setSysClock(void)
@   Configures the System clock frequency, AHB/APBx prescalers and Flash settings.
@   returns true (SUCCESS) if successful, otherwise returns false (ERROR)

_setSysClock:
                    push            {r7, lr}
                                                                    @ Enable Prefetch Buffer and set Flash Latency
                    ldr             r1, = #FLASH_R_BASE
                    ldr             r0, [r1, #FLASH_ACR_OFFSET]
                    movs            r2, #FLASH_ACR_PRFTBE
                    orrs            r0, r0, r2
                    str             r0, [r1, #FLASH_ACR_OFFSET]
                                                                    @ HCLK = PCLK = SYSCLK
                    ldr             r0, [r7, #RCC_CFGR_OFFSET]
                    ldr             r1, = #~(RCC_CFGR_PLLSRC | RCC_CFGR_PLLXTPRE | RCC_CFGR_PLLMULL)
                    ands            r0, r0, r1
                    ldr             r1, = #(RCC_CFGR_HPRE_DIV1 | RCC_CFGR_PPRE_DIV1)
                    orrs            r0, r0, r1
                    str             r0, [r7, #RCC_CFGR_OFFSET]

                    movs            r0, #SUCCESS                    @ function succeeded
__setSysClockReturn:
                    pop             {r7, pc}

    .end
