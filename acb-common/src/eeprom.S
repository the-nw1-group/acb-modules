/*
 * Copyright (c) 2015 The NW1 Group
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#include "moduleInfo.inc"
#include "acb/eeprom.inc"
#include "acb/common.inc"

@ public EEPROM routines, for reading and writing bytes and blocks of bytes

    module(Eeprom)

    .extern         EepromDrv_init                                  @ Initialise the driver
    .extern         EepromDrv_readByte                              @ Read a byte from the EEPROM
    .extern         EepromDrv_writeByte                             @ Write a byte to the EEPROM
    .extern         EepromDrv_readBlock                             @ Read a block of bytes from the EEPROM
    .extern         EepromDrv_writeBlock                            @ Write a block of bytes from the EEPROM
    .extern         EepromDrv_asyncInProgress                       @ Is async call in progress
    .extern         EepromDrv_getLastAsyncStatus                    @ Get status of last async call

@ General note: All reading and writing functions will fail if the address is out of range for the amount of memory
@ available within the EEPROM, also if the address + number of bytes to read or write is out of range.

    public_function(EepromImpl_init)

@ bool EepromImpl_init()
@   initialise EEPROM - performs a driver initialisation. Returns SUCCESS on success or ERROR on error.

EepromImpl_init:
                    b               EepromDrv_init                  @ just init the driver

    public_function(EepromImpl_readByte)

@ int EepromImpl_readByte(int address)
@   reads a byte from the EEPROM at the supplied address. Read byte is returned in the LSB of the result, with
@   status of the read (SUCCESS or ERROR) returned in the next byte. Result is:
@       32:16   unused
@       15:8    status
@       7:0     byte read if any
@   This call blocks until the byte is read, or an error condition occurs. If an asynchronous call is in progress
@   this call will block until that call is complete.

EepromImpl_readByte:
                    ldr             r1, = #ACB_EEPROM_SIZE          @ check if the read is out of range
                    cmp             r0, r1                          @ use unsigned check to check for less than 0
                    bhi             0f
                    b               EepromDrv_readByte
0:
                    ldr             r0, = #(ERROR<<8)
                    bx              lr

    public_function(EepromImpl_writeByte)

@ bool EepromImpl_writeByte(int address, byte value)
@   write the supplied byte into the EEPROM at the address. Returns SUCCESS on success or ERROR on error. This call
@   blocks until the byte is written, or an error condition occurs. If an asynchronous call is in progress
@   this call will block until that call is complete.

EepromImpl_writeByte:
                    ldr             r2, = #ACB_EEPROM_SIZE          @ check if the write is out of range
                    cmp             r0, r2                          @ use unsigned check to check for less than 0
                    bhi             0f
                    adds            r3, r0, #1                      @ and check write is all in range as well
                    cmp             r3, r2
                    bhi             0f
                    b               EepromDrv_writeByte
0:
                    movs            r0, #ERROR
                    bx              lr

    public_function(EepromImpl_readBlock)

@ int EepromImpl_readBlock(int address, short length, byte* buffer)
@   read a number of bytes from the EEPROM, starting at the supplied address, reading length bytes, and the bytes are
@   placed in the buffer. The callee is responsible for allocating and freeing the buffer, and ensuring that it is large
@   enough to store the results. The function returns SUCCESS if the data is read, ERROR on error, or PENDING if the
@   call to read the data is made asynchronously. If an asynchronous call is in progress this call will block until that
@   call is complete.

EepromImpl_readBlock:
                    bx              lr

    public_function(EepromImpl_writeBlock)

@ int EepromImpl_writeBlock(int address, short length, byte* buffer)
@   write a number of bytes to the EEPROM, starting at the supplied address, reading length bytes, and the bytes are
@   read from the buffer. The function returns SUCCESS if the data is read, ERROR on error, or PENDING if the
@   call to read the data is made asynchronously. If an asynchronous call is in progress this call will block until
@   that call is complete.

EepromImpl_writeBlock:
                    bx              lr

    public_function(EepromImpl_asyncInProgress)

@ bool EepromImpl_asyncInProgress()
@   returns TRUE if a asynchronous is in progress, otherwise false.

EepromImpl_asyncInProgress:
                    b               EepromDrv_asyncInProgress       @ just call driver

    public_function(EepromImpl_getLastAsyncStatus)

@ bool Eeprom_getLastAsyncStatus()
@   returns SUCCESS if the last asynchronous call completed successfully, otherwise error.

EepromImpl_getLastAsyncStatus:
                    b               EepromDrv_getLastAsyncStatus    @ just call driver

    public_function(EepromImpl_readBlockEx)

@ int Eeprom_readBlockEx(int address, short length, byte* buffer)
@   read a number of bytes from the EEPROM, starting at the supplied address, reading length bytes, and the bytes are
@   placed in the buffer. The callee is responsible for allocating and freeing the buffer, and ensuring that it is large
@   enough to store the results. The function returns SUCCESS if the data is read or ERROR on error. This call will
@   block until the block has been read, or an ERROR occurs.  If an asynchronous call is in progress this call will
@   block until that call is complete.

EepromImpl_readBlockEx:
                    push            {r7, lr}
                    bl              EepromImpl_readBlock
                    cmp             r0, #PENDING
                    bne             0f
0:
                    bl              EepromImpl_asyncInProgress
                    cmp             r0, #FALSE
                    bne             0b
                    bl              EepromImpl_getLastAsyncStatus
1:
                    pop             {r7, pc}

    public_function(EepromImpl_writeBlockEx)

@ bool Eeprom_writeBlockEx(int address, short length, byte* buffer)
@   write a number of bytes to the EEPROM, starting at the supplied address, writing length bytes, and the bytes are
@   read from the buffer. The function returns SUCCESS if the data is read or ERROR on error.  This call will
@   block until the block has been read, or an ERROR occurs.  If an asynchronous call is in progress this call will
@   block until that call is complete.

EepromImpl_writeBlockEx:
                    push            {r7, lr}
                    bl              EepromImpl_writeBlock
                    cmp             r0, #PENDING
                    bne             0f
0:
                    bl              EepromImpl_asyncInProgress
                    cmp             r0, #FALSE
                    bne             0b
                    bl              EepromImpl_getLastAsyncStatus
1:
                    pop             {r7, pc}

    public_function(EepromImpl_setHint)

@ void EepromImpl_setHint(int hint)
@   set a hint - which may or may not be ignored by the EEPROM system or the underlying driver.

EepromImpl_setHint:
                    bx              lr

    .end

