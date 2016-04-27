/*
 * Copyright (c) 2015 The NW1 Group
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#include "moduleInfo.inc"

#ifdef ACB_USE_DISPLAYDRIVER_I2C

@ Display drivers for I2C - current implementation doesn't use DMA, and all function calls block until completed

    module(DisplayDriverI2C)

    public_function(DisplayDriverI2C_init)

@ bool DisplayDriverI2C_init(BYTE* initcommands, int noCommands)
@   Initialise the display. Returns SUCCESS if the initialisation was successful, otherwise ERROR

DisplayDriverI2C_init:
                    push            {r0-r1, r7, lr}

    @ Probably TEMP, as we need some sort of I2C "manager", that initialises I2C
    @   and other "classes" can register to get interrupts (I2C and DMA)

                    bl              DisplayDriverI2C_setupI2C
                    cmp             r0, #ERROR
                    beq             9f

    @ end of TEMP

                    pop             {r0-r1}                         @ restore the parameters
                    bl              DisplayDriverI2C_sendCommands
                    pop             {r7, pc}
9:
                    pop             {r0-r1, r7, pc}

    public_function(DisplayDriverI2C_sendCommands)

@ bool DisplayDriverI2C_sendCommands(BYTE* commands, int noCommands)
@   Send a sequence of commands to the display. Returns SUCCESS if the initialisation was successful, otherwise ERROR

DisplayDriverI2C_sendCommands:
                    push            {r5-r7, lr}
                    cmp             r1, #0
                    ble             8f
                    movs            r5, r0                          @ save off parameters
                    movs            r6, r1
                    movs            r0, #DISPLAY_ADDR
                    lsls            r1, r1, #17                     @ send 2 bytes for every command
                    ldr             r2, = #I2C_CR2_AUTOEND
                    orrs            r1, r1, r2
                    bl              _doStart
                    cmp             r0, #ERROR
                    beq             9f
                    movs            r7, #0                          @ use to count through the loop
0:
                    ldrb            r0, [r5, r7]
                    bl              DisplayDriverI2C_sendSingleCommand
                    cmp             r0, #ERROR
                    beq             9f
                    adds            r7, r7, #1
                    cmp             r7, r6
                    blt             0b
9:
                    pop             {r5-r7, pc}
8:
                    movs            r0, #SUCCESS
                    pop             {r5-r7, pc}

    public_function(DisplayDriverI2C_sendCommand)

@ bool DisplayDriverI2C_sendCommand(BYTE command)
@   Send a command to the display. Returns SUCCESS if the command was successful, otherwise ERROR

DisplayDriverI2C_sendCommand:
                    push            {r5-r7, lr}
                    movs            r5, r0
                    movs            r0, #DISPLAY_ADDR
                    ldr             r1, = #(2<<16) | I2C_CR2_AUTOEND @ write data bytes
                    bl              _doStart
                    cmp             r0, #ERROR
                    beq             9f
                    movs            r0, r5
                    bl              DisplayDriverI2C_sendSingleCommand
9:
                    pop             {r5-r7, pc}

    public_function(DisplayDriverI2C_sendCommandAndParameter)

@ bool DisplayDriverI2C_sendCommand(BYTE command, BYTE parameter)
@   Send a command, with a parameter to the display. Returns SUCCESS if the command was successful, otherwise ERROR

DisplayDriverI2C_sendCommandAndParameter:
                    push            {r5-r7, lr}
                    movs            r5, r0
                    movs            r6, r1
                    movs            r0, #DISPLAY_ADDR
                    ldr             r1, = #(4<<16) | I2C_CR2_AUTOEND @ write data bytes
                    bl              _doStart
                    cmp             r0, #ERROR
                    beq             9f
                    movs            r0, r5
                    bl              DisplayDriverI2C_sendSingleCommand
                    cmp             r0, #ERROR
                    beq             9f
                    movs            r0, r6
                    bl              DisplayDriverI2C_sendSingleCommand
9:
                    pop             {r5-r7, pc}

    public_function(DisplayDriverI2C_sendData)

@ bool DisplayDriverI2C_sendData(BYTE* data, int noBytes)
@   Send a sequence of data to the display. Returns SUCCESS if the initialisation was successful, otherwise ERROR

DisplayDriverI2C_sendData:
                    push            {r3-r7, lr}
                    cmp             r1, #0                          @ no data to send, just return SUCCESS
                    ble             8f
                    movs            r5, r0                          @ save parameters
                    adds            r6, r1, #1                      @ need to send data byte first

                    movs            r7, #1                          @ set flag to say first time through loop, send
                                                                    @ "control" byte
_sdi2c_sendDataBlockLoop:
                    cmp             r6, #255                        @ do we need to send more than one block of data?
                    bgt             0f
                    ldr             r1, = #I2C_CR2_AUTOEND | DISPLAY_ADDR   @ last block to send, so we autoend
                    lsls            r2, r6, #16                     @ shift length of remaining bytes into the correct place
                    orrs            r1, r1, r2
                    movs            r4, r6                          @ byte counter
                    movs            r6, #0                          @ set 0 bytes left to send
                    b               1f
0:
                    ldr             r1, = #(255<<16) | I2C_CR2_RELOAD | DISPLAY_ADDR    @ send the max. no bytes in one block (255)
                    subs            r6, r6, #255                    @ and store reminder left in count
                    movs            r4, #255                        @ byte counter
1:
                    cmp             r7, #1                          @ first time through?
                    bne             _sdi2c_nextBlocks               @ nope...
_sdi2c_firstTime:
                    movs            r0, #DISPLAY_ADDR               @ send start
                    bl              _doStart
                    cmp             r0, #ERROR
                    beq             9f
                    ldr             r7, = #I2C1_BASE
                    movs            r0, #0x40                       @ data to follow, and this is a data byte
                    str             r0, [r7, #I2C_TXDR_OFFSET]
                    movs            r0, #I2C_ISR_TXIS
                    bl              _waitForStatus
                    cmp             r0, #ERROR
                    beq             9f
                    subs            r4, r4, #1                      @ we've sent a byte out, so dec the counter...
                    b               2f
_sdi2c_nextBlocks:
                    str             r1, [r7, #I2C_CR2_OFFSET]
2:
                    ldrb            r0, [r5]                        @ send all the data for this block
                    str             r0, [r7, #I2C_TXDR_OFFSET]
                    movs            r0, #I2C_ISR_TXIS | I2C_ISR_TCR | I2C_ISR_STOPF
                    bl              _waitForStatus
                    cmp             r0, #ERROR
                    beq             9f
                    adds            r5, r5, #1                      @ mov onto the next memory byte
                    subs            r4, r4, #1
                    bne             2b

                    cmp             r6, #0                          @ more blocks to send?
                    bne             _sdi2c_sendDataBlockLoop        @ yup...
8:
                    movs            r0, #SUCCESS
9:
                    pop             {r3-r7, pc}

    private_function(DisplayDriverI2C_setupI2C)

@ void DisplayDriverI2C_setupI2C(void)
@   Possibly temp function to set up the I2C interface

DisplayDriverI2C_setupI2C:
                    ldr             r3, = #ACB_DISPLAY_I2C_GPIOBASE @ setup I2C on port/pins defined in header
                    ldr             r1, [r3, #GPIO_MODER_OFFSET]    @ file
                    ldr             r0, = #(2<<(ACB_DISPLAY_I2C_SDA<<1))|(2<<(ACB_DISPLAY_I2C_SCL<<1))
                    orrs            r0, r0, r1
                    str             r0, [r3, #GPIO_MODER_OFFSET]

                    ldr             r1, [r3, #GPIO_OSPEEDR_OFFSET]  @ enable high speed for these bits
                    ldr             r0, = #(3<<(ACB_DISPLAY_I2C_SDA<<1))|(3<<(ACB_DISPLAY_I2C_SCL<<1))
                    orrs            r0, r0, r1
                    str             r0, [r3, #GPIO_OSPEEDR_OFFSET]

                    ldr             r1, [r3, #GPIO_OTYPER_OFFSET]   @ set opendrain outputs
                    ldr             r0, = #(1<<ACB_DISPLAY_I2C_SDA)|(1<<ACB_DISPLAY_I2C_SCL)
                    orrs            r0, r0, r1
                    str             r0, [r3, #GPIO_OTYPER_OFFSET]

                    ldr             r1, [r3, #GPIO_PUPDR_OFFSET]    @ enable pullups (not sure if required)
                    ldr             r0, = #(1<<(ACB_DISPLAY_I2C_SDA<<1))|(1<<(ACB_DISPLAY_I2C_SCL<<1))
                    orrs            r0, r0, r1
                    str             r0, [r3, #GPIO_PUPDR_OFFSET]

#if ACB_DISPLAY_I2C_AFR_SDA_OFFSET == ACB_DISPLAY_I2C_AFR_SCL_OFFSET
                    ldr             r1, [r3, #ACB_DISPLAY_I2C_AFR_SDA_OFFSET]
                    ldr             r0, = #(1<<(ACB_DISPLAY_I2C_AFR_SDA<<2))|(1<<(ACB_DISPLAY_I2C_AFR_SCL<<2))
                    orrs            r0, r0, r1                      @ select I2C.SDA (AF1) / I2C.SCL (AF1)
                    str             r0, [r3, #ACB_DISPLAY_I2C_AFR_SDA_OFFSET]
#else
                    ldr             r1, [r3, #ACB_DISPLAY_I2C_AFR_SDA_OFFSET]
                    ldr             r0, = #(1<<(ACB_DISPLAY_I2C_AFR_SDA<<2))
                    orrs            r0, r0, r1                      @ select I2C.SDA (AF1)
                    str             r0, [r3, #ACB_DISPLAY_I2C_AFR_SDA_OFFSET]

                    ldr             r1, [r3, #ACB_DISPLAY_I2C_AFR_SCL_OFFSET]
                    ldr             r0, = #(1<<(ACB_DISPLAY_I2C_AFR_SCL<<2))
                    orrs            r0, r0, r1                      @ select I2C.SCL (AF1)
                    str             r0, [r3, #ACB_DISPLAY_I2C_AFR_SCL_OFFSET]
#endif

__i2cSetupClocks:
                    ldr             r3, = #RCC_BASE                 @ set I2C1 clock to system clock
                    ldr             r1, [r3, #RCC_CFGR3_OFFSET]
                    movs            r0, #RCC_CFGR3_I2C1SW
                    orrs            r0, r0, r1
                    str             r0, [r3, #RCC_CFGR3_OFFSET]

                    ldr             r1, [r3, #RCC_APB1ENR_OFFSET]   @ enable I2C1 clock
                    ldr             r0, = #RCC_APB1ENR_I2C1EN
                    orrs            r0, r0, r1
                    str             r0, [r3, #RCC_APB1ENR_OFFSET]
__i2cSetupPeripheral:
                    ldr             r3, = #I2C1_BASE
                    ldr             r0, = #ACB_DISPLAY_I2C_TIMING    @ set I2C timing
                    str             r0, [r3, #I2C_TIMINGR_OFFSET]
                    ldr             r1, [r3, #I2C_CR1_OFFSET]       @ enable the I2C peripheral
                    movs            r0, #I2C_CR1_PE
                    orrs            r0, r0, r1
                    str             r0, [r3, #I2C_CR1_OFFSET]

                    bx              lr

    private_function(_doStart)

@ bool _doStart(byte address, int flags)
@   performs an I2C start. Returns SUCCESS on success, or ERROR otherwise - such as a time out. Address is I2C slave
@   device address bits 7:1 and flags is supplied directly into I2C_CR2 - I2C_CR2_START will automatically be included
@   in the flags

_doStart:
                    push            {r7, lr}
                    orrs            r1, r1, r0                      @ combine address and flags, to make CR2 register value
                    ldr             r2, = #I2C_CR2_START            @ set start flag
                    orrs            r1, r1, r2

                    ldr             r7, = #I2C1_BASE                @ clear any error flags set from previous call
                    ldr             r2, = #I2C_ICR_OVRCF | I2C_ICR_ARLOCF | I2C_ICR_BERRCF | I2C_ICR_NACKCF | I2C_ICR_STOPCF
                    str             r2, [r7, #I2C_ICR_OFFSET]

__i2cTryStart:
                    str             r1, [r7, #I2C_CR2_OFFSET]       @ do start
                    lsrs            r1, r1, #16                     @ if length is 0, then we need to wait for a TXE
                    uxtb            r1, r1                          @ rather than a TXIS
                    cmp             r1, #0
                    beq             0f
                    movs            r0, #I2C_ISR_TXIS               @ wait for transmission of this byte to end
                    b               1f
0:
                    movs            r0, #I2C_ISR_TXE                @ wait for transmission to end
1:
                    bl              _waitForStatus
                    pop             {r7, pc}

    private_function(DisplayDriverI2C_sendSingleCommand)

@ bool DisplayDriverI2C_sendCommand(BYTE command)
@   Send a command to the display. Returns SUCCESS if the command was successful, otherwise ERROR.
@   Assumes a START has already been sent, and checks for either TXIS or I2C_ISR_STOPF

DisplayDriverI2C_sendSingleCommand:
                    push            {r5-r7, lr}
                    movs            r5, r0                          @ save off the command
                    ldr             r7, = #I2C1_BASE
                    movs            r0, #0x80                       @ co=1, D/C#=0
                    str             r0, [r7, #I2C_TXDR_OFFSET]      @ send the control byte
                    movs            r0, #I2C_ISR_TXIS               @ wait for transmission to end
                    bl              _waitForStatus
                    cmp             r0, #ERROR
                    beq             9f
                    str             r5, [r7, #I2C_TXDR_OFFSET]      @ send the command byte
                    movs            r0, #I2C_ISR_TXIS | I2C_ISR_STOPF
                    bl              _waitForStatus
9:
                    pop             {r5-r7, pc}

    private_function(_waitForStatus)

@ bool _waitForStatus(int flag)
@   returns SUCCESS if the flag is set in the I2C_ISR register within the "timeout", otherwise ERROR. The timeout here
@   is defined as the number of times the loop is run, so not very accurate but stops the application from hanging if
@   there is an issue on the I2C bus.

_waitForStatus:
waitForStatusTimeout = 0x1000
                    ldr             r3, = #I2C1_BASE
                    ldr             r2, = #waitForStatusTimeout
0:
                    ldr             r1, [r3, #I2C_ISR_OFFSET]
                    tst             r1, r0
                    bne             1f
                    subs            r2, r2, #1
                    bne             0b

                    movs            r0, #ERROR
                    bx              lr
1:
                    movs            r0, #SUCCESS
                    bx              lr

#endif

    .end
