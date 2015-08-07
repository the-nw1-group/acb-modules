/*
 * Copyright (c) 2015 The NW1 Group
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

/*
 * Private ACB-4TC include file
 *
 */

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

