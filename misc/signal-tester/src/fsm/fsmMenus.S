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

    .extern         Setup_setup                                     @ setup hardware and peripherals
    .extern         Display_drawAlignedString                       @ draw a aligned single line characters
    .extern         Display_blitDisplayBuffer                       @ draw the display buffer onto the display
    .extern         Display_clearDisplayBuffer                      @ clear the display buffer
    .extern         Display_drawFilledRectangle                     @ draw a filled rectangle

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
rgbSignalTest:      .string         "> RGB Signal Test"
servoSetup:         .string         "> Servo Setup"
pwmLedSetup:        .string         "> PWM LED Setup"
configure:          .string         "> Configure"

                    .balign         4                               @ align these data structures to 4 byte boundary
                    .align          4

FsmMenus_mainMenuConf:                                              @ Main menu configuration
                    .int            rgbSignalSetup, 0
                    .int            rgbSignalTest, 0
                    .int            servoSetup, 0
                    .int            pwmLedSetup, 0
                    .int            configure, 0
FsmMenus_mainMenuConfEnd:

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


                    b               9f
8:
                    movs            r0, #0
                    ldr             r1, = #(1 | DISPLAY_ROW)
                    movs            r2, #0
                    add             sp, sp, #8
                    movs            r3, #DISPLAY_ROW_HEIGHT
                    str             r3, [sp]
                    movs            r3, #DISPLAY_WIDTH
                    bl              Display_drawFilledRectangle     @ clear the menu line
                    sub             sp, sp, #8

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
                    pop             {r5-r7, pc}

    .end
