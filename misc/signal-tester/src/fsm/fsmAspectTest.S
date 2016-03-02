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
    .extern         Display_drawFilledRectangle                     @ fill a rectangle
    .extern         FsmMenus_initSignalTestMenu                     @ show the signal test menu
    .extern         FsmCommon_showInstructions                      @ show instructions
    .extern         Ws2812_init                                     @ init WS2812 driver
    .extern         Ws2812_setBufferSizes                           @ set buffer sizes for each of the channels
    .extern         Ws2812_clearBuffer                              @ clear the WS2812 buffer
    .extern         Ws2812_setColour                                @ set the colour
    .extern         Ws2812_update                                   @ display the buffer on the display
    .extern         MsCounter_alarmIn                               @ set an alarm in x milliseconds

    private_data(FsmAspectTest_privateData)

FsmAspectTest_oneAspectR:                                           @ in SRAM as these will be configurable at some
                    .int            0x00C00014, 0, 0, 0             @ point
FsmAspectTest_twoAspectRG:
                    .int            0x00C00014, 0, 0, 0
                    .int            0, 0x0000A816, 0, 0
FsmAspectTest_twoAspectYG:
                    .int            0x00B88000, 0, 0, 0
                    .int            0, 0x0000A816, 0, 0
FsmAspectTest_threeAspectRYG:
                    .int            0x00C00014, 0, 0, 0
                    .int            0, 0x00B88000, 0, 0
                    .int            0, 0, 0x0000A816, 0
FsmAspectTest_fourAspectRYGD:
                    .int            0x00C00014, 0, 0, 0
                    .int            0, 0x00B88000, 0, 0
                    .int            0, 0, 0x0000A816, 0
                    .int            0, 0x00B88000, 0, 0x00B88000
FsmAspectTest_oneAspectY:
                    .int            0x00B88000, 0, 0, 0
FsmAspectTest_oneAspectG:
                    .int            0x0000A816, 0, 0, 0
FsmAspectTest_oneAspectW:
                    .int            0x00FFFFFF, 0, 0, 0

FsmAspectTest_currentTestPtr:
                    .int            0
FsmAspectTest_currentTestLength:
                    .byte           0
FsmAspectTest_currentTestAspect:
                    .byte           0
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
waitMessage:        .string         "Testing: "

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

aspectTextTable:
                    .int            aspect0, aspect1, aspect2, aspect3
                    .int            aspect4, aspect5, aspect6, aspect7

aspectValueTable:
                    .int            FsmAspectTest_oneAspectR, 1
                    .int            FsmAspectTest_twoAspectRG, 2
                    .int            FsmAspectTest_twoAspectYG, 2
                    .int            FsmAspectTest_threeAspectRYG, 3
                    .int            FsmAspectTest_fourAspectRYGD, 4
                    .int            FsmAspectTest_oneAspectY, 1
                    .int            FsmAspectTest_oneAspectG, 1
                    .int            FsmAspectTest_oneAspectW, 1

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

                    bl              Ws2812_init                     @ set up ws2812 module here
                    movs            r0, #0                          @ set buffer sizes
                    movs            r1, #0
                    movs            r2, #0
                    movs            r3, #4
                    bl              Ws2812_setBufferSizes
                    bl              Ws2812_clearBuffer              @ and clear the buffer

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
                    ldr             r0, = #FsmAspectTest_runAspectTest @ yes, test the "aspects"
                    b               9f
8:
                    movs            r0, #0
9:
                    pop             {r5-r7, pc}

    private_function(FsmAspectTest_runAspectTest)

@ int FsmAspectTest_runAspectTest(short redValue, short blueValue, short greenValue, int buttonsAndStatus)
@   FSM Routine for running the aspect test. Returns the next state, or 0 to remain in the same state

FsmAspectTest_runAspectTest:
                    push            {r7, lr}
                    movs            r0, #0                          @ display a line to the user that we are testing
                    ldr             r1, = #(1 | DISPLAY_ROW)        @ the Aspects
                    movs            r2, #0
                    movs            r3, #drawValueOffset-1
                    sub             sp, sp, #8
                    movs            r7, #DISPLAY_ROW_HEIGHT
                    str             r7, [sp]
                    bl              Display_drawFilledRectangle     @ fill rectangle
                    add             sp, sp, #8
                    movs            r0, #0                          @ draw the text
                    ldr             r1, = #(1 | DISPLAY_ROW)
                    movs            r2, #1
                    ldr             r3, = #waitMessage
                    bl              Display_drawString
                    bl              Display_blitDisplayBuffer

                    ldr             r0, = #FsmAspectTest_currentTestPtr  @ re-init current Aspects value and set up
                    movs            r1, #0                          @ ptrs to current test
                    strb            r1, [r0, #5]
                    ldrb            r1, [r0, #6]
                    ldr             r7, = #aspectValueTable
                    lsls            r1, r1, #3
                    ldr             r2, [r7, r1]                    @ get selected aspects and length of test
                    str             r2, [r0]
                    adds            r1, r1, #4
                    ldr             r2, [r7, r1]
                    strb            r2, [r0, #4]

                    bl              FsmAspectTest_testAspect        @ show the first Aspect
                    ldr             r0, = #FsmAspectTest_waitForAspectTest
                    pop             {r7, pc}

    private_function(FsmAspectTest_waitForAspectTest)

@ int FsmAspectTest_waitForAspectTest(short redValue, short blueValue, short greenValue, int buttonsAndStatus)
@   FSM Routine for waiting for the aspect test to finish. Returns the next state, or 0 to remain in the same state

FsmAspectTest_waitForAspectTest:
                    push            {r7, lr}

                    movs            r0, #0
                    ldr             r7, = #FsmAspectTest_currentTestAspect @ check if we've finished
                    ldrb            r2, [r7]
                    cmp             r2, #0xff                       @ uses 0xff as a marker that the test has finished
                    bne             9f

                    movs            r0, #0                          @ reset the display
                    ldr             r1, = #(1 | DISPLAY_ROW)
                    movs            r2, #0
                    movs            r3, #DISPLAY_WIDTH
                    bl              Display_fillRow
                    movs            r0, #0
                    ldr             r1, = #(1 | DISPLAY_ROW)
                    movs            r2, #1
                    ldr             r3, = #aspects
                    bl              Display_drawString
                    ldr             r0, = #FsmAspectTest_adjustAspects
9:
                    pop             {r7, pc}

    private_function(FsmAspectTest_testAspect)

@ void FsmAspectTest_testAspect()
@   Test an Aspect, and then wait to test the next one

FsmAspectTest_testAspect:
alarmSlot = 4

                    push            {r3-r7, lr}
                    bl              Ws2812_clearBuffer              @ clear the buffer and display
                    ldr             r7, = #FsmAspectTest_currentTestPtr  @ check if we've already finished, and the main
                    ldrb            r0, [r7, #4]                    @ loop hasn't caught up with us
                    ldrb            r5, [r7, #5]
                    cmp             r5, r0
                    bge             8f

                    ldr             r6, [r7]
                    lsls            r0, r5, #4
                    adds            r6, r6, r0
                    movs            r4, #0
0:
                    movs            r0, #3                          @ only uses channel 4
                    movs            r1, r4
                    lsls            r3, r4, #2
                    ldr             r2, [r6, r3]
                    bl              Ws2812_setColour                @ set the colour
                    adds            r4, r4, #1
                    cmp             r4, #4                          @ only ever 4 aspects
                    blt             0b

                    adds            r5, r5, #1
                    strb            r5, [r7, #5]
                    movs            r0, #alarmSlot                  @ enable a timer every 500ms
                    ldr             r1, = #500
                    ldr             r2, = #FsmAspectTest_testAspect
                    bl              MsCounter_alarmIn
9:
                    movs            r0, #3
                    bl              Ws2812_update
                    pop             {r3-r7, pc}
8:
                    movs            r0, #0xff                       @ use 0xff as a marker to indicate we've
                    strb            r0, [r7, #5]                    @ finished
                    b               9b

    private_function(FsmAspectTest_displayAspects)

@ void FsmAspectTest_displayAspects(short pwmValue)
@   display the number of leds on the display

FsmAspectTest_displayAspects:

drawValueOffset=35

                    push            {r7, lr}
                    lsrs            r0, r0, #9                      @ support 8 types of aspects
                    ldr             r1, = #FsmAspectTest_aspectType
                    strb            r0, [r1]
                    ldr             r1, = #aspectTextTable
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
