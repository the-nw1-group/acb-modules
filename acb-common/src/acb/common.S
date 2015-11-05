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

    .extern         NVIC_enableIRQ                                  @ enabled IRQ
    .extern         MsCounter_clearAlarm                            @ clear the alarm
    .extern         MsCounter_alarmIn                               @ set an alarm in x milliseconds

@ public ACB common routines

    module(Acb)

@ ACB private data

    private_data(Acb_private)

acbStatus:          .int            ACB_STATUS_FLIMSW_RELEASED      @ various status flags for ACB common code

ACB_STATUS_FLIM_STATE_OFFSET  = 0
ACB_STATUS_FLIM_COUNT_OFFSET  = 1
ACB_STATUS_FLIM_SWITCH_STATUS = 2

@ ACB FLiM switch state machine (in lowest byte of acbStatus)

@ User must hold down the FLiM Switch for 8s or more, then release for at least 0.5s which then signals to the module
@ to enter FLiM mode. The state machine uses external interrupts to mointor for the button press, skip over any debounce
@ and after the timeout monitor for the release. This then signals that the user wishes to enter (or leave) FLiM mode.
@ ACB units can not leave FLiM mode, but for compatibility with existing MERG modules are supplied in a pseudo SLiM
@ mode, and must be put into FLiM mode, by holding down the button.

@ Once the ACB module is in FLiM mode a brief press and release on the switch (over 500ms, but less than 8s), will
@ re-enter setup mode, as above. A brief press again will leave setup mode with the orginal parameters (node number,
@ etc, intact)

@ Note status are a single bit shifted either to the left or to the right

ACB_STATUS_FLIMSW_RELEASED = 1                                      @ default state, no button pressed
ACB_STATUS_FLIMSW_PRESSED = 2                                       @ user is pressing button, and the module is waiting 8s
ACB_STATUS_FLIMSW_WAITINGRELEASE = 4                                @ waiting for the user to release the button
ACB_STATUS_FLIMSW_RELEASETIMEOUT = 8

@ ACB FLiM count, the 2nd byte of the acbStatus word is the number of 500mS passed since the switch was pressed, up to
@ 8s. After that we don't care as that's seen as a long press.

@ ACB FLiM Switch status in the 3rd byte of the acbStatus word

ACB_STATUS_FLIMSW_READYFORFLIM = 1                                  @ flag to indicate the user is ready to enter FLiM
                                                                    @ mode, state machine is back to 0 at this point.
                                                                    @ This flag is cleared on reading.
ACB_STATUS_FLIMSW_SHORTPRESS = 2                                    @ flag to indicate the user has pressed the FLiM
                                                                    @ for more than 500ms, but less that 8s. This flag
                                                                    @ is cleared on reading

ACB_STATUS_SWITCH_STATUS_MASK = 3

FLIM_SWITCH_PRESS_TIMEOUT_COUNTS = 16                               @ Number of FLIM_SWITCH_SHORT_PRESS_TIMEOUT
FLIM_SWITCH_SHORT_PRESS_TIMEOUT  = 500
FLIM_SWITCH_RELEASE_TIMEOUT      = 500
FLIM_SWITCH_ALARM_SLOT  = 1
#if FLIM_SWITCH_ALARM_SLOT > ACB_ALARM_SLOTS
#error Not enough alarm slots defined for async write operation. Adjust ACB_ALARM_SLOTS
#endif

    public_function(Acb_init)

@ void Acb_init()
@   init the ACB common library, including:
@       setting the LED (green and yellow) as outputs, if ACB_LED_USE is set. Initialises the input for the FLiM Button.
@       Requires the ACB_LED_PORT and ACB_FLIMSW_PORT clocks to be enabled before this is called

Acb_init:
                    push            {r7, lr}
#if ACB_LED_USE
                    ldr             r2, = #ACB_LED_PORT             @ enable bits for green and yellow to be
                    ldr             r1, [r2, #GPIO_MODER_OFFSET]    @ outputs - not in debug mode, otherwise
                    ldr             r3, = #(3<<(ACB_LED_GREEN_BIT<<1))|(3<<(ACB_LED_YELLOW_BIT<<1))
                    bics            r1, r1, r3                      @ we loose access to debug and programming
                    ldr             r3, = #(1<<(ACB_LED_GREEN_BIT<<1))|(1<<(ACB_LED_YELLOW_BIT<<1))
                    orrs            r3, r3, r1
                    str             r3, [r2, #GPIO_MODER_OFFSET]
                    ldr             r1, [r2, #GPIO_OSPEEDR_OFFSET]  @ set low speed for green/yellow
                    ldr             r3, = #(3<<(ACB_LED_GREEN_BIT<<1))|(3<<(ACB_LED_YELLOW_BIT<<1))
                    bics            r1, r1, r3
                    str             r1, [r2, #GPIO_OSPEEDR_OFFSET]
#endif

#if ACB_FLIMSW_USE
                    ldr             r2, = #ACB_FLIMSW_PORT          @ FLiM Switch as an input with a pull up
                    ldr             r1, [r2, #GPIO_PUPDR_OFFSET]    @ Input mode is default, so just enable pullup
                    ldr             r3, = #3<<(ACB_FLIMSW_BIT<<1)
                    bics            r1, r1, r3
                    ldr             r3, = #1<<(ACB_FLIMSW_BIT<<1)
                    orrs            r1, r1, r3
                    str             r1, [r2, #GPIO_PUPDR_OFFSET]
                                                                    @ setup the external interrupt configuration
                    ldr             r2, = #ACB_FLIMSW_SYSCFG_EXTI_REG
                    ldr             r1, [r2]
                    ldr             r0, = #0xF<<ACB_FLIMSW_SYSCFG_EXTI_START_BIT
                    bics            r1, r1, r0
                    ldr             r0, = #ACB_FLIMSW_SYSCFG_EXTI_VALUE<<ACB_FLIMSW_SYSCFG_EXTI_START_BIT
                    orrs            r1, r1, r0
                    str             r1, [r2]
                                                                    @ setup EXTI registers
                    ldr             r2, = #EXTI_BASE
                    ldr             r1, [r2, #EXTI_IMR_OFFSET]      @ enable interrupt for FLIMSW_BIT
                    ldr             r0, = #1<<ACB_FLIMSW_BIT
                    orrs            r1, r1, r0
                    str             r1, [r2, #EXTI_IMR_OFFSET]
                    ldr             r1, [r2, #EXTI_FTSR_OFFSET]     @ set falling edge interrupt
                    orrs            r1, r1, r0
                    str             r1, [r2, #EXTI_FTSR_OFFSET]
                    ldr             r0, = #ACB_FLIMSW_SYSCFG_EXTI_IRQ
                    bl              NVIC_enableIRQ
#endif
                    pop             {r7, pc}

    public_function(Acb_showLeds)

@ void Acb_showLeds(uint32 newValue, uint32 mask)
@   show/hide Leds based on supplied parameters. In both newValue and mask:
@       bit 0 is green LED
@       bit 1 is yellow LED
@       other bits unused.
@   does nothing if ACB_LED_USE is not set

Acb_showLeds:
                    push            {r7, lr}
#if ACB_LED_USE
                    movs            r2, #3
                    ands            r0, r0, r2                      @ ensure that we only manipulate the right bits
                    ands            r1, r1, r2
                    tst             r1, r2                          @ if mask is not empty, just return
                    beq             0f

                    ldr             r7, = #ACB_LED_PORT
__acbShowLedsGreen:                                                 @ no easy bit manipulation to set both green/yellow
                    movs            r2, #0                          @ here, as GREEN and YELLOW might not be on adjacent
                    tst             r1, r2                          @ pins
                    beq             __acbShowLedsYellow
                    ldr             r3, = #(1<<ACB_LED_GREEN_BIT)
                    tst             r0, r2                          @ turn the LED on or off?
                    beq             1f
                    str             r3, [r7, #GPIO_BSRR_OFFSET]
                    b               __acbShowLedsYellow
1:
                    str             r3, [r7, #GPIO_BRR_OFFSET]
__acbShowLedsYellow:
                    movs            r2, #1
                    tst             r1, r2
                    beq             0f
                    ldr             r3, = #(1<<ACB_LED_YELLOW_BIT)
                    tst             r0, r2                          @ turn the LED on or off?
                    beq             2f
                    str             r3, [r7, #GPIO_BSRR_OFFSET]
                    b               0f
2:
                    str             r3, [r7, #GPIO_BRR_OFFSET]
#endif
0:
                    pop             {r7, pc}

    public_function(Acb_readyForFLiM)

@ bool Acb_readyForFLiM(void)
@   returns TRUE is user has pressed the FLiM switch for 8s and then released the switch, otherwise returns FALSE.
@   Clears the flag (if set), on reading.

Acb_readyForFLiM:
                    movs            r0, #ACB_STATUS_FLIMSW_READYFORFLIM
                    b               Acb_readResetFLiMButtonStatus

    public_function(Acb_shortFLiMPress)

@ bool Acb_shortFLiMPress(void)
@   returns TRUE is user has pressed the FLiM switch for more 500ms and less than 8s and then released the switch,
@   otherwise returns FALSE. Clears the flag (if set), on reading.
Acb_shortFLiMPress:
                    movs            r0, #ACB_STATUS_FLIMSW_SHORTPRESS
                    b               Acb_readResetFLiMButtonStatus

    private_function(Acb_readResetFLiMButtonStatus)

@ bool Acb_readResetFLiMButtonStatus(int status)
@   returns TRUE if the status bit is set in ACB_STATUS_FLIM_SWITCH_STATUS, otherwise false. Clears the flag (if set),
@   on reading.

Acb_readResetFLiMButtonStatus:
#if ACB_FLIMSW_USE
                    ldr             r3, = #acbStatus
                    ldrb            r2, [r3, #ACB_STATUS_FLIM_SWITCH_STATUS]
                    movs            r1, r2
                    ands            r1, r1, r0
                    beq             1f
                    bics            r2, r2, r0
                    strb            r2, [r3, #ACB_STATUS_FLIM_SWITCH_STATUS]
                    movs            r0, #TRUE
#else
                    movs            r0, #FALSE                      @ No FLiM, just return false
#endif
                    bx              lr
1:
                    movs            r0, #FALSE
                    bx              lr


#if ACB_FLIMSW_USE == 1
    public_function(ACB_FLIMSW_SYSCFG_EXTI_ISR)

@ void ACB_FLIMSW_SYSCFG_EXTI_ISR(void)
@   Handle the EXTI interrupt for the FLiM switch - assumes this is the only event on this ISR. If something more
@   complex is required, then an upstream splitter is required.

ACB_FLIMSW_SYSCFG_EXTI_ISR:
                    push            {r7, lr}
                    ldr             r3, = #EXTI_BASE                @ clear interrupt
                    ldr             r2, = #1<<ACB_FLIMSW_BIT
                    str             r2, [r3, #EXTI_PR_OFFSET]
                    ldr             r1, = #acbStatus                @ get FLiM switch state machine status
                    ldrb            r0, [r1, #ACB_STATUS_FLIM_STATE_OFFSET]
                    cmp             r0, #ACB_STATUS_FLIMSW_RELEASED
                    beq             0f
                    cmp             r0, #ACB_STATUS_FLIMSW_PRESSED
                    beq             1f
                    cmp             r0, #ACB_STATUS_FLIMSW_WAITINGRELEASE
                    beq             2f
                    cmp             r0, #ACB_STATUS_FLIMSW_RELEASETIMEOUT
                    beq             3f
                    b               9f
0:
                    lsls            r0, r0, #1                      @ move to pressed status, and clear the counter
                    strh            r0, [r1, #ACB_STATUS_FLIM_STATE_OFFSET]
                    ldr             r1, [r3, #EXTI_FTSR_OFFSET]     @ look for rising edge rather than falling edge
                    bics            r1, r1, r2                      @ now, for either debounce, or the user changed
                    str             r1, [r3, #EXTI_FTSR_OFFSET]     @ their mind
                    ldr             r1, [r3, #EXTI_RTSR_OFFSET]
                    orrs            r1, r1, r2
                    str             r1, [r3, #EXTI_RTSR_OFFSET]

                    movs            r0, #FLIM_SWITCH_ALARM_SLOT     @ set an alarm for the short press timeout, and start
                    ldr             r1, = #FLIM_SWITCH_SHORT_PRESS_TIMEOUT @ counting up
                    ldr             r2, = #(Acb_flimSwitchAlarmPress+1)
                    bl              MsCounter_alarmIn
                    b               9f
1:
                    ldrb            r7, [r1, #ACB_STATUS_FLIM_COUNT_OFFSET] @ if count is greater than 0 then wait
                    cmp             r7, #0                          @ for a release, as we have at least a short press
                    bgt             2f

                    lsrs            r0, r0, #1                      @ move to release status, user has released the
                    strb            r0, [r1, #ACB_STATUS_FLIM_STATE_OFFSET] @ button, or switch debounce. Either way reset to
                    ldr             r1, [r3, #EXTI_RTSR_OFFSET]     @ looking for a failing edge
                    bics            r1, r1, r2
                    str             r1, [r3, #EXTI_RTSR_OFFSET]
                    ldr             r1, [r3, #EXTI_FTSR_OFFSET]
                    orrs            r1, r1, r2
                    str             r1, [r3, #EXTI_FTSR_OFFSET]
                    movs            r0, #FLIM_SWITCH_ALARM_SLOT     @ and clear the alarm
                    bl              MsCounter_clearAlarm
                    b               9f
2:
                    lsls            r0, r0, #1                      @ move to release timeout, simple bit of debouncing
                    strb            r0, [r1, #ACB_STATUS_FLIM_STATE_OFFSET]
3:
                    movs            r0, #FLIM_SWITCH_ALARM_SLOT     @ set an alarm in 0.5s time
                    ldr             r1, = #FLIM_SWITCH_RELEASE_TIMEOUT
                    ldr             r2, = #(Acb_flimSwitchAlarmRelease+1)
                    bl              MsCounter_alarmIn
9:
                    pop             {r7, pc}

    private_function(Acb_flimSwitchAlarmPress)

@ void Acb_flimSwitchAlarmPress(void)
@   the alarm handler, when this times out, then the user has pressed the button for at least 500ms

Acb_flimSwitchAlarmPress:
                    ldr             r1, = #acbStatus                @ inc and check the count
                    ldrb            r0, [r1, #ACB_STATUS_FLIM_COUNT_OFFSET]
                    adds            r0, r0, #1
                    strb            r0, [r1, #ACB_STATUS_FLIM_COUNT_OFFSET]
                    cmp             r0, #FLIM_SWITCH_PRESS_TIMEOUT_COUNTS
                    ble             1f
                    ldrb            r0, [r1, #ACB_STATUS_FLIM_STATE_OFFSET]
                    lsls            r0, r0, #1                      @ we've had the button pressed for the FLiM ready
                    strb            r0, [r1, #ACB_STATUS_FLIM_STATE_OFFSET] @ timeout, so update the state machine
0:
                    bx              lr
1:
                    mov             r12, lr
                    movs            r0, #FLIM_SWITCH_ALARM_SLOT     @ set an alarm for the short press timeout
                    ldr             r1, = #FLIM_SWITCH_SHORT_PRESS_TIMEOUT
                    ldr             r2, = #(Acb_flimSwitchAlarmPress+1)
                    bl              MsCounter_alarmIn
                    bx              r12

    private_function(Acb_flimSwitchAlarmRelease)

@ void Acb_flimSwitchAlarmRelease(void)
@   the alarm handler, when this times out, then the user has pressed the button 8s and then released for 0.5s

Acb_flimSwitchAlarmRelease:

                    ldr             r1, = #acbStatus                @ get FLiM switch state machine status
                    ldrb            r3, [r1, #ACB_STATUS_FLIM_COUNT_OFFSET] @ if count is less than FLIM_SWITCH_PRESS_TIMEOUT_COUNTS
                    cmp             r3, #FLIM_SWITCH_PRESS_TIMEOUT_COUNTS   @ then set the ACB_STATUS_FLIMSW_SHORTPRESS status
                    blt             0f                              @ otherwise set the ACB_STATUS_FLIMSW_READYFORFLIM status
                    movs            r0, #ACB_STATUS_FLIMSW_READYFORFLIM
                    b               1f
0:

    nop
    nop
    nop

                    movs            r0, #ACB_STATUS_FLIMSW_SHORTPRESS
1:
                    movs            r2, #ACB_STATUS_FLIMSW_RELEASED @ reset state machine, and clear the count
                    strh            r2, [r1, #ACB_STATUS_FLIM_STATE_OFFSET]
                    ldrb            r2, [r1, #ACB_STATUS_FLIM_SWITCH_STATUS]
                    movs            r3, #ACB_STATUS_SWITCH_STATUS_MASK
                    bics            r2, r2, r3                      @ clear the status
                    orrs            r2, r2, r0
                    strb            r2, [r1, #ACB_STATUS_FLIM_SWITCH_STATUS]
                    ldr             r2, = #1<<ACB_FLIMSW_BIT        @ wait for a falling edge again...
                    ldr             r3, = #EXTI_BASE
                    ldr             r0, [r3, #EXTI_RTSR_OFFSET]
                    bics            r0, r0, r2
                    str             r0, [r3, #EXTI_RTSR_OFFSET]
                    ldr             r0, [r3, #EXTI_FTSR_OFFSET]
                    orrs            r0, r0, r2
                    str             r0, [r3, #EXTI_FTSR_OFFSET]
                    bx              lr
#endif

    .end
