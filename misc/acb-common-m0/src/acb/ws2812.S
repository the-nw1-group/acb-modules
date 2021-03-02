/*
 * Copyright (c) 2015 The NW1 Group
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#include "moduleInfo.inc"

#ifdef ACB_USE_WS2812

@ ws2812 driver
@   Implementation note: although this driver works with multiple channels (4 if using Timer2 and 3 if using Timer3),
@   transmission on one channel blocks further tramissions on any other channel until completed. It's hoped to remove
@   this limitation at some point.

    module(Ws2812)

bufferSize = 64 * 24

    private_data(Ws2812_privateData)

Ws2812_buffer:
                    .space          bufferSize, 0                   @ outbound buffer with RGB information
                                                                    @ space for bufferSize/24 leds
Ws2812_channelPtr:
                    .int            Ws2812_buffer                   @ channels pointers for 4 channels, these default
                    .int            Ws2812_buffer + (16 * 24)       @ 4 channels of 16 LEDs each
                    .int            Ws2812_buffer + (32 * 24)
                    .int            Ws2812_buffer + (48 * 24)
Ws2812_endOfChannels:
                    .int            Ws2812_buffer + (64 * 24)       @ end of the channels

Ws2812_currentChannelPtr:
                    .int            0
Ws2812_completeFlag:
                    .byte           0
Ws2812_resetCounter:
                    .byte           0

    public_function(Ws2812_init)

@ void Ws2812_init(void)
@   Initialises the WS2812 driver

Ws2812_init:
                    ldr             r3, = #_RCC_APB1ENR             @ enable Timer 3 clock
                    ldr             r1, [r3]
                    movs            r0, #WS2812_RCC_APB1ENR_TIMEN
                    orrs            r0, r0, r1
                    str             r0, [r3]

                    ldr             r3, = #WS2812_TIM_BASE          @ set basic parameters
                    movs            r0, #0
                    str             r0, [r3, #TIM_PSC_OFFSET]
                    movs            r0, #59                         @ set freq to 800kHz
                    str             r0, [r3, #TIM_ARR_OFFSET]
                    ldr             r1, [r3, #TIM_EGR_OFFSET]       @ force update generation
                    movs            r0, #TIM_EGR_UG
                    orrs            r1, r1, r0
                    str             r1, [r3, #TIM_EGR_OFFSET]

                    ldr             r3, = #_RCC_AHBENR              @ enable DMA module
                    ldr             r1, [r3]
                    movs            r0, #RCC_AHBENR_DMA1EN
                    orrs            r1, r1, r0
                    str             r1, [r3]
                    bx              lr

    public_function(Ws2812_setBufferSizes)

@ bool Ws2812_setBufferSizes(byte buffer1Size, byte buffer2Size, byte buffer3Size, byte buffer4Size)
@   Set the buffer sizes for each of the buffers. Returns true if the buffer sizes are updated, otherwise false if
@   the sum of buffer sizes is greater than the total buffer size. A call to Ws2812_clearBuffer is recommended.

Ws2812_setBufferSizes:
                    push            {r5-r7, lr}
                    movs            r7, #24                         @ each LED takes 24 bytes of buffer space
                    muls            r0, r0, r7                      @ so make the buffer sizes into byte sizes
                    muls            r1, r1, r7
                    muls            r2, r2, r7
                    muls            r3, r3, r7
                    adds            r7, r0, r1                      @ check that combined buffer sizes aren't greater
                    adds            r7, r7, r2                      @ than bufferSize
                    adds            r7, r7, r3
                    ldr             r6, = #bufferSize
                    cmp             r7, r6
                    bgt             0f
                    ldr             r6, = #Ws2812_channelPtr
                    ldr             r7, [r6, #0]
                    adds            r7, r7, r0
                    str             r7, [r6, #4]                    @ store offset to 2nd buffer
                    adds            r7, r7, r1
                    str             r7, [r6, #8]                    @ store offset to 3rd buffer
                    adds            r7, r7, r2
                    str             r7, [r6, #12]                   @ store offset to 4th buffer
                    adds            r7, r7, r3
                    str             r7, [r6, #16]                   @ store end of buffers
                    movs            r0, #SUCCESS
9:
                    pop             {r5-r7, pc}
0:
                    movs            r0, #ERROR
                    b               9b

    public_function(Ws2812_clearBuffer)

@ void Ws2812_clearBuffer(void)
@   Clears the internal buffer. Doesn't update the LED's, use Ws2812_updateAll or Ws2812_update to update all or an
@   individual channel.

Ws2812_clearBuffer:
                    ldr             r2, = #Ws2812_buffer
                    ldr             r1, = #(bufferSize-1)
                    movs            r0, #zeroTime
0:
                    strb            r0, [r2, r1]
                    subs            r1, r1, #1
                    bcs             0b
                    bx              lr

    public_function(Ws2812_setColour)

@ bool Ws2812_setColour(byte channel, short position, int rgb)
@   Updates a channel/position with a new colour. rgb is stored as bottom byte blue, 2nd byte green, 3rd byte red, with
@   the top byte currently unused. Doesn't update the LED's, use Ws2812_updateAll or Ws2812_update to update all or an
@   individual channel. Returns false if the channel or position is out of range, and no data was updated, otherwise
@   returns true.

Ws2812_setColour:
                    push            {r5-r7, lr}
                    bl              Ws2812_findStartAddress         @ find the address for the slot
                    cmp             r0, #0                          @ if the slot returned is zero, then the parameters
                    beq             9f                              @ where out of range, so return false.
                    movs            r1, r2
                    bl              Ws2812_storeRgb                 @ and store the RGB values
                    movs            r0, #SUCCESS
9:
                    pop             {r5-r7, pc}

    static_data(Ws2812_channelData)
Ws2812_channelData:
_cd_ccmr_offset         = 0
_cd_ccmr_flags_offset   = 4
_cd_ccmr_mask_offset    = 6
_cd_ccer_flags_offset   = 8
_cd_ccer_mask_offset    = 10
_cd_ccr_addr_offset     = 12
_cd_dier_flags_offset   = 16
_cd_dma_isr             = 18
_cd_dma_chan_offset     = 20
_cd_dma_ifcr_offset     = 24
Ws2812_channelData0:
                    .int            TIM_CCMR1_OFFSET
                    .short          TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1PE | TIM_CCMR1_OC1FE
                    .short          0xFF00
                    .short          TIM_CCER_CC1E
                    .short          ~(TIM_CCER_CC1E|TIM_CCER_CC1P|TIM_CCER_CC1NP)
                    .int            WS2812_TIM_BASE + TIM_CCR1_OFFSET
                    .short          TIM_DIER_CC1DE
                    .short          WS2812_DMA_ISR_CHAN0
                    .int            WS2812_DMA_CHAN0
                    .short          WS2812_DMA_IFCR_CHAN0
                    .space          32-(.-Ws2812_channelData0), 0
Ws2812_channelData1:
                    .int            TIM_CCMR1_OFFSET
                    .short          TIM_CCMR1_OC2M_2 | TIM_CCMR1_OC2M_1 | TIM_CCMR1_OC2PE | TIM_CCMR1_OC2FE
                    .short          0x00FF
                    .short          TIM_CCER_CC2E
                    .short          ~(TIM_CCER_CC2E|TIM_CCER_CC2P|TIM_CCER_CC2NP)
                    .int            WS2812_TIM_BASE + TIM_CCR2_OFFSET
                    .short          TIM_DIER_CC1DE
                    .short          WS2812_DMA_ISR_CHAN1
                    .int            WS2812_DMA_CHAN1
                    .short          WS2812_DMA_IFCR_CHAN1
                    .space          32-(.-Ws2812_channelData1), 0
Ws2812_channelData2:
                    .int            TIM_CCMR2_OFFSET
                    .short          TIM_CCMR2_OC3M_2 | TIM_CCMR2_OC3M_1 | TIM_CCMR2_OC3PE | TIM_CCMR2_OC3FE
                    .short          0xFF00
                    .short          TIM_CCER_CC3E
                    .short          ~(TIM_CCER_CC3E|TIM_CCER_CC3P|TIM_CCER_CC3NP)
                    .int            WS2812_TIM_BASE + TIM_CCR3_OFFSET
                    .short          TIM_DIER_CC3DE
                    .short          WS2812_DMA_ISR_CHAN2
                    .int            WS2812_DMA_CHAN2
                    .short          WS2812_DMA_IFCR_CHAN2
                    .space          32-(.-Ws2812_channelData2), 0
Ws2812_channelData3:
                    .int            TIM_CCMR2_OFFSET
                    .short          TIM_CCMR2_OC4M_2 | TIM_CCMR2_OC4M_1 | TIM_CCMR2_OC4PE | TIM_CCMR2_OC4FE
                    .short          0x00FF
                    .short          TIM_CCER_CC4E                   @ below generates a warning if used
                    .short          0x4fff                          @ ~(TIM_CCER_CC4E|TIM_CCER_CC4P|TIM_CCER_CC4NP)
                    .int            WS2812_TIM_BASE + TIM_CCR4_OFFSET
                    .short          TIM_DIER_CC4DE
                    .short          WS2812_DMA_ISR_CHAN3
                    .int            WS2812_DMA_CHAN3
                    .short          WS2812_DMA_IFCR_CHAN3
                    .space          32-(.-Ws2812_channelData3), 0

.if (~(TIM_CCER_CC4E|TIM_CCER_CC4P|TIM_CCER_CC4NP) != 0xffff4fff)
.error "~(TIM_CCER_CC4E|TIM_CCER_CC4P|TIM_CCER_CC4NP) doesn't equal expected value of 0x(ffff)4fff"
.endif

    public_function(Ws2812_update)

@ bool Ws2812_update(byte channel)
@   Updates the physical devices connected to the channel from the buffer. If the channel doesn't support this function
@   or the channel number is out of range, this routine returns ERROR otherwise SUCCESS. This method blocks until the
@   data has been sent.

Ws2812_update:
                    push            {r3-r7, lr}
                    cmp             r0, #0                          @ check channel, if out of range return 0
                    blt             Ws2812_update_error
                    cmp             r0, #3
                    bgt             Ws2812_update_error
                    lsls            r7, r0, #5                      @ get ptr to channel data block
                    ldr             r1, = Ws2812_channelData0
                    adds            r7, r7, r1
                    ldr             r1, [r7, #_cd_dma_chan_offset]  @ check if this channel is supported, we need a DMA
                    cmp             r1, #0                          @ channel for this pwm output, and not all are
                    beq             Ws2812_update_error             @ available (Timer 3 channel 2 for example)
                    movs            r4, r0                          @ keep channel number

                    ldr             r6, =#Ws2812_currentChannelPtr  @ store the current channel ptr
                    str             r7, [r6]

                    ldr             r6, =#WS2812_TIM_BASE           @ set up timer to be PWM on the selected channel
                    ldr             r1, [r7, #_cd_ccmr_offset]      @ and active high polarity and enable output
                    ldrh            r2, [r7, #_cd_ccmr_mask_offset]
                    ldr             r3, [r6, r1]
                    bics            r3, r3, r2
                    ldrh            r2, [r7, #_cd_ccmr_flags_offset]
                    orrs            r3, r3, r2
                    str             r3, [r6, r1]
                    ldrh            r2, [r7, #_cd_ccer_mask_offset]
                    ldr             r3, [r6, #TIM_CCER_OFFSET]
                    bics            r3, r3, r2
                    ldrh            r2, [r7, #_cd_ccer_flags_offset]
                    orrs            r3, r3, r2
                    str             r3, [r6, #TIM_CCER_OFFSET]

                    ldr             r2, = #WS2812_DMA_BASE          @ clear any interrupts
                    ldrh            r1, [r7, #_cd_dma_ifcr_offset]
                    str             r1, [r2, #DMA_IFCR_OFFSET]

                    ldr             r5, [r7, #_cd_dma_chan_offset]  @ set peripheral and memory address for the DMA
                    ldr             r1, [r7, #_cd_ccr_addr_offset]  @ channel, set 8 bit->32 bit conversion, and
                    str             r1, [r5, #DMA_Channel_CPAR_OFFSET] @ memory inc, read from memory and write to
                    movs            r1, #0                          @ peripheral, and the number of bytes to read
                    bl              Ws2812_findStartAddress
                    cmp             r0, #0
                    beq             Ws2812_update_error
                    str             r0, [r5, #DMA_Channel_CMAR_OFFSET]
                    ldr             r0, = #DMA_CCR_PSIZE_1 | DMA_CCR_MINC | DMA_CCR_DIR | DMA_CCR_TCIE | DMA_CCR_PL
                    str             r0, [r5, #DMA_Channel_CCR_OFFSET]
                    movs            r0, r4
                    bl              Ws2812_getBufferSize
                    cmp             r0, #0
                    beq             Ws2812_update_error
                    str             r0, [r5, #DMA_Channel_CNDTR_OFFSET]

                    movs            r0, #WS2812_TIM_ISR             @ use ISR redirection to intercept timer ISR
                    ldr             r1, =#Ws2812_timerIsr
                    bl              ACB_WS2812_IRQ_REDIRECT_FN
                    movs            r0, #WS2812_TIM_ISR             @ enable the timer 3 interrupt, via NVIC
                    bl              NVIC_enableIRQ

                    ldrh            r0, [r7, #_cd_dma_isr]          @ use ISR redirection to intercept dma ISR
                    ldr             r1, =#Ws2812_dmaIsr
                    bl              ACB_WS2812_IRQ_REDIRECT_FN
                    ldrh            r0, [r7, #_cd_dma_isr]          @ enable the dma channel interrupt, via NVIC
                    bl              NVIC_enableIRQ

                    ldr             r0, = #Ws2812_completeFlag      @ clear the complete flag
                    movs            r1, #0
                    strb            r1, [r0]

                    ldrh            r1, [r7, #_cd_dier_flags_offset]
                    ldr             r2, [r6, #TIM_DIER_OFFSET]      @ enable interrupts for select channel
                    orrs            r2, r2, r1
                    str             r2, [r6, #TIM_DIER_OFFSET]
                    ldr             r1, [r7, #_cd_ccr_addr_offset]  @ clear the channel counter
                    movs            r2, #0
                    str             r2, [r1]

                    ldr             r1, [r5, #DMA_Channel_CCR_OFFSET]
                    movs            r2, #DMA_CCR_EN                 @ enable the DMA channel
                    orrs            r1, r1, r2
                    str             r1, [r5, #DMA_Channel_CCR_OFFSET]

                    ldr             r1, [r6, #TIM_CR1_OFFSET]       @ and enable the timer
                    movs            r2, #TIM_CR1_CEN
                    orrs            r1, r1, r2
                    str             r1, [r6, #TIM_CR1_OFFSET]
0:
                    ldrb            r1, [r0]                        @ wait until completed
                    cmp             r1, #1
                    bne             0b

                    movs            r0, #WS2812_TIM_ISR             @ disable the timer 3 interrupt, via NVIC
                    bl              NVIC_disableIRQ
                    ldrh            r0, [r7, #_cd_dma_isr]          @ disable the dma channel interrupt, via NVIC
                    bl              NVIC_disableIRQ

                    movs            r0, #SUCCESS
9:
                    pop             {r3-r7, pc}
Ws2812_update_error:
                    movs            r0, #ERROR
                    b               9b

    public_function(Ws2812_dmaIsr)

@ void Ws2812_dmaIsr(void)
@   Handles the dma interrupt

Ws2812_dmaIsr:
                    ldr             r3, = #Ws2812_currentChannelPtr @ acknowledge the interrupt
                    ldr             r3, [r3]
                    ldr             r2, = #WS2812_DMA_BASE
                    ldrh            r1, [r3, #_cd_dma_ifcr_offset]
                    str             r1, [r2, #DMA_IFCR_OFFSET]

                    ldr             r2, [r3, #_cd_dma_chan_offset]  @ turn off DMA interrupts for this channel
                    ldr             r1, [r2, #DMA_Channel_CCR_OFFSET]
                    movs            r0, #DMA_CCR_EN
                    bics            r1, r1, r0
                    str             r1, [r2, #DMA_Channel_CCR_OFFSET]

                    ldr             r2, = #WS2812_TIM_BASE          @ enable timer3 update interrupts and turn off the
                    ldr             r1, [r2, #TIM_DIER_OFFSET]      @ channel interrupts
                    movs            r0, #TIM_DIER_UIE
                    orrs            r1, r1, r0
                    ldrh            r0, [r3, #_cd_dier_flags_offset]
                    bics            r1, r1, r0
                    str             r1, [r2, #TIM_DIER_OFFSET]
                    ldr             r1, [r3, #_cd_ccr_addr_offset]  @ force output channel to be zero
                    movs            r0, #0
                    str             r0, [r1]
                    bx              lr

    public_function(Ws2812_timerIsr)

@ void Ws2812_timerIsr(void)
@   Handles the timer interrupt

Ws2812_timerIsr:
resetDelay = 40
                    ldr             r3, = #WS2812_TIM_BASE          @ acknowledge the interrupt
                    movs            r0, #TIM_SR_UIF
                    str             r0, [r3, #TIM_SR_OFFSET]

                    ldr             r2, = #Ws2812_completeFlag      @ check the number of times the timer has overflowed
                    ldrb            r1, [r2, #1]                    @ if this is less than the resetDelay, just record
                    cmp             r1, #resetDelay                 @ and let if overflow again
                    bge             0f
                    adds            r1, r1, #1
                    strb            r1, [r2, #1]
                    b               9f
0:
                    movs            r1, #0                          @ otherwise we've finished with the reset, so clear
                    strb            r1, [r2, #1]                    @ the overflow counter

                    ldr             r1, = #Ws2812_currentChannelPtr @ turn off output from compare
                    ldr             r1, [r1]
                    ldrh            r1, [r1, #_cd_ccer_flags_offset]
                    ldr             r0, [r3, #TIM_CCER_OFFSET]
                    bics            r0, r0, r1
                    str             r0, [r3, #TIM_CCER_OFFSET]
                    movs            r1, #TIM_CR1_CEN                @ turn off the timer
                    ldr             r0, [r3, #TIM_CR1_OFFSET]
                    bics            r0, r0, r1
                    str             r0, [r3, #TIM_CR1_OFFSET]
                    movs            r1, #TIM_DIER_UIE               @ turn off the Update interrupts
                    ldr             r0, [r3, #TIM_DIER_OFFSET]
                    bics            r0, r0, r1
                    str             r0, [r3, #TIM_DIER_OFFSET]

                    movs            r1, #1                          @ set the complete flag
                    strb            r1, [r2]
9:
                    bx              lr

    public_function(Ws2812_updateAll)

@ void Ws2812_updateAll(void)
@   Updates the physical devices connected to all the channels from the buffer.

Ws2812_updateAll:
                    push            {r7, lr}
                    movs            r0, #0
                    bl              Ws2812_update
                    movs            r0, #1
                    bl              Ws2812_update
                    movs            r0, #2
                    bl              Ws2812_update
                    movs            r0, #3
                    bl              Ws2812_update
                    pop             {r7, pc}

    private_function(Ws2812_findStartAddress)

@ int Ws2812_findStartAddress(byte channel, short position)
@   find the start address of the data slot for the given channel and position. If the channel or position are out of
@   range, the result is zero, or the start address of the data slot. Implementation note, r2 and r3 aren't modified.

Ws2812_findStartAddress:
                    push            {r5-r7, lr}
                    cmp             r0, #0                          @ check channel, if out of range return 0
                    blt             0f
                    cmp             r0, #3
                    bgt             0f
                    ldr             r7, = #Ws2812_channelPtr
                    movs            r6, #24                         @ each "slot" is 24 bytes, so convert position
                    muls            r1, r1, r6                      @ into a slot position
                    lsls            r0, r0, #2                      @ offset to buffer ptr
                    adds            r6, r0, #4
                    ldr             r5, [r7, r0]
                    ldr             r6, [r7, r6]
                    subs            r0, r6, r5                      @ check if position is in range
                    cmp             r1, r0
                    bge             0f
                    adds            r0, r1, r5                      @ add to base of channel
9:
                    pop             {r5-r7, pc}
0:
                    movs            r0, #0
                    b               9b

    private_function(Ws2812_getBufferSize)

@ int Ws2812_getBufferSize(byte channel)
@   return the size of the channels buffer in bytes. Returns 0 if the channel is out of range, or if the channel's
@   buffer is zero.

Ws2812_getBufferSize:
                    cmp             r0, #0                          @ check channel, if out of range return 0
                    blt             0f
                    cmp             r0, #3
                    bgt             0f
                    ldr             r3, = #Ws2812_channelPtr
                    lsls            r0, r0, #2                      @ offset to buffer ptr
                    adds            r2, r0, #4
                    ldr             r0, [r3, r0]
                    ldr             r2, [r3, r2]
                    subs            r0, r2, r0                      @ return difference in bytes
9:
                    bx              lr
0:
                    movs            r0, #0
                    b               9b

    private_function(Ws2812_storeRgb)

@ void Ws2812_storeRgb(int* ptr, int rgb)
@   store the rgb values at the supplied pointer, ptr. rgb is stored as bottom byte blue, 2nd byte green, 3rd byte red,
@   with the top byte currently unused. This converts the rgb values into one and zero times that are used to
@   communicate with the WS2812

Ws2812_storeRgb:
oneTime = 39
zeroTime = 19
                    push            {r5-r7, lr}
                    lsls            r3, r1, #23                     @ split out R, G, and B into seperate registers
                    lsls            r2, r1, #15                     @ with all the values in the top byte - 1
                    lsls            r1, r1, #7
                    movs            r5, #0
0:
                    lsls            r2, r2, #1                      @ data is sent out G-R-B, so process Green first
                    bpl             1f
                    movs            r6, #oneTime
                    b               2f
1:
                    movs            r6, #zeroTime
2:
                    strb            r6, [r0, r5]
                    movs            r7, r5                          @ now red
                    adds            r7, r7, #8
                    lsls            r1, r1, #1
                    bpl             3f
                    movs            r6, #oneTime
                    b               4f
3:
                    movs            r6, #zeroTime
4:
                    strb            r6, [r0, r7]
                    adds            r7, r7, #8                      @ now blue
                    lsls            r3, r3, #1
                    bpl             5f
                    movs            r6, #oneTime
                    b               6f
5:
                    movs            r6, #zeroTime
6:
                    strb            r6, [r0, r7]
                    adds            r5, r5, #1
                    cmp             r5, #7
                    bls             0b
                    pop             {r5-r7, pc}

#endif

    .end
