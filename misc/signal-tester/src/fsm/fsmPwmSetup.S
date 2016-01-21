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
    .extern         FsmCommon_showInstructions                      @ show instructions
    .extern         FsmCommon_anyKeyPressed                         @ check if any key pressed

    private_data(FsmPwmSetup_privateData)

INST_DELAY  = (2 * 1000) / MAINLOOP_DELAY                           @ how long to show the instructions for
PWM_ARR     = 23999                                                 @ ARR value for frequency of 2khz

FsmPwmSetup_displayCount:
                    .short          INST_DELAY                      @ show instructions counter
FsmPwmSetup_currentInstruction:
                    .short          0
FsmPwmSetup_convertBuffer:
                    .string         "     "                         @ buffer for integer conversion

    static_data(FsmPwmSetup_const)

FsmPwmSetup_const:

title:              .string         "PWM LED Setup & Test"
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
                    bl              Display_clearDisplayBuffer      @ display title
                    movs            r0, #DISPLAY_CENTER_ALIGN
                    ldr             r1, = #(0 | DISPLAY_ROW)
                    movs            r2, #1
                    ldr             r3, = #title
                    bl              Display_drawAlignedString

                    ldr             r0, = #instructionTable         @ show the instructions
                    movs            r1, #(instructionTableEnd-instructionTable)
                    ldr             r2, = #FsmPwmSetup_setupPwm
                    bl              FsmCommon_showInstructions
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

                    ldr             r2, = #TIM3_BASE                @ setup TIMER3 to be PWM with output of OC4
                    ldr             r0, = #(TIM_CCMR2_OC4FE | TIM_CCMR2_OC4PE | TIM_CCMR2_OC4M_1 | TIM_CCMR2_OC4M_2)
                    str             r0, [r2, #TIM_CCMR2_OFFSET]
                    ldr             r0, = #(TIM_CCER_CC4E)
                    str             r0, [r2, #TIM_CCER_OFFSET]
                    ldr             r0, = #PWM_ARR
                    str             r0, [r2, #TIM_ARR_OFFSET]
                    movs            r0, #TIM_CR1_CEN                @ enable the timer...
                    str             r0, [r2, #TIM_CR1_OFFSET]

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
                    push            {r2, r3}
                    bl              FsmPwmSetup_adjustPwmFromValue  @ adjust pwm value and display %-age
                    pop             {r2, r3}
0:
                    movs            r1, r3                          @ check if any button pressed
                    ldr             r0, = #FsmMenus_initMainMenu
                    bl              FsmCommon_anyKeyPressed

                    ldr             r2, = #TIM3_BASE                @ stop TIMER3
                    movs            r1, #0
                    str             r1, [r2, #TIM_CR1_OFFSET]
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

                    ldr             r2, = #TIM3_BASE                @ adjust PWM value for Timer3:OC4
                    ldr             r0, = #PWM_ARR
                    muls            r0, r0, r7
                    lsrs            r0, r0, #12
                    str             r0, [r2, #TIM_CCR4_OFFSET]
                    pop             {r7, pc}

    .end
