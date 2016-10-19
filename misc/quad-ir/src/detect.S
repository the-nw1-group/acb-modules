/*
 * Copyright (c) 2015 The NW1 Group
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#include "moduleInfo.inc"

@ Calculations for the detection, and orchestration of starting and stopping detection

    module(Detect)

    private_data(Detect_private)

Detect_state:
                    .word           0                               @ detection state
Detect_threshold:
                    .word           0                               @ last threshold value

    public_function(Detect_checkStartupState)

@ void Detect_checkStartupState(void)
@   check if we should start normally, or in low power mode

Detect_checkStartupState:
                    push            {r7, lr}
                    bl              LowPower_getEnablePinState
                    cmp             r0, #0
                    bne             0f
                    bl              Detect_start
                    b               1f
0:
                    bl              LowPower_enterStop
1:
                    pop             {r7, pc}

    public_function(Detect_start)

@ void Detect_start(void)
@   start detection

Detect_start:
                    push            {r7, lr}
                    bl              Analog_startDetection
                    bl              IrLed_startDetection
                    bl              MsCounter_restart
                    pop             {r7, pc}

    public_function(Detect_stop)

@ void Detect_stop(void)
@   stop dectection, so that we can enter stop mode

Detect_stop:
                    push            {r7, lr}
                    bl              IrLed_stopDetection
                    bl              Analog_stopDetection
                    bl              MsCounter_pause

                    movs            r7, #QUADIR_NO_VALUES-1         @ clear any pending alarms
0:
                    movs            r0, r7
                    bl              MsCounter_clearAlarm
                    subs            r7, r7, #1
                    bcs             0b

                    cpsid           i                               @ disable interrupts
                    ldr             r2, = #Detect_state             @ clear state flag
                    movs            r0, #0
                    str             r0, [r2]

                    ldr             r2, = #QUADIR_OUT4_GPIOBASE     @ set all outputs high
                    ldr             r1, = #1<<QUADIR_OUT4
                    str             r1, [r2, #GPIO_BSRR_OFFSET]
                    ldr             r2, = #QUADIR_OUT3_GPIOBASE
                    ldr             r1, = #1<<QUADIR_OUT3
                    str             r1, [r2, #GPIO_BSRR_OFFSET]
                    ldr             r2, = #QUADIR_OUT2_GPIOBASE
                    ldr             r1, = #1<<QUADIR_OUT2
                    str             r1, [r2, #GPIO_BSRR_OFFSET]
                    ldr             r2, = #QUADIR_OUT1_GPIOBASE
                    ldr             r1, = #1<<QUADIR_OUT1
                    str             r1, [r2, #GPIO_BSRR_OFFSET]
                    cpsie           i                               @ enable interrupts
                    isb
                    pop             {r7, pc}

    public_function(Detect_check)

@ void Detect_startDetection(void)
@   check if we have samples ready for detection, if so perform detection

Detect_check:
                    push            {r7, lr}
                    bl              Analog_areOnSamplesReady        @ do we have on samples?
                    cmp             r0, #0
                    beq             0f
                    movs            r0, #1
                    bl              Analog_averageSamples           @ average them, and save the threshold value
                    ldr             r1, = #Detect_threshold
                    str             r0, [r1]
                    movs            r0, #1
                    bl              Analog_clearSamplesReady
0:
                    bl              Analog_areOffSamplesReady       @ do we have off samples
                    cmp             r0, #0
                    beq             0f
                    movs            r0, #0
                    bl              Analog_averageSamples           @ average them, add and average the threshold
                    ldr             r1, = #Detect_threshold         @ value
                    ldr             r2, [r1]
                    adds            r2, r2, r0
                    lsrs            r2, #1
                    str             r2, [r1]
                    movs            r7, r2
                    movs            r0, #0
                    bl              Analog_clearSamplesReady
                    movs            r0, r7
                    bl              Detect_compareToThreshold       @ now we have both off/on samples, we can check
                                                                    @ for detection!
0:
                    pop             {r7, pc}

    private_function(Detect_compareToThreshold)

@ void Detect_compareToThreshold(uint16_t threshold)
@   compares on and off samples against the supplied threshold. if onValue-offValue > threshold then enable output. If
@   it's less than the threshold, then time turning off the output for a 1 second to give a level of debounce.

Detect_compareToThreshold:
                    push            {r3-r7, lr}
                    movs            r4, r0                          @ copy off threshold value, before getting on
                    bl              Analog_getOnValues              @ and off values
                    movs            r7, r0
                    bl              Analog_getOffValues
                    movs            r6, r0
                    movs            r5, #0
                    movs            r0, #QUADIR_NO_VALUES-1         @ loop through all the values to check if they
0:                                                                  @ over the threshold, if so set a flag for each value
                    lsls            r1, r0, #1
                    ldrh            r2, [r7, r1]
                    ldrh            r1, [r6, r1]
                    subs            r2, r2, r1
                    cmp             r2, r4
                    blt             1f
                    movs            r1, #1
                    lsls            r1, r1, r0
                    orrs            r5, r5, r1
1:
                    subs            r0, r0, #1
                    bcs             0b

                    ldr             r0, = #Detect_state             @ load the current state, check what's changed
                    cpsid           i                               @ and store the new state back, all with interrupts
                    ldr             r1, [r0]                        @ disabled
                    str             r5, [r0]
                    cpsie           i
                    isb
                    movs            r6, r5
                    eors            r6, r6, r1

                    movs            r4, #QUADIR_NO_VALUES-1         @ if we have a changed bit set, then either enable
0:                                                                  @ bit, or set set a timer to turn if off
                    movs            r1, #1                          @ did this bit change? no then skip
                    lsls            r1, r1, r4
                    tst             r6, r1
                    beq             2f
                    tst             r5, r1                          @ did it change to turn on?
                    beq             1f
                    lsls            r3, r4, #2                      @ set output to active (low)
                    ldr             r0, = #Detect_gpioPorts
                    ldr             r0, [r0, r3]
                    ldr             r1, = #Detect_gpioPins
                    ldr             r1, [r1, r3]
                    str             r1, [r0, #GPIO_BRR_OFFSET]

                    movs            r0, r4                          @ clear any pending alarms for this output
                    bl              MsCounter_clearAlarm
                    b               2f
1:
                    ldr             r0, =#Detect_alarmTable         @ set an alarm to turn off the output
                    lsls            r1, r4, #2
                    ldr             r2, [r0, r1]
                    movs            r0, r4
                    ldr             r1, =#QUAD_IR_DEBOUNCE
                    bl              MsCounter_alarmIn
2:
                    subs            r4, r4, #1
                    bcs             0b

                    ldr             r0, = #QUADIR_STATUS_GPIOBASE   @ if the state is non-zero then show the status LED,
                    movs            r1, #1<<QUADIR_STATUS           @ otherwise, turn off the status LED
                    cmp             r5, #0
                    bne             0f
                    ldr             r1, = #(1<<QUADIR_STATUS)<<16
0:
                    str             r1, [r0, #GPIO_BSRR_OFFSET]
                    pop             {r3-r7, pc}

    static_data(Detect_alarmTable)

Detect_alarmTable:
                    .word           Detect_oneAlarm + 1
                    .word           Detect_twoAlarm + 1
                    .word           Detect_threeAlarm + 1
                    .word           Detect_fourAlarm + 1

Detect_gpioPorts:
                    .word           QUADIR_OUT1_GPIOBASE
                    .word           QUADIR_OUT2_GPIOBASE
                    .word           QUADIR_OUT3_GPIOBASE
                    .word           QUADIR_OUT4_GPIOBASE

Detect_gpioPins:
                    .word           1<<QUADIR_OUT1
                    .word           1<<QUADIR_OUT2
                    .word           1<<QUADIR_OUT3
                    .word           1<<QUADIR_OUT4

    private_function(Detect_oneAlarm)

@ void Detect_one/two/three/fourAlarm(void)
@   MsCounter callback handler for detector 1..4 callback

Detect_oneAlarm:
                    ldr             r0, = #QUADIR_OUT1_GPIOBASE
                    ldr             r1, = #1<<QUADIR_OUT1
                    b               Detect_alarmCallback

    private_function(Detect_twoAlarm)

Detect_twoAlarm:
                    ldr             r0, = #QUADIR_OUT2_GPIOBASE
                    ldr             r1, = #1<<QUADIR_OUT2
                    b               Detect_alarmCallback

    private_function(Detect_threeAlarm)

Detect_threeAlarm:
                    ldr             r0, = #QUADIR_OUT3_GPIOBASE
                    movs            r1, #1<<QUADIR_OUT3
                    b               Detect_alarmCallback

    private_function(Detect_fourAlarm)

Detect_fourAlarm:
                    ldr             r0, = #QUADIR_OUT4_GPIOBASE
                    movs            r1, #1<<QUADIR_OUT4
                    b               Detect_alarmCallback

    private_function(Detect_alarmCallback)

@ void Detect_alarmCallback(uint32_t* gpioBase, uint16_t outputPin)
@   indicate a detection on the supplied gpio base and output pin

Detect_alarmCallback:
                    str             r1, [r0, #GPIO_BSRR_OFFSET]
                    bx              lr

    .end
