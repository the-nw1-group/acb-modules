/*
 * Copyright (c) 2015 The NW1 Group
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#include "moduleInfo.inc"

#ifdef ACB_USE_DISPLAY

@ Display routines

    module(Display)

    .extern         DisplayType_init                                @ Initialise the display
    .extern         DisplayType_clearBuffer                         @ Clear the display buffer
    .extern         DisplayType_blitBuffer                          @ Copy the display buffer to the device
    .extern         DisplayType_showDisplay                         @ Turn on the display
    .extern         DisplayType_hideDisplay                         @ Turn off the display
    .extern         DisplayType_setContrast                         @ Set the display contrast

   private_data(Display_private)

fontPtr:            .word           0                               @ pointer to currently selected font


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

@ int Display_drawHorizontalLine(int x, int yOrRow, byte colour, int length)
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
                    cmp             r5, #ACB_DISPLAY_WIDTH          @ if over the ACB_DISPLAY_WIDTH, return clipped
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

@ int Display_drawVerticalLine(int x, int yOrRow, byte colour, int length)
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
                    cmp             r6, #ACB_DISPLAY_HEIGHT         @ if over the ACB_DISPLAY_HEIGHT, return clipped
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

@ int Display_drawRectangle(int x, int yOrRow, byte colour, int length, int height)
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

@ int Display_drawFilledRectangle(int x, int yOrRow, byte colour, int length, int height)
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
                    movs            r0, r5                          @ restore r0

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

    public_function(Display_fillRow)

@ int Display_fillRow(int x, int row, byte colour, int length)
@   draw filled rectangle in the selected colour
@   Returns a display status

Display_fillRow:
                    push            {r7, lr}
                    sub             sp, sp, #8
                    movs            r7, #DISPLAY_ROW_HEIGHT
                    str             r7, [sp]
                    bl              Display_drawFilledRectangle     @ fill rectangle
                    add             sp, sp, #8
                    pop             {r7, pc}

    public_function(Display_setFont)

@ void Display_setFont(__font_data* font)
@   sets the font for any text/character drawing operations

Display_setFont:
                    ldr             r1, = #fontPtr
                    str             r0, [r1]
                    bx              lr

    public_function(Display_getFont)

@ __font_data* Display_setFont()
@   gets the font for any text/character drawing operations

Display_getFont:
                    ldr             r1, = #fontPtr
                    ldr             r0, [r1]
                    bx              lr

    public_function(Display_drawChar)

@ int Display_drawChar(int x, int yOrRow, byte colour, char c)
@   draw a single ASCII character
@   Returns a display status

Display_drawChar:
                    push            {r5-r7, lr}
                    bl              Display_getPixelY               @ convert Y to pixel, if it's a row value
                    movs            r5, r0                          @ save x
                    bl              Display_checkPixelRange
                    cmp             r0, #DISPLAY_OK
                    bne             9f
                    movs            r0, r5                          @ restore x
                    bl              Display_drawFontGlyph
                    uxth            r0, r0                          @ clear width, from status
9:
                    pop             {r5-r7, pc}

    public_function(Display_drawString)

@ int Display_drawData(int x, int yOrRow, byte colour, char* str)
@   draw a single line of null terminated characters
@   Returns a display status

Display_drawString:
                    push            {r5-r7, lr}
                    cmp             r3, #0                          @ null string
                    beq             8f                              @ then just return
                    bl              Display_getPixelY               @ convert Y to pixel, if it's a row value
                    movs            r5, r0                          @ save x
                    bl              Display_checkPixelRange
                    cmp             r0, #DISPLAY_OK
                    bne             9f
                    movs            r0, r5                          @ restore x
                    bl              Display_drawStringData
9:
                    pop             {r5-r7, pc}
8:
                    movs            r0, #DISPLAY_OK
                    b               9b

    public_function(Display_drawAlignedString)

@ int Display_drawData(int alignment, int yOrRow, byte colour, char* str)
@   draw a single line of null terminated characters - alignment can be a combination of:
@       DISPLAY_CENTER_ALIGN_BIT, DISPLAY_RIGHT_ALIGN_BIT
@   if neither DISPLAY_CENTER_ALIGN_BIT or DISPLAY_RIGHT_ALIGN_BIT is set the text will be left aligned. If both
@   are set then the text will be center aligned. No string is shown in the string would clip horizontally in center or
@   right align mode.
@   Returns a display status

Display_drawAlignedString:
                    push            {r5-r7, lr}
                    bl              Display_getPixelY               @ convert Y to pixel, if it's a row value
                    movs            r5, r0                          @ save x
                    movs            r0, r3
                    bl              Display_getStringWidth
                    cmp             r0, #0                          @ nothing to draw
                    beq             8f                              @ then just return

                    movs            r6, #DISPLAY_ALIGN_MASK         @ check which alignment was required
                    ands            r5, r5, r6
                    cmp             r5, #0                          @ left align?
                    bne             0f
                    movs            r0, #0                          @ yes, just draw the string
                    bl              Display_drawStringData
                    b               9f
0:
                    cmp             r5, #DISPLAY_CENTER_ALIGN       @ center align?
                    bne             1f
                    movs            r5, #ACB_DISPLAY_WIDTH
                    subs            r5, r5, r0
                    lsrs            r0, r5, #1
                    bl              Display_drawStringData
                    b               9f
1:
                    movs            r5, #ACB_DISPLAY_WIDTH          @ right align
                    subs            r5, r5, r0
                    movs            r0, r5
                    bl              Display_drawStringData
9:
                    pop             {r5-r7, pc}
8:
                    movs            r0, #DISPLAY_OK
                    b               9b

    static_data(Display_drawBitmapMasks)
Display_drawBitmapMasks:
                    .byte           255, 254, 252, 248, 240, 224, 192, 128

    public_function(Display_drawBitmap)

@ int Display_drawBitmap(int x, int yOrRow, Bitmap* bitmap)
@   draw a bitmap at the supplied position. Returns a display status

Display_drawBitmap:
                    push            {r3-r7, lr}
                    mov             r4, r8                          @ save r8-r11
                    mov             r5, r9
                    mov             r6, r10
                    mov             r7, r11
                    push            {r4-r7}
                    sub             sp, sp, #8

                    bl              Display_getPixelY               @ convert Y to pixel, if it's a row value
                    movs            r5, r0                          @ save x
                    bl              Display_checkPixelRange         @ check initial x and y are in range
                    cmp             r0, #DISPLAY_OK
                    bne             9f
                    str             r5, [sp]
                    str             r1, [sp, #4]

                    ldrh            r6, [r2, #BitmapHeader_DisplayWidth] @ check the image has at least width, and height!
                    cmp             r6, #0
                    beq             8f
                    ldrh            r5, [r2, #BitmapHeader_DisplayHeight]
                    cmp             r5, #0
                    beq             8f
                    ldrh            r4, [r2, #BitmapHeader_DataWidth]
                    cmp             r6, r4
                    beq             0f

                    ldr             r3, = #Display_drawBitmapMasks  @ get the bitmap mask for the last byte if it's
                    subs            r0, r4, r6                      @ not a multiple of 8
                    ldrb            r3, [r3, r0]
                    lsls            r3, r3, #8
                    mov             r10, r3
0:                                                                  @ at this point:
                    lsrs            r4, r4, #3                      @ r4 = data width in bytes
                    mov             r8, r6                          @ r8 = bitmap width in pixels
                    movs            r6, #0                          @ r6 = row counter
                    mov             r11, r6                         @ r11 = result status
                    mov             r9, r5                          @ r9 = height
                    movs            r7, r2
                    adds            r7, r7, #BitmapData             @ r7 = >bitmapData
                                                                    @ r10 = bitmap mask for last row byte
                                                                    @ r4 = data width in bytes
                                                                    @ frame: [sp] = x, [sp, #4] = y
__db_drawRow:
                    cmp             r6, r9
                    beq             __db_returnStatus
                    movs            r5, #0                          @ column counter
__db_drawCol:
                    cmp             r5, r4
                    beq             __db_nextRow

                    lsls            r0, r5, #3                      @ are we on the last byte and is the bitmap width
                    adds            r0, r0, #8                      @ in pixels not a multiple of 8
                    cmp             r0, r8
                    bgt             __db_drawClipped

                    mov             r0, r4                          @ calc offset into data
                    muls            r0, r0, r6
                    adds            r3, r5, r0
                    ldrb            r3, [r7, r3]                    @ get byte to draw
                    ldr             r0, [sp]                        @ get x position
                    lsls            r1, r5, #3
                    adds            r0, r0, r1
                    ldr             r1, [sp, #4]                    @ get y position
                    adds            r1, r1, r6
                    movs            r2, #1                          @ don't invert
                    bl              DisplayType_drawHorizontalByte
__db_checkStatus:
                    mov             r3, r11                         @ save status
                    orrs            r3, r3, r0
                    mov             r11, r3
                    movs            r1, #DISPLAY_CLIPPED_VERT       @ if vertically clipped, no point printing the
                    tst             r0, r1                          @ rest of this bitmap
                    bne             __db_returnStatus
                    movs            r1, #DISPLAY_CLIPPED_HORZ       @ if horizontally clipped, move to next row
                    tst             r1, r0
                    bne             __db_nextRow
                    adds            r5, r5, #1
                    b               __db_drawCol
__db_drawClipped:
                    mov             r0, r4                          @ calc offset into data
                    muls            r0, r0, r6
                    adds            r3, r5, r0
                    ldrb            r3, [r7, r3]                    @ get byte to draw
                    mov             r0, r10                         @ add mask
                    orrs            r3, r3, r0
                    ldr             r0, [sp]                        @ get x position
                    lsls            r1, r5, #3
                    adds            r0, r0, r1
                    ldr             r1, [sp, #4]                    @ get y position
                    adds            r1, r1, r6
                    movs            r2, #1                          @ don't invert
                    bl              DisplayType_drawHorizontalClippedByte
                    b               __db_checkStatus
__db_nextRow:
                    adds            r6, r6, #1
                    bne             __db_drawRow
__db_returnStatus:
                    mov             r0, r11                         @ return the clipping status
9:
                    add             sp, sp, #8
                    pop             {r4-r7}                         @ restore r8-r10
                    mov             r8, r4
                    mov             r9, r5
                    mov             r10, r6
                    mov             r11, r7
                    pop             {r3-r7, pc}
8:
                    movs            r0, #DISPLAY_OK
                    b               9b

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
                    cmp             r7, #ACB_DISPLAY_WIDTH          @ is x > ACB_DISPLAY_WIDTH
                    blt             1f
                    movs            r0, #DISPLAY_CLIPPED_HORZ
1:
                    cmp             r1, #0                          @ is y < 0
                    bge             2f
                    orrs            r0, r0, r6
                    b               3f
2:
                    cmp             r1, #ACB_DISPLAY_WIDTH          @ is y > ACB_DISPLAY_HEIGHT
                    blt             3f
                    orrs            r0, r0, r6
3:
                    pop             {r5-r7, pc}

    private_function(Display_getPixelY)

@ void Display_getPixelY(int x, int& yOrRow)
@   converts a vertical row/pixel value to a pixel value, x not used...
@   Implementation note: preserves all registers other than r1, status and link return (lr); result is placed back in r1
@   can't be called via C/C++

Display_getPixelY:
                    push            {r3-r4, r7, lr}
                    cmp             r1, #0                          @ if y is zero, just return
                    beq             9f
                    ldr             r7, = #DISPLAY_ROW_MASK         @ if the DISPLAY_ROW bits aren't set, then just return
                    tst             r1, r7
                    beq             9f
                    movs            r4, r1                          @ convert row into pixel offset
                    bics            r4, r4, r7                      @ get just the y value
                    beq             9f                              @ if it's zero then just return
                    ands            r1, r1, r7                      @ get the height of the rows
                    lsrs            r1, r1, #8
                    muls            r1, r1, r4
9:
                    pop             {r3-r4, r7, pc}

    private_function(Display_drawFontGlyph)

@ int Display_drawFontGlyph(int x, int y, byte colour, char c)
@   draw a single ASCII character; increments x by the width of the character
@   Returns a display status in lo word, and width of character in high word

Display_drawFontGlyph:

minChar         = FontHeader_MinCharOffset
maxChar         = FontHeader_MaxCharOffset
charHeight      = FontHeader_CharHeightOffset

widthOffset     = FontGlyphEntry_CharWidthOffset
charDataOffset  = FontGlyphEntry_CharDataOffset                     @ blank top byte to get offset to character data

                    push            {r4-r7, lr}
                    mov             r4, r8                          @ save r8-r10
                    mov             r5, r9
                    mov             r6, r10
                    push            {r4-r6}

                    uxtb            r3, r3                          @ zero extend character
                    ldr             r7, = #fontPtr
                    ldr             r7, [r7]
                    ldrh            r6, [r7, #minChar]              @ check if character is out of range...
                    cmp             r3, r6
                    blt             8f
                    ldrh            r4, [r7, #maxChar]
                    cmp             r3, r4
                    bgt             8f

                    mov             r8, r0                          @ save parameters...
                    mov             r9, r1
                    mov             r10, r2
                    ldrh            r4, [r7, #charHeight]           @ get character height of font
                    subs            r4, r4, #1
                    subs            r3, r3, r6                      @ get pointer to character data
                    lsls            r3, r3, #2
                    adds            r3, r3, #FontHeader_Size
                    ldr             r6, [r7, r3]                    @ get width of character and offset to data
                    lsrs            r5, r6, #24                     @ get character width
                    ldr             r3, =#0xFFF                     @ mask out width
                    ands            r6, r6, r3
                    adds            r7, r7, r6
                    movs            r6, #0                          @ clear out status
0:
                    mov             r0, r8                          @ draw a row of character data
                    mov             r1, r9
                    adds            r1, r1, r4
                    mov             r2, r10
                    ldrb            r3, [r7, r4]
                    bl              DisplayType_drawHorizontalByte
                    orrs            r6, r6, r0
                    subs            r4, r4, #1
                    bcs             0b
                    lsls            r0, r5, #16                     @ shift width to top half word
                    orrs            r0, r0, r6                      @ and combine with status
9:
                    pop             {r4-r6}                         @ restore r8-r10
                    mov             r8, r4
                    mov             r9, r5
                    mov             r10, r6
                    pop             {r4-r7, pc}
8:
                    movs            r0, #DISPLAY_OK                 @ char out of range, nothing drawn, and character
                    b               9b                              @ width is zero

    private_function(Display_drawStringData)

@ int Display_drawStringData(int x, int y, byte colour, char* str)
@   draw a single line of null terminated characters
@   Returns a display status

Display_drawStringData:
                    push            {r3-r7, lr}
                    mov             r4, r8                          @ save off r8-r9
                    mov             r5, r9
                    push            {r4-r5}

                    movs            r4, r0
                    mov             r8, r1
                    mov             r9, r2
                    movs            r5, r3
                    movs            r6, #0                          @ clear status
0:
                    ldrb            r3, [r5]
                    cmp             r3, #0                          @ end of string? return
                    beq             9f
                    movs            r0, r4
                    mov             r1, r8
                    mov             r2, r9
                    bl              Display_drawFontGlyph
                    uxth            r1, r0                          @ get status
                    orrs            r6, r6, r1
                    movs            r1, #DISPLAY_CLIPPED_HORZ       @ if horzontally clipped, no point printing the
                    tst             r6, r1                          @ rest of ths string
                    bne             9f
                    lsrs            r0, r0, #16                     @ get the character width from the status result
                    adds            r4, r4, r0                      @ inc x by the width
                    adds            r5, r5, #1                      @ move onto the next character
                    b               0b
9:
                    movs            r0, r6                          @ copy over display status
                    pop             {r4-r5}                         @ restore r8-r9
                    mov             r8, r4
                    mov             r9, r5
                    pop             {r3-r7, pc}

    private_function(Display_getStringWidth)

@ int Display_getStringWidth(char* str)
@   get the width of the supplied string in pixels
@   Returns the width of the string in pixels
@   Implementation note: preserves all registers other than r0, status and link return (lr)

Display_getStringWidth:
                    push            {r3-r7, lr}
                    ldr             r7, = #__font_data
                    ldrh            r6, [r7, #minChar]
                    ldrh            r5, [r7, #maxChar]
                    movs            r4, #0
0:
                    ldrb            r3, [r0]                        @ get the next byte
                    cmp             r3, #0                          @ is it the null terminator?
                    beq             9f
                    cmp             r3, r5
                    bgt             1f                              @ character out of range (too high)
                    subs            r3, r3, r6
                    blt             1f                              @ character out of range (too low)

                    lsls            r3, r3, #2
                    adds            r3, r3, #FontHeader_Size
                    ldr             r3, [r7, r3]                    @ get width of character and offset to data
                    lsrs            r3, #24                         @ just get the width
                    adds            r4, r4, r3
1:
                    adds            r0, r0, #1                      @ move to the next character
                    b               0b
9:
                    movs            r0, r4                          @ return the width
                    pop             {r3-r7, pc}

#endif

    .end
