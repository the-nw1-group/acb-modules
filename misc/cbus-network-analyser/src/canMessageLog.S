/*
 * Copyright (c) 2015 The NW1 Group
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#include "moduleInfo.inc"

@ CAN message log - typical ACB applications poll for incoming messages as the data rate isn't that fast, but this
@ analyser needs a log of all of the messages, as the poll rate is that much slower than for typically ACB applications
@ (in the order of 5ms or so), where as ACB applications poll as fast as possible

    module(CanMessageLog)

CanMessageLogStatus_hasMessage  = 0
CanMessageLogStatus_hasError    = 1
CanMessageLogStatus_messageFull = 2

CanMessageLog_maxMessages       = 64

    private_data(CanMessageLog_privateData)

CanMessageLog_log:
                    .space          16*CanMessageLog_maxMessages, 0 @ space for logged messages
CanMessageLog_endOfLog:                                             @ end of message log
CanMessageLog_writePosition:
                    .word           CanMessageLog_log               @ where to insert the next message
CanMessageLog_readPosition:                                         @ where to read log entries from
                    .word           CanMessageLog_log
CanMessageLog_state:
                    .byte           0                               @ state indicating if we've had messages, or errors

    public_function(CanMessageLog_setup)

@ void CanMessageLog_setup()
@   setup the CAN message log. This assumes that the CAN peripheral clock has already been enabled, and no-other ISR
@   is listening for CAN interrupts

CanMessageLog_setup:
                    push            {r7, lr}
                    ldr             r3, =#CAN_BASE
                    ldr             r2, [r3, #CAN_IER_OFFSET]       @ enable error and receive interrupts
                    ldr             r1, = #CAN_IER_ERRIE | CAN_IER_FMPIE0 | CAN_IER_FMPIE1
                    orrs            r2, r2, r1
                    str             r2, [r3, #CAN_IER_OFFSET]
                    movs            r0, #CEC_CAN_IRQn
                    bl              NVIC_enableIRQ
                    pop             {r7, pc}

    public_function(__cecCanIRQHandler)

@ void __cecCanIRQHandler ()
@   ISR for CAN module. It expects interrupts for receives into FIFO1 and FIFO0 and notification of any errors

__cecCanIRQHandler:
                    ldr             r3, =#CAN_BASE                  @ work out what caused the interrupt
                    ldr             r2, [r3, #CAN_MSR_OFFSET]
                    movs            r1, #CAN_MSR_ERRI               @ check if it's an error
                    tst             r1, r2
                    bne             0f
                    ldr             r2, [r3, #CAN_RF0R_OFFSET]      @ check FIFO 0
                    movs            r1, #3
                    tst             r2, r1
                    bne             1f
                    ldr             r2, [r3, #CAN_RF1R_OFFSET]      @ check FIFO 1
                    movs            r1, #3
                    tst             r2, r1
                    beq             9f
                    ldr             r0, = #(CAN_sFIFOMailBox_OFFSET + CAN_FIFOMailBox_RDHR_OFFSET + 4)
                    adds            r0, r0, r3                      @ r0 is the start of the FIFO 1 data buffer
                    adds            r3, r3, #CAN_RF1R_OFFSET        @ r3 is the address of FIFO status register
                    b               2f
1:
                    ldr             r0, = #CAN_sFIFOMailBox_OFFSET
                    adds            r0, r0, r3                      @ r0 is the start of the FIFO 1 data buffer
                    adds            r3, r3, #CAN_RF0R_OFFSET        @ r3 is the address of FIFO status register
2:
                    push            {r4-r7}
                    ldr             r2, = #CanMessageLog_writePosition   @ check if the buffer is already full
                    ldrb            r1, [r2, #8]
                    movs            r4, #(1 << CanMessageLogStatus_messageFull)
                    tst             r1, r4
                    bne             8f
                    ldr             r1, [r2]
                    ldm             r0!, {r4-r7}                    @ load CAN data from FIFO
                    stm             r1!, {r4-r7}                    @ store into message buffer

                    ldr             r0, =#CanMessageLog_endOfLog    @ check if we're at the end of the buffer
                    cmp             r1, r0                          @ and cycle round back to the start...
                    bne             5f
                    ldr             r1, =#CanMessageLog_log
5:
                    str             r1, [r2]                        @ and update next write pointer
                    ldrb            r4, [r2, #8]                    @ get the current status
                    ldr             r0, [r2, #4]                    @ if, after written an entry, write=read position
                    cmp             r1, r0                          @ then the buffer is full
                    beq             3f
                    movs            r1, #(1 << CanMessageLogStatus_hasMessage) @ just set the message flag
                    b               4f
3:                                                                      @ set message and full flag
                    movs            r1, #(1 << CanMessageLogStatus_hasMessage) | (1 << CanMessageLogStatus_messageFull)
4:
                    orrs            r1, r1, r4
                    strb            r1, [r2, #8]                    @ save new status
8:
                    pop             {r4-r7}
                    movs            r0, #CAN_RF0R_RFOM0             @ indicate we've read the message
                    ldr             r1, [r3]
                    orrs            r1, r1, r0
                    str             r1, [r3]
9:
                    bx              lr
0:                                                                  @ handle error interrupts
                    bics            r2, r2, r1                      @ acknowledge the interrupts
                    str             r2, [r3, #CAN_MSR_OFFSET]
                    ldr             r3, = #CanMessageLog_state      @ and set the error state
                    ldrb            r2, [r3]
                    movs            r1, #(1 << CanMessageLogStatus_hasError)
                    orrs            r2, r2, r1
                    strb            r2, [r3]
                    bx              lr

    public_function(CanMessageLog_getStatus)

@ int CanMessageLog_getStatus()
@   returns if any messages have been received or CAN errors occurred since the last resetStatus call. Values are:
@        bit 0 - messages received if 1, otherwise 0
@        bit 1 - errors occurred if 1, otherwise 0
@        bit 2 - message log is full if 1, otherwise 0

CanMessageLog_getStatus:
                    ldr             r0, = #CanMessageLog_state      @ set state
                    cpsid           i                               @ disable interrupts
                    ldrb            r0, [r0]
                    cpsie           i                               @ re-enabled interrupts
                    isb
                    bx              lr

    public_function(CanMessageLog_resetStatus)

@ void CanMessageLog_resetStatus()
@   resets the message received and errors occurred status. Also clears the queue

CanMessageLog_resetStatus:
                    ldr             r2, = #CanMessageLog_log
                    ldr             r1, = #CanMessageLog_writePosition
                    movs            r0, #0
                    cpsid           i                               @ disable interrupts
                    str             r2, [r1]
                    str             r2, [r1, #4]
                    strb            r0, [r1, #8]
                    cpsie           i                               @ re-enabled interrupts
                    isb
                    bx              lr

    public_function(CanMessageLog_getLength)

@ int CanMessageLog_getLength()
@   return how many entries are in the buffer. Not "thread safe", message loss may occur if
@   CanMessageLog_resetStatus is called after this.

CanMessageLog_getLength:
                    ldr             r3, = #CanMessageLog_writePosition
                    cpsid           i                               @ disable interrupts
                    ldr             r0, [r3]
                    ldr             r1, [r3, #4]
                    ldrb            r2, [r3, #8]
                    cpsie           i                               @ re-enabled interrupts
                    isb
                    b               CanMessageLog_calcLength

    public_function(CanMessageLog_getLengthAndResetStatus)

@ int CanMessageLog_getLengthAndResetStatus()
@   return how many entries are in the buffer, and resets the status in one atomic operation

CanMessageLog_getLengthAndResetStatus:
                    push            {r5-r7, lr}
                    ldr             r5, = #CanMessageLog_log
                    ldr             r3, = #CanMessageLog_writePosition
                    movs            r6, #0
                    cpsid           i                               @ disable interrupts
                    ldr             r0, [r3]
                    ldr             r1, [r3, #4]
                    ldrb            r2, [r3, #8]
                    str             r5, [r3]
                    str             r5, [r3, #4]
                    strb            r6, [r3, #8]
                    cpsie           i                               @ re-enabled interrupts
                    isb
                    bl              CanMessageLog_calcLength
                    pop             {r5-r7, pc}

    private_function(CanMessageLog_calcLength)

@ int CanMessageLog_calcLength(int writePos, int readPos, byte status)
@   given the write position, read position and queue status, calculate how many messages are in the queue

CanMessageLog_calcLength:
                    movs            r3, #1 << CanMessageLogStatus_hasMessage
                    tst             r2, r3                          @ no messages flag set, just return 0
                    beq             8f
                    cmp             r0, r1                          @ if write > read, then simple subtraction
                    bgt             1f
                    ldr             r2, =#(16*CanMessageLog_maxMessages) @ otherwise, increment the write pointer up by
                    adds            r0, r0, r2                      @ the size of the buffer
1:
                    subs            r0, r0, r1                      @ otherwise difference between write and read
                    lsrs            r0, r0, #4                      @ flag, divided by 16
                    bx              lr
8:
                    movs            r0, #0
                    bx              lr

    .end

