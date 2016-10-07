/*
 * Copyright (c) 2015 The NW1 Group
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#include "stm/stm32f30x.inc"
#include "stm/system_stm32f30x.inc"

#include "cmsis/core_cm4.inc"

#include "acb/functionHeaders.inc"
#include "acb/flash.inc"
#include "acb/optionBytes.inc"

#include "constants.inc"

/*
 * Private bootloader include file
 *
 * Uses the following software resources
 *  bit 0 of option byte 0: (0x1FFFF804)
 *      1   normal operation
 *      0   bootload
 *
 * Oddly Data0 is marked as reserved in the header file, even though it's present in the reference manual
 *
 */

#define BOOTLOAD_OPTION_BYTE    (OB_BASE + OB_RESERVED0_OFFSET)
#define BOOTLOAD_OPTION_BIT     0

/*
 * Define which port/pins the CAN module uses. Define port as either CAN_USEPORTA, CAN_USEPORTB, or CAN_USEOTHER
 * If CAN_USEOTHER then you must supply the definition manually
 * CAN_USEPORTA CAN on PA11/PA12
 * CAN_USEPORTB CAN on PB8/PB9
 *
 */

#define ACB_CAN_USEPORTA 0
#define ACB_CAN_USEPORTB 1
#define ACB_CAN_USEOTHER 2

#define ACB_CANPORT ACB_CAN_USEPORTA

#include "acb/can.inc"

/*
 * The bootloader doesn't use the FLiM switch, so turn it off here
 */

#define ACB_FLIMSW_CUSTOM
#define ACB_FLIMSW_USE 0

#include "acb/common.inc"

/*
 * Other defines - device electronic signature (which is missing from stm32f30x.inc file)
 */

#define DES_UID_BASE        0x1FFFF7AC
#define DES_UID_OFFSET      0x0000
#define DES_UID2_OFFSET     0x0004
#define DES_SIZE_BASE       0x1FFFF7CC
#define DES_SIZE_OFFSET     0x0000

#define DES                 (DES_UID_BASE)
#define _DES_UID            (DES + DES_UID_OFFSET)
#define _DES_UID2           (DES + DES_UID2_OFFSET)

#define DES_SIZE            (DES_SIZE_BASE)
#define _DES_SIZE           (DES_SIZE + DES_SIZE_OFFSET)

/*
 * Configure error handler to capture default handler, and all faults
 */

#define ACB_ERRORHANDLER_DEFAULTHANDLER
#define ACB_ERRORHANDLER_HANDLEFAULTS
