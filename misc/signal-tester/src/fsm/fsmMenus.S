/*
 * Copyright (c) 2015 The NW1 Group
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#include "moduleInfo.inc"

@ Finite State Machine functions for all menus

    module(FsmMenus)

    .extern         Display_drawAlignedString                       @ draw a aligned single line characters
    .extern         Display_blitDisplayBuffer                       @ draw the display buffer onto the display
    .extern         Display_clearDisplayBuffer                      @ clear the display buffer
    .extern         Display_drawFilledRectangle                     @ draw a filled rectangle
    .extern         Display_fillRow                                 @ fill a row with colour

    .extern         FsmPwmSetup_initPwmSetup                        @ PWM LED Setup init
    .extern         FsmServoSetup_initServoSetup                    @ Server setup init
    .extern         FsmWhiteTest_initWhiteTest                      @ RGB LED test using white setup init
    .extern         FsmAspectTest_initAspectTest                    @ RGB LED test using different aspects setup init
    .extern         FsmHelp_initHelp                                @ Help init

    private_data(FsmMenus_privateData)

FsmMenus_currentMenu:
                    .int            0                               @ pointer to the current menu configuration
FsmMenus_currentPos:
                    .short          0                               @ position with in the menu configuration
FsmMenus_noEntries:
                    .short          0                               @ number of entries in this menu

    static_data(FsmMenus_const)

FsmMenus_const:                                                     @ Constant strings

FsmMenus_main:                                                      @ Main Menu constants
rgbSignalSetup:     .string         "> RGB Signal Setup"
rgbSignalTest:      .string         "> RGB Signal Test..."
servoSetup:         .string         "> Servo Setup"
pwmLedSetup:        .string         "> PWM LED Setup"
configure:          .string         "> Configure"
help:               .string         "> Help"

FsmMenus_signalTest:
stWhiteTest:        .string         "> White Test"
stAspectTest:       .string         "> Aspect Test"
stMainMenu:         .string         "> Back to main menu"

FsmMenus_servoSave:
ssTitle:            .string         "Save Servo Settings"
ssSave:             .string         "> Save Settings to EEPROM"
ssReturn:           .string         "> Return"
ssMainMenu:         .string         "> Back to main menu"

FsmMenus_signalSave:
sigTitle:           .string         "Save Signal Colour Settings"
sigSaveRed:         .string         "> Save As Red Aspect Colour"
sigSaveYellow:      .string         "> Save As Yellow Aspect Colour"
sigSaveGreen:       .string         "> Save As Green Aspect Colour"
sigSaveWhite:       .string         "> Save As White Colour"

                    .balign         4                               @ align these data structures to 4 byte boundary
                    .align          4

FsmMenus_mainMenuConf:                                              @ Main menu configuration
                    .int            rgbSignalSetup, FsmSignalSetup_initSignalSetup
                    .int            rgbSignalTest, FsmMenus_initSignalTestMenu
                    .int            servoSetup, FsmServoSetup_initServoSetup
                    .int            pwmLedSetup, FsmPwmSetup_initPwmSetup
                    .int            configure, 0
                    .int            help, FsmHelp_initHelp
FsmMenus_mainMenuConfEnd:

FsmMenus_stMenuConf:
                    .int            stWhiteTest, FsmWhiteTest_initWhiteTest
                    .int            stAspectTest, FsmAspectTest_initAspectTest
                    .int            stMainMenu, FsmMenus_initMainMenu
FsmMenus_stMenuConfEnd:

FsmMenus_ssMenuConf:
                    .int            ssSave, 0
                    .int            ssReturn, FsmServoSetup_initServoSetup
                    .int            ssMainMenu, FsmMenus_initMainMenu
FsmMenus_ssMenuConfEnd:

FsmMenus_sigMenuConf:
                    .int            sigSaveRed, 0
                    .int            sigSaveYellow, 0
                    .int            sigSaveGreen, 0
                    .int            sigSaveWhite, 0
                    .int            ssReturn, FsmSignalSetup_initSignalSetup
                    .int            ssMainMenu, FsmMenus_initMainMenu
FsmMenus_sigMenuConfEnd:

    public_function(FsmMenus_initMainMenu)

@ int FsmMenus_initMainMenu(short redValue, short blueValue, short greenValue, int buttonsAndStatus)
@   FSM Routine for initialising the main menu. Returns the next state, or 0 to remain in the same state

FsmMenus_initMainMenu:
                    push            {r7, lr}
                    ldr             r0, = #FsmMenus_mainMenuConf
                    movs            r1, (FsmMenus_mainMenuConfEnd-FsmMenus_mainMenuConf)/8
                    ldr             r2, = #FsmCommon_title
                    bl              FsmMenus_initMenu
                    pop             {r7, pc}

    public_function(FsmMenus_initSignalTestMenu)

@ int FsmMenus_initSignalTestMenu(short redValue, short blueValue, short greenValue, int buttonsAndStatus)
@   FSM Routine for initialising the signal test menu. Returns the next state, or 0 to remain in the same state

FsmMenus_initSignalTestMenu:
                    push            {r7, lr}
                    ldr             r0, = #FsmMenus_stMenuConf
                    movs            r1, (FsmMenus_stMenuConfEnd-FsmMenus_stMenuConf)/8
                    ldr             r2, = #(rgbSignalTest + 2)
                    bl              FsmMenus_initMenu
                    pop             {r7, pc}

    public_function(FsmMenus_initServoSaveMenu)

@ int FsmMenus_initServoSaveMenu(short redValue, short blueValue, short greenValue, int buttonsAndStatus)
@   FSM Routine for initialising the signal test menu. Returns the next state, or 0 to remain in the same state

FsmMenus_initServoSaveMenu:
                    push            {r7, lr}
                    ldr             r0, = #FsmMenus_ssMenuConf
                    movs            r1, (FsmMenus_ssMenuConfEnd-FsmMenus_ssMenuConf)/8
                    ldr             r2, = #(ssTitle)
                    bl              FsmMenus_initMenu
                    pop             {r7, pc}

    public_function(FsmMenus_initSignalSaveMenu)

@ int FsmMenus_initSignalSaveMenu(short redValue, short blueValue, short greenValue, int buttonsAndStatus)
@   FSM Routine for initialising the signal test menu. Returns the next state, or 0 to remain in the same state

FsmMenus_initSignalSaveMenu:
                    push            {r7, lr}
                    ldr             r0, = #FsmMenus_sigMenuConf
                    movs            r1, (FsmMenus_sigMenuConfEnd-FsmMenus_sigMenuConf)/8
                    ldr             r2, = #(sigTitle)
                    bl              FsmMenus_initMenu
                    pop             {r7, pc}

    private_function(FsmMenus_initMenu)

@ int FsmMenus_initMenu(int* menuConf, int menuSize, char* title)
@   init access to a menu, display the menu title, and store vars. Returns next state

FsmMenus_initMenu:
                    push            {r5-r7, lr}
                    movs            r5, r0
                    lsls            r6, r1, #16
                    movs            r7, r2
                    bl              Display_clearDisplayBuffer
                    movs            r0, #DISPLAY_CENTER_ALIGN
                    ldr             r1, = #(0 | DISPLAY_ROW)
                    movs            r2, #1
                    movs            r3, r7
                    bl              Display_drawAlignedString
                    movs            r0, #0
                    ldr             r1, = #(1 | DISPLAY_ROW)
                    movs            r2, #1
                    ldr             r3, [r5]
                    bl              Display_drawString
                    bl              Display_blitDisplayBuffer

                    ldr             r0, = #FsmMenus_currentMenu
                    str             r5, [r0]
                    str             r6, [r0, #4]
                    ldr             r0, = #FsmMenus_handleMenu
                    pop             {r5-r7, pc}

    private_function(FsmMenus_handleMenu)

@ int FsmMenus_handleMenu(short redValue, short blueValue, short greenValue, int buttonsAndStatus)
@   FSM Routine for handle menus, allow the user to scroll up and down the menu, and to choose a menu option.
@   Returns the next state, or 0 to remain in the same state

FsmMenus_handleMenu:
                    push            {r5-r7, lr}
                    ldr             r7, = #FsmMenus_currentMenu
                    lsrs            r6, r3, #8                      @ if non buttons have been pressed, then nothing
                    movs            r0, #FSM_STATE_BUTTONS_CHANGED
                    tst             r0, r6
                    beq             9f
                    movs            r0, #FSM_BUTTON_LEFT            @ was the left button pressed?
                    tst             r0, r3
                    beq             0f
                    ldrh            r6, [r7, #4]
                    cmp             r6, #0                          @ are we at the start?
                    beq             9f                              @ if so just return
                    subs            r6, r6, #1
                    strh            r6, [r7, #4]
                    b               8f
0:
                    movs            r0, #FSM_BUTTON_RIGHT           @ was the right button pressed?
                    tst             r0, r3
                    beq             1f
                    ldrh            r6, [r7, #4]                    @ get current position
                    ldrh            r2, [r7, #6]                    @ and the size of the menu
                    subs            r2, r2, #1                      @ make the size zero based
                    cmp             r6, r2
                    beq             9f                              @ if the same, then end of the menu, just return
                    adds            r6, r6, #1
                    strh            r6, [r7, #4]
                    b               8f
1:
                    movs            r0, #FSM_BUTTON_ACTION          @ was the right button pressed?
                    tst             r0, r3
                    beq             9f
                    ldrh            r0, [r7, #4]                    @ get current position
                    lsls            r0, r0, #3
                    adds            r0, r0, #4                      @ get action function pointer
                    ldr             r7, [r7]
                    ldr             r0, [r7, r0]                    @ if not implemented, returns 0, to stay on the
                    b               actionReturn                    @ same menu
8:
                    movs            r0, #0
                    ldr             r1, = #(1 | DISPLAY_ROW)
                    movs            r2, #0
                    movs            r3, #DISPLAY_WIDTH
                    bl              Display_fillRow

                    movs            r0, #0
                    ldr             r1, = #(1 | DISPLAY_ROW)
                    movs            r2, #1
                    lsls            r6, r6, #3
                    ldr             r7, [r7]
                    ldr             r3, [r7, r6]
                    bl              Display_drawString              @ display new menu line
                    bl              Display_blitDisplayBuffer
9:
                    movs            r0, #0
actionReturn:
                    pop             {r5-r7, pc}

    .end
