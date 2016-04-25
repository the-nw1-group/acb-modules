/*
 * Copyright (c) 2015 The NW1 Group
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#if !defined(ACB_ALARM_SLOTS)
#error ACB_ALARM_SLOTS must all be defined to use this file
#endif

#if !defined(ACB_USE_MATH) && __CORTEX_M == 0
#error acb/math.inc must be included before this file on this platform (cortex-m0)
#endif

#define ACB_USE_MS_COUNTER

