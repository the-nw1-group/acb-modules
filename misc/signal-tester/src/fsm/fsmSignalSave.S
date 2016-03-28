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

@ Finite State Machine functions for saving signal settings

   module(FsmSignalSave)

    .extern         Display_drawAlignedString                       @ draw a aligned single line characters
    .extern         Display_blitDisplayBuffer                       @ draw the display buffer onto the display
    .extern         Display_clearDisplayBuffer                      @ clear the display buffer
    .extern         Display_fillRow                                 @ fill a row in the display buffer
    .extern         Configuration_replaceOrAddNew                   @ replace or save a new record
    .extern         FsmMenus_initSignalSaveMenu                     @ go to the signal save menu
    .extern         FsmSignalSetup_colour                           @ the last colour selected by the user
    .extern         FsmCommon_showMessageFor                        @ show a message

    private_data(FsmSignalSave_private)

FsnSignalSave_dataType:
                    .byte           0

    static_data(FsmSignalSave_const)

FsmSignalSave_const:
redTitle:           .string         "Saving Red Settings"
yellowTitle:        .string         "Saving Yellow Settings"
greenTitle:         .string         "Saving Green Settings"
whiteTitle:         .string         "Saving White Settings"
pleaseWait:         .string         "Please Wait..."
success:            .string         "Settings Saved OK"
error:              .string         "Error: Memory Full"

    public_function(FsmSignalSave_initRedSave)

@ int FsmSignalSave_initRedSave(short redValue, short blueValue, short greenValue, int buttonsAndStatus)
@   FSM Routine for the Red Signal Save routines. Returns the next state, or 0 to remain in the same state

FsmSignalSave_initRedSave:
                    movs            r0, #CONFIG_DATA_RED
                    ldr             r1, = #redTitle
                    b               FsmSignalSave_initCommon

    public_function(FsmSignalSave_initYellowSave)

@ int FsmSignalSave_initYellowSave(short redValue, short blueValue, short greenValue, int buttonsAndStatus)
@   FSM Routine for the Yellow Signal Save routines. Returns the next state, or 0 to remain in the same state

FsmSignalSave_initYellowSave:
                    movs            r0, #CONFIG_DATA_YELLOW
                    ldr             r1, = #yellowTitle
                    b               FsmSignalSave_initCommon

    public_function(FsmSignalSave_initGreenSave)

@ int FsmSignalSave_initGreenSave(short redValue, short blueValue, short greenValue, int buttonsAndStatus)
@   FSM Routine for the Yellow Signal Save routines. Returns the next state, or 0 to remain in the same state

FsmSignalSave_initGreenSave:
                    movs            r0, #CONFIG_DATA_GREEN
                    ldr             r1, = #greenTitle
                    b               FsmSignalSave_initCommon

    public_function(FsmSignalSave_initWhiteSave)

@ int FsmSignalSave_initWhiteSave(short redValue, short blueValue, short greenValue, int buttonsAndStatus)
@   FSM Routine for the Yellow Signal Save routines. Returns the next state, or 0 to remain in the same state

FsmSignalSave_initWhiteSave:
                    movs            r0, #CONFIG_DATA_WHITE
                    ldr             r1, = #whiteTitle
                    b               FsmSignalSave_initCommon

    private_function(FsmSignalSave_initCommon)

@ int FsmSignalSave_initCommon(byte dataType, char* title)
@   Common init routine, which saves the data type, and displays the title. Returns the next state

FsmSignalSave_initCommon:
                    push            {r5-r7, lr}
                    movs            r5, r0                          @ save off parameters
                    movs            r6, r1
                    bl              Display_clearDisplayBuffer      @ display title
                    movs            r0, #DISPLAY_CENTER_ALIGN
                    ldr             r1, = #(0 | DISPLAY_ROW)
                    movs            r2, #1
                    movs            r3, r6
                    bl              Display_drawAlignedString
                    movs            r0, #DISPLAY_LEFT_ALIGN         @ and please wait message
                    ldr             r1, = #(1 | DISPLAY_ROW)
                    movs            r2, #1
                    ldr             r3, = #pleaseWait
                    bl              Display_drawAlignedString
                    bl              Display_blitDisplayBuffer
                    ldr             r0, = #FsnSignalSave_dataType   @ save data type
                    strb            r5, [r0]
                    ldr             r0, = #FsmSignalSave_doSignalSave
                    pop             {r5-r7, pc}

    public_function(FsmSignalSave_doSignalSave)

@ int FsmSignalSave_doSignalSave(short redValue, short blueValue, short greenValue, int buttonsAndStatus)
@   FSM Routine for the saving signal settings. Returns the next state, or 0 to remain in the same state

FsmSignalSave_doSignalSave:
                    push            {r7, lr}
                    movs            r0, #CONFIG_REC_SETTINGS        @ save the last settings to the configuration
                    ldr             r1, = #FsnSignalSave_dataType   @ manager
                    ldrb            r1, [r1]
                    ldr             r7, = #FsmSignalSetup_colour    @ it's already in the correct format
                    ldr             r2, [r7]
                    movs            r3, #0
                    bl              Configuration_replaceOrAddNew
                    ldr             r7, = #success                  @ if OK show success message, otherwise error
                    adds            r1, r0, #1
                    bne             0f
                    ldr             r7, = #error
0:
                    ldr             r0, = #400
                    ldr             r1, = #FsmMenus_initSignalSaveMenu
                    movs            r2, r7
                    bl              FsmCommon_showMessageFor
                    pop             {r7, pc}

   .end
