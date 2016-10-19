/*
 * Copyright (c) 2015 The NW1 Group
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#include "moduleInfo.inc"

    .extern         Setup_setup                                     @ setup hardware and peripherals
    .extern         LowPower_checkEnterStop                         @ check and enter stop mode
    .extern         Detect_check                                    @ check and perform detection
    .extern         Detect_checkStartupState                        @ check to see if start in low power mode

@ main code for Quad-ir

    module(Main)

    public_function(main)

@ void main() - doesn't return
@   main code for module

main:
                    bl              Setup_setup
#if !defined(DEBUG)
                    bl              Main_startUpFlash
#endif
                    bl              Detect_checkStartupState        @ check if we should enter low power straight away
__mainLoop:
                    bl              LowPower_checkEnterStop         @ see if low power mode has been set
                    bl              Detect_check
                    b               __mainLoop

    private_function(Main_startUpFlash)

@ void Main_startUpFlash()
@   flash the status LED for QUADIR_STARTUP_LEDFLASH_COUNT/2, keeping the LED on (and off) for
@   QUADIR_STARTUP_LED_ON ms

Main_startUpFlash:
                    push            {r3-r7, lr}
                    ldr             r6, = #QUADIR_STATUS_GPIOBASE
                    ldr             r5, = #1<<QUADIR_STATUS
                    movs            r7, #16
                    ldr             r4, = #QUADIR_STARTUP_LEDFLASH_COUNT
0:
                    str             r5, [r6, GPIO_BSRR_OFFSET]
                    ldr             r0, = #QUADIR_STARTUP_LED_ON
                    bl              MsCounter_waitFor
                    subs            r4, r4, #1
                    beq             1f
                    rors            r5, r5, r7
                    b               0b
1:
                    pop             {r3-r7, pc}

    .end
