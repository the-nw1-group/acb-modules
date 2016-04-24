/*
 * Copyright (c) 2015 The NW1 Group
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

/*
 * Error Handler implementation
 *
 *  For last chance fatal errors, issue the following instructions:
 *
 *                  movs            r0, #<error number>
 *                  svc             ACB_FATAL_ERROR
 *
 *  In all cases, the error handler will disable interrupts. In debug mode the error handler will then hang the
 *  application. In release mode the error handler will flash GREEN and YELLOW in a combination based on the
 *  error number supplied in r0.
 *
 *  Define the following to customise the error handler, in moduleInfo.inc (or similar)
 *
 *  ACB_ERRORHANDLER_DEFAULTHANDLER - replace the default error handler, and report error with ACB_ERROR_IN_DEFAULT_HANDLER
 *  ACB_ERRORHANDLER_HANDLEFAULTS   - replace fault error handlers, and report appropriate error codes
 *
 */

#define ACB_USE_ERROR_HANDLER

/*
 *
 * General error codes
 *
 */

ACB_ERROR_IN_DEFAULT_HANDLER    = 0x12
ACB_ERROR_NMI                   = 0x13
ACB_ERROR_HARD_FAULT            = 0x14
ACB_ERROR_MEM_MANAGE            = 0x15
ACB_ERROR_BUS_FAULT             = 0x16
ACB_ERROR_USAGE_FAULT           = 0x17
ACB_ERROR_CLOCKFAIL             = 0x18

ACB_CONFIG_LOAD_FAIL            = 0x21
ACB_CONFIG_WRONG_VERSION        = 0x22

