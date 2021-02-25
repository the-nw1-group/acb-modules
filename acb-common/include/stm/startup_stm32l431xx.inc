/*
 * Copyright (c) 2021 The NW1 Group
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#ifndef __STM32L431XX_STARTUP_H
#define __STM32L431XX_STARTUP_H

#define __STM32L431XX_STARTUP

/* 
 * These are defined in stm32fx header files, but for some reason not defined in the L431 header file, so these
 * are defined here.
 *
 */

RESET = 0
SET = !RESET

DISABLE = 0
ENABLE = !DISABLE
#define IS_FUNCTIONAL_STATE(STATE) (((STATE) == DISABLE) || ((STATE) == ENABLE))

ERROR = 0
SUCCESS = !ERROR


#endif
