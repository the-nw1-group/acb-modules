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
    .extern         Display_drawFilledRectangle                     @ fill a rectangle
    .extern         FsmCommon_showInstructions                      @ show instructions

    private_data(FsmConfigView_privateData)

FsmConfigView_viewType:
                    .byte           0

    static_data(FsmConfigView_const)

FsmConfigView_const:

titleSettings:      .string         "View Settings"
titleAll:           .string         "View All Data"
instructions1:      .string         "View data stored in the"
instructions2:      .string         "EEPROM on the board. Use"
instructions3:      .string         "the Back/Forward buttons"
instructions4:      .string         "to navigate the records, or"
instructions5:      .string         "use RED to move through the"
instructions6:      .string         "records. Use Action to return"
instructions7:      .string         "to the last menu."

                    .balign         4                               @ align these data structures to 4 byte boundary
                    .align          4

instructionTable:
                    .int            instructions1,  instructions2
                    .int            instructions3,  instructions4
                    .int            instructions5,  instructions6
                    .int            instructions7
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
                  @  ldr             r2, = #FsmAspectTest_setupAspectTest
                    movs            r2, #0
                    bl              FsmCommon_showInstructions
                    pop             {r7, pc}


       .end
