/*
 * Copyright (c) 2015 The NW1 Group
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#define ACB_USE_SSD1306

#if !defined(ACB_DISPLAY_WIDTH) || !defined(ACB_DISPLAY_HEIGHT)
#error ACB_DISPLAY_WIDTH and ACB_DISPLAY_HEIGHT must all be defined to use this file
#endif

#define DisplayType_init            Ssd1306_init
#define DisplayType_showDisplay     Ssd1306_showDisplay
#define DisplayType_hideDisplay     Ssd1306_hideDisplay
#define DisplayType_setContrast     Ssd1306_setContrast
#define DisplayType_blitBuffer      Ssd1306_blitBuffer

#define DisplayType_clearBuffer                 Ssd1306_clearBuffer
#define DisplayType_fillBuffer                  Ssd1306_fillBuffer
#define DisplayType_drawPixel                   Ssd1306_drawPixel
#define DisplayType_setPixel                    Ssd1306_setPixel
#define DisplayType_clearPixel                  Ssd1306_clearPixel
#define DisplayType_drawHorizontalByte          Ssd1306_drawHorizontalByte
#define DisplayType_drawHorizontalClippedByte   Ssd1306_drawHorizontalClippedByte
#define DisplayType_drawPageByte                Ssd1306_drawPageByte

/* Status results */
DISPLAY_CLIPPED_HBIT    =   0
DISPLAY_CLIPPED_VBIT    =   1

DISPLAY_OK              =   0x00
DISPLAY_CLIPPED_HORZ    =   (1<<DISPLAY_CLIPPED_HBIT)
DISPLAY_CLIPPED_VERT    =   (1<<DISPLAY_CLIPPED_VBIT)

DISPLAY_BLACK   = 0
DISPLAY_WHITE   = 1
