/*
 * Copyright (c) 2015 The NW1 Group
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#include "moduleInfo.inc"

@ DRV8816 driver

    module(Drv8816)

    public_function(Drv8816_init)

@ void Drv8816_init()
@   Setup the DRV8816 digtial functions - vPropi is handled by the analog module, assumes
@   gpio port and timer peripheral clocks are enabled, and SLEEP pin is setup.

Drv8816_init:
                    push            {r7, lr}
                    ldr             r0, = #UTROLLER_SLEEP_GPIOBASE  @ set sleep pin to low
                    movs            r1, #1<<UTROLLER_SLEEP
                    str             r1, [r0, #GPIO_BRR_OFFSET]                    

PWM_MODE_MK = 3<<(UTROLLER_MOTOR_EN1<<1) | 3<<(UTROLLER_MOTOR_EN2<<1) | 3<<(UTROLLER_MOTOR_IN1<<1) | 3<<(UTROLLER_MOTOR_IN2<<1)
PWM_MODE    = 2<<(UTROLLER_MOTOR_EN1<<1) | 2<<(UTROLLER_MOTOR_EN2<<1) | 2<<(UTROLLER_MOTOR_IN1<<1) | 2<<(UTROLLER_MOTOR_IN2<<1)
PWM_OUT     = 1<<UTROLLER_MOTOR_EN1 | 1<<UTROLLER_MOTOR_EN2 | 1<<UTROLLER_MOTOR_IN1 | 1<<UTROLLER_MOTOR_IN2
PWM_SPEED   = PWM_MODE_MK
PWM_AF      = UTROLLER_DRV8816_AF<<(UTROLLER_MOTOR_EN1<<2) | UTROLLER_DRV8816_AF<<(UTROLLER_MOTOR_EN2<<2) | UTROLLER_DRV8816_AF<<(UTROLLER_MOTOR_IN1<<2) | UTROLLER_DRV8816_AF<<(UTROLLER_MOTOR_IN2<<2) 
PWM_AF_MK   = 0xf<<(UTROLLER_MOTOR_EN1<<2) | 0xf<<(UTROLLER_MOTOR_EN2<<2) | 0xf<<(UTROLLER_MOTOR_IN1<<2) | 0xf<<(UTROLLER_MOTOR_IN2<<2) 

                    ldr             r0, = #UTROLLER_PWM_GPIOBASE    @ setup timer2 pwm outputs
                    ldr             r1, [r0, #GPIO_MODER_OFFSET]    @ set AF mode
                    movs            r2, #PWM_MODE_MK
                    bics            r1, r1, r2
                    movs            r2, #PWM_MODE
                    orrs            r1, r1, r2
                    str             r1, [r0, #GPIO_MODER_OFFSET]
                    ldr             r1, [r0, #GPIO_OTYPER_OFFSET]   @ set push-pull mode
                    movs            r2, #PWM_OUT
                    bics            r1, r1, r2
                    str             r1, [r0, #GPIO_OTYPER_OFFSET]
                    ldr             r1, [r0, #GPIO_OSPEEDR_OFFSET]
                    movs            r1, #PWM_SPEED
                    orrs            r1, r1, r2
                    str             r1, [r0, #GPIO_OSPEEDR_OFFSET]
                    ldr             r1, [r0, #GPIO_AFR_OFFSET]      @ set AF2 mode (TimerX)
                    ldr             r2, = #PWM_AF_MK
                    bics            r1, r1, r2
                    ldr             r2, = #PWM_AF
                    orrs            r1, r1, r2
                    str             r1, [r0, #GPIO_AFR_OFFSET]

                    ldr             r7, = #UTROLLER_DRV8816_TIMER_BASE  @ set up TimerX
                    bl              Configuration_getOption0Value   @ if config0=1 then use low frequency PWM (500Hz-ish)
                    movs            r1, #1
                    cmp             r0, #0
                    beq             0f
                    ldr             r1, =#467
0:
                    str             r1, [r7, #TIM_PSC_OFFSET]
                    ldr             r0, = #2047                     @ otherwise use high frequency PWM (11.7kHz-ish)
                    str             r0, [r7, #TIM_ARR_OFFSET]

1:

PWM_CCMR = UTROLLER_MOTOR_EN1_TIM(CCMR,OC,M_2) | UTROLLER_MOTOR_EN1_TIM(CCMR,OC,FE) | UTROLLER_MOTOR_EN1_TIM(CCMR,OC,PE) | \
           UTROLLER_MOTOR_IN1_TIM(CCMR,OC,M_2) | UTROLLER_MOTOR_IN1_TIM(CCMR,OC,FE) | UTROLLER_MOTOR_IN1_TIM(CCMR,OC,PE)
PWM_CCER = TIM_CCER_CC4E | TIM_CCER_CC3E | TIM_CCER_CC2E | TIM_CCER_CC1E
PWM_CR1  = TIM_CR1_ARPE | TIM_CR1_CEN

                    ldr             r1, = #PWM_CCMR                 @ force no output, fast update and preload, output
                    str             r1, [r7, #TIM_CCMR1_OFFSET]     @ no output is set until we're ready to output something useful
                    str             r1, [r7, #TIM_CCMR2_OFFSET]
                    ldr             r1, = # PWM_CCER                @ output enabled, and enabled positive
                    str             r1, [r7, #TIM_CCER_OFFSET]
                    ldr             r1, = # PWM_CR1                 @ enable timer, and set edge-align mode
                    str             r1, [r7, #TIM_CR1_OFFSET]
                    ldr             r0, [r7, #TIM_EGR_OFFSET]       @ force an update
                    movs            r1, #TIM_EGR_UG
                    orrs            r0, r0, r1
                    str             r0, [r7, #TIM_EGR_OFFSET]
                    pop             {r7, pc}

    public_function(Drv8816_off)

@ void Drv8816_off()
@   Turn off the output from the drv8816 (en1=en2=in1=in2=nSleep=0)
#   This will cause motor to coast

Drv8816_off:
                    ldr             r0, = #UTROLLER_SLEEP_GPIOBASE  @ set sleep pin to low
                    movs            r1, #1<<UTROLLER_SLEEP
                    str             r1, [r0, #GPIO_BRR_OFFSET]                    

PWM_FORCE_STOP = UTROLLER_MOTOR_EN1_TIM(CCMR,OC,M_2) | UTROLLER_MOTOR_IN1_TIM(CCMR,OC,M_2)

                    ldr             r0, = #UTROLLER_DRV8816_TIMER_BASE  @ force the outputs of the timers low...
                    ldr             r2, = #PWM_FORCE_STOP
                    ldr             r1, [r0, #TIM_CCMR1_OFFSET]
                    bics            r1, r1, r2
                    str             r1, [r0, #TIM_CCMR1_OFFSET]
                    ldr             r1, [r0, #TIM_CCMR2_OFFSET]
                    bics            r1, r1, r2
                    str             r1, [r0, #TIM_CCMR2_OFFSET]
                    bx              lr

    public_function(Drv8816_on)

@ void Drv8816_on()
@   Turn on the output from the drv8816 (nSleep=1), and set brake

Drv8816_on:
                    push            {r7, lr}
                    bl              Drv8816_brake                   @ set brake mode first, before enabling the device
                    ldr             r0, = #UTROLLER_SLEEP_GPIOBASE  @ set sleep pin to high
                    movs            r1, #1<<UTROLLER_SLEEP
                    str             r1, [r0, #GPIO_BSRR_OFFSET]                    
                    movs            r0, #1                          @ wait for 1ms before continuing
                    bl              MsCounter_waitFor
                    pop             {r7, pc}

    public_function(Drv8816_brake)

@ void Drv8816_brake()
@   Brake the output of the drv8816 (en1=en2=in1=in2=1)
@   This assumes nSleep=1

Drv8816_brake:
                    push            {r7, lr}

PWM_BRAKE = UTROLLER_MOTOR_EN1_TIM(CCMR,OC,M_2) | UTROLLER_MOTOR_EN1_TIM(CCMR,OC,M_0) | UTROLLER_MOTOR_IN1_TIM(CCMR,OC,M_2) | UTROLLER_MOTOR_IN1_TIM(CCMR,OC,M_0)

                    ldr             r0, = #UTROLLER_DRV8816_TIMER_BASE
                    ldr             r1, = #DRIVE_MASK           @ force all inputs into drv8816 active high
                    ldr             r2, = #PWM_BRAKE
                    ldr             r3, [r0, #TIM_CCMR1_OFFSET]
                    bics            r3, r3, r1
                    orrs            r3, r3, r2
                    ldr             r7, [r0, #TIM_CCMR2_OFFSET]
                    bics            r7, r7, r1
                    orrs            r7, r7, r2
                    str             r3, [r0, #TIM_CCMR1_OFFSET]
                    str             r7, [r0, #TIM_CCMR2_OFFSET]
                    pop             {r7, pc}

    public_function(Drv8816_forward)

@ void Drv8816_forward(uint16_t speed)
@   Set the output of the drv8816 "forwards" (en1=en2=1 in1=pwm in2=0)
@   This assumes nSleep=1, pwm signal is determined by the speed argument,
@   assumes speed is a value between 0 and 2047

Drv8816_forward:

PWM_FWD1 = UTROLLER_MOTOR_EN1_TIM(CCMR,OC,M_2) | UTROLLER_MOTOR_EN1_TIM(CCMR,OC,M_0) | UTROLLER_MOTOR_IN1_TIM(CCMR,OC,M_2) | UTROLLER_MOTOR_IN1_TIM(CCMR,OC,M_1)
PWM_FWD2 = UTROLLER_MOTOR_EN2_TIM(CCMR,OC,M_2) | UTROLLER_MOTOR_EN2_TIM(CCMR,OC,M_0) | UTROLLER_MOTOR_IN2_TIM(CCMR,OC,M_2)

                    ldr             r1, = #PWM_FWD1
                    ldr             r2, = #PWM_FWD2
                    ldr             r3, = #UTROLLER_MOTOR_IN1_CCR
                    b               Drv8816_drive

    public_function(Drv8816_reverse)

@ void Drv8816_reverse(uint16_t speed)
@   Set the output of the drv8816 "reverse" (en1=en2=1 in1=0 in2=pwm)
@   This assumes nSleep=1, pwm signal is determined by the speed argument,
@   assumes speed is a value between 0 and 2047

Drv8816_reverse:

PWM_REV1 = UTROLLER_MOTOR_EN1_TIM(CCMR,OC,M_2) | UTROLLER_MOTOR_EN1_TIM(CCMR,OC,M_0) | UTROLLER_MOTOR_IN1_TIM(CCMR,OC,M_2)
PWM_REV2 = UTROLLER_MOTOR_EN2_TIM(CCMR,OC,M_2) | UTROLLER_MOTOR_EN2_TIM(CCMR,OC,M_0) | UTROLLER_MOTOR_IN2_TIM(CCMR,OC,M_2) | UTROLLER_MOTOR_IN2_TIM(CCMR,OC,M_1)


 
                    ldr             r1, = #PWM_REV1
                    ldr             r2, = #PWM_REV2
                    ldr             r3, = #UTROLLER_MOTOR_IN2_CCR
                    b               Drv8816_drive

    private_function(Drv8816_drive)

@ void Drv8816_drive(uint16_t speed, uint32_t ccmr1, uint32_t ccmr2, uint32_t* ccr_offset)
@   set drive parameters, using speed for compare value for PWM, assumes this is between 0 and 2047

Drv8816_drive:

DRIVE_MASK = TIM_CCMR1_OC1M | TIM_CCMR1_OC2M

                    push            {r5-r7, lr}
                    ldr             r7, = #UTROLLER_DRV8816_TIMER_BASE
                    str             r0, [r7, r3]
                    ldr             r0, = #DRIVE_MASK
                    ldr             r6, [r7, #TIM_CCMR1_OFFSET]
                    bics            r6, r6, r0
                    orrs            r6, r6, r1
                    ldr             r5, [r7, #TIM_CCMR2_OFFSET]
                    bics            r5, r5, r0
                    orrs            r5, r5, r2
                    str             r6, [r7, #TIM_CCMR1_OFFSET]
                    str             r5, [r7, #TIM_CCMR2_OFFSET]
                    pop             {r5-r7, pc}

    .end
