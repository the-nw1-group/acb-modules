#include "moduleInfo.inc"

    module(log_s)

/*
 * log_s: 16 by 8 pixels, 1bpp
 *
 */

	static_data(__log_s_data)
    .global __log_s_data

__log_s_data:

@ Basic image data

                    .short          0x0000                          @ Flags
                    .short          0x0010                          @ Display width in pixels
                    .short          0x0008                          @ Display height in pixels
                    .short          0x0010                          @ Data width in bits

@ Image data

                    .byte           0xFE, 0x7F 
                    .byte           0xFF, 0xFF 
                    .byte           0xBB, 0xF3 
                    .byte           0x5B, 0xFD 
                    .byte           0x5B, 0xF5 
                    .byte           0xB3, 0xFB 
                    .byte           0xFF, 0xFF 
                    .byte           0xFF, 0xFF 

    .end

