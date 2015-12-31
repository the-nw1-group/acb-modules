/*
 * Copyright (c) 2015 The NW1 Group
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

/* Display Status results */
DISPLAY_CLIPPED_HBIT    =   0
DISPLAY_CLIPPED_VBIT    =   1

DISPLAY_OK              =   0x00
DISPLAY_CLIPPED_HORZ    =   (1<<DISPLAY_CLIPPED_HBIT)
DISPLAY_CLIPPED_VERT    =   (1<<DISPLAY_CLIPPED_VBIT)

DISPLAY_ROW_BIT         =   9                                       /* flag to set in Y to use row's instead of pixels */
DISPLAY_ROW             =   (1<<DISPLAY_ROW_BIT)                    /* A row is 16 pixels high */

/* colours */
DISPLAY_BLACK   = 0
DISPLAY_WHITE   = 1

/* text alignment */
DISPLAY_CENTRE_ALIGN_BIT =  0
DISPLAY_RIGHT_ALIGN_BIT =   1
DISPLAY_BOXED_BIT       =   2
DISPLAY_BUTTON_BIT      =   3

DISPLAY_LEFT_ALIGN      =   0
DISPLAY_CENTRE_ALIGN    =   (1<<DISPLAY_CENTRE_ALIGN_BIT)
DISPLAY_RIGHT_ALIGN     =   (1<<DISPLAY_RIGHT_ALIGN_BIT)
DISPLAY_BOXED           =   (1<<DISPLAY_BOXED_BIT)
DISPLAY_BUTTON          =   (1<<DISPLAY_BUTTON_BIT)

DISPLAY_ALIGN_MASK      =   (DISPLAY_CENTRE_ALIGN|DISPLAY_RIGHT_ALIGN)

