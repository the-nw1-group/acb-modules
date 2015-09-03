/*
 * Copyright (c) 2015 The NW1 Group
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#include "moduleInfo.inc"
#include "acb/eepromI2C.inc"
#include "acb/eeprom.inc"

@ EEPROM "driver" routines for I2C implementation

    module(EepromI2C)

    .extern         MsCounter_milliseconds                          @ ms counter

    private_data(EepromI2C_data)

EepromI2C_writeComplete:
                    .word           0                               @ the time the last write should complete
EepromI2C_status:   .byte           0                               @ status

ASYNC_IN_PROGRESS = 0                                               @ Async read or write
WRITE_IN_PROGRESS = 1
LAST_ASYNC_STATUS = 2

    public_function(EepromI2C_init)

@ bool EepromI2C_init()
@   initialise EEPROM - performs a driver initialisation. Returns SUCCESS on success or ERROR on error. This assumes
@   the port used by I2C has already had it's clocked enabled.

EepromI2C_init:
                    push            {r7, lr}
__eepromi2cResetVars:
                    movs            r0, #0
                    ldr             r1, = #EepromI2C_writeComplete
                    str             r0, [r1]
                    str             r0, [r1, #4]

__eepromi2cSetupPort:
                    ldr             r3, = #ACB_EEPROM_I2C_GPIOBASE  @ setup I2C on port/pins defined in header
                    ldr             r1, [r3, #GPIO_MODER_OFFSET]    @ file
                    ldr             r0, = #(2<<(ACB_EEPROM_I2C_SDA<<1))|(2<<(ACB_EEPROM_I2C_SCL<<1))
                    orrs            r0, r0, r1
                    str             r0, [r3, #GPIO_MODER_OFFSET]

                    ldr             r1, [r3, #GPIO_OSPEEDR_OFFSET]  @ enable high speed for these bits
                    ldr             r0, = #(3<<(ACB_EEPROM_I2C_SDA<<1))|(3<<(ACB_EEPROM_I2C_SCL<<1))
                    orrs            r0, r0, r1
                    str             r0, [r3, #GPIO_OSPEEDR_OFFSET]

                    ldr             r1, [r3, #GPIO_OTYPER_OFFSET]   @ set opendrain outputs
                    ldr             r0, = #(1<<ACB_EEPROM_I2C_SDA)|(1<<ACB_EEPROM_I2C_SCL)
                    orrs            r0, r0, r1
                    str             r0, [r3, #GPIO_OTYPER_OFFSET]

                    ldr             r1, [r3, #GPIO_PUPDR_OFFSET]    @ enable pullups (not sure if required)
                    ldr             r0, = #(1<<(ACB_EEPROM_I2C_SDA<<1))|(1<<(ACB_EEPROM_I2C_SCL<<1))
                    orrs            r0, r0, r1
                    str             r0, [r3, #GPIO_PUPDR_OFFSET]

#if ACB_EEPROM_I2C_AFR_SDA_OFFSET == ACB_EEPROM_I2C_AFR_SCL_OFFSET
                    ldr             r1, [r3, #ACB_EEPROM_I2C_AFR_SDA_OFFSET]
                    ldr             r0, = #(1<<(ACB_EEPROM_I2C_AFR_SDA<<2))|(1<<(ACB_EEPROM_I2C_AFR_SCL<<2))
                    orrs            r0, r0, r1                      @ select I2C.SDA (AF1) / I2C.SCL (AF1)
                    str             r0, [r3, #ACB_EEPROM_I2C_AFR_SDA_OFFSET]
#else
                    ldr             r1, [r3, #ACB_EEPROM_I2C_AFR_SDA_OFFSET]
                    ldr             r0, = #(1<<(ACB_EEPROM_I2C_AFR_SDA<<2))
                    orrs            r0, r0, r1                      @ select I2C.SDA (AF1)
                    str             r0, [r3, #ACB_EEPROM_I2C_AFR_SDA_OFFSET]

                    ldr             r1, [r3, #ACB_EEPROM_I2C_AFR_SCL_OFFSET]
                    ldr             r0, = #(1<<(ACB_EEPROM_I2C_AFR_SCL<<2))
                    orrs            r0, r0, r1                      @ select I2C.SCL (AF1)
                    str             r0, [r3, #ACB_EEPROM_I2C_AFR_SCL_OFFSET]
#endif

__eepromi2cSetupClocks:
                    ldr             r3, = #_RCC_CFGR3               @ set I2C1 clock to system clock
                    ldr             r1, [r3]
                    movs            r0, #RCC_CFGR3_I2C1SW
                    orrs            r0, r0, r1
                    str             r0, [r3]

                    ldr             r3, = #_RCC_APB1ENR             @ enable I2C1 clock
                    ldr             r1, [r3]
                    ldr             r0, = #RCC_APB1ENR_I2C1EN
                    orrs            r0, r0, r1
                    str             r0, [r3]
__eepromi2cSetupPeripheral:
                    ldr             r3, = #I2C1_BASE
                    ldr             r0, = #ACB_EEPROM_I2C_TIMING    @ set I2C timing
                    str             r0, [r3, #I2C_TIMINGR_OFFSET]
                    ldr             r1, [r3, #I2C_CR1_OFFSET]       @ enable the I2C peripheral
                    movs            r0, #I2C_CR1_PE
                    orrs            r0, r0, r1
                    str             r0, [r3, #I2C_CR1_OFFSET]
__eepromi2cDummyRead:
                    movs            r0, #0                          @ read the first byte
                    bl              EepromI2C_readByte
                    lsrs            r0, r0, #8                      @ shift result from readByte to return status from here
                    pop             {r7, pc}

    public_function(EepromI2C_readByte)

@ int EepromI2C_readByte(int address)
@   reads a byte from the EEPROM at the supplied address. Read byte is returned in the LSB of the result, with
@   status of the read (SUCCESS or ERROR) returned in the next byte. Result is:
@       32:16   unused
@       15:8    status
@       7:0     byte read if any
@   This call blocks until the byte is read, or an error condition occurs. If an asynchronous call is in progress
@   this call will block until that call is complete.

EepromI2C_readByte:
                    push            {r5-r7, lr}
                    mov             r6, r0                          @ save a copy of the address to write

                    lsrs            r1, r6, #7                      @ get the block address
                    movs            r0, #ACB_EEPROM_ADDRESS
                    orrs            r0, r0, r1
                    ldr             r1, = #(1<<16)                  @ write 1 byte
                    bl              EepromI2C_doStart
                    cmp             r0, #ERROR
                    beq             __eei2cReadFailed

                    ldr             r7, = #I2C1_BASE
                    str             r6, [r7, #I2C_TXDR_OFFSET]      @ send the address
                    movs            r0, #I2C_ISR_TC                 @ wait for transfer complete
                    bl              EepromI2C_waitForStatus
                    cmp             r0, #ERROR
                    beq             __eei2cReadFailed

                    ldr             r1, [r7, #I2C_CR2_OFFSET]       @ read the byte from the device
                    ldr             r2, = #(I2C_CR2_START | I2C_CR2_RD_WRN | I2C_CR2_AUTOEND)
                    orrs            r1, r1, r2
                    str             r1, [r7, #I2C_CR2_OFFSET]
                    movs            r0, #I2C_ISR_STOPF              @ wait for the byte to be received, and we have a
                    bl              EepromI2C_waitForStatus         @ STOP
                    cmp             r0, #ERROR
                    beq             __eei2cReadFailed

                    movs            r0, #I2C_ICR_STOPCF             @ clear the stop flag
                    str             r0, [r7, #I2C_ICR_OFFSET]
                    ldr             r0, [r7, #I2C_RXDR_OFFSET]      @ get the byte read
                    ldr             r1, = #SUCCESS<<8               @ and set the success flag
                    orrs            r0, r0, r1
0:
                    pop             {r5-r7, pc}
__eei2cReadFailed:
                    movs            r0, #ERROR                      @ clear result, set ERROR flag
                    b               0b

    public_function(EepromI2C_writeByte)

@ bool EepromI2C_writeByte(int address, byte value)
@   write the supplied byte into the EEPROM at the address. Returns SUCCESS on success or ERROR on error. This call
@   blocks until the byte is written, or an error condition occurs. If an asynchronous call is in progress
@   this call will block until that call is complete.

EepromI2C_writeByte:
                    push            {r5-r7, lr}
                    mov             r6, r0                          @ save a copy of the parameters
                    movs            r5, r1

                    lsrs            r1, r6, #7                      @ get the block address
                    movs            r0, #ACB_EEPROM_ADDRESS
                    orrs            r0, r0, r1
                    ldr             r1, = #(2<<16) | I2C_CR2_AUTOEND @ write 2 bytes, and autoend
                    bl              EepromI2C_doStart
                    cmp             r0, #ERROR
                    beq             __eei2cReadFailed

                    ldr             r7, = #I2C1_BASE
                    str             r6, [r7, #I2C_TXDR_OFFSET]      @ send the address
                    movs            r0, #I2C_ISR_TXIS               @ wait for transmission to end
                    bl              EepromI2C_waitForStatus
                    cmp             r0, #ERROR
                    beq             __eei2cWriteFailed

                    str             r5, [r7, #I2C_TXDR_OFFSET]      @ send the data
                    movs            r0, #I2C_ISR_STOPF              @ wait for transfer complete
                    bl              EepromI2C_waitForStatus
                    cmp             r0, #ERROR
                    beq             __eei2cWriteFailed

                    movs            r0, #I2C_ICR_STOPCF             @ clear the stop flag
                    str             r0, [r7, #I2C_ICR_OFFSET]

                    ldr             r0, = #MsCounter_milliseconds   @ store the max time when this operation will
                    ldr             r0, [r0]                        @ finish - add on half again to the defined amount
                    adds            r0, r0, #(ACB_EEPROM_WRITETIME+ACB_EEPROM_WRITETIME/2)
                    ldr             r1, =#EepromI2C_writeComplete
                    str             r0, [r1]
                    ldrb            r0, [r1, #4]                    @ set the WRITE_IN_PROGRESS in the status byte
                    movs            r2, #1<<WRITE_IN_PROGRESS
                    orrs            r0, r0, r2
                    strb            r0, [r1, #4]
                    movs            r0, #SUCCESS                    @ all ok
0:
                    pop             {r5-r7, pc}
__eei2cWriteFailed:
                    movs            r0, #ERROR                      @ clear result, set ERROR flag
                    b               0b

    public_function(EepromI2C_readBlock)

@ int EepromI2C_readBlock(int address, short length, byte* buffer)
@   read a number of bytes from the EEPROM, starting at the supplied address, reading length bytes, and the bytes are
@   placed in the buffer. The callee is responsible for allocating and freeing the buffer, and ensuring that it is large
@   enough to store the results. The function returns SUCCESS if the data is read, ERROR on error, or PENDING if the
@   call to read the data is made asynchronously. If an asynchronous call is in progress this call will block until that
@   call is complete.

EepromI2C_readBlock:
                    bx              lr

    public_function(EepromI2C_writeBlock)

@ int EepromI2C_writeBlock(int address, short length, byte* buffer)
@   write a number of bytes to the EEPROM, starting at the supplied address, reading length bytes, and the bytes are
@   read from the buffer. The function returns SUCCESS if the data is read, ERROR on error, or PENDING if the
@   call to read the data is made asynchronously. If an asynchronous call is in progress this call will block until
@   that call is complete.

EepromI2C_writeBlock:
                    bx              lr

    public_function(EepromI2C_asyncInProgress)

@ bool EepromI2C_asyncInProgress()
@   returns TRUE if a asynchronous is in progress, otherwise false.

EepromI2C_asyncInProgress:
                    ldr             r0, = #EepromI2C_status
                    ldrb            r0, [r0]
                    movs            r1, #1<<ASYNC_IN_PROGRESS
                    ands            r0, r0, r1
                    bx              lr

    public_function(EepromI2C_getLastAsyncStatus)

@ bool Eeprom_getLastAsyncStatus()
@   returns SUCCESS if the last asynchronous call completed successfully, otherwise error.

EepromI2C_getLastAsyncStatus:
                    ldr             r0, = #EepromI2C_status
                    ldrb            r0, [r0]
                    lsrs            r0, r0, #LAST_ASYNC_STATUS
                    movs            r1, #1
                    ands            r0, r0, r1
                    bx              lr

    private_function(EepromI2C_doStart)

@ bool EepromI2C_doStart(byte address, int flags)
@   performs an I2C start, after waiting for any async read/write to finish, and waiting for an previous write to
@   finish. Returns SUCCESS on success, or ERROR otherwise - such as a time out. address is I2C slave device address
@   bits 7:1 and flags is supplied directly into I2C_CR2 - I2C_CR2_START will automatically be included in the flags

EepromI2C_doStart:
                    push            {r4-r7, lr}
                    sub             sp, sp, #12
                    orrs            r1, r1, r0                      @ combine address and flags, to make CR2 register value
                    ldr             r2, = #I2C_CR2_START            @ set start flag
                    orrs            r1, r1, r2
                    movs            r5, r1                          @ and store out of harms way

                    ldr             r6, = #EepromI2C_status         @ if an aysnc call is in process, then block
                    movs            r3, #1<<ASYNC_IN_PROGRESS       @ until it finishes (no timeout here, as we don't
0:                                                                  @ know what it's doing!
                    ldrb            r2, [r6]
                    tst             r2, r3
                    bne             0b

                    ldr             r7, = #I2C1_BASE                @ clear any error flags set from previous call
                    ldr             r2, = #I2C_ICR_OVRCF | I2C_ICR_ARLOCF | I2C_ICR_BERRCF | I2C_ICR_NACKCF | I2C_ICR_STOPCF
                    str             r2, [r7, #I2C_ICR_OFFSET]

                    ldr             r4, = #MsCounter_milliseconds   @ ptr current "time" in ms
                    ldr             r0, [r4]                        @ store current time
                    str             r0, [sp, #4]
                    ldr             r0, = #EepromI2C_writeComplete  @ ptr the time the write should complete by
                    str             r0, [sp]
1:
                    str             r5, [r7, #I2C_CR2_OFFSET]       @ do start
                    movs            r0, #I2C_ISR_TXIS               @ wait for transmission to end
                    bl              EepromI2C_waitForStatus
                    cmp             r0, #ERROR
                    bne             2f                              @ worked, so any write must have finished...

                    ldr             r0, [r7, I2C_ISR_OFFSET]        @ check the error was a NAK
                    movs            r1, #I2C_ISR_NACKF
                    tst             r0, r1
                    beq             4f
                    movs            r1, #I2C_ISR_NACKF | I2C_ISR_STOPF
                    str             r1, [r7, I2C_ICR_OFFSET]        @ clear NAK and STOP

                    ldr             r0, [r6]
                    movs            r1, #1<<WRITE_IN_PROGRESS       @ write in progress?
                    beq             4f                              @ no, so just fail...

                    ldr             r0, [r4]                        @ get current "time"
                    ldr             r1, [sp]
                    ldr             r1, [r1]                        @ get complete "time"
                    cmp             r0, r1
                    bgt             1f                              @ fail if current "time" > complete "time"
                    ldr             r1, [sp, #4]
0:                                                                  @ wait for 1 ms
                    ldr             r0, [r4]
                    cmp             r0, r1
                    beq             0b

                    str             r0, [sp, #4]                    @ store last time we checked
                    b               1b                              @ check for possible start again...
2:
                    ldrb            r0, [r6]
                    movs            r2, #1<<WRITE_IN_PROGRESS
                    bics            r0, r0, r2
                    strb            r0, [r6]
                    movs            r0, #SUCCESS
3:
                    add             sp, sp, #12
                    pop             {r4-r7, pc}
4:
                    movs            r0, #ERROR
                    b               3b

    private_function(EepromI2C_waitForStatus)

@ bool EepromI2C_waitForStatus(int flag)
@   returns SUCCESS if the flag is set in the I2C_ISR register within the "timeout", otherwise ERROR. The timeout here
@   is defined as the number of times the loop is run, so not very accurate but stops the application from hanging if
@   there is an issue on the I2C bus.

EepromI2C_waitForStatus:
waitForStatusTimeout = 0xA00
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

    .end
