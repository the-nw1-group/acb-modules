/*
 * Copyright (c) 2015 The NW1 Group
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#include "moduleInfo.inc"

@ setup code for ACB-4TC (4 Turnout control)

    module(Setup)

    .extern         OptionByte_write                                @ Write option byte value
    .extern         Can_initForStandardFrames                       @ Setup CAN module
    .extern         Eeprom_init                                     @ Setup EEPROM
    .extern         Acb_init                                        @ Setup ACB common routines
    .extern         MsCounter_init                                  @ Setup millisecond counter
    .extern         MsCounter_waitFor                               @ Wait for n milliseconds
    .extern         ConfigurationManager_init                       @ Initialise the configuration manager

    public_function(Setup_setup)

@ void Setup_setup() - doesn't return if option bytes updated
@   Change options bytes to use PB8 rather than BOOT0 if required
@   Setup all major peripherals and their clocks

@ TODO: Can_xxxx needs to be renamed AcbDrv and then mapped to Can_xxx functions - but see how the EEPROM stuff
@       works out first!

Setup_setup:
                    push            {r7, lr}
__setupCounter:
                    ldr             r0, =#System_coreClock
                    ldr             r0, [r0]
                    bl              MsCounter_init

                                                                    @ it "seems" (i.e. I could be wrong), that with the
                                                                    @ ST-LINK and/or OpenOCD the processor isn't held in
                                                                    @ reset (unlike PICs for example), and some code might
                                                                    @ run before the debugger is attached, which then
                                                                    @ breaks whatever the processor was doing. This might
                                                                    @ cause issues with both the CAN and I2C interfaces
                                                                    @ so we delay here whilst the debugger attaches
#if defined(DEBUG)
                    movs            r0, #250                        @ delay for 250ms - only when running under the
                    bl              MsCounter_waitFor               @ debugger (which we can't tell on an M0, so for all
                                                                    @ debug builds
#endif

__setupGPIO:
                    ldr             r7, = #_RCC_AHBENR              @ enable port A and B peripheral clocks
                    ldr             r1, [r7]
                    ldr             r0, = #RCC_AHBENR_GPIOAEN | RCC_AHBENR_GPIOBEN
                    orrs            r0, r0, r1
                    str             r0, [r7]
__setupOptionBytes:
                    ldr             r0, = #OB_BASE                  @ turn set BOOT_SEL to 0, so that BOOT0 pin
                    movs            r1, #0                          @ becomes PB8
                    ldr             r2, = #OB_USER_BOOT_SEL
                    bl              OptionByte_write
__setupEEPROM:
                    bl              Eeprom_init
                    bl              ConfigurationManager_init
__setupACB:
                    bl              Acb_init
__setupCAN:
                    bl              Can_initForStandardFrames

                    pop             {r7, pc}

    .end
