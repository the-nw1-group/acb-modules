/*
 * Copyright (c) 2015 The NW1 Group
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#define ACB_SKIP_CACHE_REDEFINES
#include "moduleInfo.inc"

@ EEPROM cache driver - sits between the public interface and the actual EEPROM driver

    module(EepromCache)

#if defined(ACB_CACHE_EEPROM)

    private_data(EepromCache)

EepromCache:
                    .space          ACB_EEPROM_SIZE
EepromCacheStatus:
                    .int            0

    public_function(EepromCache_init)

@ bool EepromI2C_init()
@   initialise EEPROM - performs a driver initialisation. Returns SUCCESS on success or ERROR on error.

EepromCache_init:
                    push            {r7, lr}
                    bl              EepromDrvImpl_init              @ init the underlying EEPROM driver
                    cmp             r0, #ERROR
                    beq             1f
                    movs            r0, #0
                    ldr             r1, = #ACB_EEPROM_SIZE
                    ldr             r2, = #EepromCache
                    bl              EepromDrvImpl_readBlock         @ and populate the cache
                    cmp             r0, #ERROR
                    beq             1f
0:
                    pop             {r7, pc}
1:
                    ldr             r1, = #EepromCacheStatus        @ Set cache error status, and clear loaded flag
                    movs            r2, #1<<EepromCache_StatusCacheError
                    str             r2, [r1]
                    b               0b

    public_function(EepromCache_readByte)

@ int EepromI2C_readByte(int address)
@   reads a byte from the EEPROM at the supplied address. Read byte is returned in the LSB of the result, with
@   status of the read (SUCCESS or ERROR) returned in the next byte. Result is:
@       32:16   unused
@       15:8    status
@       7:0     byte read if any
@   This call blocks until the byte is read, or an error condition occurs. If an asynchronous call is in progress
@   this call will block until that call is complete.

EepromCache_readByte:
                    push            {r7, lr}
                    movs            r7, r0                          @ save r0
                    bl              EepromCache_checkState          @ check for the cache to be populated, and check
                    cmp             r0, #ERROR                      @ that we didn't get an error
                    beq             0f                              @ if we did get an error, just return
                    mov             r0, r7                          @ restore r0
                    ldr             r1, = #EepromCache
                    ldrb            r0, [r1, r0]
                    ldr             r1, = #(SUCCESS<<8)
                    orrs            r0, r0, r1
0:
                    pop             {r7, pc}

    public_function(EepromCache_writeByte)

@ bool EepromI2C_writeByte(int address, byte value)
@   write the supplied byte into the EEPROM at the address. Returns SUCCESS on success or ERROR on error. This call
@   blocks until the byte is written, or an error condition occurs. If an asynchronous call is in progress
@   this call will block until that call is complete.

EepromCache_writeByte:
                    push            {r0-r1, r7, lr}
                    bl              EepromCache_checkState          @ check for the cache to be populated, and check
                    cmp             r0, #ERROR                      @ that we didn't get an error
                    beq             2f                              @ if we did get an error, just return
                    pop             {r0-r1}                         @ restore r0 and r1
                    ldr             r3, = #EepromCache
                    ldrb            r2, [r3, r0]                    @ if the value is the same as that already in the
                    cmp             r2, r1                          @ cache, then don't call the driver
                    beq             1f
                    strb            r1, [r3, r0]                    @ otherwise update the cache, and write through
                    bl              EepromDrvImpl_writeByte         @ and check if there's an error. Any errors on
                    cmp             r0, #ERROR                      @ a write, set the error flag in the cache
                    bne             0f
                    ldr             r3, = #EepromCacheStatus
                    ldr             r2, [r3]
                    movs            r1, #(1<<EepromCache_StatusCacheLoaded | 1<<EepromCache_StatusCacheError)
                    bics            r2, r2, r1
                    movs            r1, #1<<EepromCache_StatusCacheError
                    orrs            r2, r2, r1
                    str             r2, [r3]
                    b               0f
1:
                    movs            r0, #SUCCESS
0:
                    pop             {r7, pc}
2:
                    pop             {r1-r2, r7, pc}                 @ error return, keeping r0


    public_function(EepromCache_readBlock)

@ int EepromI2C_readBlock(int address, short length, byte* buffer)
@   read a number of bytes from the EEPROM, starting at the supplied address, reading length bytes, and the bytes are
@   placed in the buffer. The callee is responsible for allocating and freeing the buffer, and ensuring that it is large
@   enough to store the results. The function returns SUCCESS if the data is read, ERROR on error, or PENDING if the
@   call to read the data is made asynchronously. If an asynchronous call is in progress this call will block until that
@   call is complete.

EepromCache_readBlock:
                    push            {r0-r2, lr}
                    bl              EepromCache_checkState          @ check for the cache to be populated, and check
                    cmp             r0, #ERROR                      @ that we didn't get an error
                    beq             2f                              @ if we did get an error, just return
                    pop             {r0-r2}
                    ldr             r3, = #EepromCache              @ add base of cache to address
                    adds            r0, r0, r3
                    bl              EepromCache_blockCopy
                    movs            r0, #SUCCESS
0:
                    pop             {pc}
2:
                    pop             {r1-r3, pc}                     @ error return, keeping r0

    public_function(EepromCache_writeBlock)

@ int EepromI2C_writeBlock(int address, short length, byte* buffer)
@   write a number of bytes to the EEPROM, starting at the supplied address, reading length bytes, and the bytes are
@   read from the buffer. The function returns SUCCESS if the data is read, ERROR on error, or PENDING if the
@   call to read the data is made asynchronously. If an asynchronous call is in progress this call will block until
@   that call is complete.

EepromCache_writeBlock:
                    push            {r0-r2, lr}
                    push            {r0-r3}                         @ save again, for the call to the driver
                    bl              EepromCache_checkState          @ check for the cache to be populated, and check
                    cmp             r0, #ERROR                      @ that we didn't get an error
                    beq             1f                              @ if we did get an error, just return
                    pop             {r0-r3}
                    ldr             r3, = #EepromCache              @ add base of cache to address
                    adds            r0, r0, r3
                    movs            r3, r0                          @ swap parameters src and dest to write into the
                    movs            r0, r2                          @ cache
                    movs            r2, r3
                    bl              EepromCache_blockCopy
                    pop             {r0-r2}
                    bl              EepromDrvImpl_writeBlock        @ write through to the driver
                    cmp             r0, #ERROR                      @ set the error flag in the cache, if the write
                    bne             0f                              @ fails (Note: if the write fails later, as it's
                    ldr             r3, = #EepromCacheStatus        @ async, then we'll miss this)
                    ldr             r2, [r3]
                    movs            r1, #(1<<EepromCache_StatusCacheLoaded | 1<<EepromCache_StatusCacheError)
                    bics            r2, r2, r1
                    movs            r1, #1<<EepromCache_StatusCacheError
                    orrs            r2, r2, r1
                    str             r2, [r3]
0:
                    pop             {pc}
1:
                    add             sp, sp, #28                     @ restore the stack, we don't care about the contents
                    pop             {pc}

    public_function(EepromCache_asyncInProgress)

@ bool EepromI2C_asyncInProgress()
@   returns TRUE if a asynchronous is in progress, otherwise false.

EepromCache_asyncInProgress:
                    b               EepromDrvImpl_asyncInProgress

    public_function(EepromCache_getLastAsyncStatus)

@ bool Eeprom_getLastAsyncStatus()
@   returns SUCCESS if the last asynchronous call completed successfully, otherwise error.

EepromCache_getLastAsyncStatus:
                    b               EepromDrvImpl_getLastAsyncStatus

    public_function(EepromCache_setHint)

@ void EepromCache_setHint(int hint, int arg0, int arg1)
@   set a hint - which may or may not be ignored by the EEPROM system or the underlying driver.

EepromCache_setHint:
                    cmp             r0, #EepromCache_setRegionDirtyHint
                    bne             0f
                    movs            r0, r1
                    movs            r1, r2
                    ldr             r2, = #EepromCache
                    adds            r2, r2, r0
                    b               EepromDrvImpl_writeBlock
0:
                    b               EepromDrvImpl_setHint

    public_function(EepromCache_getHint)

@ int EepromCache_getHint(int hint)
@   get a hint - which may or may not be ignored by the EEPROM system or the underlying driver.

EepromCache_getHint:
                    cmp             r0, #EepromCache_getBaseAddressHint
                    bne             1f
                    ldr             r0, = #EepromCache              @ return the base address of our cache
                    bx              lr
1:
                    cmp             r0, #EepromCache_getStatus
                    bne             2f
                    ldr             r0, = #EepromCacheStatus
                    ldr             r0, [r0]
                    bx              lr
2:
                    b               EepromDrvImpl_getHint

    private_function(EepromCache_checkState)

@ bool EepromCache_checkState(void)
@   wait for the cache to be populated, and then check the status of the cache. Returns ERROR if the cache is in error
@   (if it failed to load in the first place), or SUCCESS if the cache is loaded OK.

EepromCache_checkState:
                    ldr             r3, = #EepromCacheStatus        @ check the cache status first, so we can short cut
                    ldr             r2, [r3]                        @ this function, if we've either loaded OK, or already
                    movs            r1, #1<<EepromCache_StatusCacheLoaded @ failed
                    tst             r1, r2
                    bne             0f
                    movs            r1, #1<<EepromCache_StatusCacheError
                    tst             r1, r2
                    bne             1f

                    push            {r7, lr}
2:
                    bl              EepromDrvImpl_asyncInProgress
                    cmp             r0, #TRUE
                    beq             2b
                    bl              EepromCache_getLastAsyncStatus
                    ldr             r3, = #EepromCacheStatus
                    ldr             r2, [r3]
                    movs            r1, #(1<<EepromCache_StatusCacheLoaded | 1<<EepromCache_StatusCacheError)
                    bics            r2, r2, r1
                    cmp             r0, #SUCCESS
                    bne             3f
                    movs            r1, #1<<EepromCache_StatusCacheLoaded
                    b               4f
3:
                    movs            r1, #1<<EepromCache_StatusCacheError
4:
                    orrs            r2, r2, r1
                    str             r2, [r3]
                    pop             {r7, pc}
0:
                    movs            r0, #SUCCESS
                    bx              lr
1:
                    movs            r0, #ERROR
                    bx              lr

    private_function(EepromCache_blockCopy)

@ void EepromCache_blockCopy(int* src, int length, int *dest)
@   copy data from the src to the destination

EepromCache_blockCopy:
                    push            {r7, lr}
                    movs            r3, r0                          @ shuffle the parameters around so we can use
                    movs            r0, r2                          @ libc memcpy - hopefully this is better than a
                    movs            r2, r1                          @ simle byte copy loop
                    movs            r1, r3
                    bl              memcpy                          @ can't tail chain, as the call is too "far" for
                    pop             {r7, pc}                        @ simple branch

#endif

    .end
