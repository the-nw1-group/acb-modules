#include "moduleInfo.inc"

    module(tx)

/*
 * tx: 16 by 8 pixels, 1bpp
 *
 */

	static_data(__tx_data)
    .global __tx_data

__tx_data:

@ Basic image data

                    .short          0x0000                          @ Flags
                    .short          0x0010                          @ Display width in pixels
                    .short          0x0008                          @ Display height in pixels
                    .short          0x0010                          @ Data width in bits

@ Image data

                    .byte           0xFE, 0x7F 
                    .byte           0x01, 0x80 
                    .byte           0x1D, 0x80 
                    .byte           0x49, 0x81 
                    .byte           0x89, 0x80 
                    .byte           0x49, 0x81 
                    .byte           0x01, 0x80 
                    .byte           0xFF, 0xFF 

    .end

