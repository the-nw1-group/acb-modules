/*
 * Copyright (c) 2015 The NW1 Group
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#if !defined(ACB_SIB_GPIOBASE) || !defined(ACB_SIB_MASK) || !defined(ACB_SIB_STATE_DEPTH)\
    || !defined(ACB_SIB_INVERT) || !defined(ACB_SID_ALARM_SLOT)
#error ACB_SIB_GPIOBASE, ACB_SIB_MASK, ACB_SIB_STATE_DEPTH, ACB_SIB_INVERT, ACB_SID_ALARM_SLOT must all be defined to use this file
#endif

#define ACB_USE_SID

