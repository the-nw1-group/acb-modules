/*
 * Copyright (c) 2015 The NW1 Group
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#include "moduleInfo.inc"

@ Finite State Machine functions for RGB LED signal setup

    module(FsmSignalSetup)

    .extern         Display_drawAlignedString                       @ draw a aligned single line characters
    .extern         Display_blitDisplayBuffer                       @ draw the display buffer onto the display
    .extern         Display_clearDisplayBuffer                      @ clear the display buffer
    .extern         Display_drawFilledRectangle                     @ draw a filled rectangle
    .extern         Display_fillRow                                 @ fill a row in the display buffer
    .extern         Display_drawString                              @ draw a string into the display buffer
    .extern         FsmMenus_initMainMenu                           @ init and show the main menu
    .extern         FsmMenus_initSignalSaveMenu                     @ show the signal save menu
    .extern         FsmCommon_showInstructions                      @ show instructions
    .extern         FsmCommon_anyKeyPressed                         @ check if any key pressed
    .extern         Ws2812_init                                     @ init WS2812 driver
    .extern         Ws2812_setBufferSizes                           @ set buffer sizes for each of the channels
    .extern         Ws2812_clearBuffer                              @ clear the WS2812 buffer
    .extern         Ws2812_setColour                                @ set the colour
    .extern         Ws2812_update                                   @ display the buffer on the display
    .extern         itoa                                            @ convert integer to string

    public_data(FsmSignalSetup_publicData)

FsmSignalSetup_colour:
                    .int            0

    .global         FsmSignalSetup_colour

    private_data(FsmSignalSetup_privateData)

FsmSignalSetup_aspect:
                    .byte           0                               @ which aspect shown (displayed 1-4)
FsmSignalSetup_convertBuffer:
                    .string         "   "                           @ buffer for integer conversion

    static_data(FsmSignalSetup_const)

FsmSignalSetup_const:

title:              .string         "RGB Signal Setup"
instructions1:      .string         "Connect the RGB LED module to"
instructions2:      .string         "the connector, ensuring you"
instructions3:      .string         "have the connections the"
instructions4:      .string         "correct way around."
instructions5:      .string         "Use the knobs on the side to"
instructions6:      .string         "control the Red, Green and"
instructions7:      .string         "Blue shades emitted by the"
instructions8:      .string         "LED module. All values are"
instructions9:      .string         "displayed in hexadecimal and"
instructions10:     .string         "range from 0-FF. Use the"
instructions11:     .string         "Action button to change which"
instructions12:     .string         "aspect is shown (from 1-4). Use"
instructions13:     .string         "the Back button to return to"
instructions14:     .string         "the the main menu, and use the"
instructions15:     .string         "forward button to continue."

displayTemplate:    .string         "R:         G:         B:         A:"

                    .balign         4                               @ align these data structures to 4 byte boundary
                    .align          4

instructionTable:
                    .int            instructions1,  instructions2
                    .int            instructions3,  instructions4
                    .int            instructions5,  instructions6
                    .int            instructions7,  instructions8
                    .int            instructions9,  instructions10
                    .int            instructions11, instructions12
                    .int            instructions13, instructions14
                    .int            instructions15
instructionTableEnd:

    public_function(FsmSignalSetup_initSignalSetup)

@ int FsmSignalSetup_initSignalSetup(short redValue, short blueValue, short greenValue, int buttonsAndStatus)
@   FSM Routine for the Signal Setup routines. Returns the next state, or 0 to remain in the same state

FsmSignalSetup_initSignalSetup:
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
                    ldr             r2, = #FsmSignalSetup_setupSignal
                    bl              FsmCommon_showInstructions
                    pop             {r7, pc}

    private_function(FsmSignalSetup_setupSignal)

@ int FsmSignalSetup_setupSignal(short redValue, short blueValue, short greenValue, int buttonsAndStatus)
@   FSM Routine for setting up a signal. Returns the next state, or 0 to remain in the same state

FsmSignalSetup_setupSignal:
                    push            {r7, lr}
                    ldr             r3, = #FsmSignalSetup_aspect
                    ldrb            r3, [r3]
                    bl              FsmSignalSetup__setSignalValues @ set and display values
                    ldr             r0, = #FsmSignalSetup_adjustSignalParameters
                    pop             {r7, pc}

    private_function(FsmSignalSetup_adjustSignalParameters)

@ int FsmSignalSetup_adjustSignalParameters(short redValue, short blueValue, short greenValue, int buttonsAndStatus)
@   FSM Routine for adjusting the signal parameters. Returns the next state, or 0 to remain in the same state

FsmSignalSetup_adjustSignalParameters:
                    push            {r5-r7, lr}
                    movs            r5, #FSM_STATE_ANALOG_CHANGED   @ if the analog state hasn't changed, then
                    rev16           r6, r3                          @ just check for any button press
                    tst             r5, r6
                    beq             0f
                    movs            r7, r3
                    ldr             r3, = #FsmSignalSetup_aspect
                    ldrb            r3, [r3]
                    bl              FsmSignalSetup__setSignalValues @ set and display signal values
                    movs            r3, r7
0:
                    movs            r5, #FSM_STATE_BUTTONS_CHANGED  @ if the digital state hasn't changed, then
                    tst             r5, r6                          @ just return
                    beq             8f
                    movs            r5, #FSM_BUTTON_LEFT            @ Left/Back pressed?
                    tst             r3, r5
                    beq             1f
                    ldr             r0, = #FsmSignalSetup_exitSignalSetup @ yes, then exit
                    b               9f
1:
                    movs            r5, #FSM_BUTTON_ACTION          @ action button pressed?
                    tst             r3, r5
                    beq             2f
                    ldr             r5, = #FsmSignalSetup_aspect    @ yes, change the apsect
                    ldrb            r6, [r5]
                    movs            r0, #3                          @ clear the current displayed colour
                    movs            r1, r6
                    movs            r2, #0
                    bl              Ws2812_setColour                @ set the colour
                    movs            r0, #3
                    bl              Ws2812_update                   @ and display it
                    adds            r6, r6, #1
                    cmp             r6, #4
                    bne             0f
                    movs            r6, #0
0:
                    strb            r6, [r5]
                    b               8f
2:
                    movs            r5, #FSM_BUTTON_RIGHT           @ Next/Forward button pressed?
                    tst             r3, r5
                    beq             8f
                    ldr             r0, = #FsmMenus_initSignalSaveMenu  @ yes, then show save menu
                    b               9f
8:
                    movs            r0, #0
9:
                    pop             {r5-r7, pc}

    public_function(FsmSignalSetup_exitSignalSetup)

@ int FsmSignalSetup_exitSignalSetup(short redValue, short blueValue, short greenValue, int buttonsAndStatus)
@   FSM Routine for exiting the signal setup. Returns the next state, or 0 to remain in the same state

FsmSignalSetup_exitSignalSetup:
                    push            {r7, lr}
                    bl              Ws2812_clearBuffer              @ clear the buffer and display
                    movs            r0, #3
                    bl              Ws2812_update
                    ldr             r0, = #FsmMenus_initMainMenu    @ return to the main menu
                    pop             {r7, pc}


    private_function(FsmSignalSetup__setSignalValues)

@ void FsmServoSetup_setServoValues(short redValue, short blueValue, short greenValue, byte aspect)
@   Set and display the new signal values

FsmSignalSetup__setSignalValues:
                    push            {r3-r7, lr}
                    movs            r4, r0                          @ save parameters
                    movs            r5, r1
                    movs            r6, r2
                    movs            r7, r3
                    movs            r0, #0                          @ clear row, and display the template
                    ldr             r1, = #(1 | DISPLAY_ROW)
                    movs            r2, #0
                    movs            r3, #ACB_DISPLAY_WIDTH
                    bl              Display_fillRow
                    movs            r0, #0
                    ldr             r1, = #(1 | DISPLAY_ROW)
                    movs            r2, #1
                    ldr             r3, = #displayTemplate
                    bl              Display_drawString

                    lsrs            r4, r4, #4                      @ shift to the right, to it's an 8 bit value
                    lsrs            r5, r5, #4
                    lsrs            r6, r6, #4
0:
                    movs            r0, r4                          @ display the red value
                    movs            r1, #8
                    bl              FsmSignalSetup_displayValue
                    movs            r0, r5                          @ display the green value
                    movs            r1, #34
                    bl              FsmSignalSetup_displayValue
                    movs            r0, r6                          @ display the blue value
                    movs            r1, #59
                    bl              FsmSignalSetup_displayValue
                    adds            r0, r7, #1                      @ display the aspect, which is 1 based
                    movs            r1, #85
                    bl              FsmSignalSetup_displayValue
                    bl              Display_blitDisplayBuffer

                    movs            r2, r6
                    lsls            r0, r5, #8                      @ shift the colours, into rgb in one word
                    orrs            r2, r2, r0
                    lsls            r0, r4, #16
                    orrs            r2, r2, r0
                    ldr             r3, = #FsmSignalSetup_colour    @ store the colour about to be displayed
                    str             r2, [r3]
                    movs            r0, #3                          @ only uses channel 4
                    movs            r1, r7                          @ and set the aspect
                    bl              Ws2812_setColour                @ set the colour
                    movs            r0, #3
                    bl              Ws2812_update                   @ and display it
                    pop             {r3-r7, pc}

    private_function(FsmSignalSetup_displayValue)

@ void FsmSignalSetup_displayValue(byte value, short xOffset)
@   Display the supplied value. in hex, on the last row on the display at the x offset. Assumes the display is
@   blank at the appropriate place.

FsmSignalSetup_displayValue:
                    push            {r7, lr}
                    movs            r7, r1                          @ save off offset
                    ldr             r1, = #FsmSignalSetup_convertBuffer
                    movs            r2, #16
                    bl              itoa
                    movs            r3, r0
                    movs            r0, r7                          @ write value on the display
                    ldr             r1, = #(1 | DISPLAY_ROW)
                    movs            r2, #1
                    bl              Display_drawString
                    pop             {r7, pc}

    .end
