/*
 * Copyright (c) 2015 The NW1 Group
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#include "moduleInfo.inc"

@ Finite State Machine functions simple PWM of LED connected to output and ground

    module(FsmPwmSetup)

    .extern         Display_drawAlignedString                       @ draw a aligned single line characters
    .extern         Display_blitDisplayBuffer                       @ draw the display buffer onto the display
    .extern         Display_clearDisplayBuffer                      @ clear the display buffer
    .extern         Display_drawFilledRectangle                     @ draw a filled rectangle

    private_data(FsmPwmSetup_privateData)

INST_DELAY = (2 * 1000) / MAINLOOP_DELAY

FsmPwmSetup_displayCount:
                    .short          INST_DELAY                      @ show instructions counter
FsmPwmSetup_currentInstruction:
                    .short          0

    static_data(FsmPwmSetup_const)

FsmPwmSetup_const:

title:              .string         "PWM LED Setup & Test "
instructions1:      .string         "Connect a LED and resistor"
instructions2:      .string         "between SIG and GND, and use"
instructions3:      .string         "RED to adjust the duty cycle"
instructions4:      .string         "Click any button to quit"
dutyCycle:          .string         "Duty Cycle: "

                    .balign         4                               @ align these data structures to 4 byte boundary
                    .align          4

instructionTable:
                    .int            instructions1, instructions2
                    .int            instructions3, instructions4
instructionTableEnd:

    public_function(FsmPwmSetup_initPwmSetup)

@ int FsmPwmSetup_initPwmSetup(short redValue, short blueValue, short greenValue, int buttonsAndStatus)
@   FSM Routine for the PWM LED Setup routines. Returns the next state, or 0 to remain in the same state

FsmPwmSetup_initPwmSetup:
                    push            {r7, lr}
                    ldr             r0, = #instructions1
                    bl              FsmPwmSetup_showInstruction
                    ldr             r0, = #FsmPwmSetup_instructionTimeout
                    pop             {r7, pc}

    private_function(FsmPwmSetup_showInstruction)

@ void FsmPwmSetup_showInstruction(char* text)
@   show instruction text on the display for INST_DELAY

FsmPwmSetup_showInstruction:
                    push            {r7, lr}
                    movs            r7, r0                          @ save off r0
                    bl              Display_clearDisplayBuffer
                    movs            r0, #DISPLAY_CENTER_ALIGN
                    ldr             r1, = #(0 | DISPLAY_ROW)
                    movs            r2, #1
                    ldr             r3, = #title
                    bl              Display_drawAlignedString
                    movs            r0, #0
                    ldr             r1, = #(1 | DISPLAY_ROW)
                    movs            r2, #1
                    movs            r3, r7
                    bl              Display_drawString
                    bl              Display_blitDisplayBuffer
                    ldr             r0, = #FsmPwmSetup_displayCount @ reset delay
                    ldr             r1, = #INST_DELAY
                    strh            r1, [r0]
                    pop             {r7, pc}

    private_function(FsmPwmSetup_instructionTimeout)

@ int FsmPwmSetup_instructionTimeout(short redValue, short blueValue, short greenValue, int buttonsAndStatus)
@   FSM Routine for showing the instructions. Returns the next state, or 0 to remain in the same state

FsmPwmSetup_instructionTimeout:
                    push            {r7, lr}
                    ldr             r0, = #FsmPwmSetup_displayCount
                    ldrh            r1, [r0]
                    subs            r1, r1, #1
                    beq             0f
                    strh            r1, [r0]
                    movs            r0, #0
                    b               9f
0:
                    ldrh            r1, [r0, #2]
                    adds            r1, r1, #4
                    cmp             r1, #(instructionTableEnd-instructionTable)
                    beq             1f
                    strh            r1, [r0, #2]
                    ldr             r0, = #instructionTable
                    ldr             r0, [r0, r1]
                    bl              FsmPwmSetup_showInstruction
                    movs            r0, #0
                    b               9f
1:
                    ldr             r0, = #FsmPwmSetup_setupPwm
9:
                    pop             {r7, pc}

    private_function(FsmPwmSetup_setupPwm)

@ int FsmPwmSetup_instructionTimeout(short redValue, short blueValue, short greenValue, int buttonsAndStatus)
@   FSM Routine setting up the PWM timer. Returns the next state, or 0 to remain in the same state

FsmPwmSetup_setupPwm:
                    push            {r7, lr}
                    movs            r0, #0
                    ldr             r1, = #(1 | DISPLAY_ROW)
                    movs            r2, #0
                    movs            r3, #DISPLAY_WIDTH
                    bl              Display_fillRow
                    movs            r0, #0
                    ldr             r1, = #(1 | DISPLAY_ROW)
                    movs            r2, #1
                    ldr             r3, = #dutyCycle
                    bl              Display_drawString
                    bl              Display_blitDisplayBuffer

    @ setup timer 3 for pwm

                    ldr             r0, = #0
                    pop             {r7, pc}

    .end
