#include "moduleInfo.inc"

    module(graph)

/*
 * graph: 16 by 8 pixels, 1bpp
 *
 */

	static_data(__graph_data)
    .global __graph_data

__graph_data:

@ Basic image data

                    .short          0x0000                          @ Flags
                    .short          0x0010                          @ Display width in pixels
                    .short          0x0008                          @ Display height in pixels
                    .short          0x0010                          @ Data width in bits

@ Image data

                    .byte           0xFE, 0x7F 
                    .byte           0x01, 0x80 
                    .byte           0xA5, 0x93 
                    .byte           0x55, 0xAC 
                    .byte           0x0D, 0x80 
                    .byte           0xFD, 0xBF 
                    .byte           0x01, 0x80 
                    .byte           0xFF, 0xFF 

    .end

