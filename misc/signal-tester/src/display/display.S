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
    .extern         DisplayType_clearBuffer                         @ Clear the display buffer
    .extern         DisplayType_blitBuffer                          @ Copy the display buffer to the device
    .extern         DisplayType_showDisplay                         @ Turn on the display
    .extern         DisplayType_hideDisplay                         @ Turn off the display
    .extern         DisplayType_setContrast                         @ Set the display contrast

    public_function(Display_init)

@ bool Display_init(void)
@   Initialise the display. Returns TRUE if the initialisation was successful, otherwise FALSE

Display_init:
                    push            {r7, lr}
                    bl              DisplayType_init                @ initialise the display type
                    cmp             r0, #ERROR
                    beq             9f
                    bl              DisplayType_clearBuffer
                    bl              DisplayType_blitBuffer
                    cmp             r0, #ERROR
                    beq             9f
                    bl              DisplayType_showDisplay

    sub     sp, sp, #12
    movs    r7, #5
    str     r7, [sp]
    movs    r0, #20
    movs    r1, #3
    movs    r2, #1
    movs    r3, #40
    bl      Display_drawFilledRectangle
    add     sp, sp, #12
    bl      DisplayType_blitBuffer
    b       .


9:
                    pop             {r7, pc}

    public_function(Display_showDisplay)

@ bool Display_showDisplay(void)
@   Turn the display on. Returns TRUE if the initialisation was successful, otherwise FALSE

Display_showDisplay:
                    b               DisplayType_showDisplay

    public_function(Display_hideDisplay)

@ bool Display_hideDisplay(void)
@   Turn the display on. Returns TRUE if the initialisation was successful, otherwise FALSE

Display_hideDisplay:
                    b               DisplayType_hideDisplay

    public_function(Display_setContrast)

@ bool Display_setContrast(byte contrast)
@   set the display contrast level. Contrast value between 0 and 255. Returns TRUE if the initialisation was successful,
@   otherwise FALSE

Display_setContrast:
                    b               DisplayType_setContrast

    public_function(Display_blitDisplayBuffer)

@ bool Display_blitDisplayBuffer(void)
@   send the contents of the display buffer to the display. Returns TRUE if the initialisation was successful,
@   otherwise FALSE

Display_blitDisplayBuffer:
                    b               DisplayType_blitBuffer

    public_function(Display_clearDisplayBuffer)

@ void Display_clearDisplayBuffer(void)
@   clear the contents of the display buffer. This doesn't write to the display

Display_clearDisplayBuffer:
                    b               DisplayType_clearBuffer

    public_function(Display_drawPixel)

@ int Display_drawPixel(int x, int y, bool colour)
@   set (colour=1)/clear (colour=0) a pixel in the display buffer. This doesn't write to the display.
@   Returns a display status

Display_drawPixel:
                    mov             r12, lr                         @ save off link return
                    movs            r5, r0                          @ save off x
                    bl              Display_checkPixelRange
                    cmp             r0, #DISPLAY_OK
                    bne             9f
                    movs            r0, r5                          @ restore x
                    b               DisplayType_drawPixel
9:
                    bx              r12

    public_function(Display_setPixel)

@ int Display_setPixel(int x, int y)
@   set a pixel in the display buffer. This doesn't write to the display
@   Returns a display status

Display_setPixel:
                    mov             r12, lr                         @ save off link return
                    movs            r5, r0                          @ save off x
                    bl              Display_checkPixelRange
                    cmp             r0, #DISPLAY_OK
                    bne             9f
                    movs            r0, r5                          @ restore x
                    b               DisplayType_setPixel
9:
                    bx              r12

    public_function(Display_clearPixel)

@ int Display_clearPixel(int x, int y)
@   set a pixel in the display buffer. This doesn't write to the display
@   Returns a display status

Display_clearPixel:
                    mov             r12, lr                         @ save off link return
                    movs            r5, r0                          @ save off x
                    bl              Display_checkPixelRange
                    cmp             r0, #DISPLAY_OK
                    bne             9f
                    movs            r0, r5                          @ restore x
                    b               DisplayType_clearPixel
9:
                    bx              r12

    public_function(Display_drawHorizontalLine)

@ int Display_drawHorizontalLine(int x, int yOrRowm, byte colour, int length)
@   draw horiztonal line in the selected colour
@   Returns a display status

Display_drawHorizontalLine:
                    push            {r3-r7, lr}
                    cmp             r3, #0                          @ if length is zero, or less, nothing to draw
                    ble             7f
                    bl              Display_getPixelY               @ convert Y to pixel, if it's a row value
                    movs            r5, r0                          @ save x
                    bl              Display_checkPixelRange
                    cmp             r0, #DISPLAY_OK
                    bne             9f
                    movs            r6, r1                          @ save y
                    movs            r7, r2                          @ save colour
                    movs            r4, r3                          @ save length
0:
                    movs            r0, r5                          @ draw a pixel
                    movs            r1, r6
                    movs            r2, r7
                    bl              DisplayType_drawPixel
                    adds            r5, r5, #1
                    cmp             r5, #DISPLAY_WIDTH              @ if over the DISPLAY_WIDTH, return clipped
                    bge             8f
                    subs            r4, r4, #1
                    bne             0b
7:
                    movs            r0, #DISPLAY_OK
                    b               9f
8:
                    movs            r0, #DISPLAY_CLIPPED_HBIT
9:
                    pop             {r3-r7, pc}

    public_function(Display_drawVerticalLine)

@ int Display_drawVerticalLine(int x, int yOrRowm, byte colour, int length)
@   draw vertical line in the selected colour
@   Returns a display status

Display_drawVerticalLine:
                    push            {r3-r7, lr}
                    cmp             r3, #0                          @ if length is zero, or less, nothing to draw
                    ble             7f
                    bl              Display_getPixelY               @ convert Y to pixel, if it's a row value
                    movs            r5, r0                          @ save x
                    bl              Display_checkPixelRange
                    cmp             r0, #DISPLAY_OK
                    bne             9f
                    movs            r6, r1                          @ save y
                    movs            r7, r2                          @ save colour
                    movs            r4, r3                          @ save length
0:
                    movs            r0, r5                          @ draw a pixel
                    movs            r1, r6
                    movs            r2, r7
                    bl              DisplayType_drawPixel
                    adds            r6, r6, #1
                    cmp             r6, #DISPLAY_HEIGHT             @ if over the DISPLAY_HEIGHT, return clipped
                    bge             8f
                    subs            r4, r4, #1
                    bne             0b
7:
                    movs            r0, #DISPLAY_OK
                    b               9f
8:
                    movs            r0, #DISPLAY_CLIPPED_VBIT
9:
                    pop             {r3-r7, pc}

    public_function(Display_drawRectangle)

@ int Display_drawRectangle(int x, int yOrRowm, byte colour, int length, int height)
@   draw hollow rectangle in the selected colour
@   Returns a display status

Display_drawRectangle:
                    push            {r3-r7, lr}
                    cmp             r3, #0                          @ if length or height are zero, then just return
                    ble             8f
                    ldr             r4, [sp, #0+24]                 @ retrieve height from stack
                    cmp             r4, #0
                    ble             8f
                    bl              Display_getPixelY               @ convert Y to pixel, if it's a row value
                    movs            r5, r0                          @ save x
                    bl              Display_checkPixelRange
                    cmp             r0, #DISPLAY_OK
                    bne             9f

                    mov             r6, r8                          @ save r8-r9
                    mov             r7, r9
                    push            {r6-r7}

                    movs            r6, r0                          @ save off X
                    movs            r7, r1                          @ save off Y
                    mov             r8, r2                          @ save off colour
                    mov             r9, r3                          @ save off length
                    movs            r5, #DISPLAY_OK                 @ set initial result as OK

                    bl              Display_drawHorizontalLine      @ draw top line
                    orrs            r5, r5, r0                      @ save result
                    movs            r0, r6
                    movs            r1, r7
                    add             r1, r1, r4
                    subs            r1, #1
                    mov             r2, r8
                    mov             r3, r9
                    bl              Display_drawHorizontalLine      @ draw bottom line
                    orrs            r5, r5, r0                      @ save result
                    movs            r0, r6
                    adds            r1, r7, #1                      @ don't overwrite pixels already drawn...
                    mov             r2, r8
                    subs            r3, r4, #2
                    bl              Display_drawVerticalLine        @ draw left line
                    orrs            r5, r5, r0                      @ save result
                    subs            r0, r6, #1
                    add             r0, r0, r9
                    adds            r1, r7, #1                      @ don't overwrite pixels already drawn...
                    mov             r2, r8
                    subs            r3, r4, #2
                    bl              Display_drawVerticalLine        @ draw right line
                    orrs            r5, r5, r0                      @ save result

                    movs            r0, r5                          @ return status
                    pop             {r6-r7}                         @ restore r8-r9
                    mov             r8, r6
                    mov             r9, r7
                    b               9f
8:
                    movs            r0, #DISPLAY_OK
                    b               9f
9:
                    pop             {r3-r7, pc}

    public_function(Display_drawFilledRectangle)

@ int Display_drawFilledRectangle(int x, int yOrRowm, byte colour, int length, int height)
@   draw filled rectangle in the selected colour
@   Returns a display status

Display_drawFilledRectangle:
                    push            {r3-r7, lr}
                    cmp             r3, #0                          @ if length or height are zero, then just return
                    ble             8f
                    ldr             r4, [sp, #0+24]                 @ retrieve height from stack
                    cmp             r4, #0
                    ble             8f
                    bl              Display_getPixelY               @ convert Y to pixel, if it's a row value
                    movs            r5, r0                          @ save x
                    bl              Display_checkPixelRange
                    cmp             r0, #DISPLAY_OK
                    bne             9f

                    mov             r5, r8                          @ save r8-r10
                    mov             r6, r9
                    mov             r7, r10
                    push            {r4-r7}

                    movs            r7, r0                          @ save off X
                    mov             r8, r1                          @ save off Y
                    mov             r9, r2                          @ save off colour
                    mov             r10, r3                         @ save off length
                    movs            r5, #DISPLAY_OK                 @ set initial result as OK
                    movs            r6, #0                          @ counter
0:
                    movs            r0, r7
                    mov             r1, r8
                    adds            r1, r1, r6
                    mov             r2, r9
                    mov             r3, r10
                    bl              Display_drawHorizontalLine      @ draw line
                    orrs            r5, r5, r0                      @ save result
                    movs            r1, #DISPLAY_CLIPPED_VERT       @ if vertically clipped, then just end...
                    tst             r5, r0
                    bne             7f
                    adds            r6, r6, #1
                    cmp             r6, r4
                    bne             0b
7:
                    movs            r0, r5                          @ return status
                    pop             {r4-r7}                         @ restore r8-r10
                    mov             r8, r5
                    mov             r9, r6
                    mov             r10, r7
                    b               9f
8:
                    movs            r0, #DISPLAY_OK
                    b               9f
9:
                    pop             {r3-r7, pc}

    private_function(Display_checkPixelRange)

@ int Display_checkPixelRange(int x, int y)
@   checks if pixel coordinates are out of range, returns display status
@   Implementation note: preserves all registers other than r0, status and link return (lr)

Display_checkPixelRange:
                    push            {r5-r7, lr}
                    movs            r6, #DISPLAY_CLIPPED_VERT
                    movs            r7, r0                          @ copy x to r7
                    movs            r0, #0                          @ clear result
                    cmp             r7, #0                          @ is x < 0
                    bge             0f
                    movs            r0, #DISPLAY_CLIPPED_HORZ
                    b               1f
0:
                    cmp             r7, #DISPLAY_WIDTH              @ is x > DISPLAY_WIDTH
                    blt             1f
                    movs            r0, #DISPLAY_CLIPPED_HORZ
1:
                    cmp             r1, #0                          @ is y < 0
                    bge             2f
                    orrs            r0, r0, r6
                    b               3f
2:
                    cmp             r1, #DISPLAY_WIDTH              @ is y > DISPLAY_HEIGHT
                    blt             3f
                    orrs            r0, r0, r6
3:
                    pop             {r5-r7, pc}

    private_function(Display_getPixelY)

@ void Display_getPixelY(int x, int* yOrRow)
@   converts a vertical row/pixel value to a pixel value, x not used...
@   Implementation note: preserves all registers other than r1, status and link return (lr)

Display_getPixelY:
noRows = (DISPLAY_HEIGHT / 16)
                    push            {r7, lr}
                    cmp             r1, #0                          @ if y is zero, just return
                    beq             9f
                    ldr             r7, = #DISPLAY_ROW              @ if the DISPLAY_ROW bit isn't set, then just return
                    tst             r1, r7
                    beq             9f
                    movs            r7, #(noRows-1)
                    ands            r1, r1, r7
                    lsls            r1, r1, #4
9:
                    pop             {r7, pc}

    .end
