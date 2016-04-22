/*
 * Copyright (c) 2015 The NW1 Group
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#include "moduleInfo.inc"

@ Common Finite State Machine functions

    module(FsmCommon)

    .extern         Setup_setup                                     @ setup hardware and peripherals
    .extern         Display_drawAlignedString                       @ draw a aligned single line characters
    .extern         Display_blitDisplayBuffer                       @ draw the display buffer onto the display
    .extern         Display_fillRow                                 @ fill a row in the display buffer
    .extern         Display_drawString                              @ draw a string into the display buffer
    .extern         NVIC_disableIRQ                                 @ disable interrupt
    .extern         NVIC_enableIRQ                                  @ enable interrupt

    private_data(FsmCommon_private)

INSTRUCTION_DELAY  = (2 * 1000) / MAINLOOP_DELAY                    @ how long to show the instructions for


Fsm_state:          .int            FsmCommon_showSplash            @ Current FSM State
FsmCommon_splashCount:
                    .int            INSTRUCTION_DELAY               @ show splash screen for 2s

FsmCommon_instructionTablePtr:                                      @ data for the instruction table
                    .int            0
FsmCommon_afterInstructionsState:
                    .int            0
FsmCommon_displayCount:
                    .short          INSTRUCTION_DELAY
FsmCommon_currentInstruction:
                    .byte           0
FsmCommon_maxInstructions:
                    .byte           0

FsmCommon_timer3Isr:
                    .int            0
FsmCommon_dma23Isr:
                    .int            0

FsmCommon_delayNext:
                    .int            0
FsmCommon_delayCount:
                    .short          0

    static_data(FsmCommon_const)

FsmCommon_const:
FsmCommon_title:
welcome:            .string         "Signal / Servo Tester"
version:            .string         "Version 1.00"

                    .global         FsmCommon_title                 @ Application title

    public_function(FsmCommon_dispatch)

@ void FsmCommon_dispatch(short redValue, short blueValue, short greenValue, int buttonsAndStatus)
@   Dispatch message to the current state.

FsmCommon_dispatch:
                    push            {r5-r7, lr}
                    ldr             r7, = #Fsm_state                @ load the current FSM state
                    ldr             r5, [r7]
                    blx             r5                              @ call the current FSM state
                    cmp             r0, #0                          @ has the state changed?
                    beq             9f                              @ nope...
                    str             r0, [r7]                        @ otherwise store the new state
9:
                    pop             {r5-r7, pc}

    public_function(FsmCommon_showInstructions)

@ int FsmCommon_showInstructions(int* insTablePtr, byte insTableSize, int afterState)
@   Show a set of instructions as detailed in by the insTablePtr. insTableSize is the size of the
@   instruction table (no instructions * 4). The FSM transitions to the afterState after showing the instructions.
@   Returns new FSM state

FsmCommon_showInstructions:
                    push            {r7, lr}
                    ldr             r7, = #FsmCommon_instructionTablePtr
                    str             r0, [r7]                        @ store parameters into member variables
                    strb            r1, [r7, #11]
                    str             r2, [r7, #4]
                    ldr             r1, = #INSTRUCTION_DELAY        @ reset other variables
                    strh            r1, [r7, #8]
                    movs            r1, #0
                    strb            r1, [r7, #10]
                    ldr             r0, [r0]                        @ draw the first instruction
                    bl              FsmCommon_drawInstruction
                    ldr             r0, = #FsmCommon_instructionTimeout
                    pop             {r7, pc}

    public_function(FsmCommon_anyKeyPressed)

@ int FsmCommon_anyKeyPressed(int newFsmState, int buttonsAndStatus)
@   If any of the buttons have been pressed, then return the newState, otherwise return 0

FsmCommon_anyKeyPressed:
                    rev16           r2, r1
                    movs            r3, #FSM_STATE_BUTTONS_CHANGED  @ has a button state changed?
                    tst             r3, r2
                    beq             8f                              @ no, just return
                    movs            r3, #FSM_BUTTON_MASK
                    tst             r3, r1                          @ was it a button pressed?
                    beq             8f                              @ no, just return
                    bx              lr
8:
                    movs            r0, #0
                    bx              lr

    public_function(FsmCommon_enableTimer3Isr)

@ void FsmCommon_enableTimer3Isr(short interruptEnable, fn* handler)
@   Enable interrupts for timer 3, based on the interruptEnable parameter. When an interrupt occurs for timer 3
@   the handler is called.

FsmCommon_enableTimer3Isr:
                    push            {r7, lr}
                    cmp             r0, #0
                    beq             9f
                    cmp             r1, #0
                    beq             9f
                    cpsid           i                               @ disable interrupts except NMI
                    ldr             r2,  = #FsmCommon_timer3Isr     @ set the ISR
                    str             r1, [r2]
                    ldr             r2, = #TIM3_BASE                @ enable event generation from timer3
                    str             r0, [r2, #TIM_DIER_OFFSET]
                    movs            r0, #TIM3_IRQn                  @ enable the timer 3 interrupt, via NVIC
                    bl              NVIC_enableIRQ
                    cpsie           i                               @ enable interrupts
                    dsb                                             @ flush any memory writes before continuing
9:
                    pop             {r7, pc}

    public_function(FsmCommon_disableTimer3Isr)

@ void FsmCommon_disableTimer3Isr(void)
@   Disable interrupts for timer 3.

FsmCommon_disableTimer3Isr:
                    push            {r7, lr}
                    cpsid           i                               @ disable interrupts except NMI
                    movs            r0, #TIM3_IRQn                  @ disable the timer 3 interrupt, via NVIC
                    bl              NVIC_disableIRQ
                    movs            r0, #0                          @ turn off event generation from timer 3
                    ldr             r1, = #TIM3_BASE
                    str             r0, [r1, #TIM_DIER_OFFSET]
                    ldr             r1, = #FsmCommon_timer3Isr      @ clear the isr routine
                    str             r0, [r1]
                    cpsie           i                               @ enable interrupts
                    dsb                                             @ flush any memory writes before continuing
                    pop             {r7, pc}

    public_function(FsmCommon_interceptIsr)

@ void FsmCommon_interceptIsr(int irq, fn* handler)
@   Intercept a ISR. The only ISR's handled by this method is TIM3_IRQn and DMA1_Channel2_3_IRQn. This doesn't enable
@   the interrupt, so callee must still call NVIC_enableIRQ

FsmCommon_interceptIsr:
                    cmp             r0, #TIM3_IRQn
                    beq             0f
                    cmp             r0, #DMA1_Channel2_3_IRQn
                    beq             1f
                    bx              lr
0:
                    movs            r0, r1
                    b               FsmCommon_setTimer3Handler      @ tail chain call to the handler below
1:
                    movs            r0, r1
                    b               FsmCommon_setDma23Handler       @ tail chain call to the handler below

    public_function(FsmCommon_setTimer3Handler)

@ void FsmCommon_setTimer3Handler(fn* handler)
@   Set the timer 3 ISR handler

FsmCommon_setTimer3Handler:
                    ldr             r1,  = #FsmCommon_timer3Isr     @ set the ISR
                    b               FsmCommon_setHandler            @ tail chain call to the handler below

    public_function(FsmCommon_setDma23Handler)

@ void FsmCommon_setDma23Handler(fn* handler)
@   Set the timer 3 ISR handler

FsmCommon_setDma23Handler:
                    ldr             r1,  = #FsmCommon_dma23Isr      @ set the ISR
                    b               FsmCommon_setHandler            @ tail chain call to the handler below

    private_function(FsmCommon_setHandler)

@ void FsmCommon_setHandler(fn* handler, int* handlerLocation)
@   Set the handler

FsmCommon_setHandler:
                    cpsid           i                               @ disable interrupts except NMI
                    str             r0, [r1]                        @ store value
                    cpsie           i                               @ enable interrupts
                    dsb                                             @ flush any memory writes before continuing
                    bx              lr

    public_function(__tim3IRQHandler)

@ void __tim3IRQHandler(void)
@   System timer 3 ISR routine

__tim3IRQHandler:
                    ldr             r1, = #FsmCommon_timer3Isr      @ load the real ISR
                    ldr             r1, [r1]
                    cmp             r1, #0                          @ if zero, then just ignore it
                    beq             9f
                    bx              r1                              @ no need to link here, just let the real ISR
9:                                                                  @ return straight through here
                    bx              lr

    public_function(__dma1Channel23IRQHandler)

@ void __dma1Channel23IRQHandler (void)
@   DMA interrupt service routine for channel 2, and channel 3

__dma1Channel23IRQHandler:
                    ldr             r1, = #FsmCommon_dma23Isr       @ load the real ISR
                    ldr             r1, [r1]
                    cmp             r1, #0                          @ if zero, then just ignore it
                    beq             9f
                    bx              r1                              @ no need to link here, just let the real ISR
9:                                                                  @ return straight through here
                    bx              lr

    public_function(FsmCommon_showMessageFor)

@ int FsmCommon_showMessageFor(short delayFor, fn* handler, char* message)
@   show a message on the bottom row of the display and delay for delayFor * 5ms, and then set the handler as the next
@   state. Returns the next state, or 0 to remain in the same state

FsmCommon_showMessageFor:
                    push            {r0-r1, r7, lr}
                    movs            r7, r2
                    movs            r0, #0                          @ clear row
                    ldr             r1, = #(1 | DISPLAY_ROW)
                    movs            r2, #0
                    movs            r3, #DISPLAY_WIDTH
                    bl              Display_fillRow
                    movs            r0, #0
                    ldr             r1, = #(1 | DISPLAY_ROW)
                    movs            r2, #1
                    movs            r3, r7
                    bl              Display_drawString
                    bl              Display_blitDisplayBuffer
                    pop             {r0-r1}
                    bl              FsmCommon_delayFor
                    pop             {r7, pc}

    public_function(FsmCommon_delayFor)

@ int FsmCommon_delayFor(short delayFor, fn* handler)
@   delay for delayFor * 5ms, and then set the handler as the next state. Returns the next state, or 0 to remain in the
@   same state

FsmCommon_delayFor:
                    ldr             r2, = #FsmCommon_delayNext
                    str             r1, [r2]
                    strh            r0, [r2, #4]
                    ldr             r0, = #FsmCommon_delay
                    bx              lr

    private_function(FsmCommon_delay)

@ int FsmCommon_delay(short redValue, short blueValue, short greenValue, int buttonsAndStatus)
@   FSM Routine for delaying. Returns the next state, or 0 to remain in the same state

FsmCommon_delay:
                    ldr             r2, = #FsmCommon_delayNext
                    ldrh            r0, [r2, #4]
                    subs            r0, r0, #1
                    bcc             0f
                    strh            r0, [r2, #4]
                    movs            r0, #0
                    bx              lr
0:
                    ldr             r0, [r2]
                    bx              lr

    private_function(FsmCommon_instructionTimeout)

@ int FsmCommon_instructionTimeout(short redValue, short blueValue, short greenValue, int buttonsAndStatus)
@   FSM Routine for showing the instructions. Returns the next state, or 0 to remain in the same state

FsmCommon_instructionTimeout:
                    push            {r7, lr}
                    ldr             r7, = #FsmCommon_instructionTablePtr

                    ldr             r0, [r7, #4]
                    movs            r1, r3
                    bl              FsmCommon_anyKeyPressed         @ if a key is press, then skip the instructions
                    cmp             r0, #0
                    bne             9f

                    ldrh            r1, [r7, #8]
                    subs            r1, r1, #1
                    beq             0f
                    strh            r1, [r7, #8]
                    movs            r0, #0
                    b               9f
0:
                    ldrb            r1, [r7, #10]
                    ldrb            r2, [r7, #11]
                    adds            r1, r1, #4
                    cmp             r1, r2
                    beq             1f
                    strb            r1, [r7, #10]
                    ldr             r0, [r7]
                    ldr             r0, [r0, r1]
                    bl              FsmCommon_drawInstruction
                    ldr             r1, = #INSTRUCTION_DELAY        @ reset instruction delay
                    strh            r1, [r7, #8]
                    movs            r0, #0
                    b               9f
1:
                    ldr             r0, [r7, #4]
9:
                    pop             {r7, pc}

    private_function(FsmCommon_drawInstruction)

@ void FsmCommon_showInstruction(char* text)
@   show instruction text on the display

FsmCommon_drawInstruction:
                    push            {r7, lr}
                    movs            r7, r0                          @ save off r0
                    movs            r0, #0
                    ldr             r1, = #(1 | DISPLAY_ROW)
                    movs            r2, #0
                    movs            r3, #DISPLAY_WIDTH
                    bl              Display_fillRow
                    movs            r0, #0                          @ draw the text
                    ldr             r1, = #(1 | DISPLAY_ROW)
                    movs            r2, #1
                    movs            r3, r7
                    bl              Display_drawString
                    bl              Display_blitDisplayBuffer
                    pop             {r7, pc}

    private_function(FsmCommon_showSplash)

@ int FsmCommon_showSplash(short redValue, short blueValue, short greenValue, int buttonsAndStatus)
@   FSM Routine for showing the splash screen. Returns the next state, or 0 to remain in the same state

FsmCommon_showSplash:
                    push            {r7, lr}
                    movs            r0, #DISPLAY_CENTER_ALIGN
                    ldr             r1, = #(0 | DISPLAY_ROW)
                    movs            r2, #1
                    ldr             r3, = #welcome
                    bl              Display_drawAlignedString
                    movs            r0, #DISPLAY_CENTER_ALIGN
                    ldr             r1, = #(1 | DISPLAY_ROW)
                    movs            r2, #1
                    ldr             r3, = #version
                    bl              Display_drawAlignedString
                    bl              Display_blitDisplayBuffer
                    ldr             r0, = #FsmCommon_splashTimeout
                    pop             {r7, pc}

    private_function(FsmCommon_splashTimeout)

@ int FsmCommon_splashTimeout(short redValue, short blueValue, short greenValue, int buttonsAndStatus)
@   FSM Routine for showing the splash screen. Returns the next state, or 0 to remain in the same state

FsmCommon_splashTimeout:
                    ldr             r1, = #FsmCommon_splashCount
                    ldr             r0, [r1]
                    subs            r0, r0, #1
                    str             r0, [r1]
                    beq             8f
                    movs            r0, #0
                    bx              lr
8:
                    ldr             r0, = #FsmMenus_initMainMenu
                    bx              lr

    .end
