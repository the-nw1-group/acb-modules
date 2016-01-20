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
    .extern         Display_fillRow                                 @ fill a row in the display buffer
    .extern         Display_drawString                              @ draw a string into the display buffer
    .extern         FsmMenus_initMainMenu                           @ init and show the main menu

    private_data(FsmPwmSetup_privateData)

INST_DELAY = (2 * 1000) / MAINLOOP_DELAY

FsmPwmSetup_displayCount:
                    .short          INST_DELAY                      @ show instructions counter
FsmPwmSetup_currentInstruction:
                    .short          0
FsmPwmSetup_convertBuffer:
                    .string         "     "                         @ buffer for integer conversion

    static_data(FsmPwmSetup_const)

FsmPwmSetup_const:

title:              .string         "PWM LED Setup & Test "
instructions1:      .string         "Connect a LED and resistor"
instructions2:      .string         "between SIG and GND, and use"
instructions3:      .string         "RED to adjust the duty cycle"
instructions4:      .string         "Click any button to go back"
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
                    movs            r0, #0
                    ldr             r1, = #FsmPwmSetup_currentInstruction
                    strh            r0, [r1]
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
                    movs            r7, r0                          @ save off the redValue for later
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

                    movs            r0, r7
                    bl              FsmPwmSetup_adjustPwmFromValue  @ adjust pwm value and display %-age
                    ldr             r0, = #FsmPwmSetup_adjustPwm
                    pop             {r7, pc}

    private_function(FsmPwmSetup_adjustPwm)

@ int FsmPwmSetup_adjustPwm(short redValue, short blueValue, short greenValue, int buttonsAndStatus)
@   FSM Routine adjusting the PWM timer based on Red. Returns the next state, or 0 to remain in the same state

FsmPwmSetup_adjustPwm:
                    push            {r7, lr}
                    movs            r1, #FSM_STATE_ANALOG_CHANGED   @ if the analog state hasn't changed, then
                    rev16           r2, r3                          @ just check for any button press
                    tst             r1, r2
                    beq             0f
                    movs            r7, r2
                    bl              FsmPwmSetup_adjustPwmFromValue  @ adjust pwm value and display %-age
                    movs            r2, r7
0:
                    movs            r1, #FSM_STATE_BUTTONS_CHANGED  @ has a button state changed?
                    tst             r1, r2
                    beq             8f                              @ no, just return
                    movs            r1, #FSM_BUTTON_MASK
                    tst             r1, r3                          @ was it a button pressed?
                    beq             8f                              @ no, just return
                    ldr             r0, = #FsmMenus_initMainMenu    @ otherwise return to the main menu

    @ stop timer 3

                    b               9f
8:
                    movs            r0, #0
9:
                    pop             {r7, pc}

    private_function(FsmPwmSetup_adjustPwmFromValue)

@ void FsmPwmSetup_adjustPwmFromValue(short pwmValue)
@   display the pwm value on the display, and adjust timer 3 value to the pwmValue

FsmPwmSetup_adjustPwmFromValue:

drawValueOffset=50

                    push            {r7, lr}
                    movs            r7, r0                          @ save r0 for later
                    movs            r1, #100                        @ calculate PWM as a percentage
                    muls            r1, r1, r0
                    lsrs            r0, r1, #12                     @ analog range is 12 bits
                    ldr             r1, = #FsmPwmSetup_convertBuffer
                    movs            r2, #10                         @ convert to base 10
                    bl              itoa
0:                                                                  @ add %<NULL> to the end of the returned string
                    ldrb            r1, [r0]
                    cmp             r1, #0
                    beq             1f
                    adds            r0, r0, #1
                    b               0b
1:
                    movs            r1, #'%'
                    strb            r1, [r0]
                    adds            r0, r0, #1
                    movs            r1, #0
                    strb            r1, [r0]

                    movs            r0, #drawValueOffset            @ blank previous values
                    ldr             r1, = #(1 | DISPLAY_ROW)
                    movs            r2, #0
                    sub             sp, sp, #8
                    movs            r3, #DISPLAY_HEIGHT
                    str             r3, [sp]
                    movs            r3, #(DISPLAY_WIDTH - drawValueOffset)
                    bl              Display_drawFilledRectangle
                    add             sp, sp, #8
                    movs            r0, #drawValueOffset            @ write new percentage value on the display
                    ldr             r1, = #(1 | DISPLAY_ROW)
                    movs            r2, #1
                    ldr             r3, = #FsmPwmSetup_convertBuffer
                    bl              Display_drawString
                    bl              Display_blitDisplayBuffer

    @ set pwm value for timer 3

                    pop             {r7, pc}

    .end
