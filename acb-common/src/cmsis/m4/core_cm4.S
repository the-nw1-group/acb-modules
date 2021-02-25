@ Manually extracted functions from core_cm4.h file

/**************************************************************************//**
 * @file     core_cm4.h
 * @brief    CMSIS Cortex-M4 Core Peripheral Access Layer Header File
 * @version  V4.00
 * @date     22. August 2014
 *
 * @note
 *
 ******************************************************************************/
/* Copyright (c) 2009 - 2014 ARM LIMITED

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
   IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
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

#ifdef __CORE_CM4_GENERIC

    module(core_cm4)

    public_function(NVIC_systemReset)

@ void NVIC_systemReset(void)
@   this function initiates a system reset request to reset the MCU.

NVIC_systemReset:
                                                                    @ no need to save r6 or r7 as this function never returns

                    dsb                                             @ Ensure all outstanding memory accesses included buffered write are completed before reset
                    ldr             r6, = #SCB_AIRCR
                    ldr             r0, [r6]                        @ Keep priority group unchanged
                    movs            r1, #SCB_AIRCR_PRIGROUP_Msk
                    orrs            r0, r0, r1
                    ldr             r7, = #((0x5FA << SCB_AIRCR_VECTKEY_Pos) | SCB_AIRCR_SYSRESETREQ_Msk)
                    orrs            r7, r7, r0
                    str             r7, [r6]
                    dsb                                             @ Ensure completion of memory access
                    b               .                               @ wait until reset

    public_function(NVIC_SetPriorityGrouping)

@ void NVIC_SetPriorityGrouping(uint priorityGroup)
@   the function sets the priority grouping field using the required unlock sequence.

NVIC_SetPriorityGrouping:
                    ands            r0, r0, #7                      @ only values 0..7 are used
                    ldr             r1, =#SCB_AIRCR                 @ read old register configuration
                    ldr             r2, [r1]
                    ldr             r3, =#(SCB_AIRCR_VECTKEY_Msk | SCB_AIRCR_PRIGROUP_Msk)
                    bics            r2, r2, r3                      @ clear bits to write
                    ldr             r3, =#(0x5FA << SCB_AIRCR_VECTKEY_Pos)
                    lsl             r0, r0, #8                      @ insert the write key and priority group
                    orrs            r3, r3, r0
                    orrs            r2, r2, r3
                    str             r2, [r1]
                    bx              lr

    public_function(NVIC_GetPriorityGrouping)

@ uint NVIC_GetPriorityGrouping(void)
@   the function reads the priority grouping field from the NVIC Interrupt Controller.

NVIC_GetPriorityGrouping:
                    ldr             r1, =#SCB_AIRCR
                    ldr             r0, [r1]
                    ldr             r1, =#SCB_AIRCR_PRIGROUP_Msk
                    ands            r0, r0, r1
                    lsr             r0, r0, #SCB_AIRCR_PRIGROUP_Pos
                    bx              lr

    public_function(NVIC_enableIRQ)

@ void NVIC_enableIRQ(int irq)
@   enable the interrupt for the supplied irq

NVIC_enableIRQ:
                    ands            r0, r0, #0x1F                   @ mask out possible interrupt numbers
                    movs            r1, #1
                    lsls            r1, r1, r0
                    ldr             r2, = #NVIC_ISER
                    lsrs            r3, r0, #5
                    str             r1, [r2, r3]
                    bx              lr

    public_function(NVIC_disableIRQ)

@ void NVIC_disableIRQ(int irq)
@   disable the interrupt for the supplied irq

NVIC_disableIRQ:
                    ands            r0, r0, #0x1F                   @ mask out possible interrupt numbers
                    movs            r1, #1
                    lsls            r1, r1, r0
                    ldr             r2, = #NVIC_ICER
                    lsrs            r3, r0, #5
                    str             r1, [r2, r3]
                    bx              lr

    public_function(NVIC_getPendingIRQ)

@ void NVIC_getPendingIRQ(int irq)
@   reads the pending register in the NVIC and returns the pending bit for the specified interrupt

NVIC_getPendingIRQ:
                    ands            r0, r0, #0x1F
                    movs            r1, #1
                    lsls            r1, r1, r0
                    ldr             r2, = #NVIC_ISPR
                    lsrs            r3, r0, #5
                    ldr             r0, [r2, r3]
                    tst             r0, r1
                    ite             eq
                    movseq          r0, #1
                    movsne          r0, #0
                    bx              lr

    public_function(NVIC_setPendingIRQ)

@ void NVIC_setPendingIRQ(int irq)
@   sets the pending bit of an external interrupt.

NVIC_setPendingIRQ:
                    ands            r0, r0, #0x1F                   @ mask out possible interrupt numbers
                    movs            r1, #1
                    lsls            r1, r1, r0
                    ldr             r2, = #NVIC_ISPR
                    lsrs            r3, r0, #5
                    str             r1, [r2, r3]
                    bx              lr

    public_function(NVIC_clearPendingIRQ)

@ void NVIC_clearPendingIRQ(int irq)
@   clears the pending bit of an external interrupt.

NVIC_clearPendingIRQ:
                    ands            r0, r0, #0x1F                   @ mask out possible interrupt numbers
                    movs            r1, #1
                    lsls            r1, r1, r0
                    ldr             r2, = #NVIC_ICPR
                    lsrs            r3, r0, #5
                    str             r1, [r2, r3]
                    bx              lr

    public_function(NVIC_GetActive)

@ uint NVIC_GetActive(int irq)
@   the function reads the active register in NVIC and returns the active bit.

NVIC_GetActive:
                    ands            r0, r0, #0x1F
                    movs            r1, #1
                    lsls            r1, r1, r0
                    ldr             r2, = #NVIC_IABR
                    lsrs            r3, r0, #5
                    ldr             r0, [r2, r3]
                    tst             r0, r1
                    ite             eq
                    movseq          r0, #1
                    movsne          r0, #0
                    bx              lr

    public_function(NVIC_setPriority)

@ void NVIC_setPriority(int irq, uint priority)
@   this function sets the priority of an interrupt. The priority cannot be set for every core interrupt.

NVIC_setPriority:
                    lsls            r1, r1, #(8-__NVIC_PRIO_BITS) & 0xFF
                    cmp             r0, #0
                    blt             0f
                    ldr             r2, =#NVIC_IP                   @ set Priority for device specific Interrupts
                    strb            r1, [r2, r0]
                    bx              lr
0:                                                                  @ set Priority for Cortex-M  System Interrupts
                    ands            r0, r0, #0x0F                   @ Mask only the bottom 4 bits
                    subs            r0, r0, #4
                    ldr             r2, =#SCB_SHP
                    strb            r1, [r2, r0]
                    bx              lr

    public_function(NVIC_GetPriority)

@ uint NVIC_GetPriority(int irq)
@   the function reads the priority of an interrupt. The interrupt number can be positive to specify an
@   external (device specific) interrupt, or negative to specify an internal (core) interrupt.

NVIC_GetPriority:
                    cmp             r0, #0
                    blt             0f
                    ldr             r2, =#NVIC_IP
                    ldrb            r0, [r2, r0]
1:
                    lsrs            r0, r0, #(8 - __NVIC_PRIO_BITS)
                    bx              lr
0:                                                                  @ get priority for Cortex-M  system interrupts
                    ands            r0, r0, #0x0F                   @ Mask only the bottom 4 bits
                    subs            r0, r0, #4
                    ldr             r2, =#SCB_SHP
                    ldrb            r0, [r2, r0]
                    b               1b

    public_function(NVIC_EncodePriority)

@ uint NVIC_EncodePriority(uint priorityGroup, uint preemptPriority, uint subPriority)
@   the function encodes the priority for an interrupt with the given priority group, preemptive priority value, and subpriority value.
NVIC_EncodePriority:
                    push            {r7, lr}
                    ands            r0, r0, #7
                    rsbs            r3, r0, #7
                    cmp             r3, #__NVIC_PRIO_BITS
                    ite             gt
                    movsgt          r3, #__NVIC_PRIO_BITS
                    nople
                    adds            r7, r0, #__NVIC_PRIO_BITS
                    cmp             r7, #7
                    ite             lt
                    movslt          r7, #0
                    addsge          r7, r0, #(7-__NVIC_PRIO_BITS)

                    movs            r0, #1
                    lsls            r0, r1, r3
                    subs            r0, r0, #1
                    ands            r3, r3, r0
                    lsls            r3, r3, r7

                    movs            r0, #1
                    lsls            r0, r0, r7
                    subs            r0, r0, #1
                    lsls            r0, r2, r0
                    orrs            r0, r0, r3
                    pop             {r7, pc}

    public_function(NVIC_DecodePriority)

@ void NVIC_DecodePriority(uint priority, uint priorityGroup, uint* pPreemptPriority, unit* pSubPriority)
@   the function decodes an interrupt priority value with a given priority group to preemptive priority value and subpriority value.

NVIC_DecodePriority:
                    push            {r5-r7, lr}
                    ands            r1, r1, #7
                    rsbs            r5, r1, #7
                    cmp             r5, #__NVIC_PRIO_BITS
                    ite             gt
                    movsgt          r5, #__NVIC_PRIO_BITS
                    nople
                    adds            r7, r1, #__NVIC_PRIO_BITS
                    cmp             r7, #7
                    ite             lt
                    movslt          r7, #0
                    addsge          r7, r1, #(7-__NVIC_PRIO_BITS)

                    lsrs            r1, r0, r7
                    movs            r4, #1
                    lsls            r4, r4, r5
                    subs            r4, r4, #1
                    ands            r1, r1, r4
                    str             r1, [r2]

                    movs            r4, #1
                    lsls            r4, r4, r7
                    subs            r4, r4, #1
                    ands            r0, r0, r4
                    str             r0, [r3]
                    pop             {r5-r7, pc}

    public_function(SysTick_config)

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
