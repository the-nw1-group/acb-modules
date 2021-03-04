/*
 * Copyright (c) 2021 The NW1 Group
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#include "moduleInfo.inc"


    .extern         NVIC_setPriorityGrouping
    .extern         System_coreClockUpdate
    .extern         MSCounter_init

    module(Main)

    public_function(main)

@ void main() - doesn't return
@   main code for module

main:
                    movs            r0, #1
                    ldr             r1, =#PERIPH_BITBAND_ADDR(_RCC_APB2ENR, RCC_APB2ENR_SYSCFGEN)
                    str             r0, [r1]
                    ldr             r1, =#PERIPH_BITBAND_ADDR(_RCC_APB1ENR1, RCC_APB1ENR1_PWREN)
                    str             r0, [r1]

                    movs            r0, #4
                    bl              NVIC_setPriorityGrouping

                    bl              SystemClock_Config

__mainLoop:
                    b               __mainLoop                      @ infinite loop

    private_function(SystemClock_Config)

@ void SystemClock_Config(void)
@   System Clock Configuration

SystemClock_Config:
                    push            {r7, lr}
                    ldr             r7, =#FLASH_BASE                @ Set flash latency to 4WS
                    ldr             r0, [r7, #FLASH_ACR_OFFSET]
                    bics            r0, r0, #FLASH_ACR_LATENCY_Msk
                    movs            r1, #FLASH_ACR_LATENCY_4WS
                    orrs            r0, r0, r1
                    str             r0, [r7, #FLASH_ACR_OFFSET]
0:
                    ldr             r0, [r7, #FLASH_ACR_OFFSET]
                    ands            r0, r0, FLASH_ACR_LATENCY_Msk
                    cmp             r0, r1
                    bne             0b

                    ldr             r7, =#_PWR_CR1                  @ Set voltage scaling 1
                    ldr             r0, [r7]
                    bics            r0, r0, #PWR_CR1_VOS_Msk
                    orrs            r0, r0, #PWR_CR1_VOS_0
                    str             r0, [r7]

                    ldr             r7, =#RCC_BASE                  @ Enable HSE
                    ldr             r0, [r7, #RCC_CR_OFFSET]
                    orrs            r0, r0, #RCC_CR_HSEBYP
                    str             r0, [r7, #RCC_CR_OFFSET]
                    ldr             r1, =#RCC_CR_HSEON
                    orrs            r0, r0, r1
                    str             r0, [r7, #RCC_CR_OFFSET]
0:
                    ldr             r0, [r7, #RCC_CR_OFFSET]
                    tst             r0, r1
                    bne             0b

                    ldr             r0, [r7, #RCC_PLLCFGR_OFFSET]   @ Set PLL and enable it
                    ldr             r1, =#(RCC_PLLCFGR_PLLSRC | RCC_PLLCFGR_PLLM | RCC_PLLCFGR_PLLN | RCC_PLLCFGR_PLLR)
                    bics            r0, r0, r1
                    orrs            r0, r0, #(RCC_PLLCFGR_PLLSRC_HSE | RCC_PLLCFGR_PLLM_1 | 40 | 0)
                    str             r0, [r7, #RCC_PLLCFGR_OFFSET]

                    ldr             r0, [r7, #RCC_PLLCFGR_OFFSET]
                    orrs            r0, r0, #RCC_PLLCFGR_PLLREN
                    str             r0, [r7, #RCC_PLLCFGR_OFFSET]

                    ldr             r0, [r7, #RCC_CR_OFFSET]
                    orrs            r0, r0, #RCC_CR_PLLON
                    str             r0, [r7, #RCC_CR_OFFSET]
0:
                    ldr             r0, [r7, #RCC_CR_OFFSET]
                    tst             r0, #RCC_CR_PLLRDY
                    bne             0b

                    ldr             r0, [r7, #RCC_CFGR_OFFSET]      @ Set the PLL as the clock source
                    orrs            r0, r0, #RCC_CFGR_SW_PLL
                    str             r0, [r7, #RCC_CFGR_OFFSET]
0:
                    ldr             r0, [r7, #RCC_CFGR_OFFSET]
                    tst             r0, #RCC_CFGR_SWS_PLL
                    bne             0b

                    ldr             r0, [r7, #RCC_CFGR_OFFSET]      @ Set AHB Prescaler/APB1 Prescaler/APB2 Prescaler
                    ldr             r1, =#(RCC_CFGR_HPRE_Msk | RCC_CFGR_PPRE1_Msk | RCC_CFGR_PPRE2_Msk)
                    bics            r0, r0, r1
                    orrs            r0, r0, #(RCC_CFGR_HPRE_DIV1 | RCC_CFGR_PPRE1_DIV1 | RCC_CFGR_PPRE2_DIV1)
                    str             r0, [r7, #RCC_CFGR_OFFSET]

                    bl              System_coreClockUpdate          @ Update system core clock
                    ldr             r0, =#System_coreClock
                    ldr             r0, [r0]
                    bl              MsCounter_init
                    pop             {r7, pc}

    .end
