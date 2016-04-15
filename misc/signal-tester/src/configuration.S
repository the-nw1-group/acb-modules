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
 *      | Record Type |    1    The type of record
 *      +-------------+
 *      | Data Type   |    1    The type of data stored in this record
 *      +-------------+
 *      | Data        |    6    Data associated with this record
 *      +-------------+
 *
 * Record Types are:
 *  0 or 0xff   Unpopulated
 *  1           Settings record
 *  2           Data record
 *              Others Reserved
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
 * Data format is specific to each data type:
 *  0 or 0xff   Ununsed
 *  1           Data[0] = start position, Data[1] = end position, Data[2] = speed
 *  2-5         Data[0..3] = RGB colour as 32 bit number (top byte is zero), stored little endian
 *              Others Reserved
 */

    module(Configuration)

    .extern         Eeprom_init                                     @ Initialise the EEPROM sub-system
    .extern         Eeprom_getHint                                  @ Ask the EEPROM sub-system for information
    .extern         Eeprom_setHint                                  @ Tell the EEPROM sub-system a hint
    .extern         Eeprom_asyncInProgress                          @ Is an async process in progress
    .extern         Eeprom_getLastAsyncStatus                       @ Get the status of the last async process

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
                    bl              Eeprom_asyncInProgress          @ wait for the cache to be loaded
                    cmp             r0, #TRUE
                    beq             0b
                    bl              Eeprom_getLastAsyncStatus
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
                    push            {r7, lr}
                    bl              Configuration_findRecord
                    cmp             r0, #0
                    beq             9f
                    ldr             r2, = #Configuration_buffer     @ copy the data to be return
                    ldr             r1, [r0]
                    str             r1, [r2]
                    ldr             r1, [r0, #4]
                    str             r1, [r0, #4]
9:
                    pop             {r7, pc}

    public_function(Configuration_getDataAt)

@ byte* Configuration_getDataAt(int index)
@   Reads the next data record, returning it as a read-only array of bytes. If there is no next record, or another
@   error occurs, a null pointer is returned. index is a zero based index of the data.

Configuration_getDataAt:

                    movs            r0, #0
                    bx              lr

    public_function(Configuration_getAt)

@ byte* Configuration_getAt(int index)
@   Reads the next record, returning it as a read-only array of bytes. If the index is out of range, or another
@   error occurs, a null pointer is returned. index is a zero based index of the data.

Configuration_getAt:
                    push            {r7, lr}
                    cmp             r0, #0                          @ check if the index is out of range
                    blt             8f
                    movs            r7, r0
                    bl              Configuration_countAll
                    cmp             r7, r0
                    bgt             8f
                    lsls            r1, r7, #3                      @ otherwise it's just an index into the data
                    ldr             r7, = #Configuration_baseAddress
                    ldr             r7, [r7]
                    ldr             r0, = #Configuration_buffer
                    ldr             r2, [r7, r1]
                    str             r2, [r0]
                    adds            r1, r1, #4
                    ldr             r2, [r7, r1]
                    str             r2, [r0, #4]
                    b               9f
8:
                    movs            r0, #0
9:
                    pop             {r7, pc}

    public_function(Configuration_addNew)

@ int Configuration_addNew(byte recordType, byte dataType, int data1, short data2)
@   Store a new record of the supplied record type and dataType. data1 and data2 are stored in the following bytes
@   in little endian format. On success it returns the index of the saved record, otherwise it returns -1.

Configuration_addNew:
                    push            {r0-r1, r7, lr}
                    bl              Configuration_findFirstFree
                    cmp             r0, #0
                    beq             8f
                    movs            r7, r0
                    pop             {r0-r1}
                    strb            r0, [r7]                        @ copy record and data type
                    strb            r1, [r7, #1]
                    strh            r2, [r7, #2]
                    lsrs            r2, r2, #16
                    strh            r2, [r7, #4]
                    strh            r3, [r7, #6]

    @ TODO: Tell Eeprom to update this area in back store (via hint)

                    ldr             r2, = #Configuration_baseAddress
                    ldr             r2, [r2]
                    subs            r7, r7, r2
                    lsrs            r0, r7, #3
9:
                    pop             {r7, pc}
8:
                    pop             {r0-r1}
                    ldr             r0, = #-1
                    b               9b

    public_function(Configuration_replaceOrAddNew)

@ int Configuration_replaceOrAddNew(byte recordType, byte dataType, int data1, short data2)
@   Store a new record of the supplied record type and dataType, if that combination isn't already stored, otherwise
@   a new record is created.  data1 and data2 are stored in the following bytes in little endian format.
@   On success it returns the index of the saved record, otherwise it returns -1.

Configuration_replaceOrAddNew:
                    push            {r0-r1, r7, lr}
                    bl              Configuration_findRecord
                    cmp             r0, #0
                    beq             croan_addNew
croan_replace:
                    movs            r7, r0
                    pop             {r0-r1}
0:
                    strh            r2, [r7, #2]                    @ overwrite existing entry. No need to store data
                    lsrs            r2, r2, #16                     @ and record type, as they won't have changed. Need
                    strh            r2, [r7, #4]                    @ to store data1 in two half words as it's not
                    strh            r3, [r7, #6]                    @ word aligned

    @ TODO: Tell Eeprom to update this area in back store (via hint)

                    ldr             r2, = #Configuration_baseAddress
                    ldr             r2, [r2]
                    subs            r7, r7, r2
                    lsrs            r0, r7, #3
                    b               9f
croan_addNew:
                    bl              Configuration_findFirstFree     @ need to create a new record, find first free slot
                    cmp             r0, #0                          @ if none found, then return an error
                    beq             8f
                    movs            r7, r0
                    pop             {r0-r1}
                    strb            r0, [r7]                        @ copy record and data type
                    strb            r1, [r7, #1]
                    b               0b                              @ and then the rest of the data
9:
                    pop             {r7, pc}
8:
                    pop             {r0-r1}
                    ldr             r0, = #-1
                    b               9b

    public_function(Configuration_deleteAllData)

@ bool Configuration_deleteAllData()
@   Deletes all data records. Returns SUCCESS if new value stored, otherwise ERROR.

Configuration_deleteAllData:
                    push            {r5-r7, lr}
                    ldr             r0, = #(ACB_EEPROM_SIZE - 8)    @ set all the data to 0xffffffff
                    movs            r1, #0
                    subs            r1, r1, #1
                    ldr             r2, = #Configuration_baseAddress
                    ldr             r2, [r2]
                    movs            r5, #0
                    movs            r6, #0
0:
                    ldrb            r3, [r2, r0]                    @ check if configuration record
                    cmp             r3, #CONFIG_REC_DATA
                    bne             1f                              @ no, just move to next record
                    str             r1, [r2, r0]                    @ overwrite the data
                    adds            r7, r0, #4
                    str             r1, [r2, r7]
                    movs            r5, r0                          @ store the end of this record as the lowest written
                    cmp             r6, #0                          @ record, and check if we have a highest record yet?
                    bne             1f
                    adds            r6, r7, #4                      @ no, then store this as the highest record
1:
                    subs            r0, r0, #8
                    bcs             0b
                    cmp             r5, r6                          @ anything to write?
                    beq             8f                              @ no, just return SUCCESS
                    movs            r0, #EepromCache_setRegionDirtyHint
                    movs            r1, r5                          @ otherwise write out to the EEPROM whats changed
                    movs            r2, r6
                    bl              Eeprom_setHint
                    cmp             r0, #ERROR
                    beq             9f
2:
                    bl              Eeprom_asyncInProgress          @ wait for the cache to be loaded
                    cmp             r0, #TRUE
                    beq             2b
                    bl              Eeprom_getLastAsyncStatus
9:
                    pop             {r5-r7, pc}
8:
                    movs            r0, #SUCCESS
                    b               9b


    public_function(Configuration_deleteAll)

@ bool Configuration_deleteAll()
@   Deletes all records. Returns SUCCESS if new value stored, otherwise ERROR. Blocks until the data is written back
@   to the EEPROM.

Configuration_deleteAll:
                    push            {r7, lr}
                    ldr             r0, = #(ACB_EEPROM_SIZE - 4)    @ set all to 0xffffffff
                    movs            r1, #0
                    subs            r1, r1, #1
                    ldr             r2, = #Configuration_baseAddress
                    ldr             r2, [r2]
0:
                    str             r1, [r2, r0]
                    subs            r0, r0, #4
                    bcs             0b

                    movs            r0, #EepromCache_setRegionDirtyHint
                    movs            r1, #0
                    ldr             r2, = #ACB_EEPROM_SIZE
                    bl              Eeprom_setHint
                    cmp             r0, #ERROR
                    beq             9f
1:
                    bl              Eeprom_asyncInProgress          @ wait for the cache to be loaded
                    cmp             r0, #TRUE
                    beq             1b
                    bl              Eeprom_getLastAsyncStatus
9:
                    pop             {r7, pc}

    private_function(Configuration_countMatching)

@ int Configuration_countMatching(int mask)
@   Return the number of records currently stored that's record type matches the supplied mask, ignoring unused
@   entries

Configuration_countMatching:
                    push            {r7, lr}
                    ldr             r7, = #Configuration_baseAddress
                    ldr             r7, [r7]
                    movs            r1, #0                          @ count
                    movs            r2, #0                          @ index into array (record type at position index+1)
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

    private_function(Configuration_findRecord)

@ byte* Configuration_findRecord(byte recordType, byte dataType)
@   Find an entry by it's record and data type, returning it as a pointer to the entry. If the record can't be
@   found, this function returns a null pointer. Implementation note: r2 and r3 are preserved

Configuration_findRecord:
                    push            {r5-r7, lr}
                    lsls            r1, r1, #8                      @ combine record and data type
                    orrs            r0, r0, r1                      @ so we just do half word compares, rather than 2
                    ldr             r7, = #Configuration_baseAddress @ byte compares
                    ldr             r7, [r7]
                    movs            r6, #0
0:
                    ldrh            r1, [r7, r6]                    @ test this record
                    cmp             r1, r0
                    beq             8f
                    adds            r6, r6, #8                      @ move to the next record
                    ldr             r1, = #ACB_EEPROM_SIZE
                    cmp             r6, r1
                    blt             0b
                    movs            r0, #0
9:
                    pop             {r5-r7, pc}
8:
                    adds            r0, r7, r6
                    b               9b

    private_function(Configuration_findFirstFree)

@ byte* Configuration_findFirstFree()
@   find the first free slot, returning a pointer to it, otherwise returns 0. Implementation note: r2 and r3 are
@   preserved

Configuration_findFirstFree:
                    movs            r0, #0xff
                    movs            r1, r0
                    b               Configuration_findRecord

    .end
