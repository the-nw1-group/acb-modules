#include "moduleInfo.inc"

    module(stat_s)

/*
 * stat_s: 16 by 8 pixels, 1bpp
 *
 */

	static_data(__stat_s_data)
    .global __stat_s_data

__stat_s_data:

@ Basic image data

                    .short          0x0000                          @ Flags
                    .short          0x0010                          @ Display width in pixels
                    .short          0x0008                          @ Display height in pixels
                    .short          0x0010                          @ Data width in bits

@ Image data

                    .byte           0xFE, 0x7F 
                    .byte           0xFF, 0xFF 
                    .byte           0x13, 0xE0 
                    .byte           0xFF, 0xFF 
                    .byte           0x13, 0xFF 
                    .byte           0xFF, 0xFF 
                    .byte           0x13, 0xF8 
                    .byte           0xFF, 0xFF 

    .end

