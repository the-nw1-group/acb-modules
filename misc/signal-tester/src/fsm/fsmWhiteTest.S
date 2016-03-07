/*
 * Copyright (c) 2015 The NW1 Group
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#include "moduleInfo.inc"
#include "configuration.inc"

@ Finite State Machine functions to test a number of RGB LEDs using white (all dies displayed)

    module(FsmWhiteTest)

    .extern         Display_drawAlignedString                       @ draw a aligned single line characters
    .extern         Display_blitDisplayBuffer                       @ draw the display buffer onto the display
    .extern         Display_clearDisplayBuffer                      @ clear the display buffer
    .extern         Display_drawFilledRectangle                     @ draw a filled rectangle
    .extern         Display_fillRow                                 @ fill a row in the display buffer
    .extern         Display_drawString                              @ draw a string into the display buffer
    .extern         FsmMenus_initSignalTestMenu                     @ show the signal test menu
    .extern         FsmCommon_showInstructions                      @ show instructions
    .extern         itoa                                            @ convert integer to string
    .extern         Ws2812_init                                     @ init WS2812 driver
    .extern         Ws2812_setBufferSizes                           @ set buffer sizes for each of the channels
    .extern         Ws2812_clearBuffer                              @ clear the WS2812 buffer
    .extern         Ws2812_setColour                                @ set the colour
    .extern         Ws2812_update                                   @ display the buffer on the display
    .extern         MsCounter_alarmIn                               @ set an alarm in x milliseconds

    private_data(FsmWhiteTest_privateData)

FsmWhiteTest_white:                                                 @ value to use for white (in SRAM as will be
                    .int            0x00FFFFFF                      @ configurable
FsmWhiteTest_convertBuffer:
                    .string         "    "                          @ buffer for integer conversion
FsmWhiteTest_noOfLeds:
                    .byte           0
FsmWhiteTest_currentLed:
                    .byte           0

    static_data(FsmWhiteTest_const)

FsmWhiteTest_const:

title:              .string         "RGB LED White Test"
instructions1:      .string         "Connect the RGB LED module to"
instructions2:      .string         "the connector, ensuring you"
instructions3:      .string         "have the connections the"
instructions4:      .string         "correct way around."
instructions5:      .string         "Use RED to adjust the number"
instructions6:      .string         "of LEDs to test, then use"
instructions7:      .string         "the Action button to test"
instructions8:      .string         "the LEDs. Use Back or Next"
instructions9:      .string         "to return to the last menu."
noLeds:             .string         "Number of LEDs: "
waitMessage:        .string         "Testing the LEDs"

                    .balign         4                               @ align these data structures to 4 byte boundary
                    .align          4

instructionTable:
                    .int            instructions1,  instructions2
                    .int            instructions3,  instructions4
                    .int            instructions5,  instructions6
                    .int            instructions7,  instructions8
                    .int            instructions9
instructionTableEnd:

    public_function(FsmWhiteTest_initWhiteTest)

@ int FsmWhiteTest_initWhiteTest(short redValue, short blueValue, short greenValue, int buttonsAndStatus)
@   FSM Routine for the Servo Setup routines. Returns the next state, or 0 to remain in the same state

FsmWhiteTest_initWhiteTest:
                    push            {r7, lr}
                    bl              FsmWhiteTest_loadConfiguration
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
                    movs            r3, #32
                    bl              Ws2812_setBufferSizes
                    bl              Ws2812_clearBuffer              @ and clear the buffer

                    ldr             r0, = #instructionTable         @ show the instructions
                    movs            r1, #(instructionTableEnd-instructionTable)
                    ldr             r2, = #FsmWhiteTest_setupWhiteTest
                    bl              FsmCommon_showInstructions
                    pop             {r7, pc}

    private_function(FsmWhiteTest_loadConfiguration)

@ void FsmWhiteTest_loadConfiguration()
@   load the white led "colour" from configuration if present

FsmWhiteTest_loadConfiguration:
                    push            {r7, lr}
                    movs            r0, #CONFIG_REC_SETTINGS
                    movs            r1, #CONFIG_DATA_WHITE
                    bl              Configuration_find
                    cmp             r0, #0                          @ no configuration found
                    beq             9f

                    ldr             r1, =#FsmWhiteTest_white        @ save stored value locally
                    ldrh            r2, [r0, #CONFIG_DATA_OFFSET]   @ it's not word aligned, so load as two half words
                    strh            r2, [r1]
                    ldrh            r2, [r0, #(CONFIG_DATA_OFFSET+2)]
                    strh            r2, [r1, #2]
9:
                    pop             {r7, pc}

    private_function(FsmWhiteTest_setupWhiteTest)

@ int FsmWhiteTest_setupWhiteTest(short redValue, short blueValue, short greenValue, int buttonsAndStatus)
@   FSM Routine setting up the white test. Returns the next state, or 0 to remain in the same state

FsmWhiteTest_setupWhiteTest:
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
                    ldr             r3, = #noLeds
                    bl              Display_drawString
                    bl              Display_blitDisplayBuffer

                    movs            r0, r7
                    bl              FsmWhiteTest_displayNumber      @ adjust number of LEDs and display
                    ldr             r0, = #FsmWhiteTest_adjustNumber
                    pop             {r7, pc}

    private_function(FsmWhiteTest_adjustNumber)

@ int FsmWhiteTest_adjustNumber(short redValue, short blueValue, short greenValue, int buttonsAndStatus)
@   FSM Routine adjusting the number of LEDS based on Red. Returns the next state, or 0 to remain in the same state

FsmWhiteTest_adjustNumber:
                    push            {r5-r7, lr}
                    movs            r5, #FSM_STATE_ANALOG_CHANGED   @ if the analog state hasn't changed, then
                    rev16           r6, r3                          @ just check for any button press
                    tst             r5, r6
                    beq             0f
                    movs            r7, r3
                    bl              FsmWhiteTest_displayNumber      @ set and display number of LEDs values
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
                    ldr             r0, = #FsmWhiteTest_runWhiteTest @ yes, test the LEDs
                    b               9f
8:
                    movs            r0, #0
9:
                    pop             {r5-r7, pc}

    private_function(FsmWhiteTest_runWhiteTest)

@ int FsmWhiteTest_runWhiteTest(short redValue, short blueValue, short greenValue, int buttonsAndStatus)
@   FSM Routine for running the white test. Returns the next state, or 0 to remain in the same state

FsmWhiteTest_runWhiteTest:
                    push            {r7, lr}
                    movs            r0, #0                          @ display a line to the user that we are testing
                    ldr             r1, = #(1 | DISPLAY_ROW)        @ the LEDs
                    movs            r2, #0
                    movs            r3, #DISPLAY_WIDTH
                    bl              Display_fillRow
                    movs            r0, #0                          @ draw the text
                    ldr             r1, = #(1 | DISPLAY_ROW)
                    movs            r2, #1
                    ldr             r3, = #waitMessage
                    bl              Display_drawString
                    bl              Display_blitDisplayBuffer

                    ldr             r0, = #FsmWhiteTest_currentLed  @ re-init current LED value
                    movs            r1, #0
                    strb            r1, [r0]
                    bl              FsmWhiteTest_testLed            @ show the first LED
                    ldr             r0, = #FsmWhiteTest_waitForWhiteTest
                    pop             {r7, pc}

    private_function(FsmWhiteTest_waitForWhiteTest)

@ int FsmWhiteTest_waitForWhiteTest(short redValue, short blueValue, short greenValue, int buttonsAndStatus)
@   FSM Routine for waiting for the white test to finish. Returns the next state, or 0 to remain in the same state

FsmWhiteTest_waitForWhiteTest:
                    push            {r7, lr}

                    movs            r0, #0
                    ldr             r7, = #FsmWhiteTest_currentLed  @ check if we've finished
                    ldrb            r2, [r7]
                    cmp             r2, #0xff                       @ uses 0xff as a marker that the test has finished
                    bne             9f
                    ldr             r0, = #FsmWhiteTest_adjustNumber
9:
                    pop             {r7, pc}

    private_function(FsmWhiteTest_testLed)

@ void FsmWhiteTest_testLed()
@   Test an LED, and then wait to test the next one

FsmWhiteTest_testLed:
alarmSlot = 4

                    push            {r5-r7, lr}
                    bl              Ws2812_clearBuffer              @ clear the buffer and display
                    ldr             r7, = #FsmWhiteTest_noOfLeds    @ check if we've already finished, and the main
                    ldrb            r0, [r7]                        @ loop hasn't caught up with us
                    ldrb            r5, [r7, #1]
                    cmp             r5, r0
                    bge             8f

                    movs            r0, #3                          @ only uses channel 4
                    movs            r1, r5                          @ and set the aspect
                    ldr             r2, = #FsmWhiteTest_white
                    ldr             r2, [r2]
                    bl              Ws2812_setColour                @ set the colour
                    adds            r5, r5, #1
                    strb            r5, [r7, #1]

                    movs            r0, #alarmSlot                  @ enable a timer every 500ms
                    ldr             r1, = #500
                    ldr             r2, = #FsmWhiteTest_testLed
                    bl              MsCounter_alarmIn
9:
                    movs            r0, #3
                    bl              Ws2812_update
                    pop             {r5-r7, pc}
8:
                    movs            r0, #0xff                       @ use 0xff as a marker to indicate we've
                    strb            r0, [r7, #1]                    @ finished
                    b               9b

    private_function(FsmWhiteTest_adjustNumber)

@ void FsmWhiteTest_adjustNumber(short pwmValue)
@   display the number of leds on the display

FsmWhiteTest_displayNumber:

drawValueOffset=69

                    push            {r7, lr}
                    lsrs            r0, r0, #7                      @ support 32 number of LEDs
                    adds            r0, r0, #1                      @ ensure we always test one LED!
                    ldr             r1, = #FsmWhiteTest_noOfLeds
                    strb            r0, [r1]
                    ldr             r1, = #FsmWhiteTest_convertBuffer
                    movs            r2, #10                         @ convert to base 10
                    bl              itoa

                    movs            r0, #drawValueOffset            @ blank previous values
                    ldr             r1, = #(1 | DISPLAY_ROW)
                    movs            r2, #0
                    sub             sp, sp, #8
                    movs            r3, #DISPLAY_HEIGHT
                    str             r3, [sp]
                    movs            r3, #(DISPLAY_WIDTH - drawValueOffset)
                    bl              Display_drawFilledRectangle
                    add             sp, sp, #8
                    movs            r0, #drawValueOffset            @ write new number on the display
                    ldr             r1, = #(1 | DISPLAY_ROW)
                    movs            r2, #1
                    ldr             r3, = #FsmWhiteTest_convertBuffer
                    bl              Display_drawString
                    bl              Display_blitDisplayBuffer
                    pop             {r7, pc}

       .end
