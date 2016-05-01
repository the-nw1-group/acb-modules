/*
 * Copyright (c) 2015 The NW1 Group
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#include "moduleInfo.inc"

#ifdef ACB_USE_DISPLAYDRIVER_SPI

@ Display drivers for SPI - current implementation uses DMA, and all function calls are non-blocking

    module(DisplayDriverSPI)

   private_data(DisplayDriverSPI_private)

cmdParamBuffer:     .short          0                               @ buffer used when sending a command + parameter

#if ACB_DISPLAY_SPI_ALARM_SLOT >= ACB_ALARM_SLOTS
#error Not enough alarm slots defined for async write operation. Adjust ACB_ALARM_SLOTS
#endif
#define SPI_ALARM_SLOT = ACB_DISPLAY_SPI_ALARM_SLOT

    public_function(DisplayDriverSPI_init)

@ bool DisplayDriverSPI_init(BYTE* initcommands, int noCommands)
@   Initialise the display. Returns SUCCESS if the initialisation was successful, otherwise ERROR
@   Assumes the peripheral clock for the appropriate SPI module has already been enabled.

DisplayDriverSPI_init:
                    push            {r0-r1, r7, lr}
                    bl              DisplayDriverSPI_setupSPI
                    cmp             r0, #ERROR
                    beq             9f
                    pop             {r0-r1}                         @ restore the parameters
                    bl              DisplayDriverSPI_sendCommands
                    pop             {r7, pc}
9:
                    pop             {r0-r1, r7, pc}

    public_function(DisplayDriverSPI_sendCommands)

@ int DisplayDriverSPI_sendCommands(BYTE* commands, int noCommands)
@   Send a sequence of commands to the display. Returns SUCCESS if the data was sent successfully, PENDING if the
@   data is being sent but not completed, otherwise ERROR

DisplayDriverSPI_sendCommands:
                    push            {r7, lr}
                    bl              DisplayDriverSPI_readyToSend    @ wait until the bus is idle
                    ldr             r7, = #ACB_DISPLAY_DC_GPIOBASE  @ de-assert DC, this is a command
                    ldr             r3, = #1<<ACB_DISPLAY_DC_PIN
                    str             r3, [r7, #GPIO_BRR_OFFSET]
                    bl              DisplayDriverSPI_send
                    pop             {r7, pc}

    public_function(DisplayDriverSPI_sendCommand)

@ bool DisplayDriverSPI_sendCommand(BYTE command)
@   Send a command to the display. Returns SUCCESS if the command was successful, otherwise ERROR

DisplayDriverSPI_sendCommand:
                    push            {r7, lr}
                    bl              DisplayDriverSPI_readyToSend    @ wait until the bus is idle
                    ldr             r7, = #ACB_DISPLAY_DC_GPIOBASE  @ de-assert that this is a command
                    ldr             r3, = #1<<ACB_DISPLAY_DC_PIN
                    str             r3, [r7, #GPIO_BRR_OFFSET]
                    ldr             r1, = #ACB_DISPLAY_CS_GPIOBASE  @ bring CS low, to indicate we are going to write to
                    ldr             r3, = #1<<ACB_DISPLAY_CS_PIN    @ to the display
                    str             r3, [r1, #GPIO_BRR_OFFSET]

                    ldr             r7, = #ACB_DISPLAY_SPI_BASE
                    ldr             r3, [r7, #SPI_CR2_OFFSET]       @ clear TXDMAEN and TXEIE as we don't use DMA or
                    ldr             r2, = #SPI_CR2_TXDMAEN | SPI_CR2_TXEIE @ interrupts for a single byte
                    bics            r3, r3, r2
                    str             r3, [r7, #SPI_CR2_OFFSET]
                    ldr             r3, [r7, #SPI_CR1_OFFSET]       @ enable the SPI module
                    ldr             r2, = #SPI_CR1_SPE
                    orrs            r3, r3, r2
                    str             r3, [r7, #SPI_CR1_OFFSET]
                    strb            r0, [r7, #SPI_DR_OFFSET]        @ write the byte to send
                    ldr             r2, = #SPI_SR_BSY
0:
                    ldr             r3, [r7, #SPI_SR_OFFSET]        @ wait until the data has been sent
                    tst             r3, r2
                    bne             0b

                    bl              DisplayDriverSPI_endTx
                    movs            r0, #SUCCESS
                    pop             {r7, pc}

    public_function(DisplayDriverSPI_sendCommandAndParameter)

@ int DisplayDriverSPI_sendCommand(BYTE command, BYTE parameter)
@   Send a command, with a parameter to the display. Returns SUCCESS if the data was sent successfully, PENDING if the
@   data is being sent but not completed, otherwise ERROR

DisplayDriverSPI_sendCommandAndParameter:
                    push            {r7, lr}
                    ldr             r2, = #cmdParamBuffer
                    strb            r0, [r2]
                    strb            r1, [r2, #1]
                    movs            r0, r2
                    movs            r1, #2
                    bl              DisplayDriverSPI_sendCommands
                    pop             {r7, pc}

    public_function(DisplayDriverSPI_sendData)

@ bool DisplayDriverSPI_sendData(BYTE* data, int noBytes)
@   Send a sequence of data to the display. Returns SUCCESS if the data was sent successfully, PENDING if the
@   data is being sent but not completed, otherwise ERROR

DisplayDriverSPI_sendData:
                    push            {r3-r7, lr}
                    cmp             r1, #0                          @ no data to send, just return SUCCESS
                    ble             8f

                    bl              DisplayDriverSPI_readyToSend    @ wait until the bus is idle
                    ldr             r7, = #ACB_DISPLAY_DC_GPIOBASE  @ assert DC, this is data
                    ldr             r3, = #1<<ACB_DISPLAY_DC_PIN
                    str             r3, [r7, #GPIO_BSRR_OFFSET]
                    bl              DisplayDriverSPI_send
                    b               9f
8:
                    movs            r0, #SUCCESS
9:
                    pop             {r3-r7, pc}

    private_function(DisplayDriverSPI_setupSPI)

@ void DisplayDriverSPI_setupSPI(void)
@   Function to set up the SPI interface with DMA used for transmitting

DisplayDriverSPI_setupSPI:
                    push            {r7, lr}
                    ldr             r3, = #ACB_DISPLAY_SPI_GPIOBASE @ setup SPI on port/pings defined in header file
                    ldr             r1, [r3, #GPIO_MODER_OFFSET]    @ set mode to AF
                    ldr             r0, = #(2<<(ACB_DISPLAY_SPI_CLK<<1))|(2<<(ACB_DISPLAY_SPI_MOSI<<1))
                    orrs            r1, r1, r0
                    str             r1, [r3, #GPIO_MODER_OFFSET]
                    ldr             r1, [r3, #GPIO_OSPEEDR_OFFSET]  @ enable high speed
                    ldr             r0, = #(3<<(ACB_DISPLAY_SPI_CLK<<1))|(3<<(ACB_DISPLAY_SPI_MOSI<<1))
                    orrs            r1, r1, r0
                    str             r1, [r3, #GPIO_OSPEEDR_OFFSET]
                                                                    @ default AF settings are zero, which is SPI1 on
                                                                    @ PA5 (SCK), PA7 (MOSI), so no need to set here
                    ldr             r3, = #ACB_DISPLAY_DC_GPIOBASE
                    ldr             r1, [r3, #GPIO_MODER_OFFSET]    @ set mode to output, medium speed
                    ldr             r0, = #(1<<(ACB_DISPLAY_DC_PIN<<1))
                    orrs            r1, r1, r0
                    str             r1, [r3, #GPIO_MODER_OFFSET]
                    ldr             r1, [r3, #GPIO_OSPEEDR_OFFSET]
                    ldr             r0, = #(1<<(ACB_DISPLAY_DC_PIN<<1))
                    str             r1, [r3, #GPIO_OSPEEDR_OFFSET]

                    ldr             r3, = #ACB_DISPLAY_CS_GPIOBASE
                    ldr             r1, [r3, #GPIO_MODER_OFFSET]    @ set mode to output, medium speed, pull up
                    ldr             r0, = #(1<<(ACB_DISPLAY_CS_PIN<<1))
                    orrs            r1, r1, r0
                    str             r1, [r3, #GPIO_MODER_OFFSET]
                    ldr             r1, [r3, #GPIO_OSPEEDR_OFFSET]
                    ldr             r0, = #(1<<(ACB_DISPLAY_CS_PIN<<1))
                    orrs            r1, r1, r0
                    str             r1, [r3, #GPIO_OSPEEDR_OFFSET]
                    ldr             r1, [r3, #GPIO_PUPDR_OFFSET]
                    ldr             r0, = #(1<<(ACB_DISPLAY_CS_PIN<<1))
                    str             r1, [r3, #GPIO_PUPDR_OFFSET]
                    ldr             r0, = #1<<ACB_DISPLAY_CS_PIN    @ set CS high
                    str             r0, [r3, #GPIO_BSRR_OFFSET]

__spiSetupPeripheral:
                    ldr             r3, = #ACB_DISPLAY_SPI_BASE     @ select simplex, tx only, baud rate as defined in
                                                                    @ in the header file, master mode, CPOL=1 CPHA=1,
                                                                    @ 8-bit data, NSS in software
                    ldr             r0, = #SPI_CR1_BIDIMODE | SPI_CR1_BIDIOE | SPI_CR1_SSM | SPI_CR1_SSI |\
                                           (ACB_DISPLAY_SPI_PRESCALER<<3) | SPI_CR1_MSTR | SPI_CR1_CPOL | SPI_CR1_CPHA
                    str             r0, [r3, #SPI_CR1_OFFSET]
                    ldr             r0, = #SPI_CR2_DS_2 | SPI_CR2_DS_1 | SPI_CR2_DS_0 | SPI_CR2_TXEIE
                    str             r0, [r3, #SPI_CR2_OFFSET]
                    movs            r0, #ACB_DISPLAY_SPI_IRQ        @ enable SPI interrupts
                    bl              NVIC_enableIRQ
__spiSetupDma:                                                      @ pre-configure some of the DMA channel
                    ldr             r3, = #ACB_DISPLAY_SPI_DMA_CHANNEL @ set DMA to point to SPI data register
                    ldr             r0, = #(ACB_DISPLAY_SPI_BASE + SPI_DR_OFFSET) @, high priority, 8 bit memory/peripheral
                    str             r0, [r3, #DMA_Channel_CPAR_OFFSET] @ size, memory inc mode, and read from memory
                    ldr             r0, = #DMA_CCR_PL_1 | DMA_CCR_MINC | DMA_CCR_DIR
                    str             r0, [r3, #DMA_Channel_CCR_OFFSET]
                    pop             {r7, pc}

    public_function(ACB_DISPLAY_SPI_ISR)

@ void ACB_DISPLAY_SPI_ISR()
@   SPI ISR - if the SPI module has finished sending the data, then raise the CS line, turn off the DMA and SPI modules

ACB_DISPLAY_SPI_ISR:
                    ldr             r3, = #ACB_DISPLAY_SPI_BASE
                    ldr             r2, [r3, #SPI_SR_OFFSET]
                    ldr             r1, = #SPI_SR_BSY
                    tst             r2, r1
                    beq             DisplayDriverSPI_endTx
                    movs            r0, #ACB_DISPLAY_SPI_ALARM_SLOT @ set an alarm for 1ms to recheck the BSY flag
                    movs            r1, #1
                    ldr             r2, = #(ACB_DISPLAY_SPI_ISR+1)
                    b               MsCounter_alarmIn

    public_function(DisplayDriverSPI_send)

@ bool DisplayDriverSPI_send(BYTE* dataToSend, int dataSize)
@   send a sequence of bytes to the display. Returns SUCCESS if the data was successfully sent, otherwise ERROR. This
@   method is non-blocking, and callee's must have already checked that the SPI bus is ready to send.

DisplayDriverSPI_send:
                    push            {r7, lr}
                    ldr             r3, = #ACB_DISPLAY_SPI_DMA_CHANNEL @ configure the DMA channel for this transmission
                    str             r0, [r3, #DMA_Channel_CMAR_OFFSET] @ set source memory address
                    str             r1, [r3, #DMA_Channel_CNDTR_OFFSET] @ and size of transfer
                    ldr             r2, [r3, #DMA_Channel_CCR_OFFSET]   @ enable the DMA channel
                    ldr             r1, = #DMA_CCR_EN
                    orrs            r2, r2, r1
                    str             r2, [r3, #DMA_Channel_CCR_OFFSET]

                    ldr             r7, = #ACB_DISPLAY_CS_GPIOBASE  @ bring CS low, to indicate we are going to write to
                    ldr             r3, = #1<<ACB_DISPLAY_CS_PIN    @ to the display
                    str             r3, [r7, #GPIO_BRR_OFFSET]

                    ldr             r7, = #ACB_DISPLAY_SPI_BASE
                    ldr             r1, [r7, #SPI_CR2_OFFSET]
                    movs            r0, #SPI_CR2_TXDMAEN
                    orrs            r1, r1, r0
                    str             r1, [r7, #SPI_CR2_OFFSET]
                    ldr             r1, [r7, #SPI_CR1_OFFSET]
                    movs            r0, #SPI_CR1_SPE
                    orrs            r1, r1, r0
                    str             r1, [r7, #SPI_CR1_OFFSET]
                    movs            r0, #PENDING
                    pop             {r7, pc}

    public_function(DisplayDriverSPI_readyToSend)

@ void DisplayDriverSPI_readyToSend(void)
@   blocks until the SPI bus is ready to send more data. This waits until CS line goes high. Implementation note: this
@   method preserves r0 and r1

DisplayDriverSPI_readyToSend:
                    push            {r7, lr}
                    ldr             r3, = #ACB_DISPLAY_CS_GPIOBASE
                    ldr             r7, = #1<<ACB_DISPLAY_CS_PIN
0:
                    ldr             r2, [r3, #GPIO_ODR_OFFSET]
                    tst             r2, r7
                    beq             0b
                    pop             {r7, pc}

    public_function(DisplayDriverSPI_readyToSend)

@ void DisplayDriverSPI_readyToSend(void)
@   disables the DMA Channel, SPI module, and raises CS

DisplayDriverSPI_endTx:
                    ldr             r2, = #ACB_DISPLAY_SPI_DMA_CHANNEL @ disable the DMA channel
                    ldr             r1, [r2, #DMA_Channel_CCR_OFFSET]
                    ldr             r0, = #DMA_CCR_EN
                    bics            r1, r1, r0
                    str             r1, [r2, #DMA_Channel_CCR_OFFSET]

                    ldr             r3, = #ACB_DISPLAY_SPI_BASE
                    ldr             r2, [r3, #SPI_CR1_OFFSET]       @ disable the SPI module
                    ldr             r1, = #SPI_CR1_SPE
                    bics            r2, r2, r1
                    str             r2, [r3, #SPI_CR1_OFFSET]

                    ldr             r3, = #ACB_DISPLAY_CS_GPIOBASE  @ raise CS to finish communication with the display
                    ldr             r1, = #1<<ACB_DISPLAY_CS_PIN
                    str             r1, [r3, #GPIO_BSRR_OFFSET]
                    bx              lr

#endif

    .end
