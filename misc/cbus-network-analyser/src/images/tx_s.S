#include "moduleInfo.inc"

    module(tx_s)

/*
 * tx_s: 16 by 8 pixels, 1bpp
 *
 */

	static_data(__tx_s_data)
    .global __tx_s_data

__tx_s_data:

@ Basic image data

                    .short          0x0000                          @ Flags
                    .short          0x0010                          @ Display width in pixels
                    .short          0x0008                          @ Display height in pixels
                    .short          0x0010                          @ Data width in bits

@ Image data

                    .byte           0xFE, 0x7F 
                    .byte           0xFF, 0xFF 
                    .byte           0xE3, 0xFF 
                    .byte           0xB7, 0xFE 
                    .byte           0x77, 0xFF 
                    .byte           0xB7, 0xFE 
                    .byte           0xFF, 0xFF 
                    .byte           0xFF, 0xFF 

    .end

