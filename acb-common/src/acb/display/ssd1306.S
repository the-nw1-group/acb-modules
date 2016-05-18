/*
 * Copyright (c) 2015 The NW1 Group
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#include "moduleInfo.inc"

#ifdef ACB_USE_SSD1306

@ Display drivers for SSD1306 based display

    module(Ssd1306)

    .extern         DisplayDrv_init                                 @ Initialise the display
    .extern         MsCounter_waitFor                               @ Wait for a number of ms

    private_data(Ssd1306_private)

_buffer:
__displayBufferSize     = (ACB_DISPLAY_WIDTH * ACB_DISPLAY_HEIGHT) / 8
                    .space          __displayBufferSize, 0x00       @ buffer for display

@ Fundamental Command Table
__setContrastControl    = 0x81
__setEntireDisplayOn    = 0xA4
__setEntireDisplayOff   = 0xA5
__setNormalDisplay      = 0xA6
__setInverseDisplay     = 0xA7
__setDisplayOff         = 0xAE
__setDisplayOn          = 0xAF

@ Scrolling Command Table
__continuousHorizontalScrollSetupRight              = 0x26
__continuousHorizontalScrollSetupLeft               = 0x27
__continuousVerticalAndHorizontalScrollSetupRight   = 0x29
__continuousVerticalAndHorizontalScrollSetupLeft    = 0x2A
__deactivateScroll                                  = 0x2E
__activateScroll                                    = 0x2F
__setVerticalScrollArea                             = 0xA3

@ Address Setting Command Table
__setLowerColumnStartAddressForPageAddressingModeBase   = 0x00
__setHigherColumnStartAddressForPageAddressingModeBase  = 0x10
__setMemoryAddressingMode                               = 0x20
__setColumnAddress                                      = 0x21
__setPageAddress                                        = 0x22
__setPageStartAddressForPageAddressingModeBase          = 0xB0

@ Hardware Configuration (Panel resolution & layout related) Command Table

__setDisplayStartLineBase           = 0x40
__setSegmentRemap0                  = 0xA0
__setSegmentRemap127                = 0xA1
__setMultiplexRatio                 = 0xA8
__setComOutputScanDirectionNormal   = 0xC0
__setComOutputScanDirectionRemap    = 0xC8
__setDisplayOffset                  = 0xD3
__setComPinsHardwareConfiguration   = 0xDA

@ Timing & Driving Scheme Setting Command Table

__setDisplayClockDivideRatioOscillatorFrequency = 0xD5
__setPreChargePeriod                            = 0xD9
__setVComhDeselectLevel                         = 0xDB
__nop                                           = 0xE3

@ Advance Graphic Command Table

__setFadeOutAndBlinking = 0x23
__setZoomIn             = 0xD6

@ Charge Pump Command Table

__setChargePumpSetting  = 0x8D

    static_data(__ssd1306_init_data)

__ssd1306_init_data:
                    .byte           __setDisplayOff
                    .byte           __setDisplayClockDivideRatioOscillatorFrequency, 0xF0 @ was 0x82
#if ACB_DISPLAY_HEIGHT == 32
                    .byte           __setMultiplexRatio, 0x1F
#elif ACB_DISPLAY_HEIGHT == 64
                    .byte           __setMultiplexRatio, 0x3F
#else
#error Unsupported ACB_DISPLAY_HEIGHT
#endif
                    .byte           __setDisplayOffset, 0x00
                    .byte           __setDisplayStartLineBase
                    .byte           __setChargePumpSetting, 0x14
                    .byte           __setMemoryAddressingMode, 0x00
#if  ACB_DISPLAY_HEIGHT == 32
                    .byte           __setPageAddress, 0x00, 0x03
#endif
                    .byte           __setSegmentRemap127
                    .byte           __setComOutputScanDirectionRemap
                    .byte           __setComPinsHardwareConfiguration, 0x12
                    .byte           __setContrastControl, 0x80 @ was 0x20
                    .byte           __setPreChargePeriod, 0x22
                    .byte           __setVComhDeselectLevel, 0x20 @ was 0x30
                    .byte           __setEntireDisplayOn
                    .byte           __setNormalDisplay
__ssd1306_init_data_end:
                                                                    @ each start up command's size is listed in this
                                                                    @ word. a 0 for 1 byte command, and a 1 for a 2
                                                                    @ byte command.
#if ACB_DISPLAY_HEIGHT == 32
__ssd1305_init_data_size = 0b0011110011101110
#elif ACB_DISPLAY_HEIGHT == 64
__ssd1305_init_data_size = 0b0001111001101110
#else
#error Unsupported ACB_DISPLAY_HEIGHT
#endif

    public_function(Ssd1306_init)

@ bool Ssd1306_init(void)
@   Initialise the display. Returns TRUE if the initialisation was successful, otherwise FALSE

Ssd1306_init:
                    push            {r7, lr}

                    ldr             r2, = #ACB_DISPLAY_RES_GPIOBASE @ set LCD_RES# to be an output, medium speed
                    ldr             r0, [r2, #GPIO_MODER_OFFSET]
                    ldr             r1, = #1<<(ACB_DISPLAY_RES_PIN<<1)
                    orrs            r0, r0, r1
                    str             r0, [r2, #GPIO_MODER_OFFSET]
                    ldr             r0, [r2, #GPIO_OSPEEDR_OFFSET]
                    ldr             r1, = #1<<(ACB_DISPLAY_RES_PIN<<1)
                    orrs            r0, r0, r1
                    str             r0, [r2, #GPIO_OSPEEDR_OFFSET]
                    movs            r0, #1<<ACB_DISPLAY_RES_PIN     @ force reset low
                    str             r0, [r2, #GPIO_BRR_OFFSET]

                    movs            r0, #100                        @ wait for at 100ms for the supply to settle
                    bl              MsCounter_waitFor
                    ldr             r7, = #ACB_DISPLAY_RES_GPIOBASE @ raise the RESET line
                    movs            r0, #1<<ACB_DISPLAY_RES_PIN
                    str             r0, [r7, #GPIO_BSRR_OFFSET]
                    movs            r0, #1
                    bl              MsCounter_waitFor               @ wait for at least 3us, min we can do is 1ms
#if !defined(ACB_SEND_INIT_WITHOUT_DMA)
                    ldr             r0, = #__ssd1306_init_data      @ we can use DMA to send the init commands
                    movs            r1, #(__ssd1306_init_data_end - __ssd1306_init_data)
                    bl              DisplayDrv_init
#else
                    movs            r0, #0                          @ can't use DMA, so we'll send the commands one, by
                    movs            r1, #0                          @ one
                    bl              DisplayDrv_init
                    bl              Ssd1306_sendInitCommands
#endif
9:
                    pop             {r7, pc}

    public_function(Ssd1306_showDisplay)

@ bool Ssd1306_showDisplay(void)
@   turn on the display. Returns TRUE if the initialisation was successful, otherwise FALSE

Ssd1306_showDisplay:
                    push            {r7, lr}
                    movs            r0, #__setDisplayOn
                    bl              DisplayDrv_sendCommand
                    pop             {r7, pc}

    public_function(Ssd1306_hideDisplay)

@ bool Ssd1306_hideDisplay(void)
@   turn off the display. Returns TRUE if the initialisation was successful, otherwise FALSE

Ssd1306_hideDisplay:
                    push            {r7, lr}
                    movs            r0, #__setDisplayOff
                    bl              DisplayDrv_sendCommand
                    pop             {r7, pc}

    public_function(Ssd1306_setContrast)

@ bool Ssd1306_setContrast(byte contrast)
@   set the display contrast level. Contrast value between 0 and 255. Returns TRUE if the initialisation was successful,
@   otherwise FALSE

Ssd1306_setContrast:
                    push            {r7, lr}
                    movs            r1, r0
                    movs            r0, #__setContrastControl
                    bl              DisplayDrv_sendCommandAndParameter
                    pop             {r7, pc}

    public_function(Ssd1306_blitBuffer)

@ bool Ssd1306_blitBuffer(void)
@   send the contents of the display buffer to the display. Returns TRUE if the initialisation was successful,
@   otherwise FALSE

Ssd1306_blitBuffer:
                    push            {r7, lr}
                    ldr             r0, = #_buffer
                    ldr             r1, = #__displayBufferSize
                    bl              DisplayDrv_sendData
9:
                    pop             {r7, pc}

    public_function(Ssd1306_clearBuffer)

@ void Ssd1306_clearBuffer(void)
@   clear the contents of the display buffer. This doesn't write to the display

Ssd1306_clearBuffer:
                    movs            r0, #0
                    b               Ssd1306_fillBuffer

    public_function(Ssd1306_fillBuffer)

@ void Ssd1306_fillBuffer(int pattern)
@   fill the contents of the display buffer with the pattern supplied. This doesn't write to the display

Ssd1306_fillBuffer:
                    ldr             r1, = #_buffer
                    ldr             r2, = #(__displayBufferSize-4)
0:
                    str             r0, [r1, r2]
                    subs            r2, r2, #4
                    bcs             0b
                    bx              lr

    public_function(Ssd1306_drawPixel)

@ void Ssd1306_drawPixel(int x, int y, bool colour)
@   set (colour=1)/clear (colour=0) a pixel in the display buffer. This doesn't write to the display

Ssd1306_drawPixel:
                    push            {r7, lr}
                    movs            r3, #0x7
                    ands            r3, r3, r1                      @ get which bit of the page of the display we are changing
                    movs            r7, #0xf8                       @ and which page
                    ands            r1, r1, r7
                    lsls            r1, r1, #4                      @ and use that as an offset into our buffer memory for vertical
                    add             r0, r0, r1                      @ and then add onto that the horiztonal offset
                    ldr             r7, = #_buffer
                    movs            r1, #1                          @ which bit to set in the byte
                    lsls            r1, r1, r3
                    ldrb            r3, [r7, r0]                    @ get the byte to change
                    cmp             r2, #0
                    beq             0f
                    orrs            r3, r3, r1                      @ set bit
                    b               1f
0:
                    bics            r3, r3, r1                      @ clear bit
1:
                    strb            r3, [r7, r0]                    @ store byte back
                    pop             {r7, pc}

    public_function(Ssd1306_setPixel)

@ void Ssd1306_setPixel(int x, int y)
@   set a pixel in the display buffer. This doesn't write to the display

Ssd1306_setPixel:
                    movs            r2, #DISPLAY_WHITE
                    b               Ssd1306_drawPixel

    public_function(Ssd1306_clearPixel)

@ void Ssd1306_drawPixel(int x, int y, bool colour)
@   clear a pixel in the display buffer. This doesn't write to the display

Ssd1306_clearPixel:
                    movs            r2, #DISPLAY_BLACK
                    b               Ssd1306_drawPixel

    public_function(Ssd1306_drawHorizontalByte)

@ int Ssd1306_drawHorizontalByte(int x, int y, bool colour, byte byteToWrite)
@   draw a horiztonal byte into the display buffer. This doesn't write to the display.
@   returns a display status

Ssd1306_drawHorizontalByte:
                    mov             r12, r7
                    ldr             r7, = #0xFF00
                    orrs            r3, r3, r7
                    mov             r7, r12
                    b               Ssd1306_drawHorizontalClippedByte

    public_function(Ssd1306_drawHorizontalClippedByte)

@ int Ssd1306_drawHorizontalClippedByte(int x, int y, bool colour, short byteToWriteAndMask)
@   draw a horiztonal byte into the display buffer, determined by the mask. This doesn't write to the display.
@   Returns a display status. byteToWriteAndMask is comprised of the low byte of the byteToWrite, and the high
@   byte is the mask, 1 to write the bit to the screen, 0 not to write that bit

Ssd1306_drawHorizontalClippedByte:
                    push            {r3-r7, lr}
                    rev16           r7, r3                          @ get mask of which bits to draw
                    lsls            r7, r7, #24                     @ and push to the last byte of the word
                    cmp             r2, #DISPLAY_BLACK              @ if colour is 0, then invert the byteToWrite
                    bne             0f
                    mvns            r3, r3
0:
                    movs            r6, r0                          @ copy off the X position
                    movs            r2, #0x07                       @ get which bit of the page of the display we are changing
                    ands            r2, r2, r1
                    movs            r5, #0xf8                       @ and get which page
                    ands            r1, r1, r5
                    lsls            r1, r1, #4                      @ and use that as an offset into our buffer memory
                    adds            r0, r0, r1                      @ and then add onto that the horiztonal offset
                    ldr             r1, = #_buffer
                    adds            r0, r0, r1
                    movs            r5, #0                          @ use as a counter
                    movs            r4, #1                          @ destination mask
                    lsls            r4, r4, r2
2:
                    lsls            r7, r7, #1                      @ check if we write this bit?
                    bcc             3f
                    ldrb            r1, [r0, r5]                    @ copy the byte from the buffer
                    lsrs            r3, r3, #1
                    bcs             5f
                    bics            r1, r1, r4                      @ clear the bit
                    b               6f
5:
                    orrs            r1, r1, r4                      @ set the bit
6:
                    strb            r1, [r0, r5]                    @ store the modified byte back
3:
                    adds            r6, r6, #1
                    cmp             r6, #ACB_DISPLAY_WIDTH
                    bge             4f
                    adds            r5, r5, #1
                    cmp             r5, #8
                    bge             1f
                    b               2b
4:
                    movs            r0, #DISPLAY_CLIPPED_HBIT       @ clipped whilst drawing...
                    pop             {r3-r7, pc}
1:
                    movs            r0, #DISPLAY_OK
                    pop             {r3-r7, pc}

    public_function(Ssd1306_drawPageByte)

@ void drawPageByte(int x, int page, byte byteToWrite)
@   draw a page byte (vertical byte) into the display buffer. This doesn't write to the display

Ssd1306_drawPageByte:
                    lsls            r1, r1, #7
                    adds            r0, r0, r1
                    ldr             r3, = #_buffer
                    strb            r2, [r3, r0]
                    bx              lr

    private_function(Ssd1306_sendInitCommands)

@ int Ssd1306_sendInitCommands(void)
@   send the init commands to the display driver a command at a time.
@   returns a display status

Ssd1306_sendInitCommands:
                    push            {r5-r7, lr}
                    ldr             r7, =#__ssd1306_init_data
                    movs            r6, #(__ssd1306_init_data_end - __ssd1306_init_data)
                    ldr             r5, =#__ssd1305_init_data_size
0:
                    lsrs            r5, r5, #1
                    bcc             sic_sendByte
sic_sendShort:
                    ldrb            r0, [r7]
                    ldrb            r1, [r7, #1]
                    bl              DisplayDrv_sendCommandAndParameter
                    cmp             r0, #ERROR
                    beq             9f
                    adds            r7, r7, #2
                    subs            r6, r6, #2
                    b               1f
sic_sendByte:
                    ldrb            r0, [r7]
                    bl              DisplayDrv_sendCommand
                    cmp             r0, #ERROR
                    beq             9f
                    adds            r7, r7, #1
                    subs            r6, r6, #1
1:
                    bne             0b
9:
                    pop             {r5-r7, pc}

#endif

    .end
