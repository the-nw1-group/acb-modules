/*
 * Copyright (c) 2015 The NW1 Group
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#include "moduleInfo.inc"

    module(font)

/*
 * Simple font: included chars ' '(32) to '~'(126), and the following
 *  symbols: 127 (up), 128 (right), 129 (down), 130 (left)
 *
 * Font data:  Height: 12 pixels, 1 bit per pixel
 *
 */


	static_data(__font_data)
    .global __font_data

__font_data:

@ Basic font data
	
                    .byte           0x00                            @ font ID
                    .byte           0x00                            @ Font information:  1 bit per pixel, Characters zero degress rotation
                    .short          0x20                            @ First Character
                    .short          0x82                            @ Last Character
                    .short          0x0C                            @ Height

@ Glyph table (format: byte width; byte[3] offset_to_character_data)

                    .int            0x194 | (0x02 << 24)            @ Character - 32, offset (0x00000194)
                    .int            0x1A0 | (0x02 << 24)            @ Character - 33, offset (0x000001A0)
                    .int            0x1AC | (0x04 << 24)            @ Character - 34, offset (0x000001AC)
                    .int            0x1B8 | (0x06 << 24)            @ Character - 35, offset (0x000001B8)
                    .int            0x1C4 | (0x05 << 24)            @ Character - 36, offset (0x000001C4)
                    .int            0x1D0 | (0x08 << 24)            @ Character - 37, offset (0x000001D0)
                    .int            0x1DC | (0x06 << 24)            @ Character - 38, offset (0x000001DC)
                    .int            0x1E8 | (0x02 << 24)            @ Character - 39, offset (0x000001E8)
                    .int            0x1F4 | (0x03 << 24)            @ Character - 40, offset (0x000001F4)
                    .int            0x200 | (0x03 << 24)            @ Character - 41, offset (0x00000200)
                    .int            0x20C | (0x06 << 24)            @ Character - 42, offset (0x0000020C)
                    .int            0x218 | (0x05 << 24)            @ Character - 43, offset (0x00000218)
                    .int            0x224 | (0x02 << 24)            @ Character - 44, offset (0x00000224)
                    .int            0x230 | (0x03 << 24)            @ Character - 45, offset (0x00000230)
                    .int            0x23C | (0x02 << 24)            @ Character - 46, offset (0x0000023C)
                    .int            0x248 | (0x03 << 24)            @ Character - 47, offset (0x00000248)
                    .int            0x254 | (0x05 << 24)            @ Character - 48, offset (0x00000254)
                    .int            0x260 | (0x05 << 24)            @ Character - 49, offset (0x00000260)
                    .int            0x26C | (0x05 << 24)            @ Character - 50, offset (0x0000026C)
                    .int            0x278 | (0x05 << 24)            @ Character - 51, offset (0x00000278)
                    .int            0x284 | (0x05 << 24)            @ Character - 52, offset (0x00000284)
                    .int            0x290 | (0x05 << 24)            @ Character - 53, offset (0x00000290)
                    .int            0x29C | (0x05 << 24)            @ Character - 54, offset (0x0000029C)
                    .int            0x2A8 | (0x05 << 24)            @ Character - 55, offset (0x000002A8)
                    .int            0x2B4 | (0x05 << 24)            @ Character - 56, offset (0x000002B4)
                    .int            0x2C0 | (0x05 << 24)            @ Character - 57, offset (0x000002C0)
                    .int            0x2CC | (0x02 << 24)            @ Character - 58, offset (0x000002CC)
                    .int            0x2D8 | (0x02 << 24)            @ Character - 59, offset (0x000002D8)
                    .int            0x2E4 | (0x05 << 24)            @ Character - 60, offset (0x000002E4)
                    .int            0x2F0 | (0x05 << 24)            @ Character - 61, offset (0x000002F0)
                    .int            0x2FC | (0x05 << 24)            @ Character - 62, offset (0x000002FC)
                    .int            0x308 | (0x04 << 24)            @ Character - 63, offset (0x00000308)
                    .int            0x314 | (0x08 << 24)            @ Character - 64, offset (0x00000314)
                    .int            0x320 | (0x06 << 24)            @ Character - 65, offset (0x00000320)
                    .int            0x32C | (0x05 << 24)            @ Character - 66, offset (0x0000032C)
                    .int            0x338 | (0x05 << 24)            @ Character - 67, offset (0x00000338)
                    .int            0x344 | (0x06 << 24)            @ Character - 68, offset (0x00000344)
                    .int            0x350 | (0x05 << 24)            @ Character - 69, offset (0x00000350)
                    .int            0x35C | (0x05 << 24)            @ Character - 70, offset (0x0000035C)
                    .int            0x368 | (0x06 << 24)            @ Character - 71, offset (0x00000368)
                    .int            0x374 | (0x06 << 24)            @ Character - 72, offset (0x00000374)
                    .int            0x380 | (0x04 << 24)            @ Character - 73, offset (0x00000380)
                    .int            0x38C | (0x04 << 24)            @ Character - 74, offset (0x0000038C)
                    .int            0x398 | (0x06 << 24)            @ Character - 75, offset (0x00000398)
                    .int            0x3A4 | (0x05 << 24)            @ Character - 76, offset (0x000003A4)
                    .int            0x3B0 | (0x08 << 24)            @ Character - 77, offset (0x000003B0)
                    .int            0x3BC | (0x06 << 24)            @ Character - 78, offset (0x000003BC)
                    .int            0x3C8 | (0x07 << 24)            @ Character - 79, offset (0x000003C8)
                    .int            0x3D4 | (0x05 << 24)            @ Character - 80, offset (0x000003D4)
                    .int            0x3E0 | (0x07 << 24)            @ Character - 81, offset (0x000003E0)
                    .int            0x3EC | (0x05 << 24)            @ Character - 82, offset (0x000003EC)
                    .int            0x3F8 | (0x05 << 24)            @ Character - 83, offset (0x000003F8)
                    .int            0x404 | (0x05 << 24)            @ Character - 84, offset (0x00000404)
                    .int            0x410 | (0x06 << 24)            @ Character - 85, offset (0x00000410)
                    .int            0x41C | (0x06 << 24)            @ Character - 86, offset (0x0000041C)
                    .int            0x428 | (0x08 << 24)            @ Character - 87, offset (0x00000428)
                    .int            0x434 | (0x06 << 24)            @ Character - 88, offset (0x00000434)
                    .int            0x440 | (0x06 << 24)            @ Character - 89, offset (0x00000440)
                    .int            0x44C | (0x05 << 24)            @ Character - 90, offset (0x0000044C)
                    .int            0x458 | (0x03 << 24)            @ Character - 91, offset (0x00000458)
                    .int            0x464 | (0x04 << 24)            @ Character - 92, offset (0x00000464)
                    .int            0x470 | (0x03 << 24)            @ Character - 93, offset (0x00000470)
                    .int            0x47C | (0x05 << 24)            @ Character - 94, offset (0x0000047C)
                    .int            0x488 | (0x04 << 24)            @ Character - 95, offset (0x00000488)
                    .int            0x494 | (0x05 << 24)            @ Character - 96, offset (0x00000494)
                    .int            0x4A0 | (0x05 << 24)            @ Character - 97, offset (0x000004A0)
                    .int            0x4AC | (0x05 << 24)            @ Character - 98, offset (0x000004AC)
                    .int            0x4B8 | (0x04 << 24)            @ Character - 99, offset (0x000004B8)
                    .int            0x4C4 | (0x05 << 24)            @ Character - 100, offset (0x000004C4)
                    .int            0x4D0 | (0x05 << 24)            @ Character - 101, offset (0x000004D0)
                    .int            0x4DC | (0x04 << 24)            @ Character - 102, offset (0x000004DC)
                    .int            0x4E8 | (0x05 << 24)            @ Character - 103, offset (0x000004E8)
                    .int            0x4F4 | (0x05 << 24)            @ Character - 104, offset (0x000004F4)
                    .int            0x500 | (0x02 << 24)            @ Character - 105, offset (0x00000500)
                    .int            0x50C | (0x03 << 24)            @ Character - 106, offset (0x0000050C)
                    .int            0x518 | (0x05 << 24)            @ Character - 107, offset (0x00000518)
                    .int            0x524 | (0x02 << 24)            @ Character - 108, offset (0x00000524)
                    .int            0x530 | (0x08 << 24)            @ Character - 109, offset (0x00000530)
                    .int            0x53C | (0x05 << 24)            @ Character - 110, offset (0x0000053C)
                    .int            0x548 | (0x05 << 24)            @ Character - 111, offset (0x00000548)
                    .int            0x554 | (0x05 << 24)            @ Character - 112, offset (0x00000554)
                    .int            0x560 | (0x05 << 24)            @ Character - 113, offset (0x00000560)
                    .int            0x56C | (0x04 << 24)            @ Character - 114, offset (0x0000056C)
                    .int            0x578 | (0x04 << 24)            @ Character - 115, offset (0x00000578)
                    .int            0x584 | (0x04 << 24)            @ Character - 116, offset (0x00000584)
                    .int            0x590 | (0x05 << 24)            @ Character - 117, offset (0x00000590)
                    .int            0x59C | (0x05 << 24)            @ Character - 118, offset (0x0000059C)
                    .int            0x5A8 | (0x06 << 24)            @ Character - 119, offset (0x000005A8)
                    .int            0x5B4 | (0x05 << 24)            @ Character - 120, offset (0x000005B4)
                    .int            0x5C0 | (0x05 << 24)            @ Character - 121, offset (0x000005C0)
                    .int            0x5CC | (0x04 << 24)            @ Character - 122, offset (0x000005CC)
                    .int            0x5D8 | (0x03 << 24)            @ Character - 123, offset (0x000005D8)
                    .int            0x5E4 | (0x05 << 24)            @ Character - 124, offset (0x000005E4)
                    .int            0x5F0 | (0x03 << 24)            @ Character - 125, offset (0x000005F0)
                    .int            0x5FC | (0x05 << 24)            @ Character - 126, offset (0x000005FC)
                    .int            0x608 | (0x08 << 24)            @ Character - 127, offset (0x00000608)
                    .int            0x614 | (0x08 << 24)            @ Character - 128, offset (0x00000614)
                    .int            0x620 | (0x08 << 24)            @ Character - 129, offset (0x00000620)
                    .int            0x62C | (0x08 << 24)            @ Character - 130, offset (0x0000062C)

@ Font Character Data

/***********************************
 * Character - 32
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00

/***********************************
 * Character - 33
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x01
                    .byte           0x01
                    .byte           0x01
                    .byte           0x01
                    .byte           0x01
                    .byte           0x00
                    .byte           0x01
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00

/***********************************
 * Character - 34
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x05
                    .byte           0x05
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00

/***********************************
 * Character - 35
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x14
                    .byte           0x14
                    .byte           0x3F
                    .byte           0x12
                    .byte           0x3F
                    .byte           0x0A
                    .byte           0x0A
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00

/***********************************
 * Character - 36
 ***********************************/
                    .byte           0x00
                    .byte           0x04
                    .byte           0x0E
                    .byte           0x05
                    .byte           0x05
                    .byte           0x06
                    .byte           0x0A
                    .byte           0x0A
                    .byte           0x07
                    .byte           0x02
                    .byte           0x00
                    .byte           0x00

/***********************************
 * Character - 37
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x27
                    .byte           0x15
                    .byte           0x15
                    .byte           0x7F
                    .byte           0x54
                    .byte           0x54
                    .byte           0x72
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00

/***********************************
 * Character - 38
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x0F
                    .byte           0x09
                    .byte           0x05
                    .byte           0x02
                    .byte           0x25
                    .byte           0x19
                    .byte           0x1E
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00

/***********************************
 * Character - 39
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x01
                    .byte           0x01
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00

/***********************************
 * Character - 40
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x02
                    .byte           0x01
                    .byte           0x01
                    .byte           0x01
                    .byte           0x01
                    .byte           0x01
                    .byte           0x01
                    .byte           0x02
                    .byte           0x00
                    .byte           0x00

/***********************************
 * Character - 41
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x01
                    .byte           0x02
                    .byte           0x02
                    .byte           0x02
                    .byte           0x02
                    .byte           0x02
                    .byte           0x02
                    .byte           0x01
                    .byte           0x00
                    .byte           0x00

/***********************************
 * Character - 42
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x04
                    .byte           0x1F
                    .byte           0x04
                    .byte           0x0A
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00

/***********************************
 * Character - 43
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x04
                    .byte           0x04
                    .byte           0x0F
                    .byte           0x04
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00

/***********************************
 * Character - 44
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x01
                    .byte           0x01
                    .byte           0x00
                    .byte           0x00

/***********************************
 * Character - 45
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x03
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00

/***********************************
 * Character - 46
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x01
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00

/***********************************
 * Character - 47
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x04
                    .byte           0x04
                    .byte           0x02
                    .byte           0x02
                    .byte           0x02
                    .byte           0x01
                    .byte           0x01
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00

/***********************************
 * Character - 48
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x06
                    .byte           0x09
                    .byte           0x09
                    .byte           0x09
                    .byte           0x09
                    .byte           0x09
                    .byte           0x06
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00

/***********************************
 * Character - 49
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x06
                    .byte           0x05
                    .byte           0x04
                    .byte           0x04
                    .byte           0x04
                    .byte           0x04
                    .byte           0x04
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00

/***********************************
 * Character - 50
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x07
                    .byte           0x08
                    .byte           0x08
                    .byte           0x04
                    .byte           0x04
                    .byte           0x02
                    .byte           0x0F
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00

/***********************************
 * Character - 51
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x0F
                    .byte           0x08
                    .byte           0x08
                    .byte           0x06
                    .byte           0x08
                    .byte           0x08
                    .byte           0x07
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00

/***********************************
 * Character - 52
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x08
                    .byte           0x0C
                    .byte           0x0A
                    .byte           0x09
                    .byte           0x1F
                    .byte           0x08
                    .byte           0x08
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00

/***********************************
 * Character - 53
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x0F
                    .byte           0x01
                    .byte           0x01
                    .byte           0x07
                    .byte           0x08
                    .byte           0x08
                    .byte           0x07
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00

/***********************************
 * Character - 54
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x0E
                    .byte           0x01
                    .byte           0x01
                    .byte           0x0F
                    .byte           0x09
                    .byte           0x09
                    .byte           0x06
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00

/***********************************
 * Character - 55
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x0F
                    .byte           0x08
                    .byte           0x04
                    .byte           0x04
                    .byte           0x04
                    .byte           0x02
                    .byte           0x02
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00

/***********************************
 * Character - 56
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x0E
                    .byte           0x09
                    .byte           0x09
                    .byte           0x06
                    .byte           0x09
                    .byte           0x09
                    .byte           0x06
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00

/***********************************
 * Character - 57
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x06
                    .byte           0x09
                    .byte           0x09
                    .byte           0x0F
                    .byte           0x08
                    .byte           0x08
                    .byte           0x07
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00

/***********************************
 * Character - 58
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x01
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x01
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00

/***********************************
 * Character - 59
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x01
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x01
                    .byte           0x01
                    .byte           0x00
                    .byte           0x00

/***********************************
 * Character - 60
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x08
                    .byte           0x06
                    .byte           0x01
                    .byte           0x06
                    .byte           0x08
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00

/***********************************
 * Character - 61
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x0F
                    .byte           0x00
                    .byte           0x0F
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00

/***********************************
 * Character - 62
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x01
                    .byte           0x06
                    .byte           0x08
                    .byte           0x06
                    .byte           0x01
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00

/***********************************
 * Character - 63
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x07
                    .byte           0x04
                    .byte           0x04
                    .byte           0x02
                    .byte           0x02
                    .byte           0x00
                    .byte           0x02
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00

/***********************************
 * Character - 64
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x3C
                    .byte           0x42
                    .byte           0x59
                    .byte           0x55
                    .byte           0x55
                    .byte           0x2D
                    .byte           0x01
                    .byte           0x1E
                    .byte           0x00
                    .byte           0x00

/***********************************
 * Character - 65
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x04
                    .byte           0x0A
                    .byte           0x0A
                    .byte           0x0A
                    .byte           0x0E
                    .byte           0x11
                    .byte           0x11
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00

/***********************************
 * Character - 66
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x0F
                    .byte           0x09
                    .byte           0x09
                    .byte           0x07
                    .byte           0x09
                    .byte           0x09
                    .byte           0x07
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00

/***********************************
 * Character - 67
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x0E
                    .byte           0x01
                    .byte           0x01
                    .byte           0x01
                    .byte           0x01
                    .byte           0x01
                    .byte           0x0E
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00

/***********************************
 * Character - 68
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x0F
                    .byte           0x11
                    .byte           0x11
                    .byte           0x11
                    .byte           0x11
                    .byte           0x19
                    .byte           0x0F
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00

/***********************************
 * Character - 69
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x0F
                    .byte           0x01
                    .byte           0x01
                    .byte           0x0F
                    .byte           0x01
                    .byte           0x01
                    .byte           0x0F
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00

/***********************************
 * Character - 70
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x0F
                    .byte           0x01
                    .byte           0x01
                    .byte           0x0F
                    .byte           0x01
                    .byte           0x01
                    .byte           0x01
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00

/***********************************
 * Character - 71
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x1E
                    .byte           0x01
                    .byte           0x01
                    .byte           0x19
                    .byte           0x11
                    .byte           0x11
                    .byte           0x1E
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00

/***********************************
 * Character - 72
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x11
                    .byte           0x11
                    .byte           0x11
                    .byte           0x1F
                    .byte           0x11
                    .byte           0x11
                    .byte           0x11
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00

/***********************************
 * Character - 73
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x03
                    .byte           0x02
                    .byte           0x02
                    .byte           0x02
                    .byte           0x02
                    .byte           0x02
                    .byte           0x03
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00

/***********************************
 * Character - 74
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x04
                    .byte           0x04
                    .byte           0x04
                    .byte           0x04
                    .byte           0x04
                    .byte           0x04
                    .byte           0x04
                    .byte           0x04
                    .byte           0x03
                    .byte           0x00

/***********************************
 * Character - 75
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x11
                    .byte           0x09
                    .byte           0x05
                    .byte           0x07
                    .byte           0x05
                    .byte           0x09
                    .byte           0x11
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00

/***********************************
 * Character - 76
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x01
                    .byte           0x01
                    .byte           0x01
                    .byte           0x01
                    .byte           0x01
                    .byte           0x01
                    .byte           0x0F
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00

/***********************************
 * Character - 77
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x43 
                    .byte           0x63 
                    .byte           0x63 
                    .byte           0x55 
                    .byte           0x55 
                    .byte           0x55 
                    .byte           0x49 
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00

/***********************************
 * Character - 78
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x11
                    .byte           0x13
                    .byte           0x13
                    .byte           0x15
                    .byte           0x19 
                    .byte           0x19 
                    .byte           0x11
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00

/***********************************
 * Character - 79
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x1E
                    .byte           0x21 
                    .byte           0x21 
                    .byte           0x21 
                    .byte           0x21 
                    .byte           0x21 
                    .byte           0x1E
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00

/***********************************
 * Character - 80
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x0F
                    .byte           0x09
                    .byte           0x09
                    .byte           0x07
                    .byte           0x01
                    .byte           0x01
                    .byte           0x01
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00

/***********************************
 * Character - 81
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x1E
                    .byte           0x21
                    .byte           0x21
                    .byte           0x21
                    .byte           0x21
                    .byte           0x21
                    .byte           0x1E
                    .byte           0x10
                    .byte           0x10
                    .byte           0x00

/***********************************
 * Character - 82
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x0F
                    .byte           0x09
                    .byte           0x09
                    .byte           0x07
                    .byte           0x05
                    .byte           0x09
                    .byte           0x09
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00

/***********************************
 * Character - 83
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x0E
                    .byte           0x01
                    .byte           0x01
                    .byte           0x06
                    .byte           0x08
                    .byte           0x08
                    .byte           0x07
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00

/***********************************
 * Character - 84
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x1F
                    .byte           0x04
                    .byte           0x04
                    .byte           0x04
                    .byte           0x04
                    .byte           0x04
                    .byte           0x04
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00

/***********************************
 * Character - 85
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x11
                    .byte           0x11
                    .byte           0x11
                    .byte           0x11
                    .byte           0x11
                    .byte           0x11
                    .byte           0x0E
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00

/***********************************
 * Character - 86
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x11
                    .byte           0x11
                    .byte           0x11
                    .byte           0x0A
                    .byte           0x0A
                    .byte           0x0A
                    .byte           0x04
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00

/***********************************
 * Character - 87
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x49 
                    .byte           0x4D 
                    .byte           0x55 
                    .byte           0x55 
                    .byte           0x55 
                    .byte           0x22 
                    .byte           0x22 
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00

/***********************************
 * Character - 88
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x11
                    .byte           0x0A
                    .byte           0x0A
                    .byte           0x04
                    .byte           0x0A
                    .byte           0x0A
                    .byte           0x11
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00

/***********************************
 * Character - 89
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x11
                    .byte           0x09
                    .byte           0x0A
                    .byte           0x04
                    .byte           0x04
                    .byte           0x04
                    .byte           0x04
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00

/***********************************
 * Character - 90
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x0F
                    .byte           0x08
                    .byte           0x04
                    .byte           0x02
                    .byte           0x02
                    .byte           0x01
                    .byte           0x0F
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00

/***********************************
 * Character - 91
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x03
                    .byte           0x01
                    .byte           0x01
                    .byte           0x01
                    .byte           0x01
                    .byte           0x01
                    .byte           0x01
                    .byte           0x03
                    .byte           0x00
                    .byte           0x00

/***********************************
 * Character - 92
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x01
                    .byte           0x01
                    .byte           0x02
                    .byte           0x02
                    .byte           0x02
                    .byte           0x04
                    .byte           0x04
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00

/***********************************
 * Character - 93
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x03
                    .byte           0x02
                    .byte           0x02
                    .byte           0x02
                    .byte           0x02
                    .byte           0x02
                    .byte           0x02
                    .byte           0x03
                    .byte           0x00
                    .byte           0x00

/***********************************
 * Character - 94
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x04
                    .byte           0x0A
                    .byte           0x0A
                    .byte           0x11
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00

/***********************************
 * Character - 95
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x0F
                    .byte           0x00

/***********************************
 * Character - 96
 ***********************************/
                    .byte           0x00
                    .byte           0x04
                    .byte           0x08
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00

/***********************************
 * Character - 97
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x0F
                    .byte           0x08
                    .byte           0x0E
                    .byte           0x09
                    .byte           0x0F
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00

/***********************************
 * Character - 98
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x01
                    .byte           0x01
                    .byte           0x07
                    .byte           0x09
                    .byte           0x09
                    .byte           0x09
                    .byte           0x07
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00

/***********************************
 * Character - 99
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x06
                    .byte           0x01
                    .byte           0x01
                    .byte           0x01
                    .byte           0x06
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00

/***********************************
 * Character - 100
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x08
                    .byte           0x08
                    .byte           0x0E
                    .byte           0x09
                    .byte           0x09
                    .byte           0x09
                    .byte           0x0E
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00

/***********************************
 * Character - 101
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x06
                    .byte           0x09
                    .byte           0x0F
                    .byte           0x01
                    .byte           0x0E
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00

/***********************************
 * Character - 102
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x06
                    .byte           0x02
                    .byte           0x07
                    .byte           0x02
                    .byte           0x02
                    .byte           0x02
                    .byte           0x02
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00

/***********************************
 * Character - 103
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x0F
                    .byte           0x05
                    .byte           0x07
                    .byte           0x02
                    .byte           0x0E
                    .byte           0x09
                    .byte           0x0F
                    .byte           0x00

/***********************************
 * Character - 104
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x01
                    .byte           0x01
                    .byte           0x0F
                    .byte           0x09
                    .byte           0x09
                    .byte           0x09
                    .byte           0x09
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00

/***********************************
 * Character - 105
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x01
                    .byte           0x00
                    .byte           0x01
                    .byte           0x01
                    .byte           0x01
                    .byte           0x01
                    .byte           0x01
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00

/***********************************
 * Character - 106
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x02
                    .byte           0x00
                    .byte           0x02
                    .byte           0x02
                    .byte           0x02
                    .byte           0x02
                    .byte           0x02
                    .byte           0x02
                    .byte           0x03
                    .byte           0x00

/***********************************
 * Character - 107
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x01
                    .byte           0x01
                    .byte           0x09
                    .byte           0x05
                    .byte           0x03
                    .byte           0x05
                    .byte           0x09
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00

/***********************************
 * Character - 108
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x01
                    .byte           0x01
                    .byte           0x01
                    .byte           0x01
                    .byte           0x01
                    .byte           0x01
                    .byte           0x01
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00

/***********************************
 * Character - 109
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x77 
                    .byte           0x49 
                    .byte           0x49 
                    .byte           0x49 
                    .byte           0x49 
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00

/***********************************
 * Character - 110
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x0F
                    .byte           0x09
                    .byte           0x09
                    .byte           0x09
                    .byte           0x09
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00

/***********************************
 * Character - 111
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x06
                    .byte           0x09
                    .byte           0x09
                    .byte           0x09
                    .byte           0x06
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00

/***********************************
 * Character - 112
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x07
                    .byte           0x09
                    .byte           0x09
                    .byte           0x09
                    .byte           0x07
                    .byte           0x01
                    .byte           0x01
                    .byte           0x00

/***********************************
 * Character - 113
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x0E
                    .byte           0x09
                    .byte           0x09
                    .byte           0x09
                    .byte           0x0E
                    .byte           0x08
                    .byte           0x08
                    .byte           0x00

/***********************************
 * Character - 114
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x07
                    .byte           0x01
                    .byte           0x01
                    .byte           0x01
                    .byte           0x01
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00

/***********************************
 * Character - 115
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x07
                    .byte           0x01
                    .byte           0x02
                    .byte           0x04
                    .byte           0x07
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00

/***********************************
 * Character - 116
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x02
                    .byte           0x07
                    .byte           0x02
                    .byte           0x02
                    .byte           0x02
                    .byte           0x06
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00

/***********************************
 * Character - 117
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x09
                    .byte           0x09
                    .byte           0x09
                    .byte           0x09
                    .byte           0x0F
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00

/***********************************
 * Character - 118
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x09
                    .byte           0x09
                    .byte           0x06
                    .byte           0x06
                    .byte           0x06
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00

/***********************************
 * Character - 119
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x15
                    .byte           0x15
                    .byte           0x15
                    .byte           0x0B
                    .byte           0x0A
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00

/***********************************
 * Character - 120
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x09
                    .byte           0x06
                    .byte           0x06
                    .byte           0x06
                    .byte           0x09
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00

/***********************************
 * Character - 121
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x09
                    .byte           0x09
                    .byte           0x06
                    .byte           0x06
                    .byte           0x06
                    .byte           0x02
                    .byte           0x03
                    .byte           0x00

/***********************************
 * Character - 122
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x07
                    .byte           0x04
                    .byte           0x02
                    .byte           0x01
                    .byte           0x07
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00

/***********************************
 * Character - 123
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x06
                    .byte           0x02
                    .byte           0x02
                    .byte           0x01
                    .byte           0x02
                    .byte           0x02
                    .byte           0x02
                    .byte           0x06
                    .byte           0x00
                    .byte           0x00

/***********************************
 * Character - 124
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x04
                    .byte           0x04
                    .byte           0x04
                    .byte           0x04
                    .byte           0x04
                    .byte           0x04
                    .byte           0x04
                    .byte           0x04
                    .byte           0x04
                    .byte           0x00

/***********************************
 * Character - 125
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x03
                    .byte           0x02
                    .byte           0x02
                    .byte           0x02
                    .byte           0x04
                    .byte           0x02
                    .byte           0x02
                    .byte           0x03
                    .byte           0x00
                    .byte           0x00

/***********************************
 * Character - 126
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x03
                    .byte           0x0C
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00

/***********************************
 * Character - 127
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x18
                    .byte           0x18
                    .byte           0x3C
                    .byte           0x3C
                    .byte           0x7E
                    .byte           0x7E
                    .byte           0xFF
                    .byte           0xFF
                    .byte           0x00
                    .byte           0x00

/***********************************
 * Character - 128
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0xC0
                    .byte           0xF0
                    .byte           0xFC
                    .byte           0xFF
                    .byte           0xFF
                    .byte           0xFC
                    .byte           0xF0
                    .byte           0xC0
                    .byte           0x00
                    .byte           0x00

/***********************************
 * Character - 129
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0xFF
                    .byte           0xFF
                    .byte           0x7E
                    .byte           0x7E
                    .byte           0x3C
                    .byte           0x3C
                    .byte           0x18
                    .byte           0x18
                    .byte           0x00
                    .byte           0x00

/***********************************
 * Character - 130
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x03
                    .byte           0x0F
                    .byte           0x3F
                    .byte           0xFF
                    .byte           0xFF
                    .byte           0x3F
                    .byte           0x0F
                    .byte           0x03
                    .byte           0x00
                    .byte           0x00

    .end
