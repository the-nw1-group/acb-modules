/*
 * Copyright (c) 2015 The NW1 Group
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#include "moduleInfo.inc"

@ Display drivers for SSD1306 based display

    module(Ssd1306)

    .extern         DisplayDrv_init                                 @ Initialise the display
    .extern         MsCounter_waitFor                               @ Wait for a number of ms

    private_data(Ssd1306_private)

_buffer:
__displayBufferSize     = (DISPLAY_WIDTH * DISPLAY_HEIGHT) / 8
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
                    .byte           __setDisplayClockDivideRatioOscillatorFrequency, 0x82
                    .byte           __setMultiplexRatio, 0x1F
                    .byte           __setDisplayOffset, 0x00
                    .byte           __setDisplayStartLineBase
                    .byte           __setChargePumpSetting, 0x14
                    .byte           __setMemoryAddressingMode, 0x00
                    .byte           __setPageAddress, 0x00, 0x03
                    .byte           __setSegmentRemap127
                    .byte           __setComOutputScanDirectionRemap
                    .byte           __setComPinsHardwareConfiguration, 0x12
                    .byte           __setContrastControl, 0x10
                    .byte           __setPreChargePeriod, 0x22
                    .byte           __setVComhDeselectLevel, 0x30
                    .byte           __setEntireDisplayOn
                    .byte           __setNormalDisplay
__ssd1306_init_data_end:

    public_function(Ssd1306_init)

@ bool Ssd1306_init(void)
@   Initialise the display. Returns TRUE if the initialisation was successful, otherwise FALSE

Ssd1306_init:
                    push            {r7, lr}
                    movs            r0, #100                        @ wait for 100ms, allowing the power supply to
                    bl              MsCounter_waitFor               @ settle
                    ldr             r7, = #SIGTEST_LCD_RES_GPIOBASE @ raise the RESET line
                    movs            r0, #1<<SIGTEST_LCD_RES
                    str             r0, [r7, #GPIO_BSRR_OFFSET]
                    movs            r0, #1
                    bl              MsCounter_waitFor               @ wait for at least 3us, min we can do is 1ms
                    ldr             r0, = #__ssd1306_init_data
                    movs            r1, #(__ssd1306_init_data_end - __ssd1306_init_data)
                    bl              DisplayDrv_init
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
                    ldr             r0, = #_buffer
                    ldr             r1, = #(__displayBufferSize)
                    movs            r2, #0
0:
                    str             r2, [r0, r1]
                    subs            r1, r1, #4
                    bne             0b
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
                    push            {r3-r7, lr}
                    movs            r7, #DISPLAY_OK                 @ set status...
                    cmp             r2, #DISPLAY_BLACK              @ if colour is 0, then invert the byteToWrite
                    bne             0f
                    mvns            r3, r3
0:
                    movs            r6, r0                          @ copy off the X position
                    movs            r2, #0x07                       @ get which bit of the page of the display we are changing
                    ands            r2, r2, r1
                    movs            r5, #0xf8                       @ and get which page
                    ands            r1, r1, r5
                    lsls            r1, r1, #4                      @ and use that as an offset into our buffer memory for vertical
                    adds            r0, r0, r1                      @ and then add onto that the horiztonal offset
                    ldr             r1, = #_buffer
                    adds            r0, r0, r1
                    movs            r5, #0                          @ use as a counter
2:
                    ldrb            r1, [r0, r5]                    @ copy the byte from the buffer
                    movs            r4, #1                          @ get which bit to set/clear
                    lsls            r4, r5
                    ands            r4, r4, r3                      @ get bit
                    lsrs            r4, r4, r5                      @ shift back to start
                    lsls            r4, r4, r2                      @ shift to correct place in byte to write
                    eors            r1, r1, r4                      @ set/clear bit
                    strb            r1, [r0, r5]                    @ store the modified byte back

                    adds            r6, r6, #1
                    cmp             r6, #DISPLAY_WIDTH
                    bge             3f
                    adds            r5, r5, #1
                    cmp             r5, #8
                    bge             1f
                    b               2b
3:
                    movs            r7, #DISPLAY_CLIPPED_HBIT       @ clipped whilst drawing...
1:
                    movs            r0, r7                          @ return status
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

    .end
