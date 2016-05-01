/*
 * Copyright (c) 2015 The NW1 Group
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#include "moduleInfo.inc"

@ Finite State Machine functions for the help system

    module(FsmHelp)

    .extern         FsmMenus_initMainMenu                           @ init and show the main menu
    .extern         FsmCommon_showInstructions                      @ show instructions
    .extern         FsmCommon_anyKeyPressed                         @ check if any key pressed

    static_data(FsmHelp_const)

FsmHelp_const:

title:              .string         "Help"
help1:              .string         "Select an item from the menu"
help2:              .string         "by using the Back, Forward and"
help3:              .string         "Action buttons to select a menu"
help4:              .string         "item."
help5:              .string         "Each section will begin with a"
help6:              .string         "brief set of instructions before"
help7:              .string         "you can use that area."
help19:             .string         "During the instructions you can"
help20:             .string         "press any button to skip them"
help21:             .string         "(also during these help pages)"
help8:              .string         "Back: moves back or returns to"
help9:              .string         "the previous menu."
help10:             .string         "Next: moves forward or cont-"
help11:             .string         "inues to the next part."
help12:             .string         "Action: selects an item or"
help13:             .string         "performs an action."
help14:             .string         "Use the 3 knobs on the left"
help15:             .string         "to select variable inputs."
help16:             .string         "They are (R)ed, (G)reen, (B)lue"
help17:             .string         "If one variable input is required"
help18:             .string         "the top knob, Red, is used."
help99:             .string         "Click any button to go back"

                    .balign         4                               @ align these data structures to 4 byte boundary
                    .align          4

helpTable:
                    .int             help1,  help2,  help3,  help4
                    .int             help5,  help6,  help7, help19
                    .int            help20, help21,  help8
                    .int             help9, help10, help11, help12
                    .int            help13, help14, help15, help16
                    .int            help17, help18
                    .int            help99
helpTableEnd:

   public_function(FsmHelp_initHelp)

@ int FsmPwmSetup_initPwmSetup(short redValue, short blueValue, short greenValue, int buttonsAndStatus)
@   FSM Routine for showing the help system. Returns the next state, or 0 to remain in the same state

FsmHelp_initHelp:
                    push            {r7, lr}
                    bl              Display_clearDisplayBuffer      @ display title
                    movs            r0, #DISPLAY_CENTER_ALIGN
                    ldr             r1, = #(0 | DISPLAY_ROW_FLAG)
                    movs            r2, #1
                    ldr             r3, = #title
                    bl              Display_drawAlignedString

                    ldr             r0, = #helpTable                @ show the help
                    movs            r1, #(helpTableEnd-helpTable)
                    ldr             r2, = #FsmHelp_exitHelp
                    bl              FsmCommon_showInstructions
                    pop             {r7, pc}

   private_function(FsmHelp_exitHelp)

@ int FsmHelp_exitHelp(short redValue, short blueValue, short greenValue, int buttonsAndStatus)
@   FSM Routine for exiting the help system. Returns the next state, or 0 to remain in the same state

FsmHelp_exitHelp:
                    push            {r7, lr}
                    movs            r1, r3
                    ldr             r0, = #FsmMenus_initMainMenu
                    bl              FsmCommon_anyKeyPressed
                    cmp             r0, #0
                    bne             9f

                    movs            r0, #0                          @ display the press any key button
                    ldr             r1, = #(1 | DISPLAY_ROW_FLAG)   @ (yes a bit of a kludge)
                    movs            r2, #0
                    movs            r3, #ACB_DISPLAY_WIDTH
                    bl              Display_fillRow
                    movs            r0, #0
                    ldr             r1, = #(1 | DISPLAY_ROW_FLAG)
                    movs            r2, #1
                    ldr             r3, = #help99
                    bl              Display_drawString
                    bl              Display_blitDisplayBuffer
                    movs            r0, #0
9:
                    pop             {r7, pc}

    .end
