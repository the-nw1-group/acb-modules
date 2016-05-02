#include "moduleInfo.inc"

#ifdef ACB_USE_SMALLFONT

    module(smallFont)

/*
 * smallFont: included chars ' ' (32) to '' (130)
 *
 * Font data: Height 8, 1 bits per pixel
 *
 */

	static_data(__smallFont_data)
    .global __smallFont_data

__smallFont_data:

@ Basic font data

                    .byte           0x00                            @ font ID
                    .byte           0x00                            @ Font information:  1 bit per pixel, Characters zero degress rotation
                    .short          0x0020                          @ First Character
                    .short          0x0082                          @ Last Character
                    .short          0x0008                          @ Height

@ Glyph table (format: byte width; byte[3] offset_to_character_data)

                    .int            0x194 | (0x02 << 24)            @ Character 32, offset (0x00000194)
                    .int            0x19C | (0x02 << 24)            @ Character 33, offset (0x0000019C)
                    .int            0x1A4 | (0x03 << 24)            @ Character 34, offset (0x000001A4)
                    .int            0x1AC | (0x05 << 24)            @ Character 35, offset (0x000001AC)
                    .int            0x1B4 | (0x04 << 24)            @ Character 36, offset (0x000001B4)
                    .int            0x1BC | (0x07 << 24)            @ Character 37, offset (0x000001BC)
                    .int            0x1C4 | (0x06 << 24)            @ Character 38, offset (0x000001C4)
                    .int            0x1CC | (0x02 << 24)            @ Character 39, offset (0x000001CC)
                    .int            0x1D4 | (0x02 << 24)            @ Character 40, offset (0x000001D4)
                    .int            0x1DC | (0x02 << 24)            @ Character 41, offset (0x000001DC)
                    .int            0x1E4 | (0x04 << 24)            @ Character 42, offset (0x000001E4)
                    .int            0x1EC | (0x04 << 24)            @ Character 43, offset (0x000001EC)
                    .int            0x1F4 | (0x02 << 24)            @ Character 44, offset (0x000001F4)
                    .int            0x1FC | (0x03 << 24)            @ Character 45, offset (0x000001FC)
                    .int            0x204 | (0x02 << 24)            @ Character 46, offset (0x00000204)
                    .int            0x20C | (0x03 << 24)            @ Character 47, offset (0x0000020C)
                    .int            0x214 | (0x04 << 24)            @ Character 48, offset (0x00000214)
                    .int            0x21C | (0x04 << 24)            @ Character 49, offset (0x0000021C)
                    .int            0x224 | (0x04 << 24)            @ Character 50, offset (0x00000224)
                    .int            0x22C | (0x04 << 24)            @ Character 51, offset (0x0000022C)
                    .int            0x234 | (0x04 << 24)            @ Character 52, offset (0x00000234)
                    .int            0x23C | (0x04 << 24)            @ Character 53, offset (0x0000023C)
                    .int            0x244 | (0x04 << 24)            @ Character 54, offset (0x00000244)
                    .int            0x24C | (0x04 << 24)            @ Character 55, offset (0x0000024C)
                    .int            0x254 | (0x04 << 24)            @ Character 56, offset (0x00000254)
                    .int            0x25C | (0x04 << 24)            @ Character 57, offset (0x0000025C)
                    .int            0x264 | (0x02 << 24)            @ Character 58, offset (0x00000264)
                    .int            0x26C | (0x02 << 24)            @ Character 59, offset (0x0000026C)
                    .int            0x274 | (0x04 << 24)            @ Character 60, offset (0x00000274)
                    .int            0x27C | (0x04 << 24)            @ Character 61, offset (0x0000027C)
                    .int            0x284 | (0x04 << 24)            @ Character 62, offset (0x00000284)
                    .int            0x28C | (0x04 << 24)            @ Character 63, offset (0x0000028C)
                    .int            0x294 | (0x07 << 24)            @ Character 64, offset (0x00000294)
                    .int            0x29C | (0x06 << 24)            @ Character 65, offset (0x0000029C)
                    .int            0x2A4 | (0x05 << 24)            @ Character 66, offset (0x000002A4)
                    .int            0x2AC | (0x05 << 24)            @ Character 67, offset (0x000002AC)
                    .int            0x2B4 | (0x05 << 24)            @ Character 68, offset (0x000002B4)
                    .int            0x2BC | (0x04 << 24)            @ Character 69, offset (0x000002BC)
                    .int            0x2C4 | (0x04 << 24)            @ Character 70, offset (0x000002C4)
                    .int            0x2CC | (0x06 << 24)            @ Character 71, offset (0x000002CC)
                    .int            0x2D4 | (0x06 << 24)            @ Character 72, offset (0x000002D4)
                    .int            0x2DC | (0x04 << 24)            @ Character 73, offset (0x000002DC)
                    .int            0x2E4 | (0x02 << 24)            @ Character 74, offset (0x000002E4)
                    .int            0x2EC | (0x05 << 24)            @ Character 75, offset (0x000002EC)
                    .int            0x2F4 | (0x04 << 24)            @ Character 76, offset (0x000002F4)
                    .int            0x2FC | (0x08 << 24)            @ Character 77, offset (0x000002FC)
                    .int            0x304 | (0x06 << 24)            @ Character 78, offset (0x00000304)
                    .int            0x30C | (0x06 << 24)            @ Character 79, offset (0x0000030C)
                    .int            0x314 | (0x05 << 24)            @ Character 80, offset (0x00000314)
                    .int            0x31C | (0x06 << 24)            @ Character 81, offset (0x0000031C)
                    .int            0x324 | (0x05 << 24)            @ Character 82, offset (0x00000324)
                    .int            0x32C | (0x04 << 24)            @ Character 83, offset (0x0000032C)
                    .int            0x334 | (0x04 << 24)            @ Character 84, offset (0x00000334)
                    .int            0x33C | (0x06 << 24)            @ Character 85, offset (0x0000033C)
                    .int            0x344 | (0x06 << 24)            @ Character 86, offset (0x00000344)
                    .int            0x34C | (0x08 << 24)            @ Character 87, offset (0x0000034C)
                    .int            0x354 | (0x05 << 24)            @ Character 88, offset (0x00000354)
                    .int            0x35C | (0x05 << 24)            @ Character 89, offset (0x0000035C)
                    .int            0x364 | (0x05 << 24)            @ Character 90, offset (0x00000364)
                    .int            0x36C | (0x03 << 24)            @ Character 91, offset (0x0000036C)
                    .int            0x374 | (0x03 << 24)            @ Character 92, offset (0x00000374)
                    .int            0x37C | (0x02 << 24)            @ Character 93, offset (0x0000037C)
                    .int            0x384 | (0x04 << 24)            @ Character 94, offset (0x00000384)
                    .int            0x38C | (0x03 << 24)            @ Character 95, offset (0x0000038C)
                    .int            0x394 | (0x05 << 24)            @ Character 96, offset (0x00000394)
                    .int            0x39C | (0x04 << 24)            @ Character 97, offset (0x0000039C)
                    .int            0x3A4 | (0x05 << 24)            @ Character 98, offset (0x000003A4)
                    .int            0x3AC | (0x04 << 24)            @ Character 99, offset (0x000003AC)
                    .int            0x3B4 | (0x05 << 24)            @ Character 100, offset (0x000003B4)
                    .int            0x3BC | (0x04 << 24)            @ Character 101, offset (0x000003BC)
                    .int            0x3C4 | (0x03 << 24)            @ Character 102, offset (0x000003C4)
                    .int            0x3CC | (0x04 << 24)            @ Character 103, offset (0x000003CC)
                    .int            0x3D4 | (0x05 << 24)            @ Character 104, offset (0x000003D4)
                    .int            0x3DC | (0x02 << 24)            @ Character 105, offset (0x000003DC)
                    .int            0x3E4 | (0x02 << 24)            @ Character 106, offset (0x000003E4)
                    .int            0x3EC | (0x04 << 24)            @ Character 107, offset (0x000003EC)
                    .int            0x3F4 | (0x02 << 24)            @ Character 108, offset (0x000003F4)
                    .int            0x3FC | (0x08 << 24)            @ Character 109, offset (0x000003FC)
                    .int            0x404 | (0x05 << 24)            @ Character 110, offset (0x00000404)
                    .int            0x40C | (0x05 << 24)            @ Character 111, offset (0x0000040C)
                    .int            0x414 | (0x05 << 24)            @ Character 112, offset (0x00000414)
                    .int            0x41C | (0x05 << 24)            @ Character 113, offset (0x0000041C)
                    .int            0x424 | (0x03 << 24)            @ Character 114, offset (0x00000424)
                    .int            0x42C | (0x04 << 24)            @ Character 115, offset (0x0000042C)
                    .int            0x434 | (0x03 << 24)            @ Character 116, offset (0x00000434)
                    .int            0x43C | (0x05 << 24)            @ Character 117, offset (0x0000043C)
                    .int            0x444 | (0x04 << 24)            @ Character 118, offset (0x00000444)
                    .int            0x44C | (0x06 << 24)            @ Character 119, offset (0x0000044C)
                    .int            0x454 | (0x04 << 24)            @ Character 120, offset (0x00000454)
                    .int            0x45C | (0x04 << 24)            @ Character 121, offset (0x0000045C)
                    .int            0x464 | (0x04 << 24)            @ Character 122, offset (0x00000464)
                    .int            0x46C | (0x03 << 24)            @ Character 123, offset (0x0000046C)
                    .int            0x474 | (0x04 << 24)            @ Character 124, offset (0x00000474)
                    .int            0x47C | (0x03 << 24)            @ Character 125, offset (0x0000047C)
                    .int            0x484 | (0x04 << 24)            @ Character 126, offset (0x00000484)
                    .int            0x48C | (0x08 << 24)            @ Character 127, offset (0x0000048C)
                    .int            0x494 | (0x08 << 24)            @ Character 128, offset (0x00000494)
                    .int            0x49C | (0x08 << 24)            @ Character 129, offset (0x0000049C)
                    .int            0x4A4 | (0x08 << 24)            @ Character 130, offset (0x000004A4)
@ Font Character Data

/***********************************
 * Character - 32 ( )
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00

/***********************************
 * Character - 33 (!)
 ***********************************/
                    .byte           0x00
                    .byte           0x01
                    .byte           0x01
                    .byte           0x01
                    .byte           0x01
                    .byte           0x00
                    .byte           0x01
                    .byte           0x00

/***********************************
 * Character - 34 (")
 ***********************************/
                    .byte           0x00
                    .byte           0x06
                    .byte           0x06
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00

/***********************************
 * Character - 35 (#)
 ***********************************/
                    .byte           0x00
                    .byte           0x0C
                    .byte           0x0C
                    .byte           0x1F
                    .byte           0x1F
                    .byte           0x06
                    .byte           0x06
                    .byte           0x00

/***********************************
 * Character - 36 ($)
 ***********************************/
                    .byte           0x02
                    .byte           0x07
                    .byte           0x03
                    .byte           0x03
                    .byte           0x06
                    .byte           0x06
                    .byte           0x07
                    .byte           0x02

/***********************************
 * Character - 37 (%)
 ***********************************/
                    .byte           0x00
                    .byte           0x13
                    .byte           0x0B
                    .byte           0x3B
                    .byte           0x37
                    .byte           0x34
                    .byte           0x32
                    .byte           0x00

/***********************************
 * Character - 38 (&)
 ***********************************/
                    .byte           0x00
                    .byte           0x0F
                    .byte           0x09
                    .byte           0x06
                    .byte           0x25
                    .byte           0x19
                    .byte           0x1F
                    .byte           0x00

/***********************************
 * Character - 39 (')
 ***********************************/
                    .byte           0x00
                    .byte           0x02
                    .byte           0x02
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00

/***********************************
 * Character - 40 (()
 ***********************************/
                    .byte           0x00
                    .byte           0x02
                    .byte           0x01
                    .byte           0x01
                    .byte           0x01
                    .byte           0x01
                    .byte           0x01
                    .byte           0x02

/***********************************
 * Character - 41 ())
 ***********************************/
                    .byte           0x00
                    .byte           0x01
                    .byte           0x02
                    .byte           0x02
                    .byte           0x02
                    .byte           0x02
                    .byte           0x02
                    .byte           0x01

/***********************************
 * Character - 42 (*)
 ***********************************/
                    .byte           0x00
                    .byte           0x02
                    .byte           0x07
                    .byte           0x02
                    .byte           0x05
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00

/***********************************
 * Character - 43 (+)
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x04
                    .byte           0x04
                    .byte           0x0F
                    .byte           0x04
                    .byte           0x00
                    .byte           0x00

/***********************************
 * Character - 44 (,)
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x01
                    .byte           0x01

/***********************************
 * Character - 45 (-)
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x03
                    .byte           0x00
                    .byte           0x00

/***********************************
 * Character - 46 (.)
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x01
                    .byte           0x00

/***********************************
 * Character - 47 (/)
 ***********************************/
                    .byte           0x00
                    .byte           0x04
                    .byte           0x04
                    .byte           0x02
                    .byte           0x02
                    .byte           0x01
                    .byte           0x01
                    .byte           0x00

/***********************************
 * Character - 48 (0)
 ***********************************/
                    .byte           0x00
                    .byte           0x02
                    .byte           0x05
                    .byte           0x05
                    .byte           0x05
                    .byte           0x05
                    .byte           0x02
                    .byte           0x00

/***********************************
 * Character - 49 (1)
 ***********************************/
                    .byte           0x00
                    .byte           0x02
                    .byte           0x03
                    .byte           0x02
                    .byte           0x02
                    .byte           0x02
                    .byte           0x02
                    .byte           0x00

/***********************************
 * Character - 50 (2)
 ***********************************/
                    .byte           0x00
                    .byte           0x07
                    .byte           0x04
                    .byte           0x04
                    .byte           0x02
                    .byte           0x02
                    .byte           0x07
                    .byte           0x00

/***********************************
 * Character - 51 (3)
 ***********************************/
                    .byte           0x00
                    .byte           0x07
                    .byte           0x04
                    .byte           0x02
                    .byte           0x04
                    .byte           0x04
                    .byte           0x07
                    .byte           0x00

/***********************************
 * Character - 52 (4)
 ***********************************/
                    .byte           0x00
                    .byte           0x04
                    .byte           0x06
                    .byte           0x06
                    .byte           0x05
                    .byte           0x0F
                    .byte           0x04
                    .byte           0x00

/***********************************
 * Character - 53 (5)
 ***********************************/
                    .byte           0x00
                    .byte           0x07
                    .byte           0x01
                    .byte           0x07
                    .byte           0x04
                    .byte           0x04
                    .byte           0x03
                    .byte           0x00

/***********************************
 * Character - 54 (6)
 ***********************************/
                    .byte           0x00
                    .byte           0x06
                    .byte           0x01
                    .byte           0x07
                    .byte           0x05
                    .byte           0x05
                    .byte           0x06
                    .byte           0x00

/***********************************
 * Character - 55 (7)
 ***********************************/
                    .byte           0x00
                    .byte           0x07
                    .byte           0x04
                    .byte           0x04
                    .byte           0x02
                    .byte           0x02
                    .byte           0x02
                    .byte           0x00

/***********************************
 * Character - 56 (8)
 ***********************************/
                    .byte           0x00
                    .byte           0x07
                    .byte           0x05
                    .byte           0x05
                    .byte           0x02
                    .byte           0x05
                    .byte           0x07
                    .byte           0x00

/***********************************
 * Character - 57 (9)
 ***********************************/
                    .byte           0x00
                    .byte           0x03
                    .byte           0x05
                    .byte           0x05
                    .byte           0x07
                    .byte           0x04
                    .byte           0x03
                    .byte           0x00

/***********************************
 * Character - 58 (:)
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x01
                    .byte           0x00
                    .byte           0x00
                    .byte           0x01
                    .byte           0x00

/***********************************
 * Character - 59 (;)
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x01
                    .byte           0x00
                    .byte           0x00
                    .byte           0x01
                    .byte           0x01

/***********************************
 * Character - 60 (<)
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x04
                    .byte           0x02
                    .byte           0x03
                    .byte           0x04
                    .byte           0x00
                    .byte           0x00

/***********************************
 * Character - 61 (=)
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x07
                    .byte           0x00
                    .byte           0x07
                    .byte           0x00
                    .byte           0x00

/***********************************
 * Character - 62 (>)
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x01
                    .byte           0x02
                    .byte           0x06
                    .byte           0x01
                    .byte           0x00
                    .byte           0x00

/***********************************
 * Character - 63 (?)
 ***********************************/
                    .byte           0x00
                    .byte           0x07
                    .byte           0x04
                    .byte           0x04
                    .byte           0x02
                    .byte           0x00
                    .byte           0x02
                    .byte           0x00

/***********************************
 * Character - 64 (@)
 ***********************************/
                    .byte           0x00
                    .byte           0x1E
                    .byte           0x21
                    .byte           0x2D
                    .byte           0x2D
                    .byte           0x3D
                    .byte           0x01
                    .byte           0x1E

/***********************************
 * Character - 65 (A)
 ***********************************/
                    .byte           0x00
                    .byte           0x04
                    .byte           0x0A
                    .byte           0x0A
                    .byte           0x0E
                    .byte           0x11
                    .byte           0x11
                    .byte           0x00

/***********************************
 * Character - 66 (B)
 ***********************************/
                    .byte           0x00
                    .byte           0x0F
                    .byte           0x09
                    .byte           0x0F
                    .byte           0x09
                    .byte           0x09
                    .byte           0x07
                    .byte           0x00

/***********************************
 * Character - 67 (C)
 ***********************************/
                    .byte           0x00
                    .byte           0x0E
                    .byte           0x01
                    .byte           0x01
                    .byte           0x01
                    .byte           0x01
                    .byte           0x0E
                    .byte           0x00

/***********************************
 * Character - 68 (D)
 ***********************************/
                    .byte           0x00
                    .byte           0x07
                    .byte           0x09
                    .byte           0x09
                    .byte           0x09
                    .byte           0x09
                    .byte           0x07
                    .byte           0x00

/***********************************
 * Character - 69 (E)
 ***********************************/
                    .byte           0x00
                    .byte           0x07
                    .byte           0x01
                    .byte           0x07
                    .byte           0x01
                    .byte           0x01
                    .byte           0x07
                    .byte           0x00

/***********************************
 * Character - 70 (F)
 ***********************************/
                    .byte           0x00
                    .byte           0x07
                    .byte           0x01
                    .byte           0x07
                    .byte           0x01
                    .byte           0x01
                    .byte           0x01
                    .byte           0x00

/***********************************
 * Character - 71 (G)
 ***********************************/
                    .byte           0x00
                    .byte           0x1E
                    .byte           0x01
                    .byte           0x01
                    .byte           0x19
                    .byte           0x11
                    .byte           0x1E
                    .byte           0x00

/***********************************
 * Character - 72 (H)
 ***********************************/
                    .byte           0x00
                    .byte           0x11
                    .byte           0x11
                    .byte           0x1F
                    .byte           0x11
                    .byte           0x11
                    .byte           0x11
                    .byte           0x00

/***********************************
 * Character - 73 (I)
 ***********************************/
                    .byte           0x00
                    .byte           0x02
                    .byte           0x02
                    .byte           0x02
                    .byte           0x02
                    .byte           0x02
                    .byte           0x02
                    .byte           0x00

/***********************************
 * Character - 74 (J)
 ***********************************/
                    .byte           0x00
                    .byte           0x02
                    .byte           0x02
                    .byte           0x02
                    .byte           0x02
                    .byte           0x02
                    .byte           0x02
                    .byte           0x02

/***********************************
 * Character - 75 (K)
 ***********************************/
                    .byte           0x00
                    .byte           0x09
                    .byte           0x05
                    .byte           0x03
                    .byte           0x05
                    .byte           0x05
                    .byte           0x09
                    .byte           0x00

/***********************************
 * Character - 76 (L)
 ***********************************/
                    .byte           0x00
                    .byte           0x01
                    .byte           0x01
                    .byte           0x01
                    .byte           0x01
                    .byte           0x01
                    .byte           0x0F
                    .byte           0x00

/***********************************
 * Character - 77 (M)
 ***********************************/
                    .byte           0x00
                    .byte           0x41
                    .byte           0x63
                    .byte           0x63
                    .byte           0x55
                    .byte           0x55
                    .byte           0x49
                    .byte           0x00

/***********************************
 * Character - 78 (N)
 ***********************************/
                    .byte           0x00
                    .byte           0x11
                    .byte           0x13
                    .byte           0x15
                    .byte           0x15
                    .byte           0x19
                    .byte           0x11
                    .byte           0x00

/***********************************
 * Character - 79 (O)
 ***********************************/
                    .byte           0x00
                    .byte           0x0E
                    .byte           0x11
                    .byte           0x11
                    .byte           0x11
                    .byte           0x11
                    .byte           0x0E
                    .byte           0x00

/***********************************
 * Character - 80 (P)
 ***********************************/
                    .byte           0x00
                    .byte           0x0F
                    .byte           0x09
                    .byte           0x09
                    .byte           0x07
                    .byte           0x01
                    .byte           0x01
                    .byte           0x00

/***********************************
 * Character - 81 (Q)
 ***********************************/
                    .byte           0x00
                    .byte           0x0E
                    .byte           0x11
                    .byte           0x11
                    .byte           0x11
                    .byte           0x11
                    .byte           0x0E
                    .byte           0x08

/***********************************
 * Character - 82 (R)
 ***********************************/
                    .byte           0x00
                    .byte           0x0F
                    .byte           0x09
                    .byte           0x09
                    .byte           0x07
                    .byte           0x05
                    .byte           0x09
                    .byte           0x00

/***********************************
 * Character - 83 (S)
 ***********************************/
                    .byte           0x00
                    .byte           0x07
                    .byte           0x01
                    .byte           0x03
                    .byte           0x04
                    .byte           0x04
                    .byte           0x07
                    .byte           0x00

/***********************************
 * Character - 84 (T)
 ***********************************/
                    .byte           0x00
                    .byte           0x07
                    .byte           0x02
                    .byte           0x02
                    .byte           0x02
                    .byte           0x02
                    .byte           0x02
                    .byte           0x00

/***********************************
 * Character - 85 (U)
 ***********************************/
                    .byte           0x00
                    .byte           0x11
                    .byte           0x11
                    .byte           0x11
                    .byte           0x11
                    .byte           0x11
                    .byte           0x0E
                    .byte           0x00

/***********************************
 * Character - 86 (V)
 ***********************************/
                    .byte           0x00
                    .byte           0x11
                    .byte           0x11
                    .byte           0x0A
                    .byte           0x0A
                    .byte           0x0A
                    .byte           0x04
                    .byte           0x00

/***********************************
 * Character - 87 (W)
 ***********************************/
                    .byte           0x00
                    .byte           0x49
                    .byte           0x55
                    .byte           0x55
                    .byte           0x55
                    .byte           0x32
                    .byte           0x22
                    .byte           0x00

/***********************************
 * Character - 88 (X)
 ***********************************/
                    .byte           0x00
                    .byte           0x09
                    .byte           0x06
                    .byte           0x06
                    .byte           0x06
                    .byte           0x05
                    .byte           0x09
                    .byte           0x00

/***********************************
 * Character - 89 (Y)
 ***********************************/
                    .byte           0x00
                    .byte           0x11
                    .byte           0x0A
                    .byte           0x0A
                    .byte           0x04
                    .byte           0x04
                    .byte           0x04
                    .byte           0x00

/***********************************
 * Character - 90 (Z)
 ***********************************/
                    .byte           0x00
                    .byte           0x0F
                    .byte           0x04
                    .byte           0x04
                    .byte           0x02
                    .byte           0x02
                    .byte           0x0F
                    .byte           0x00

/***********************************
 * Character - 91 ([)
 ***********************************/
                    .byte           0x00
                    .byte           0x06
                    .byte           0x02
                    .byte           0x02
                    .byte           0x02
                    .byte           0x02
                    .byte           0x02
                    .byte           0x06

/***********************************
 * Character - 92 (\)
 ***********************************/
                    .byte           0x00
                    .byte           0x01
                    .byte           0x01
                    .byte           0x02
                    .byte           0x02
                    .byte           0x04
                    .byte           0x04
                    .byte           0x00

/***********************************
 * Character - 93 (])
 ***********************************/
                    .byte           0x00
                    .byte           0x03
                    .byte           0x02
                    .byte           0x02
                    .byte           0x02
                    .byte           0x02
                    .byte           0x02
                    .byte           0x03

/***********************************
 * Character - 94 (^)
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x06
                    .byte           0x09
                    .byte           0x09
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00

/***********************************
 * Character - 95 (_)
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00

/***********************************
 * Character - 96 (`)
 ***********************************/
                    .byte           0x04
                    .byte           0x08
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00

/***********************************
 * Character - 97 (a)
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x07
                    .byte           0x04
                    .byte           0x07
                    .byte           0x07
                    .byte           0x00

/***********************************
 * Character - 98 (b)
 ***********************************/
                    .byte           0x00
                    .byte           0x01
                    .byte           0x01
                    .byte           0x07
                    .byte           0x09
                    .byte           0x09
                    .byte           0x07
                    .byte           0x00

/***********************************
 * Character - 99 (c)
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x06
                    .byte           0x01
                    .byte           0x01
                    .byte           0x06
                    .byte           0x00

/***********************************
 * Character - 100 (d)
 ***********************************/
                    .byte           0x00
                    .byte           0x08
                    .byte           0x08
                    .byte           0x0E
                    .byte           0x09
                    .byte           0x09
                    .byte           0x0E
                    .byte           0x00

/***********************************
 * Character - 101 (e)
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x07
                    .byte           0x07
                    .byte           0x01
                    .byte           0x07
                    .byte           0x00

/***********************************
 * Character - 102 (f)
 ***********************************/
                    .byte           0x00
                    .byte           0x03
                    .byte           0x01
                    .byte           0x03
                    .byte           0x01
                    .byte           0x01
                    .byte           0x01
                    .byte           0x00

/***********************************
 * Character - 103 (g)
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x0F
                    .byte           0x05
                    .byte           0x07
                    .byte           0x0E
                    .byte           0x09

/***********************************
 * Character - 104 (h)
 ***********************************/
                    .byte           0x00
                    .byte           0x01
                    .byte           0x01
                    .byte           0x0F
                    .byte           0x09
                    .byte           0x09
                    .byte           0x09
                    .byte           0x00

/***********************************
 * Character - 105 (i)
 ***********************************/
                    .byte           0x00
                    .byte           0x01
                    .byte           0x00
                    .byte           0x01
                    .byte           0x01
                    .byte           0x01
                    .byte           0x01
                    .byte           0x00

/***********************************
 * Character - 106 (j)
 ***********************************/
                    .byte           0x00
                    .byte           0x02
                    .byte           0x00
                    .byte           0x02
                    .byte           0x02
                    .byte           0x02
                    .byte           0x02
                    .byte           0x02

/***********************************
 * Character - 107 (k)
 ***********************************/
                    .byte           0x00
                    .byte           0x01
                    .byte           0x01
                    .byte           0x05
                    .byte           0x03
                    .byte           0x03
                    .byte           0x05
                    .byte           0x00

/***********************************
 * Character - 108 (l)
 ***********************************/
                    .byte           0x00
                    .byte           0x01
                    .byte           0x01
                    .byte           0x01
                    .byte           0x01
                    .byte           0x01
                    .byte           0x01
                    .byte           0x00

/***********************************
 * Character - 109 (m)
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x77
                    .byte           0x49
                    .byte           0x49
                    .byte           0x49
                    .byte           0x00

/***********************************
 * Character - 110 (n)
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x0F
                    .byte           0x09
                    .byte           0x09
                    .byte           0x09
                    .byte           0x00

/***********************************
 * Character - 111 (o)
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x06
                    .byte           0x09
                    .byte           0x09
                    .byte           0x06
                    .byte           0x00

/***********************************
 * Character - 112 (p)
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x0F
                    .byte           0x09
                    .byte           0x09
                    .byte           0x07
                    .byte           0x01

/***********************************
 * Character - 113 (q)
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x0E
                    .byte           0x09
                    .byte           0x09
                    .byte           0x0E
                    .byte           0x08

/***********************************
 * Character - 114 (r)
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x03
                    .byte           0x01
                    .byte           0x01
                    .byte           0x01
                    .byte           0x00

/***********************************
 * Character - 115 (s)
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x07
                    .byte           0x03
                    .byte           0x04
                    .byte           0x07
                    .byte           0x00

/***********************************
 * Character - 116 (t)
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x01
                    .byte           0x03
                    .byte           0x01
                    .byte           0x01
                    .byte           0x03
                    .byte           0x00

/***********************************
 * Character - 117 (u)
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x09
                    .byte           0x09
                    .byte           0x09
                    .byte           0x0F
                    .byte           0x00

/***********************************
 * Character - 118 (v)
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x05
                    .byte           0x05
                    .byte           0x05
                    .byte           0x02
                    .byte           0x00

/***********************************
 * Character - 119 (w)
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x15
                    .byte           0x15
                    .byte           0x0B
                    .byte           0x0A
                    .byte           0x00

/***********************************
 * Character - 120 (x)
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x05
                    .byte           0x02
                    .byte           0x02
                    .byte           0x05
                    .byte           0x00

/***********************************
 * Character - 121 (y)
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x05
                    .byte           0x05
                    .byte           0x05
                    .byte           0x02
                    .byte           0x02

/***********************************
 * Character - 122 (z)
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x07
                    .byte           0x02
                    .byte           0x02
                    .byte           0x07
                    .byte           0x00

/***********************************
 * Character - 123 ({)
 ***********************************/
                    .byte           0x00
                    .byte           0x02
                    .byte           0x02
                    .byte           0x02
                    .byte           0x01
                    .byte           0x02
                    .byte           0x02
                    .byte           0x02

/***********************************
 * Character - 124 (|)
 ***********************************/
                    .byte           0x00
                    .byte           0x02
                    .byte           0x02
                    .byte           0x02
                    .byte           0x02
                    .byte           0x02
                    .byte           0x02
                    .byte           0x02

/***********************************
 * Character - 125 (})
 ***********************************/
                    .byte           0x00
                    .byte           0x02
                    .byte           0x02
                    .byte           0x02
                    .byte           0x04
                    .byte           0x02
                    .byte           0x02
                    .byte           0x02

/***********************************
 * Character - 126 (~)
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x03
                    .byte           0x04
                    .byte           0x00
                    .byte           0x00

/***********************************
 * Character - 127 ()
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00

/***********************************
 * Character - 128 ()
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00

/***********************************
 * Character - 129 ()
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00

/***********************************
 * Character - 130 ()
 ***********************************/
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00
                    .byte           0x00


#endif

    .end

