/*
 * Copyright (c) 2015 The NW1 Group
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#include "moduleInfo.inc"

#ifdef ACB_USE_MS_COUNTER

    .extern         Math_divu1000                                   @ unsigned integer divide by 1000
    .extern         SysTick_config                                  @ configure the SysTick core peripheral

    module(MsCounter)

numberOfSlots = ACB_ALARM_SLOTS

@ public variables

    public_data(MsCounter_globals)
    .global         MsCounter_milliseconds

MsCounter_milliseconds:
                    .int            0

    private_data(MsCounter_private)

MsCounter_alarms:
                    .space          numberOfSlots*8, 0              @ space for x alarms, each alarm take 2 words
                                                                    @ first word is the millisecond to raise the alarm
                                                                    @ the 2nd is the address to call when the alarm
                                                                    @ occurs

@ A simple millisecond counter - using SysTick to provide the implementation
@ Also allows for up to 8 alarms

    public_function(MsCounter_init)

@ void MsCounter_init(uint systemFrequency)
@   initialise the millisecond counter based on the supplied system frequency.

MsCounter_init:
                    push            {r7, lr}
#if __CORTEX_M == 0
                    bl              Math_divu1000                   @ divide clock frequency by 1000
#else
                    ldr             r1, = #1000
                    udiv            r0, r0, r1
#endif
                    bl              SysTick_config
                    pop             {r7, pc}

    public_function(MsCounter_pause)

@ void  MsCounter_pause()
@   stop the SysTick timer temporarily

MsCounter_pause:
                    ldr             r3, = #SysTick_BASE
                    ldr             r2, [r3, #SysTick_CTRL_OFFSET]
                    movs            r1, #SysTick_CTRL_ENABLE_Msk
                    bics            r2, r2, r1
                    str             r2, [r3, #SysTick_CTRL_OFFSET]
                    bx              lr

    public_function(MsCounter_restart)

@ void  MsCounter_pause()
@   restart the SysTick timer

MsCounter_restart:
                    ldr             r3, = #SysTick_BASE
                    ldr             r2, [r3, #SysTick_CTRL_OFFSET]
                    movs            r1, #SysTick_CTRL_ENABLE_Msk
                    orrs            r2, r2, r1
                    str             r2, [r3, #SysTick_CTRL_OFFSET]
                    bx              lr

    public_function(__sysTickHandler)

@ void __sysTickHandler()
@   interrupt handler for the system tick timer

__sysTickHandler:
                    push            {r5-r7, lr}
                    ldr             r0, = #MsCounter_milliseconds
                    ldr             r6, [r0]
                    adds            r6, r6, #1
                    str             r6, [r0]
__sysTickHandleCheckForAlarms:
                    ldr             r7, = #MsCounter_alarms
                    movs            r5, #(numberOfSlots * 8) - 4
0:
                    ldr             r1, [r7, r5]                    @ load the address, if it's zero, then the slot
                    cmp             r1, #0                          @ is empty so move onto the next slot
                    beq             1f
                    subs            r2, r5, #4
                    ldr             r0, [r7, r2]                    @ load the time of the alarm, if it matches the
                    cmp             r0, r6                          @ current time, then call the address
                    bne             1f
                    movs            r0, #0                          @ clear the alarm once it's fired - cleared before
                    str             r0, [r7, r5]                    @ the handler, as the handler make create another alarm
                    lsls            r0, r2, #3                      @ pass the slot number onto the handler
                    blx             r1
1:
                    subs            r5, r5, #8
                    bgt             0b
                    pop             {r5-r7, pc}

    public_function(MsCounter_alarmAt)

@ bool MsCounter_alarmAt(int slot, int timeToAlarm, int address)
@   Call the address at the specified time. Returns SUCCESS if the slot was unpdated with the time and address, otherwise
@   ERROR is returned. Typically if the slot number is invalid. timeToAlarm can be less than the current time to allow
@   for the current time to wrap

MsCounter_alarmAt:
                    push            {r7, lr}
                    movs            r3, #numberOfSlots              @ check the slot number is in range
                    cmp             r0, r3                          @ use unsigned check to check for less than 0
                    bhi             0f
                    ldr             r7, = #MsCounter_alarms
                    lsls            r0, r0, #3                      @ check slot location
                    cpsid           i                               @ disable all interrupts, don't allow the alarm
                    str             r1, [r7, r0]                    @ to be raised straight away. Store time
                    adds            r0, r0, #4
                    str             r2, [r7, r0]                    @ store address in the next word
                    cpsie           i                               @ re-enable interrupts
                    pop             {r7, pc}
0:
                    movs            r0, #ERROR
                    pop             {r7, pc}

    public_function(MsCounter_alarmIn)

@ bool MsCounter_alarmIn(int slot, int offsetToAlarm, int address)
@   Call the address at the current time plus the offset . Returns SUCCESS if the slot was unpdated with the time and
@   address, otherwise ERROR is returned. Typically if the slot number is invalid.

MsCounter_alarmIn:
                    push            {r7, lr}
                    movs            r3, #numberOfSlots              @ check the slot number is in range
                    cmp             r0, r3                          @ use unsigned check to check for less than 0
                    bhi             0f
                    ldr             r7, = #MsCounter_alarms
                    ldr             r3, = #MsCounter_milliseconds
                    lsls            r0, r0, #3                      @ check slot location
                    cpsid           i                               @ disable all interrupts, don't allow the alarm
                    ldr             r3, [r3]                        @ to be raised straight away. Add the current time
                    adds            r1, r1, r3                      @ onto the offset supplied
                    str             r1, [r7, r0]                    @ store time
                    adds            r0, r0, #4
                    str             r2, [r7, r0]                    @ store address in the next word
                    cpsie           i                               @ re-enable interrupts
                    pop             {r7, pc}
0:
                    movs            r0, #ERROR
                    pop             {r7, pc}

    public_function(MsCounter_clearAlarm)

@ bool MsCounter_clearAlarm(int slot)
@   Clear the alarm in the specified slot. Returns SUCCESS if the slot was unpdated otherwise ERROR is returned.
@   Typically if the slot number is invalid.

MsCounter_clearAlarm:
                    movs            r1, #0
                    movs            r2, #0
                    b               MsCounter_alarmAt

    public_function(MsCounter_waitFor)

@ void MsCounter_waitFor (int numberOfMs)
@   Wait for the supplied number of milliseconds

MsCounter_waitFor:
                    ldr             r1, = #MsCounter_milliseconds
                    ldr             r1, [r1]
                    adds            r0, r0, r1
                    b               MsCounter_waitUntil

    public_function(MsCounter_waitUntil)

@ void MsCounter_waitUntil (int time)
@   Wait until the supplied time or after the supplied time as passed

MsCounter_waitUntil:
                    ldr             r1, = #MsCounter_milliseconds
0:
                    ldr             r2, [r1]
                    cmp             r2, r0
                    bge             1f
                    b               0b
1:
                    bx              lr

#endif

    .end
