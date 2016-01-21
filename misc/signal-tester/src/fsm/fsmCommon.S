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

    static_data(FsmCommon_const)

FsmCommon_const:
FsmCommon_title:
welcome:            .string         "Signal / Servo Tester"
version:            .string         "Version 0.01"

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
