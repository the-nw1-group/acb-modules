@ Manually extracted functions from core_cm0.h file

/**************************************************************************//**
 * @file     core_cm0.h
 * @brief    CMSIS Cortex-M0 Core Peripheral Access Layer Header File
 * @version  V3.20
 * @date     25. February 2013
 *
 * @note
 *
 ******************************************************************************/
/* Copyright (c) 2009 - 2013 ARM LIMITED

   All rights reserved.
   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are met:
   - Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.
   - Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimer in the
     documentation and/or other materials provided with the distribution.
   - Neither the name of ARM nor the names of its contributors may be used
     to endorse or promote products derived from this software without
     specific prior written permission.
   *
   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
   IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICAR PURPOSE
   ARE DISCLAIMED. IN NO EVENT SHALL COPYRIGHT HOLDERS AND CONTRIBUTORS BE
   LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
   INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
   CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
   ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
   POSSIBILITY OF SUCH DAMAGE.
   ---------------------------------------------------------------------------*/

#include "moduleInfo.inc"
#include "acb/functionHeaders.inc"

#ifdef __CORE_CM0_GENERIC

    module(core_cm0)

    av_public_function(NVIC_systemReset)

@ void NVIC_systemReset(void)
@   this function initiates a system reset request to reset the MCU.

NVIC_systemReset:
                                                                    @ no need to save r6 or r7 as this function never returns

                    dsb                                             @ Ensure all outstanding memory accesses included buffered write are completed before reset
                    ldr             r6, = #SCB_AIRCR
                    ldr             r7, = #((0x5FA << SCB_AIRCR_VECTKEY_Pos) | SCB_AIRCR_SYSRESETREQ_Msk)
                    str             r7, [r6]
                    dsb                                             @ Ensure completion of memory access
                    b               .                               @ wait until reset

    av_public_function(NVIC_enableIRQ)

@ void NVIC_enableIRQ(int irq)
@   enable the interrupt for the supplied irq

NVIC_enableIRQ:
                    movs            r1, #0x1F                       @ mask out possible interrupt numbers
                    ands            r0, r0, r1
                    movs            r1, #1
                    lsls            r1, r1, r0
                    ldr             r0, = #NVIC_ISER
                    str             r1, [r0]
                    bx              lr

    av_public_function(NVIC_disableIRQ)

@ void NVIC_disableIRQ(int irq)
@   disable the interrupt for the supplied irq

NVIC_disableIRQ:
                    movs            r1, #0x1F                       @ mask out possible interrupt numbers
                    ands            r0, r0, r1
                    movs            r1, #1
                    lsls            r1, r1, r0
                    ldr             r0, = #NVIC_ICER
                    str             r1, [r0]
                    bx              lr

    av_public_function(NVIC_setPriority)

@ void NVIC_setPriority(int irq, uint priority)
@   this function sets the priority of an interrupt. The priority cannot be set for every core interrupt.

NVIC_setPriority:
                    push            {r7, lr}
                    cmp             r0, #0
                    bge             1f
                    ldr             r7, = #SCB_SHP2
                    movs            r2, r0
                    adds            r2, r2, #8
                    movs            r3, #3
                    bics            r2, r2, r3
                    adds            r7, r7, r2
                    ldr             r2, [r7]
                    ands            r0, r0, r3
                    lsls            r0, r0, #3
                    movs            r3, #0xFF
                    lsls            r3, r3, r0
                    bics            r2, r2, r3
                    lsls            r1, r1, # 8 - __NVIC_PRIO_BITS
                    lsls            r1, r1, r0
                    orrs            r2, r2, r1
                    str             r2, [r7]
                    pop             {r7, pc}
1:
                    ldr             r7, = #NVIC_IP0
                    movs            r2, #3
                    movs            r3, r0
                    bics            r3, r3, r2
                    add             r7, r7, r3
                    ldr             r2, [r7]
                    movs            r3, #3
                    ands            r0, r0, r3
                    lsls            r0, r0, #3
                    movs            r3, #0xFF
                    lsls            r3, r3, r0
                    bics            r2, r2, r3
                    lsls            r1, r1, # 8 - __NVIC_PRIO_BITS
                    lsls            r1, r1, r0
                    orrs            r2, r2, r1
                    str             r2, [r7]
                    pop             {r7, pc}

    av_public_function(SysTick_config)

@ bool SysTick_config(uint ticks)
@   the function initializes the System Timer and its interrupt, and starts the System Tick Timer.
@   Counter is in free running mode to generate periodic interrupts. Parameter is mumber of ticks between two
@   interrupts. Returns SUCCESS on success, otherwise ERROR.

SysTick_config:
                    push            {r7, lr}
                    subs            r0, r0, #1                      @ check if reload value is possible or not
                    ldr             r2, = #SysTick_LOAD_RELOAD_Msk
                    cmp             r0, r2
                    bgt             1f
                    ldr             r7, = #SysTick_BASE
                    str             r0, [r7, #SysTick_LOAD_OFFSET]
                    ldr             r0, = #SysTick_IRQn
                    movs            r1, #(1<<__NVIC_PRIO_BITS) - 1
                    bl              NVIC_setPriority
                    movs            r0, #0
                    str             r0, [r7, #SysTick_VA_OFFSET]
                    ldr             r0, = #SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_TICKINT_Msk | SysTick_CTRL_ENABLE_Msk;
                    str             r0, [r7, #SysTick_CTRL_OFFSET]
                    movs            r0, #SUCCESS
                    pop             {r7, pc}
1:
                    movs            r0, #ERROR
                    pop             {r7, pc}

#endif

    .end
