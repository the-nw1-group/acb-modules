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

@ Finite State Machine functions for saving servo settings

   module(FsmServoSave)

    .extern         Display_drawAlignedString                       @ draw a aligned single line characters
    .extern         Display_blitDisplayBuffer                       @ draw the display buffer onto the display
    .extern         Display_clearDisplayBuffer                      @ clear the display buffer
    .extern         Display_fillRow                                 @ fill a row in the display buffer
    .extern         Configuration_addNew                            @ save a new record
    .extern         FsmServoSetup_initServoSetup
    .extern         FsmCommon_delayFor                              @ delay for a time
    .extern         itoa                                            @ convert integer to string

    private_data(FsmSignalSave_private)

FsmServoSave_buffer:
                    .string         "    "

    static_data(FsmServoSave_const)

FsmServoSave_const:
title:              .string         "Saving Servo Settings"
pleaseWait:         .string         "Please Wait..."
success:            .string         "Settings Saved at"
error:              .string         "Error: Memory Full"

    public_function(FsmServoSave_initServoSave)

@ int FsmServoSave_initServoSave(short redValue, short blueValue, short greenValue, int buttonsAndStatus)
@   FSM Routine for the Servo Save routines. Returns the next state, or 0 to remain in the same state

FsmServoSave_initServoSave:
                    push            {r7, lr}
                    bl              Display_clearDisplayBuffer      @ display title
                    movs            r0, #DISPLAY_CENTER_ALIGN
                    ldr             r1, = #(0 | DISPLAY_ROW)
                    movs            r2, #1
                    ldr             r3, = #title
                    bl              Display_drawAlignedString
                    movs            r0, #DISPLAY_LEFT_ALIGN         @ and please wait message
                    ldr             r1, = #(1 | DISPLAY_ROW)
                    movs            r2, #1
                    ldr             r3, = #pleaseWait
                    bl              Display_drawAlignedString
                    bl              Display_blitDisplayBuffer
                    ldr             r0, = #FsmServoSave_doServoSave
                    pop             {r7, pc}

    public_function(FsmServoSave_doServoSave)

@ int FsmServoSave_doServoSave(short redValue, short blueValue, short greenValue, int buttonsAndStatus)
@   FSM Routine for the saving servo settings. Returns the next state, or 0 to remain in the same state

FsmServoSave_doServoSave:
drawValueOffset = 74
                    push            {r7, lr}
                    movs            r0, #0                          @ clear row, and display the template
                    ldr             r1, = #(1 | DISPLAY_ROW)
                    movs            r2, #0
                    movs            r3, #DISPLAY_WIDTH
                    bl              Display_fillRow

                    movs            r0, #CONFIG_REC_DATA            @ save the last settings to the configuration
                    movs            r1, #CONFIG_DATA_SERVO          @ manager
                    ldr             r7, = #FsmServoSetup_start
                    ldrb            r3, [r7]
                    ldrb            r2, [r7, #1]
                    lsls            r2, r2, #16
                    orrs            r3, r3, r2
                    ldrb            r2, [r7, #2]
                    lsls            r2, r2, #24
                    orrs            r2, r2, r3
                    movs            r3, #0
                    bl              Configuration_addNew
                    adds            r1, r0, #1
                    bne             8f
                    ldr             r7, = #error
0:
                    movs            r0, #0                          @ display success or error text
                    ldr             r1, = #(1 | DISPLAY_ROW)
                    movs            r2, #1
                    movs            r3, r7
                    bl              Display_drawString
                    bl              Display_blitDisplayBuffer

                    ldr             r0, = #400
                    ldr             r1, = #FsmServoSetup_initServoSetup
                    bl              FsmCommon_delayFor
                    pop             {r7, pc}
8:                                                                  @ convert slot to ascii, so we can display it
                    ldr             r1, = #FsmServoSave_buffer
                    movs            r2, #10                         @ convert to base 10
                    bl              itoa
                    movs            r3, r0
                    movs            r0, #drawValueOffset
                    ldr             r1, = #(1 | DISPLAY_ROW)
                    movs            r2, #1
                    bl              Display_drawString
                    ldr             r7, = #success
                    b               0b

   .end
