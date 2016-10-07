#include "moduleInfo.inc"

    module(log)

/*
 * log: 16 by 8 pixels, 1bpp
 *
 */

	static_data(__log_data)
    .global __log_data

__log_data:

@ Basic image data

                    .short          0x0000                          @ Flags
                    .short          0x0010                          @ Display width in pixels
                    .short          0x0008                          @ Display height in pixels
                    .short          0x0010                          @ Data width in bits

@ Image data

                    .byte           0xFE, 0x7F 
                    .byte           0x01, 0x80 
                    .byte           0x45, 0x8C 
                    .byte           0xA5, 0x82 
                    .byte           0xA5, 0x8A 
                    .byte           0x4D, 0x84 
                    .byte           0x01, 0x80 
                    .byte           0xFF, 0xFF 

    .end

