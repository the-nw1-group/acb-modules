/*
 * Copyright (c) 2015 The NW1 Group
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#include "moduleInfo.inc"
#include "configuration.inc"

/*
 * Provides a wrapper over the configuration data stored in the EEPROM. The data can be of two types. The first is
 * settings, and these are the values stored for each servo (start, end, speed). Then there is configuration data,
 * which are colours for red/green/.../white for the aspects test. Commonly the servo data may be reset often, without
 * having to lose the aspect data.
 *
 * Each configuration record is 8 bytes long, allowing 256 records to be stored within a 2048 byte EEPROM.
 *
 * Each record looks like:
 *
 *      +-------------+
 *      | Data Type   |    1    The type of data stored in this record
 *      +-------------+
 *      | Record Type |    1    The type of record
 *      +-------------+
 *      | Data        |    6    Data associated with this record
 *      +-------------+
 *
 * Data Types are:
 *  0 or 0xff   Unpopulated
 *  1           Servo Data
 *  2           Red Aspect Colour
 *  3           Yellow Aspect Colour
 *  4           Green Aspect Colour
 *  5           White Aspect Colour
 *              Others Reserved
 *
 * Record Types are:
 *  0 or 0xff   Unpopulated
 *  1           Settings record
 *  2           Data record
 *              Others Reserved
 *
 * Data format is specific to each data type:
 *  0 or 0xff   Ununsed
 *  1           Data[0] = start position, Data[1] = end position, Data[2] = speed
 *  2-5         Data[0..3] = RGB colour as 32 bit number (top byte is zero), stored little endian
 *              Others Reserved
 */

    module(Configuration)

    .extern         Eeprom_init                                     @ Initialise the EEPROM sub-system
    .extern         Eeprom_getHint                                  @ ask the EEPROM sub-system for information

    private_data(Configuration_private)

Configuration_baseAddress:
                    .int            0                               @ base address of EEPROM cache
Configuration_buffer:
                    .int            0, 0                            @ copy of the data returned

    public_data(Configuration_public)

    public_function(Configuration_init)

@ bool Configuration_init()
@   Setup the Configuration Manager, Storage Engine and associated variables, etc... Returns SUCCESS if communicated
@   with EEPROM ok, otherwise ERROR

Configuration_init:
                    push            {r7, lr}
                    bl              Eeprom_init
                    cmp             r0, #ERROR
                    beq             9f
                    movs            r0, #EepromCache_getBaseAddressHint
                    bl              Eeprom_getHint                  @ get the base address of the cache
                    cmp             r0, #0
                    beq             9f
                    ldr             r1, = #Configuration_baseAddress
                    str             r0, [r1]
0:
                    bl              EepromImpl_asyncInProgress      @ wait for the cache to be loaded
                    cmp             r0, #TRUE
                    beq             0b
                    bl              EepromImpl_getLastAsyncStatus
9:
                    pop             {r7, pc}

    public_function(Configuration_countData)

@ int Configuration_countData()
@   Return the number of data records currently stored

Configuration_countData:
                    movs            r0, #CONFIG_REC_DATA
                    b               Configuration_countMatching

    public_function(Configuration_countAll)

@ int Configuration_countAll()
@   Return the number of records currently stored

Configuration_countAll:
                    movs            r0, #CONFIG_REC_DATA | CONFIG_REC_SETTINGS
                    b               Configuration_countMatching

    public_function(Configuration_find)

@ byte* Configuration_find(byte recordType, byte dataType)
@   Find an entry by it's record and data type, returning it as a read-only array of bytes. If the record can't be
@   found, this function returns a null pointer.

Configuration_find:


    public_function(Configuration_getDataAt)

@ byte* Configuration_getDataAt(int index)
@   Reads the next data record, returning it as a read-only array of bytes. If there is no next record, or another
@   error occurs, a null pointer is returned. index is a zero based index of the data.

Configuration_getDataAt:

    public_function(Configuration_getAt)

Configuration_getAt:

@ byte* Configuration_getAt(int index)
@   Reads the next record, returning it as a read-only array of bytes. If there is no next record, or another
@   error occurs, a null pointer is returned. index is a zero based index of the data.

    public_function(Configuration_addNew)

@ bool Configuration_addNew(byte recordType, byte dataType, int data1, short data2)
@   Store a new record of the supplied record type and dataType. data1 and data2 are stored in the following bytes
@   in little endian format. Returns SUCCESS if new value stored, otherwise ERROR (if out of space for example.)

Configuration_addNew:
                    push            {r7, lr}
                    movs            r0, #SUCCESS
                    pop             {r7, pc}

    public_function(Configuration_replaceOrAddNew)

@ bool Configuration_replaceOrAddNew(byte recordType, byte dataType, int data1, short data2)
@   Store a new record of the supplied record type and dataType, if that combination isn't already stored, otherwise
@   a new record is created.  data1 and data2 are stored in the following bytes in little endian format. Returns
@   SUCCESS if new value stored, otherwise ERROR (if out of space for example.)

Configuration_replaceOrAddNew:
                    push            {r7, lr}
                    movs            r0, #SUCCESS
                    pop             {r7, pc}

    public_function(Configuration_deleteAllData)

@ bool Configuration_deleteAllData()
@   Deletes all data records. Returns SUCCESS if new value stored, otherwise ERROR.

Configuration_deleteAllData:

    public_function(Configuration_deleteAll)

@ bool Configuration_deleteAll()
@   Deletes all records. Returns SUCCESS if new value stored, otherwise ERROR.

Configuration_deleteAll:


    private_function(Configuration_countMatching)

@ int Configuration_countMatching(int mask)
@   Return the number of records currently stored that's record type matches the supplied mask, ignoring unused
@   entries

Configuration_countMatching:
                    push            {r7, lr}
                    ldr             r7, = #Configuration_baseAddress
                    ldr             r7, [r7]
                    movs            r1, #0                          @ count
                    movs            r2, #1                          @ index into array (record type at position index+1)
0:
                    ldrb            r3, [r7, r2]
                    cmp             r3, CONFIG_REC_UNUSED           @ unused, then skip
                    beq             1f
                    tst             r3, r0                          @ does it match mask?
                    beq             1f
                    adds            r1, r1, #1
1:
                    adds            r2, r2, #8
                    ldr             r3, = #ACB_EEPROM_SIZE
                    cmp             r2, r3
                    blt             0b
                    movs            r0, r1
                    pop             {r7, pc}

    .end
