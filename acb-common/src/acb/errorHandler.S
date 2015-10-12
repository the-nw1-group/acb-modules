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
#include "acb/errorHandler.inc"

@ public error handler routine

    module(ErrorHandler)

    public_function(__svcHandler)

@ void __svcHandler(int errorCode)
@   Last chance fatal error handler if svc immediate value is ACB_FATAL_ERROR, otherwise return. This routine works
@   if either the MSP or PSP is used by the callee. It's an reworking of:
@       http://infocenter.arm.com/help/index.jsp?topic=/com.arm.doc.dui0203j/BABFGEFG.html

__svcHandler:
                    movs            r2, #4                          @ test LR (exception return)
                    mov             r1, lr                          @ check EXC_RETURN to see if PSP or MSP was used
                    tst             r2, r1
                    beq             0f
                    mrs             r1, psp                         @ PSP was used
                    b               1f
0:
                    mrs             r1, msp                         @ otherwise MSP was used
1:                                                                  @ r1 will point to r0, r1, r2, r3, r12, lr, pc, xPSR
                    ldr             r2, [r1, #24]                   @ get the PC of the instruction that called here
                    subs            r2, r2, #2                      @ we need to get the instruction before the return
                    ldrh            r2, [r2]                        @ address, so we can get the immediate value supplied
                    uxtb            r2, r2                          @ immediate in SVC stored in bottom byte
                    cmp             r2, #ACB_FATAL_ERROR            @ on SVC
                    beq             ErrorHandler_handle
                    bx              lr                              @ if not ACB_FATAL_ERROR return

#if defined(ACB_ERRORHANDLER_DEFAULTHANDLER)

    public_function(__defaultHandler)

@ void __defaultHandler(void)
@   Default __defaultHandler, that just reports the error via the standard error handler

__defaultHandler:
                    movs            r0, #ACB_ERROR_IN_DEFAULT_HANDLER
                    b               ErrorHandler_handle

#endif

#if defined(ACB_ERRORHANDLER_HANDLEFAULTS)

    public_function(__nmiHandler)

@ void __nmiHandler(void)
@   Default __nmiHandler, that just reports the error via the standard error handler

__nmiHandler:
                    movs            r0, #ACB_ERROR_NMI
                    b               ErrorHandler_handle

    public_function(__hardFaultHandler)

@ void __hardFaultHandler(void)
@   Default __hardFaultHandler, that just reports the error via the standard error handler

__hardFaultHandler:
                    movs            r0, #ACB_ERROR_HARD_FAULT
                    b               ErrorHandler_handle

#if (__CORTEX_M == 0x03) || (__CORTEX_M == 0x04) || (__CORTEX_M == 0x07)

    public_function(__memManageHandler)

@ void __memManageHandler(void)
@   Default __memManageHandler, that just reports the error via the standard error handler

__memManageHandler:
                    movs            r0, #ACB_ERROR_MEM_MANAGE
                    b               ErrorHandler_handle

    public_function(__busFaultHandler)

@ void __busFaultHandler(void)
@   Default __busFaultHandler, that just reports the error via the standard error handler

__busFaultHandler:
                    movs            r0, #ACB_ERROR_BUS_FAULT
                    b               ErrorHandler_handle

    public_function(__usageFaultHandler)

@ void __usageFaultHandler(void)
@   Default __usageFaultHandler, that just reports the error via the standard error handler

__usageFaultHandler:
                    movs            r0, #ACB_ERROR_USAGE_FAULT
                    b               ErrorHandler_handle
#endif

#endif

    private_function(ErrorHandler_handle)

@ void ErrorHandler_handle(int errorCode)
@   Last chance fatal error handler, in release flash GREEN and YELLOW, otherwise just hang. This assumes that at least
@   Acb_init has been called successfully.

ErrorHandler_handle:
                    cpsid           i                               @ disable all configurable interrupts
#if defined(DEBUG)
                    nop                                             @ in debug we don't have access to GREEN and YELLOW
                    nop                                             @ so just hang
                    bkpt            #0                              @ or try to breakpoint any debugger
                    b               .
#endif
                    mov             r4, r0
                    ldr             r7, = #ACB_LED_PORT
__flashErrorLoop:
                    lsrs            r6, r4, #4                      @ use high nibble, of the first byte for how many
                                                                    @ green flashes - always as least one flash of each
                    movs            r5, #1<<ACB_LED_GREEN_BIT       @ LED
                    bl              __flashFor

                    movs            r0, #0xF                        @ use low nibble, of the first byte for how many
                    ands            r0, r0, r4                      @ yellow flashes - always at leaste on flash of each
                    movs            r6, r0                          @ LED
                    movs            r5, #1<<ACB_LED_YELLOW_BIT
                    bl              __flashFor

                    ldr             r0, = #500
                    bl              __waitFor
                    b               __flashErrorLoop

__flashFor:                                                         @ flash LED in r5 for f6 times - GPIO_BASE in r7
                    mov             r12, lr
0:
                    str             r5, [r7, #GPIO_BSRR_OFFSET]
                    movs            r0, #250
                    bl              __waitFor
                    str             r5, [r7, #GPIO_BRR_OFFSET]
                    movs            r0, #250
                    bl              __waitFor
                    subs            r6, r6, #1
                    bne             0b
                    bx              r12

__waitFor:                                                          @ wait Xms - using SYSTICK - which assumes the
                    ldr             r3, = #SysTick_CTRL             @ rest of the application got as far as initialising
                    ldr             r1, = #1<<SysTick_CTRL_COUNTFLAG_Pos @ that - no interrupts here, so just poll.
0:
                    ldr             r2, [r3]                        @ has the COUNTFLAG been set to 1, which indicates
                    tst             r2, r1                          @ the timer has hit 0
                    beq             0b
                    subs            r0, r0, #1                      @ count down the 500
                    bne             0b
                    bx              lr                              @ return when complete

    .end
