#include "moduleInfo.inc"

    module(stat)

/*
 * stat: 16 by 8 pixels, 1bpp
 *
 */

	static_data(__stat_data)
    .global __stat_data

__stat_data:

@ Basic image data

                    .short          0x0000                          @ Flags
                    .short          0x0010                          @ Display width in pixels
                    .short          0x0008                          @ Display height in pixels
                    .short          0x0010                          @ Data width in bits

@ Image data

                    .byte           0xFE, 0x7F 
                    .byte           0x01, 0x80 
                    .byte           0xED, 0x9F 
                    .byte           0x01, 0x80 
                    .byte           0xED, 0x80 
                    .byte           0x01, 0x80 
                    .byte           0xED, 0x87 
                    .byte           0xFF, 0xFF 

    .end

