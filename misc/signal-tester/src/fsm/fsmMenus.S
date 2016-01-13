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

    static_data(FsmMenus_const)
FsmMenus_const:
rgbSignalSetup:     .string         "> RGB Signal Setup"            @ Main Menu constants
rgbSignalTest:      .string         "> RGB Signal Test"
servoSetup:         .string         "> Servo Setup"
pwmLedSetup:        .string         "> PWM LED Setup"
configure:          .string         "> Configure"


    public_function(FsmMenus_initMainMenu)

@ int FsmMenus_initMainMenu(short redValue, short blueValue, short greenValue, int buttonsAndStatus)
@   FSM Routine for initialising the main menu. Returns the next state, or 0 to remain in the same state

FsmMenus_initMainMenu:
                    push            {r7, lr}
                    bl              Display_clearDisplayBuffer
                    bl              Display_blitDisplayBuffer
                    ldr             r0, = #0 //FsmCommon_splashTimeout
                    pop             {r7, pc}


    .end
