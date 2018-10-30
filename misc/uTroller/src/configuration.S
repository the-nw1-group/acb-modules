/*
 * Copyright (c) 2018 The NW1 Group
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#include "moduleInfo.inc"

@ configuration code for the uTroller

    module(Configuation)

    eeprom_data(Configuation_eeprom)

Configuation_eeprom:

configStatus:           .short      0                               @ does the config block contain valid data
configMaxReverseValue:  .short      0                               @ ADC value of max reverse (pot. to the left)
configMaxForwardValue:  .short      0                               @ ADC value of max forward (pot. to the right)
configOffValue:         .short      0                               @ ADC value of off (pot. to the middle)

CONFIG_STATUS_CONFIGURED = 0x01
CONFIG_STATUS_EMPTY      = 0x00
CONFIG_VERSION           = 0x10

    private_data(Configuation_private)

configOptionCache:      .byte       0xFF                            @ Cache of the configuration otions

    public_function(Configuation_isConfigured)

@ bool Configuation_isConfigured()
@   Checks to see if the "eeprom" contains valid values, and therefore the module is already configured.
@   Returns true if the module is configured, otherwise false

Configuation_isConfigured:
                    ldr             r0, =#configStatus
                    ldrh            r0, [r0]
                    movs            r1, #CONFIG_STATUS_CONFIGURED
                    adds            r0, r0, r1
                    bx              lr

    public_function(Configuration_getMaxReverse)

@ short Configuration_getMaxReverse()
@   Returns the configured max reverse value

Configuration_getMaxReverse:
                    ldr             r0, =#configMaxReverseValue
                    ldrh            r0, [r0]
                    bx              lr

    public_function(Configuration_getMaxForward)

@ short Configuration_getMaxForward()
@   Returns the configured max forward value

Configuration_getMaxForward:
                    ldr             r0, =#configMaxForwardValue
                    ldrh            r0, [r0]
                    bx              lr


    public_function(Configuration_getOffValue)

@ short Configuration_getOffValue()
@   Returns the configured max forward value

Configuration_getOffValue:
                    ldr             r0, =#configOffValue
                    ldrh            r0, [r0]
                    bx              lr

    public_function(Configuration_getOption0Value)

@ bool Configuration_getOption0Value()
@   Returns true if the option #1 value is set, otherwise false

Configuration_getOption0Value:
                    push            {r7, lr}
                    ldr             r7, =#configOptionCache
                    ldrb            r0, [r7]
                    cmp             r0, #0xFF
                    bne             0f
                    bl              Configuration_getOptions
0:
                    movs            r1, #1<<0
                    ands            r0, r0, r1
                    pop             {r7, pc}

    public_function(Configuration_getOption1Value)

@ bool Configuration_getOption1Value()
@   Returns true if the option #1 value is set, otherwise false

Configuration_getOption1Value:
                    push            {r7, lr}
                    ldr             r7, =#configOptionCache
                    ldrb            r0, [r7]
                    cmp             r0, #0xFF
                    bne             0f
                    bl              Configuration_getOptions
0:
                    movs            r1, #1<<1
                    ands            r0, r0, r1
                    pop             {r7, pc}

    private_function(Configuration_getOptions)

@ byte Configuration_getOptions()
@   loads the options from the configuration jumpers (UTROLLER_CONFIG0, UTROLLER_CONFIG1), and stores in
@   configOptionCache. Returns the value stored

Configuration_getOptions:
                    ldr             r2, =#UTROLLER_CONFIG_GPIOBASE
                    ldr             r0, [r2, #GPIO_IDR_OFFSET]
                    ldr             r1, =#(1<<UTROLLER_CONFIG0) | (1<<UTROLLER_CONFIG1)
                    ands            r0, r0, r1
                    lsls            r0, r0, #UTROLLER_CONFIG0
                    ldr             r2, =#configOptionCache
                    strb            r0, [r2]
                    bx              lr

    .end
