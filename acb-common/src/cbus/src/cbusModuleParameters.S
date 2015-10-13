/*
 * Copyright (c) 2015 The NW1 Group
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#include "moduleInfo.inc"
#include "acb/common.inc"

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
__endOfParameters:
                    .space          10, 0

@ The assembler can only do + and - on non-absolute values, but it see's both __moduleName and CBUS_LOAD_ADDRESS
@ as non-absolute (both resolved at link time), so this massive hack, ensures that the checksum is correct, but
@ relies on __moduleName and CBUS_LOAD_ADDRESS *not* changing...

LOAD_ADDRESS = 0x08000C00
MODULE_NAME  = (0x08001188+32)

checksum = CBUS_MANUFACTURER + CBUS_MINOR_VERSION + CBUS_MODULE_ID + CBUS_MAX_EVENTS +\
           CBUS_EVENT_VARS_PER_EVENT + CBUS_MAX_NODE_VARIABLES + CBUS_MAJOR_VERSION + CBUS_BASE_FLAGS +\
           LOBYTE(LOAD_ADDRESS) + HIBYTE(LOAD_ADDRESS) + TOPBYTE(LOAD_ADDRESS) + TOPMOSTBYTE(LOAD_ADDRESS) +\
           LOBYTE(MODULE_NAME) + HIBYTE(MODULE_NAME) + TOPBYTE(MODULE_NAME) + TOPMOSTBYTE(MODULE_NAME) +\
           (cbus_moduleParameters - __endOfParameters)

                    .short          cbus_moduleParameters - __endOfParameters
                    .int            __moduleName
                    .short          checksum

__moduleName:
                    .ascii          CBUS_MODULE_NAME

    .end

