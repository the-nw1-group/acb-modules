#include "moduleInfo.inc"

    module(graph_s)

/*
 * graph_s: 16 by 8 pixels, 1bpp
 *
 */

	static_data(__graph_s_data)
    .global __graph_s_data

__graph_s_data:

@ Basic image data

                    .short          0x0000                          @ Flags
                    .short          0x0010                          @ Display width in pixels
                    .short          0x0008                          @ Display height in pixels
                    .short          0x0010                          @ Data width in bits

@ Image data

                    .byte           0xFE, 0x7F 
                    .byte           0xFF, 0xFF 
                    .byte           0x5B, 0xEC 
                    .byte           0xAB, 0xD3 
                    .byte           0xF3, 0xFF 
                    .byte           0x03, 0xC0 
                    .byte           0xFF, 0xFF 
                    .byte           0xFF, 0xFF 

    .end

