/*
 * Copyright (c) 2015 The NW1 Group
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#include "moduleInfo.inc"

#ifdef CBUS_USE_MODULE_PARAMS

@ CBUS Module Parameters table

    module(CbusModuleParameters)

@ The following code lives in the .cbus_moduleParams section, so the linker places it in the correct, known, location
@ in the output

    .section        .cbus_moduleParams, "ax", %progbits
    .type           cbus_moduleParameters, %function
    .size           cbus_moduleParameters, .-cbus_moduleParameters
    .balign         1
    .align          1

cbus_moduleParameters:

                    .byte           CBUS_MANUFACTURER, CBUS_MINOR_VERSION, CBUS_MODULE_ID, CBUS_MAX_EVENTS
                    .byte           CBUS_EVENT_VARS_PER_EVENT, CBUS_MAX_NODE_VARIABLES, CBUS_MAJOR_VERSION, CBUS_BASE_FLAGS
                    .byte           CBUS_CPU_TYPE, CBUS_BUS_TYPE
                    .int            CBUS_LOAD_ADDRESS
__endOfParameters:                                                  @ zero fill between this block, and the parameter
                    .space          PAR_COUNT-(__endOfParameters-cbus_moduleParameters), 0  @ count location

@ The assembler can only do + and - on non-absolute values, but it see's both __moduleName and CBUS_LOAD_ADDRESS
@ as non-absolute (both resolved at link time), so this massive hack, ensures that the checksum is correct, but
@ relies on __moduleName and CBUS_LOAD_ADDRESS *not* changing...

LOAD_ADDRESS = 0x08000C00
MODULE_NAME  = (0x08001188+(__moduleName-cbus_moduleParameters))

baseParameterCount =  __endOfParameters - cbus_moduleParameters

checksum = CBUS_MANUFACTURER + CBUS_MINOR_VERSION + CBUS_MODULE_ID + CBUS_MAX_EVENTS +\
           CBUS_EVENT_VARS_PER_EVENT + CBUS_MAX_NODE_VARIABLES + CBUS_MAJOR_VERSION + CBUS_BASE_FLAGS +\
           CBUS_CPU_TYPE + CBUS_BUS_TYPE +\
           TOPMOSTBYTE(MODULE_NAME) + TOPBYTE(MODULE_NAME) + HIBYTE(MODULE_NAME) + LOBYTE(MODULE_NAME) +\
           TOPMOSTBYTE(LOAD_ADDRESS) + TOPBYTE(LOAD_ADDRESS) + HIBYTE(LOAD_ADDRESS) + LOBYTE(LOAD_ADDRESS) +\
           baseParameterCount

                    .short          baseParameterCount
                    .int            __moduleName
                    .short          checksum

__moduleName:
                    .ascii          CBUS_MODULE_NAME

#endif

    .end

