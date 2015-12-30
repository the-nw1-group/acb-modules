/*
 * Copyright (c) 2015 The NW1 Group
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#include "moduleInfo.inc"

@ Display routines

    module(Display)

    .extern         DisplayType_init                                @ Initialise the display

    public_function(Display_init)

@ bool Display_init(void)
@   Initialise the display. Returns TRUE if the initialisation was successful, otherwise FALSE

Display_init:
                    push            {r7, lr}
                    bl              DisplayType_init                @ initialise the display type
                    cmp             r0, #ERROR
                    beq             __diFail
                    bl              DisplayType_clearBuffer
                    bl              DisplayType_blitBuffer
                    cmp             r0, #ERROR
                    beq             __diFail
                    bl              DisplayType_showDisplay
                    cmp             r0, #ERROR
                    beq             __diFail

    movs    r0, #0xff
    bl      DisplayType_setContrast
    cmp     r0, #ERROR
    beq     __diFail

    movs    r7, #0x55
    movs    r6, #0
    movs    r5, #0
__pixelInnerLoop:
    movs    r0, r5
    movs    r1, r6
    movs    r2, #1
    movs    r3, r7
    bl      DisplayType_drawHorizontalByte
    bl      DisplayType_blitBuffer
    cmp     r0, #ERROR
    beq     __diFail

    adds    r5, r5, #8
    cmp     r5, #DISPLAY_WIDTH
    blt     __pixelInnerLoop
    movs    r5, #0
    adds    r6, r6, #1
    cmp     r6, #DISPLAY_HEIGHT
    blt     __pixelInnerLoop
    movs    r6, #0
    mvns    r7, r7
    b       __pixelInnerLoop


9:
                    pop             {r7, pc}
__diFail:
                    movs            r0, #SIGTEST_DISPLAY_INIT_FAIL
                    svc             ACB_FATAL_ERROR

    .end
