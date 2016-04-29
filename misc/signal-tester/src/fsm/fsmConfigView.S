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

@ Finite State Machine functions to delete configuration

    module(FsmConfigView)

    .extern         Display_drawAlignedString                       @ draw a aligned single line characters
    .extern         Display_blitDisplayBuffer                       @ draw the display buffer onto the display
    .extern         Display_clearDisplayBuffer                      @ clear the display buffer
    .extern         Display_drawFilledRectangle                     @ draw a filled rectangle
    .extern         Display_fillRow                                 @ fill a row in the display buffer
    .extern         Display_drawString                              @ draw a string into the display buffer
    .extern         FsmCommon_showInstructions                      @ show instructions

    private_data(FsmConfigView_privateData)

FsmConfigView_noRecords:
                    .short          0
FsmConfigView_currentRecord:
                    .short          512
FsmConfigView_viewType:
                    .byte           0
FsmConfigView_redShift:
                    .byte           0
FsmConfigView_convertBuffer:
                    .space          128, 0

    static_data(FsmConfigView_const)

FsmConfigView_const:

titleSettings:      .string         "View Settings"
titleAll:           .string         "View All Data"
instructions1:      .string         "View data stored in the"
instructions2:      .string         "EEPROM on the board. Use"
instructions3:      .string         "RED to move through the"
instructions4:      .string         "records. Use any button to"
instructions5:      .string         "return to the last menu."
noRecords:          .string         "No records to display."
errorLoading:       .string         "Failed to load."
                                    @01234567890123456789012345
servo:              .string         "Servo: St:    En:    Sp:  "
red:                .string         "Red: R:    G:    B:   "
yellow:             .string         "Ylw: R:    G:    B:   "
green:              .string         "Grn: R:    G:    B:   "
white:              .string         "Wht: R:    G:    B:   "

                    .balign         4                               @ align these data structures to 4 byte boundary
                    .align          4

instructionTable:
                    .int            instructions1,  instructions2
                    .int            instructions3,  instructions4
                    .int            instructions5
instructionTableEnd:

    public_function(FsmConfigView_initViewSettings)

@ int FsmConfigView_initViewSettings(short redValue, short blueValue, short greenValue, int buttonsAndStatus)
@   FSM Routine for the viewing the settings. Returns the next state, or 0 to remain in the same state

FsmConfigView_initViewSettings:
                    movs            r0, #CONFIG_REC_SETTINGS
                    ldr             r1, = #titleSettings
                    b               FsmConfigView_initViewCommon

    public_function(FsmConfigView_initViewData)

@ int FsmConfigView_initViewData(short redValue, short blueValue, short greenValue, int buttonsAndStatus)
@   FSM Routine for the viewing all the data. Returns the next state, or 0 to remain in the same state

FsmConfigView_initViewData:
                    movs            r0, #CONFIG_REC_DATA
                    ldr             r1, = #titleAll
                    b               FsmConfigView_initViewCommon

    private_function(FsmConfigView_initViewCommon)

@ int FsmConfigView_initViewCommon(byte viewType, char* title)
@   store the viewType, display the title, and show the instructions

FsmConfigView_initViewCommon:
                    push            {r7, lr}
                    ldr             r2, = #FsmConfigView_viewType
                    strb            r0, [r2]
                    movs            r7, r1
                    bl              Display_clearDisplayBuffer      @ display title
                    movs            r0, #DISPLAY_LEFT_ALIGN
                    ldr             r1, = #(0 | DISPLAY_ROW)
                    movs            r2, #1
                    movs            r3, r7
                    bl              Display_drawAlignedString

                    ldr             r0, = #instructionTable         @ show the instructions
                    movs            r1, #(instructionTableEnd-instructionTable)
                    ldr             r2, = #FsmConfigView_setupViewData
                    bl              FsmCommon_showInstructions
                    pop             {r7, pc}

    private_function(FsmConfigView_setupViewData)

@ int FsmConfigView_setupViewData(short redValue, short blueValue, short greenValue, int buttonsAndStatus)
@   FSM Routine for the viewing the data. Returns the next state, or 0 to remain in the same state

FsmConfigView_setupViewData:
                    push            {r7, lr}
                    ldr             r7, = #FsmConfigView_noRecords
                    ldrb            r3, [r7, #4]
                    cmp             r3, #CONFIG_REC_DATA
                    beq             svd_allData
                    bl              Configuration_countData
                    b               svd_continue
svd_allData:
                    bl              Configuration_countAll
svd_continue:
                    cmp             r0, #0
                    beq             8f
                    subs            r0, r0, #1
                    strh            r0, [r7]
                    movs            r1, #0
                    strh            r1, [r7, #2]
                    bl              FsmConfigView_calculateShift
                    strb            r0, [r7, #5]
                    ldr             r0, = # 512                     @ init the current displayed value to out of range
                    strh            r0, [r7, #2]                    @ to ensure we always show a record when first started
                    ldr             r0, = #FsmConfigView_adjustDisplay
9:
                    pop             {r7, pc}
8:
                    ldr             r0, = #400
                    ldr             r1, = #FsmMenus_initConfigurationMenu
                    ldr             r2, = #noRecords
                    bl              FsmCommon_showMessageFor
                    b               9b

    private_function(FsmConfigView_adjustDisplay)

@ int FsmConfigView_adjustDisplay(short redValue, short blueValue, short greenValue, int buttonsAndStatus)
@   FSM Routine for adjusting the displayed record. Returns the next state, or 0 to remain in the same state

FsmConfigView_adjustDisplay:
                    push            {r7, lr}
                    movs            r1, #FSM_STATE_ANALOG_CHANGED   @ if the analog state hasn't changed, then
                    rev16           r2, r3                          @ just check for any button press
                    tst             r1, r2
                    beq             0f
                    push            {r2, r3}
                    bl              FsmConfigView_showRecord        @ show the current record
                    pop             {r2, r3}
0:
                    movs            r1, r3                          @ check if any button pressed
                    ldr             r0, = #FsmMenus_initMainMenu
                    bl              FsmCommon_anyKeyPressed
                    cmp             r0, #0
9:
                    pop             {r7, pc}

    private_function(FsmConfigView_showRecord)

@ void FsmConfigView_showRecord(short redValue)
@   show the record that's position is a scaled value of the redValue parameter

FsmConfigView_showRecord:
                    push            {r7, lr}
                    ldr             r7, = FsmConfigView_noRecords
                    ldrh            r1, [r7, #2]                    @ get current record
                    ldrb            r2, [r7, #5]                    @ get the red shift value
                    lsrs            r0, r0, r2
                    ldrh            r2, [r7]
                    cmp             r0, r2                          @ if the current record is greater than the max
                    blt             0f                              @ records, then just set it to the max record
                    movs            r0, r2
0:
                    cmp             r0, r1                          @ if it's the record we're already showing
                    beq             9f                              @ just return
                    strh            r0, [r7, #2]                    @ store current record

                    bl              FsmConfigView_showRecordIndicator
                    bl              FsmConfigView_showRecordDetails
                    bl              Display_blitDisplayBuffer
9:
                    pop             {r7, pc}

    private_function(FsmConfigView_showRecordIndicator)

@ void FsmConfigView_showRecordIndicator(void)
@   display the current position, and the max. number of records

FsmConfigView_showRecordIndicator:
drawValueOffset = 74
                    push            {r7, lr}
                    movs            r0, #drawValueOffset            @ clear the area
                    ldr             r1, = #(0 | DISPLAY_ROW)
                    movs            r2, #0
                    movs            r3, #ACB_DISPLAY_WIDTH - drawValueOffset
                    sub             sp, sp, #8
                    movs            r7, #DISPLAY_ROW_HEIGHT
                    str             r7, [sp]
                    bl              Display_drawFilledRectangle     @ fill rectangle
                    add             sp, sp, #8

                    ldr             r7, = #FsmConfigView_noRecords
                    ldrh            r0, [r7, #2]
                    adds            r0, r0, #1                      @ make the output 1's based
                    ldr             r1, = #FsmConfigView_convertBuffer
                    movs            r2, #10
                    bl              itoa
0:                                                                  @ add / to the end of the returned string
                    ldrb            r1, [r0]
                    cmp             r1, #0
                    beq             1f
                    adds            r0, r0, #1
                    b               0b
1:
                    movs            r1, #'/'
                    strb            r1, [r0]
                    adds            r0, r0, #1
                    movs            r1, r0                          @ add total no records to the display
                    ldrh            r0, [r7]
                    adds            r0, r0, #1
                    movs            r2, #10
                    bl              itoa

                    movs            r0, #1<<DISPLAY_RIGHT_ALIGN_BIT
                    ldr             r1, = #(0 | DISPLAY_ROW)        @ write to the buffer
                    movs            r2, #1
                    ldr             r3, = #FsmConfigView_convertBuffer
                    bl              Display_drawAlignedString
                    pop             {r7, pc}

    private_function(FsmConfigView_showRecordDetails)

@ void FsmConfigView_showRecordDetails(void)
@   display the current record

FsmConfigView_showRecordDetails:
                    push            {r4-r7, lr}
                    movs            r0, #0                          @ clear the bottom row
                    ldr             r1, = #(1 | DISPLAY_ROW)
                    movs            r2, #0
                    movs            r3, #ACB_DISPLAY_WIDTH
                    bl              Display_fillRow

                    ldr             r7, = #FsmConfigView_noRecords
                    ldrh            r0, [r7, #2]
                    ldrb            r1, [r7, #4]
                    cmp             r1, #CONFIG_REC_SETTINGS
                    bne             0f
                    bl              Configuration_getDataAt
                    b               1f
0:
                    bl              Configuration_getAt
1:
                    cmp             r0, #0
                    beq             8f                              @ if loading failed, display error message
                    ldr             r2, = #FsmConfigView_recordDecode
                    ldrb            r1, [r0, #CONFIG_TYPE_OFFSET]
                    lsls            r1, r1, #2
                    ldr             r2, [r2, r1]
                    bx              r2
9:
                    movs            r3, r0
                    movs            r0, #0
                    ldr             r1, = #(1 | DISPLAY_ROW)
                    movs            r2, #1
                    bl              Display_drawString
                    pop             {r4-r7, pc}
FsmConfigView_recordDecodeFail:
8:
                    ldr             r0, = #errorLoading
                    b               9b

FsmConfigView_recordDecodeServo:
                    movs            r7, r0
                    ldr             r0, =#FsmConfigView_convertBuffer
                    ldr             r1, =#servo
                    bl              strcpy
                    movs            r4, r0
                    ldrb            r0, [r7, #CONFIG_DATA_OFFSET]   @ get the start, end and offset, and convert to
                    movs            r1, r4
                    adds            r1, r1, #11
                    movs            r2, #16
                    bl              FsmConfigView_toString
                    ldrb            r0, [r7, #CONFIG_DATA_OFFSET + 1]
                    movs            r1, r4
                    adds            r1, r1, #18
                    movs            r2, #16
                    bl              FsmConfigView_toString
                    ldrb            r0, [r7, #CONFIG_DATA_OFFSET + 2]
                    movs            r1, r4
                    adds            r1, r1, #25
                    movs            r2, #10
                    bl              itoa
                    movs            r0, r4
                    b               9b

FsmConfigView_recordDecodeRed:
                    ldr             r1, =#red
                    b               FsmConfigView_recordDecodeCommon
FsmConfigView_recordDecodeYellow:
                    ldr             r1, =#yellow
                    b               FsmConfigView_recordDecodeCommon
FsmConfigView_recordDecodeGreen:
                    ldr             r1, =#green
                    b               FsmConfigView_recordDecodeCommon
FsmConfigView_recordDecodeWhite:
                    ldr             r1, =#white
FsmConfigView_recordDecodeCommon:
                    movs            r7, r0
                    ldr             r0, =#FsmConfigView_convertBuffer
                    bl              strcpy
                    movs            r4, r0
                    ldrb            r0, [r7, #CONFIG_DATA_OFFSET + 2] @ get R G B values, and display
                    movs            r1, r4
                    adds            r1, r1, #8
                    movs            r2, #16
                    bl              FsmConfigView_toString
                    ldrb            r0, [r7, #CONFIG_DATA_OFFSET + 1]
                    movs            r1, r4
                    adds            r1, r1, #14
                    movs            r2, #16
                    bl              FsmConfigView_toString
                    ldrb            r0, [r7, #CONFIG_DATA_OFFSET]
                    movs            r1, r4
                    adds            r1, r1, #20
                    movs            r2, #16
                    bl              itoa
                    movs            r0, r4
                    b               9b

    static_data(FsmConfigView_recordDecode)

FsmConfigView_recordDecode:
                    .word           FsmConfigView_recordDecodeFail + 1   @ no record type 0
                    .word           FsmConfigView_recordDecodeServo + 1  @ servo (type=1)
                    .word           FsmConfigView_recordDecodeRed + 1    @ red colour (type=2)
                    .word           FsmConfigView_recordDecodeYellow + 1 @ yellow colour (type=3)
                    .word           FsmConfigView_recordDecodeGreen + 1  @ green colour (type=4)
                    .word           FsmConfigView_recordDecodeWhite + 1  @ white colour (type=5)

    private_function(FsmConfigView_calculateShift)

@ int FsmConfigView_calculateShift(int noItems)
@   caculates the the shift required from a 12-bit number, to give the best range over the noItems. Returns the shift.

FsmConfigView_calculateShift:
                    movs            r1, #12
0:
                    cmp             r0, #0
                    beq             9f
                    lsrs            r0, r0, #1
                    subs            r1, r1, #1
                    b               0b
9:
                    movs            r0, r1
                    bx              lr

    private_function(FsmConfigView_toString)

@ void FsmConfigView_toString(int value, char* buffer, int base)
@   converts a value to a string, to the supplied base; this method replaces the terminating byte with a space.

FsmConfigView_toString:
                    push            {r7, lr}
                    bl              itoa
0:
                    ldrb            r1, [r0]
                    cmp             r1, #0
                    beq             1f
                    adds            r0, r0, #1
                    b               0b
1:
                    movs            r1, #32
                    strb            r1, [r0]
                    pop             {r7, pc}

       .end
