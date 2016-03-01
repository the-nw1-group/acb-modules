/*
 * Copyright (c) 2015 The NW1 Group
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#include "moduleInfo.inc"

@ Finite State Machine functions to test a number of RGB LEDs with Aspect colours

    module(FsmAspectTest)

    .extern         Display_drawAlignedString                       @ draw a aligned single line characters
    .extern         Display_blitDisplayBuffer                       @ draw the display buffer onto the display
    .extern         Display_clearDisplayBuffer                      @ clear the display buffer
    .extern         Display_drawFilledRectangle                     @ draw a filled rectangle
    .extern         Display_fillRow                                 @ fill a row in the display buffer
    .extern         Display_drawString                              @ draw a string into the display buffer
    .extern         FsmMenus_initSignalTestMenu                     @ show the signal test menu
    .extern         FsmCommon_showInstructions                      @ show instructions

    private_data(FsmAspectTest_privateData)

FsmWhiteTest_convertBuffer:
                    .string         "    "                          @ buffer for integer conversion
FsmAspectTest_aspectType:
                    .byte           0

    static_data(FsmAspectTest_const)

FsmAspectTest_const:

title:              .string         "RGB LED Aspect Test"
instructions1:      .string         "Connect the RGB LED module to"
instructions2:      .string         "the connector, ensuring you"
instructions3:      .string         "have the connections the"
instructions4:      .string         "correct way around."
instructions5:      .string         "Use RED to adjust the number"
instructions6:      .string         "and types of aspects to test,"
instructions7:      .string         "then use the Action button to"
instructions8:      .string         "test the LEDs. Use Back or Next"
instructions9:      .string         "to return to the last menu."
aspects:            .string         "Aspects: "

aspect0:            .string         "1 Aspect   [R]"                @ the aspects and types (yes they do all line
aspect1:            .string         "2 Aspects [RG]"                @ up on the display
aspect2:            .string         "2 Aspects [YG]"
aspect3:            .string         "3 Aspects [RYG]"
aspect4:            .string         "4 Aspects [RYGD]"
aspect5:            .string         "1 Aspect   [Y]"
aspect6:            .string         "1 Aspect   [G]"
aspect7:            .string         "1 Aspect   [W]"

                    .balign         4                               @ align these data structures to 4 byte boundary
                    .align          4

instructionTable:
                    .int            instructions1,  instructions2
                    .int            instructions3,  instructions4
                    .int            instructions5,  instructions6
                    .int            instructions7,  instructions8
                    .int            instructions9
instructionTableEnd:

aspectTable:
                    .int            aspect0, aspect1, aspect2, aspect3
                    .int            aspect4, aspect5, aspect6, aspect7

    public_function(FsmAspectTest_initAspectTest)

@ int FsmAspectTest_initAspectTest(short redValue, short blueValue, short greenValue, int buttonsAndStatus)
@   FSM Routine for the Servo Setup routines. Returns the next state, or 0 to remain in the same state

FsmAspectTest_initAspectTest:
                    push            {r7, lr}
                    bl              Display_clearDisplayBuffer      @ display title
                    movs            r0, #DISPLAY_CENTER_ALIGN
                    ldr             r1, = #(0 | DISPLAY_ROW)
                    movs            r2, #1
                    ldr             r3, = #title
                    bl              Display_drawAlignedString

                    ldr             r0, = #instructionTable         @ show the instructions
                    movs            r1, #(instructionTableEnd-instructionTable)
                    ldr             r2, = #FsmAspectTest_setupAspectTest
                    bl              FsmCommon_showInstructions
                    pop             {r7, pc}

    private_function(FsmAspectTest_setupAspectTest)

@ int FsmAspectTest_setupAspectTest(short redValue, short blueValue, short greenValue, int buttonsAndStatus)
@   FSM Routine setting up the white test. Returns the next state, or 0 to remain in the same state

FsmAspectTest_setupAspectTest:
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
                    ldr             r3, = #aspects
                    bl              Display_drawString
                    bl              Display_blitDisplayBuffer

/*
                    ldr             r2, = #TIM3_BASE                @ setup TIMER3 to be PWM with output of OC4
                    ldr             r0, = #(TIM_CCMR2_OC4FE | TIM_CCMR2_OC4PE | TIM_CCMR2_OC4M_1 | TIM_CCMR2_OC4M_2)
                    str             r0, [r2, #TIM_CCMR2_OFFSET]
                    ldr             r0, = #(TIM_CCER_CC4E)
                    str             r0, [r2, #TIM_CCER_OFFSET]
                    ldr             r0, = #PWM_ARR
                    str             r0, [r2, #TIM_ARR_OFFSET]
                    movs            r0, #0                          @ 0 prescale
                    str             r0, [r2, #TIM_PSC_OFFSET]
                    movs            r0, #TIM_CR1_CEN                @ enable the timer...
                    str             r0, [r2, #TIM_CR1_OFFSET]
*/
                    movs            r0, r7
                    bl              FsmAspectTest_displayAspects    @ adjust number of Aspects and Type
                    ldr             r0, = #FsmAspectTest_adjustAspects
                    pop             {r7, pc}

    private_function(FsmAspectTest_adjustAspects)

@ int FsmAspectTest_adjustAspects(short redValue, short blueValue, short greenValue, int buttonsAndStatus)
@   FSM Routine adjusting the PWM timer based on Red. Returns the next state, or 0 to remain in the same state

FsmAspectTest_adjustAspects:
                    push            {r5-r7, lr}
                    movs            r5, #FSM_STATE_ANALOG_CHANGED   @ if the analog state hasn't changed, then
                    rev16           r6, r3                          @ just check for any button press
                    tst             r5, r6
                    beq             0f
                    movs            r7, r3
                    bl              FsmAspectTest_displayAspects    @ set and display aspects and type
                    movs            r3, r7
0:
                    movs            r5, #FSM_STATE_BUTTONS_CHANGED  @ if the digital state hasn't changed, then
                    tst             r5, r6                          @ just return
                    beq             8f
                    movs            r5, #(FSM_BUTTON_LEFT | FSM_BUTTON_RIGHT) @ Left/Back pressed, or Next/Forward
                    tst             r3, r5
                    beq             1f
                    ldr             r0, = #FsmMenus_initSignalTestMenu @ yes, return to the last menu
                    b               9f
1:
                    movs            r5, #FSM_BUTTON_ACTION          @ action button pressed?
                    tst             r3, r5
                    beq             8f
                    ldr             r0, = #0 @ FsmServoSetup_runServo   @ yes, test the LEDs
                    b               9f
8:
                    movs            r0, #0
9:
                    pop             {r5-r7, pc}

    private_function(FsmAspectTest_displayAspects)

@ void FsmAspectTest_displayAspects(short pwmValue)
@   display the number of leds on the display

FsmAspectTest_displayAspects:

drawValueOffset=35

                    push            {r7, lr}
                    lsrs            r0, r0, #9                      @ support 8 types of aspects
                    ldr             r1, = #FsmAspectTest_aspectType
                    strb            r0, [r1]
                    ldr             r1, = #aspectTable
                    lsls            r0, r0, #2
                    ldr             r7, [r1, r0]

                    movs            r0, #drawValueOffset            @ blank previous values
                    ldr             r1, = #(1 | DISPLAY_ROW)
                    movs            r2, #0
                    sub             sp, sp, #8
                    movs            r3, #DISPLAY_HEIGHT
                    str             r3, [sp]
                    movs            r3, #(DISPLAY_WIDTH - drawValueOffset)
                    bl              Display_drawFilledRectangle
                    add             sp, sp, #8
                    movs            r0, #drawValueOffset            @ write new aspect and type
                    ldr             r1, = #(1 | DISPLAY_ROW)
                    movs            r2, #1
                    movs            r3, r7
                    bl              Display_drawString
                    bl              Display_blitDisplayBuffer
                    pop             {r7, pc}

       .end
