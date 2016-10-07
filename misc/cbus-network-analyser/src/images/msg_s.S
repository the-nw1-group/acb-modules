#include "moduleInfo.inc"

    module(msg_s)

/*
 * msg_s: 16 by 8 pixels, 1bpp
 *
 */

	static_data(__msg_s_data)
    .global __msg_s_data

__msg_s_data:

@ Basic image data

                    .short          0x0000                          @ Flags
                    .short          0x0010                          @ Display width in pixels
                    .short          0x0008                          @ Display height in pixels
                    .short          0x0010                          @ Data width in bits

@ Image data

                    .byte           0xFE, 0x7F 
                    .byte           0xFF, 0xFF 
                    .byte           0x93, 0xC9 
                    .byte           0xFF, 0xFF 
                    .byte           0x93, 0xC9 
                    .byte           0xFF, 0xFF 
                    .byte           0x93, 0xC9 
                    .byte           0xFF, 0xFF 

    .end

