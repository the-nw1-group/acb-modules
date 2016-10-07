/*
 * Copyright (c) 2015 The NW1 Group
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#define ACB_USE_DISPLAY

#if !defined(ACB_DISPLAY_WIDTH) || !defined(ACB_DISPLAY_HEIGHT)
#error ACB_DISPLAY_WIDTH and ACB_DISPLAY_HEIGHT must all be defined to use this file
#endif

/* Display Status results */
DISPLAY_CLIPPED_HBIT    =   0
DISPLAY_CLIPPED_VBIT    =   1

DISPLAY_OK              =   0x00
DISPLAY_CLIPPED_HORZ    =   (1<<DISPLAY_CLIPPED_HBIT)
DISPLAY_CLIPPED_VERT    =   (1<<DISPLAY_CLIPPED_VBIT)

DISPLAY_ROW_MASK        =   0x3F00                                  /* bits 8-13 indicate a row, whose height is the */
DISPLAY_ROW_SHIFT       =   8                                       /* value. A value of 0 in bits 16-21 means the value */
                                                                    /* is a pixel value, otherwise it's a row value. */
                                                                    /* allows for rows of 1 to 63 pixels high */

/* colours */
DISPLAY_BLACK   = 0
DISPLAY_WHITE   = 1

/* text alignment */
DISPLAY_CENTER_ALIGN_BIT =  0
DISPLAY_RIGHT_ALIGN_BIT =   1

DISPLAY_LEFT_ALIGN      =   0
DISPLAY_CENTER_ALIGN    =   (1<<DISPLAY_CENTER_ALIGN_BIT)
DISPLAY_RIGHT_ALIGN     =   (1<<DISPLAY_RIGHT_ALIGN_BIT)

DISPLAY_ALIGN_MASK      =   (DISPLAY_CENTER_ALIGN|DISPLAY_RIGHT_ALIGN)

/* font constants */

FontHeader_Size                 = 8
FontHeader_IdOffset             = 0
FontHeader_InfoOffset           = 1
FontHeader_MinCharOffset        = 2
FontHeader_MaxCharOffset        = 4
FontHeader_CharHeightOffset     = 6

FontGlyphEntry_Size             = 4
FontGlyphEntry_CharWidthOffset  = 0
FontGlyphEntry_CharDataOffset   = 0

/* bitmap constants */

BitmapHeader_Flags              = 0
BitmapHeader_DisplayWidth       = 2
BitmapHeader_DisplayHeight      = 4
BitmapHeader_DataWidth          = 6
BitmapData                      = 8
