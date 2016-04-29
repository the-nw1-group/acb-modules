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

    module(FsmConfigDelete)

    .extern         Display_drawAlignedString                       @ draw a aligned single line characters
    .extern         Display_blitDisplayBuffer                       @ draw the display buffer onto the display
    .extern         Display_clearDisplayBuffer                      @ clear the display buffer
    .extern         Display_drawFilledRectangle                     @ draw a filled rectangle
    .extern         Display_fillRow                                 @ fill a row in the display buffer
    .extern         Display_drawString                              @ draw a string into the display buffer
    .extern         Display_drawFilledRectangle                     @ fill a rectangle
    .extern         FsmCommon_showInstructions                      @ show instructions
    .extern         FsmCommon_showMessageFor                        @ show a message
    .extern         NVIC_systemReset                                @ reset the device

    private_data(FsmConfigDelete_privateData)

FsmConfigDelete_deleteType:
                    .byte           0

    static_data(FsmConfigDelete_const)

FsmConfigDelete_const:

titleSettings:      .string         "Delete Settings"
titleAll:           .string         "Delete All Data"
instructions1:      .string         "Delete the data stored in the"
instructions2:      .string         "EEPROM on the board."
instructions3:      .string         "YOU WILL NOT BE ABLE TO"
instructions4:      .string         "RECOVER THIS DATA ONCE"
instructions5:      .string         "THE OPERATION IS COMPLETE"
areYouSure1:        .string         "ARE YOU SURE?"
areYouSure2:        .string         "PLEASE CONFIRM"
complete:           .string         "Settings have been deleted"
reboot:             .string         "Data deleted, device will restart"
failed:             .string         "Failed to delete"

                    .balign         4                               @ align these data structures to 4 byte boundary
                    .align          4

instructionTable:
                    .int            instructions1,  instructions2
                    .int            instructions3,  instructions4
                    .int            instructions5
instructionTableEnd:

    public_function(FsmConfigDelete_initDeleteSettings)

@ int FsmConfigDelete_initDeleteSettings(short redValue, short blueValue, short greenValue, int buttonsAndStatus)
@   FSM Routine for the deleting the settings. Returns the next state, or 0 to remain in the same state

FsmConfigDelete_initDeleteSettings:
                    movs            r0, #CONFIG_REC_SETTINGS
                    ldr             r1, = #titleSettings
                    b               FsmConfigDelete_initDeleteCommon

    public_function(FsmConfigDelete_initDeleteData)

@ int FsmConfigDelete_initDeleteData(short redValue, short blueValue, short greenValue, int buttonsAndStatus)
@   FSM Routine for the deleting all the data. Returns the next state, or 0 to remain in the same state

FsmConfigDelete_initDeleteData:
                    movs            r0, #CONFIG_REC_DATA
                    ldr             r1, = #titleAll
                    b               FsmConfigDelete_initDeleteCommon

    public_function(FsmConfigDelete_showAreYouSure1)

@ int FsmConfigDelete_showAreYouSure1(short redValue, short blueValue, short greenValue, int buttonsAndStatus)
@   FSM Routine for the deleting all the data, showing the are you sure 1 message. Returns the next state, or 0
@   to remain in the same state

FsmConfigDelete_showAreYouSure1:
                    ldr             r0, = #areYouSure1
                    ldr             r1, = #FsmConfigDelete_waitForSure1
                    b               FsmConfigDelete_areYouSureCommon

    public_function(FsmConfigDelete_showAreYouSure2)

@ int FsmConfigDelete_showAreYouSure1(short redValue, short blueValue, short greenValue, int buttonsAndStatus)
@   FSM Routine for the deleting all the data, showing the are you sure 2 message. Returns the next state, or 0
@   to remain in the same state

FsmConfigDelete_showAreYouSure2:
                    ldr             r0, = #areYouSure2
                    ldr             r1, = #FsmConfigDelete_waitForSure2
                    b               FsmConfigDelete_areYouSureCommon

    public_function(FsmConfigDelete_waitForSure1)

@ int FsmConfigDelete_waitForSure1(short redValue, short blueValue, short greenValue, int buttonsAndStatus)
@   FSM Routine waiting for the user to confirm. Returns the next state, or 0 to remain in the same state

FsmConfigDelete_waitForSure1:
                    movs            r0, r3
                    ldr             r1, = #FsmConfigDelete_showAreYouSure2
                    movs            r2, #FSM_BUTTON_ACTION
                    b               FsmConfigDelete_waitForSureCommon

    public_function(FsmConfigDelete_waitForSure2)

@ int FsmConfigDelete_waitForSure1(short redValue, short blueValue, short greenValue, int buttonsAndStatus)
@   FSM Routine waiting for the user to confirm. Returns the next state, or 0 to remain in the same state

FsmConfigDelete_waitForSure2:
                    movs            r0, r3
                    ldr             r1, = #FsmConfigDelete_doDelete
                    movs            r2, #FSM_BUTTON_RIGHT
                    b               FsmConfigDelete_waitForSureCommon

    public_function(FsmConfigDelete_doDelete)

@ int FsmConfigDelete_waitForSure1(short redValue, short blueValue, short greenValue, int buttonsAndStatus)
@   FSM Routine deletes the data from the EEPROM. Returns the next state, or 0 to remain in the same state

FsmConfigDelete_doDelete:
                    push            {r7, lr}
                    ldr             r0, = #FsmConfigDelete_deleteType
                    ldrb            r0, [r0]                        @ which kind of delete?
                    cmp             r0, #CONFIG_REC_SETTINGS
                    bne             1f
                    bl              Configuration_deleteAllData     @ just data items
                    cmp             r0, #SUCCESS
                    bne             8f
                    ldr             r2, = #complete
                    b               7f
1:
                    bl              Configuration_deleteAll         @ all the data
                    cmp             r0, #SUCCESS
                    bne             8f
                    movs            r0, #200
                    ldr             r1, =#FsmConfigDelete_reboot
                    ldr             r2, = #reboot
                    bl              FsmCommon_showMessageFor
9:
                    pop             {r7, pc}
8:
                    ldr             r2, =#failed
7:
                    movs            r0, #200
                    ldr             r1, =#FsmMenus_initConfigurationMenu
                    bl              FsmCommon_showMessageFor
                    b               9b

    public_function(FsmConfigDelete_reboot)

@ int FsmConfigDelete_reboot(short redValue, short blueValue, short greenValue, int buttonsAndStatus)
@   FSM Routine for rebooting. Doesn't return

FsmConfigDelete_reboot:
                    bl              NVIC_systemReset

    private_function(FsmConfigDelete_initDeleteCommon)

@ int FsmConfigDelete_initDeleteCommon(byte viewType, char* title)
@   store the deleteType, display the title, and show the instructions

FsmConfigDelete_initDeleteCommon:
                    push            {r7, lr}
                    ldr             r2, = #FsmConfigDelete_deleteType
                    strb            r0, [r2]
                    movs            r7, r1
                    bl              Display_clearDisplayBuffer      @ display title
                    movs            r0, #DISPLAY_CENTER_ALIGN
                    ldr             r1, = #(0 | DISPLAY_ROW)
                    movs            r2, #1
                    movs            r3, r7
                    bl              Display_drawAlignedString

                    ldr             r0, = #instructionTable         @ show the instructions
                    movs            r1, #(instructionTableEnd-instructionTable)
                    ldr             r2, = #FsmConfigDelete_showAreYouSure1
                    bl              FsmCommon_showInstructions
                    pop             {r7, pc}

    private_function(FsmConfigDelete_areYouSureCommon)

@ int FsmConfigDelete_areYouSureCommon(char* message, int newState)
@   display message, and moves to state

FsmConfigDelete_areYouSureCommon:
                    push            {r0-r1, r7, lr}
                    movs            r0, #0
                    ldr             r1, = #(1 | DISPLAY_ROW)
                    movs            r2, #0
                    movs            r3, #ACB_DISPLAY_WIDTH
                    bl              Display_fillRow
                    movs            r0, #0
                    ldr             r1, = #(1 | DISPLAY_ROW)
                    movs            r2, #1
                    pop             {r3}
                    bl              Display_drawString
                    bl              Display_blitDisplayBuffer
                    pop             {r0, r7, pc}

    private_function(FsmConfigDelete_waitForSureCommon)

@ int FsmConfigDelete_waitForSureCommon(int buttonState, int newState, int buttonToMove)
@   move to newState is buttonToMove button is pressed. If any other button is pressed return to the configuration
@   menu.

FsmConfigDelete_waitForSureCommon:
                    push            {r7, lr}
                    movs            r7, #FSM_STATE_BUTTONS_CHANGED  @ just check for any button press
                    rev16           r3, r0
                    tst             r3, r7
                    beq             8f
                    tst             r2, r0                          @ buttonToMove button pressed?
                    beq             1f
                    movs            r0, r1                          @ move to new state
                    b               9f
1:
                    movs            r3, #FSM_BUTTON_LEFT | FSM_BUTTON_RIGHT | FSM_BUTTON_ACTION
                    tst             r3, r0
                    beq             8f
                    ldr             r0, = #FsmMenus_initConfigurationMenu @ otherwise return to the configuration menu
                    b               9f
8:
                    movs            r0, #0
9:
                    pop             {r7, pc}


       .end
