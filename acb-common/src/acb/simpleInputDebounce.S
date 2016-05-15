/*
 * Copyright (c) 2015 The NW1 Group
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#include "moduleInfo.inc"

#ifdef ACB_USE_SID

@ Simple input debounce - input debounces one port on the device
@ Based on ideas by Jack Ganssle
@
@ Requires the following defines:
@
@   ACB_SIB_GPIOBASE        the GPIO port base address to monitor
@   ACB_SIB_MASK            which bits of the port are interesting
@   ACB_SIB_STATE_DEPTH     how many states to compare for result
@   ACB_SIB_INVERT          flag to indicate to invert the inputs before storing
@   ACB_SID_ALARM_SLOT      alarm slot to use
@
@ Uses alarm slot 1 - samples input every 4ms

    module(SimpleInputDebounce)

    .extern         MsCounter_alarmIn                               @ set an alarm in x milliseconds
    .extern         MsCounter_waitFor                               @ wait for a number of milliseconds

SID_SAMPLE_TIME = 4
SID_ALARM_SLOT = ACB_SID_ALARM_SLOT
#if ACB_SID_ALARM_SLOT >= ACB_ALARM_SLOTS
#error Not enough alarm slots defined for simple input debouncing. Adjust ACB_ALARM_SLOTS
#endif

    private_data(SimpleInputDebounce_privateData)

Sid_stateSlot:      .int            0                               @ current slot
Sid_stateBuffer:    .space          2 * ACB_SIB_STATE_DEPTH, 0      @ state buffer to record key presses over time

    public_function(SimpleInputDebounce_setup)

@ void SimpleInputDebounce_setup(void)
@   set up the simple input debounce module

SimpleInputDebounce_setup:
                    push            {r7, lr}
                    movs            r0, #SID_ALARM_SLOT             @ set an alarm in ACB_EEPROM_WRITETIME time
                    movs            r1, #SID_SAMPLE_TIME
                    ldr             r2, = #(SimpleInputDebounce_sample+1)
                    bl              MsCounter_alarmIn
                    ldr             r0, = #SID_SAMPLE_TIME * ACB_SIB_STATE_DEPTH
                    bl              MsCounter_waitFor               @ wait for at least a buffer worth of data to be read
                    pop             {r7, pc}

    public_function(SimpleInputDebounce_getState)

@ short SimpleInputDebounce_getState()
@   returns the debounced button state

SimpleInputDebounce_getState:
                    ldr             r0, = #0xFFFF                   @ init state
                    ldr             r1, = #Sid_stateBuffer
                    movs            r2, #(ACB_SIB_STATE_DEPTH * 2) - 2  @ counter
0:
                    ldrh            r3, [r1, r2]
                    ands            r0, r0, r3
                    subs            r2, r2, #2
                    bcs             0b
                    bx              lr

    private_function(SimpleInputDebounce_sample)

@ void SimpleInputDebounce_sample(void)
@   Sample the current input, store in sample buffer, and rearm the alarm

SimpleInputDebounce_sample:
                    push            {r7, lr}
                    ldr             r0, = #ACB_SIB_GPIOBASE         @ read current input state
                    ldr             r0, [r0, #GPIO_IDR_OFFSET]
#if (ACB_SIB_INVERT != 0)
                    mvns            r0, r0                          @ invert if required
#endif
#if (ACB_SIB_MASK != 0xFFFF)
                    ldr             r1, = #ACB_SIB_MASK             @ mask only those bits we're interested in
                    ands            r0, r0, r1
#endif
                    ldr             r1, = #Sid_stateSlot            @ store sample in next slot
                    ldr             r2, [r1]
                    ldr             r3, = #Sid_stateBuffer
                    strh            r0, [r3, r2]
                    adds            r2, r2, #2
                    cmp             r2, #(ACB_SIB_STATE_DEPTH * 2)  @ come to the end of the buffer?
                    bne             0f
                    movs            r2, #0                          @ yes: overwrite at the start of the buffer
0:
                    str             r2, [r1]
                    movs            r0, #SID_ALARM_SLOT             @ set an alarm in ACB_EEPROM_WRITETIME time
                    movs            r1, #SID_SAMPLE_TIME
                    ldr             r2, = #(SimpleInputDebounce_sample+1)
                    bl              MsCounter_alarmIn
                    pop             {r7, pc}

#endif

    .end
