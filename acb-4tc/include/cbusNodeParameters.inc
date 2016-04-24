/*
 * Copyright (c) 2015 The NW1 Group
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

/*
 * Defines the CBUS node parameters - in node parameter order
 *
 */

#include "cbus/cbus_defs.inc"

#define CBUS_MODULE_NAME            "4TC     "

#define CBUS_MANUFACTURER           MANU_THENW1GROUP
#define CBUS_MINOR_VERSION          'A'
#define CBUS_MODULE_ID              MTYP_ACB_4TC
#define CBUS_MAX_EVENTS             64
#define CBUS_EVENT_VARS_PER_EVENT   2
#define CBUS_MAX_NODE_VARIABLES     16
#define CBUS_MAJOR_VERSION          0
#define CBUS_BASE_FLAGS             PF_COMBI | PF_BOOT
#define CBUS_CPU_TYPE               STM32F042K6T
#define CBUS_BUS_TYPE               PB_CAN
#define CBUS_LOAD_ADDRESS           _flash_origin
#define CBUS_CPU_MANUFACTURER       CPUM_STMICRO
#define CBUS_BETA_FLAG              1
