/*
 * Copyright (c) 2015 The NW1 Group
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#include "moduleInfo.inc"

/*
 * Enable low power mode when the EN pin is brought high. This configures
 * the external interrupt for this pin, QUADIR_EN_GPIOBASE/QUADIR_EN and
 * the low power features of the microcontroller
 *
 */

    module(LowPower)

    private_data(LowPower_private)

LowPower_canStop:
                    .word           0                               @ flag to indicate we can enter stop mode

    public_function(LowPower_init)

@ void LowPower_init()
@   Setup the external interrupt, GPIO and STOP modes on the processor

LowPower_init:

__lpower_powerSave:
                    push            {r7, lr}
                    ldr             r2, = #PWR_BASE                 @ enable STOP mode when going into sleep
                    ldr             r0, [r2, #PWR_CR_OFFSET]
                    movs            r1, #PWR_CR_PDDS | PWR_CR_LPDS
                    bics            r0, r0, r1
                    movs            r1, #PWR_CR_LPDS
                    orrs            r0, r0, r1
                    str             r0, [r2, #PWR_CR_OFFSET]

                    ldr             r2, = #SCB_SCR
                    ldr             r0, [r2]
                    movs            r1, #1 << SCB_SCR_SLEEPDEEP_Pos
                    orrs            r0, r0, r1
                    str             r0, [r2]
__lpower_enablePin:
                    ldr             r2, = #QUADIR_EN_GPIOBASE       @ enable pullup on QUADIR_EN
                    ldr             r0, [r2, #GPIO_PUPDR_OFFSET]
                    movs            r1, #1<<(QUADIR_EN<<1)
                    orrs            r0, r0, r1
                    str             r0, [r2, #GPIO_PUPDR_OFFSET]
                    ldr             r3, [r2, #GPIO_IDR_OFFSET]      @ grab current input value

                    ldr             r2, = #SYSCFG_BASE              @ enable external interrupt for QUADIR_EN
                    ldr             r0, [r2, #QUADIR_EN_EXTICR]
                    movs            r1, #QUADIR_EN_EXTICR_MASK
                    bics            r0, r0, r1
                    movs            r1, #QUADIR_EN_EXTICR_VALUE
                    orrs            r0, r0, r1
                    str             r0, [r2, #QUADIR_EN_EXTICR]

                    ldr             r2, = #EXTI_BASE
                    ldr             r0, [r2, #EXTI_IMR_OFFSET]
                    movs            r1, #1<<QUADIR_EN_IMR
                    orrs            r0, r0, r1
                    str             r0, [r2, #EXTI_IMR_OFFSET]

                    movs            r0, #1<<QUADIR_EN_IMR
                    movs            r1, #1<<QUADIR_EN               @ if current value is low, then look for rising
                    tst             r3, r1                          @ edges to trigger interrupt, otherwise look for
                    beq             0f                              @ a falling edge
                    ldr             r1, [r2, #EXTI_FTSR_OFFSET]
                    orrs            r0, r0, r1
                    str             r0, [r2, #EXTI_FTSR_OFFSET]
                    b               1f
0:
                    ldr             r1, [r2, #EXTI_RTSR_OFFSET]
                    orrs            r0, r0, r1
                    str             r0, [r2, #EXTI_RTSR_OFFSET]
1:
                    movs            r0, #QUADIR_EN_IRQn             @ enable EXTI interrupts
                    bl              NVIC_enableIRQ
                    pop             {r7, pc}

    public_function(LowPower_enterStop)

@ void LowPower_enterStop(void)
@   set the flag to indicate we can enter stop mode

LowPower_enterStop:
                    ldr             r0, =#LowPower_canStop
                    movs            r1, #1
                    str             r1, [r0]
                    bx              lr

    public_function(LowPower_checkEnterStop)

@ void LowPower_checkEnterStop(void)
@   checks if stop mode/low power mode has been requested, and enters low power mode/stop if it has. Function doesn't
@   return if low power mode has been entered

LowPower_checkEnterStop:
                    push            {r7, lr}
                    ldr             r2, = #LowPower_canStop
                    cpsid           i                               @ disable interrupts
                    ldr             r0, [r2]
                    cmp             r0, #0                          @ if canStop is 0, then just return, after enabling
                    beq             0f                              @ interrupts
                    movs            r0, #0                          @ otherwise reset flag
                    str             r0, [r2]
                    cpsie           i                               @ enable interrupts
                    isb
                    wfi                                             @ go to sleep/stop
                    pop             {r7, pc}
0:
                    cpsie           i                               @ enable interrupts
                    isb
                    pop             {r7, pc}

    public_function(LowPower_getEnablePinState)

@ bool LowPower_getEnablePinState(void)
@   get the enable pin state, 0 pin is low (enable), 1 pin is high (disable/low power)

LowPower_getEnablePinState:
                    ldr             r2, = #QUADIR_EN_GPIOBASE
                    ldr             r0, [r2, #GPIO_IDR_OFFSET]
                    movs            r1, #1<<QUADIR_EN
                    ands            r0, r1
#if QUADIR_EN > 0
                    lsrs            r0, #(QUADIR_EN-1)
#endif
                    bx              lr

    public_function(QUADIR_EN_ISR)

@ void QUADIR_EN_ISR(void)
@   ISR to handle when enable pin goes low or high

QUADIR_EN_ISR:
                    push            {r7, lr}
                    ldr             r2, = #EXTI_BASE                @ clear EXTI pending register
                    movs            r1, #1<<QUADIR_EN_IMR
                    str             r1, [r2, #EXTI_PR_OFFSET]

                    ldr             r3, = #QUADIR_EN_GPIOBASE       @ was the pin brought low, or high
                    ldr             r0, [r3, #GPIO_IDR_OFFSET]
                    movs            r3, #1<<QUADIR_EN
                    tst             r0, r3
                    beq             0f
                                                                    @ pin brough high
                    ldr             r0, [r2, #EXTI_FTSR_OFFSET]
                    bics            r0, r0, r1
                    str             r0, [r2, #EXTI_FTSR_OFFSET]
                    ldr             r0, [r2, #EXTI_RTSR_OFFSET]
                    orrs            r0, r0, r1
                    str             r0, [r2, #EXTI_RTSR_OFFSET]
                    bl              Detect_stop
                    bl              LowPower_enterStop

0:                                                                  @ pin brought low
                    ldr             r0, [r2, #EXTI_RTSR_OFFSET]
                    bics            r0, r0, r1
                    str             r0, [r2, #EXTI_RTSR_OFFSET]
                    ldr             r0, [r2, #EXTI_FTSR_OFFSET]
                    orrs            r0, r0, r1
                    str             r0, [r2, #EXTI_FTSR_OFFSET]
                    bl              Detect_start
1:
                    movs            r0, #QUADIR_EN_IRQn             @ clear any pending EXTI interrupts
                    bl              NVIC_clearPendingIRQ
                    pop             {r7, pc}

    .end
