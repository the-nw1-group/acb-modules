/*
 * Copyright (c) 2015 The NW1 Group
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#include "moduleInfo.inc"

@ Continuously convert ADC1 on 5 channels, with a sample time of 5us, using DMA to
@ put the results into either onSampleMemory, or offSampleMemory, depending
@ on if TIM17 output is on or off. Use DMA single mode to limit the number of samples
@ within the time that TIM17 is either high or low

@ ADC inputs on PA2-6 - do in reverse order, and only do 49 transfers, to ensure
@ we do all the conversions in the correct time. PA2 (last conversion), is for the
@ sensitivity level, and should be stable, so it's OK to do one less conversion
@ do in DMA onshot mode, requesting 49 half word transfers, on each tim17 interrupt
@ once for LED on, once for LED off....

@ DMA channel configured in circular mode as this automatically resets the data count

    module(Analog)

    private_data(Analog_private)

Analog_onSamples:
                    .space          2 * QUADIR_NO_SAMPLES           @ on sample memory buffer
Analog_offSamples:
                    .space          2 * QUADIR_NO_SAMPLES           @ off sample memory buffer
Analog_onValues:
                    .space          2 * QUADIR_NO_VALUES            @ on ADC values
Analog_offValues:
                    .space          2 * QUADIR_NO_VALUES            @ off ADC values

@ Analog_onSamplesReady / Analog_offSamplesReady is not very memory efficient, but we have more than enough space

                    .align 4
Analog_onSamplesReady:
                    .word           0                               @ do we have enough on samples
Analog_offSamplesReady:
                    .word           0                               @ do we have enough off samples
Analog_sum:
                    .space          4 * (QUADIR_NO_VALUES + 1)      @ temporary sum

    public_function(Analog_init)

@ void Analog_init()
@   Setup the ADCs and associated variables, etc...

Analog_init:
                    push            {r7, lr}
__ainit_vars:                                                        @ initialise off/on sample memory + off/on values
                    ldr             r0, = #((QUADIR_NO_SAMPLES<<1) + (QUADIR_NO_VALUES<<1)) - 2
                    movs            r1, #0
                    ldr             r2, = #Analog_onSamples
0:
                    strh            r1, [r2, r0]
                    subs            r0, r0, #2
                    bcs             0b

__ainit_dma:
dmaConfig = DMA_CCR_PL_1 | DMA_CCR_MSIZE_0 | DMA_CCR_PSIZE_1 | DMA_CCR_MINC | DMA_CCR_CIRC | DMA_CCR_EN | DMA_CCR_TCIE

                    ldr             r2, = #DMA1_Channel1            @ configure the DMA to move the converted data from
                    ldr             r0, = #QUADIR_NO_SAMPLES        @ the adc to sample memory, transfer QUADIR_NO_SAMPLES
                    str             r0, [r2, #DMA_Channel_CNDTR_OFFSET] @ from ADC DR register to sample buffer (which
                    ldr             r0, = #_ADC1_DR                 @ on depends on whether the IR LED is on or off)
                    str             r0, [r2, #DMA_Channel_CPAR_OFFSET]
                    ldr             r0, = #dmaConfig
                    str             r0, [r2, #DMA_Channel_CCR_OFFSET]
                    movs            r0, #DMA1_Channel1_IRQn
                    bl              NVIC_enableIRQ

__ainit_adc:
                    ldr             r2, = #ADC1_BASE                @ configure the ADC
                    ldr             r0, = #ADC_CR_ADCAL             @ calibrate the ADC
                    str             r0, [r2, #ADC_CR_OFFSET]
0:
                    ldr             r1, [r2, #ADC_CR_OFFSET]        @ wait for the calibration to finish
                    tst             r0, r1
                    bne             0b

                    movs            r0, #ADC_CR_ADEN                @ enable the ADC so we can configure it
                    str             r0, [r2, #ADC_CR_OFFSET]
                    movs            r1, #ADC_ISR_ADRDY
1:
                    ldr             r0, [r2, #ADC_ISR_OFFSET]       @ wait until the ADC is ready
                    tst             r0, r1
                    beq             1b
                                                                    @ set continous, overwrite, reverse direction, using DMA
                    ldr             r0, = #ADC_CFGR1_CONT | ADC_CFGR1_SCANDIR | ADC_CFGR1_DMAEN
                    str             r0, [r2, #ADC_CFGR1_OFFSET]
                    ldr             r0, = #ADC_CFGR2_CKMODE_0       @ use PCLK/2
                    str             r0, [r2, #ADC_CFGR2_OFFSET]
                    movs            r0, #ADC_SMPR_SMP_0             @ set sample time of 7.5 ADC clock cycles
                    str             r0, [r2, #ADC_SMPR_OFFSET]
                    movs            r0, #QUADIR_ADC_SENSE | QUADIR_ADC_IN4 | QUADIR_ADC_IN3 | QUADIR_ADC_IN2 | QUADIR_ADC_IN1
                    str             r0, [r2, #ADC_CHSELR_OFFSET]

                    pop             {r7, pc}

    public_function(Analog_startDetection)

@ void Analog_startDetection()
@   start the ADC process

Analog_startDetection:
                    ldr             r2, = #DMA1_Channel1            @ set the number of samples to read, via
                    movs            r1, #QUADIR_NO_SAMPLES          @ DMA, and enable the channel
                    str             r1, [r2, #DMA_Channel_CNDTR_OFFSET]
                    ldr             r0, [r2, #DMA_Channel_CCR_OFFSET]
                    movs            r1, #DMA_CCR_EN
                    orrs            r0, r0, r1
                    str             r0, [r2, #DMA_Channel_CCR_OFFSET]
                    bx              lr

    public_function(Analog_stopDetection)

@ void Analog_stopDetection()
@   stop the ADC process

Analog_stopDetection:
                    push            {r7, lr}
                    ldr             r2, = #ADC1_BASE                @ turn off the ADC, and turn off the DMA channel
                    ldr             r0, [r2, #ADC_CR_OFFSET]
                    movs            r1, #ADC_CR_ADSTART
                    tst             r0, r1
                    beq             0f
                    movs            r1, #ADC_CR_ADSTP
                    orrs            r0, r0, r1
                    str             r0, [r2, #ADC_CR_OFFSET]
1:                                                                  @ wait for the ADC to stop
                    ldr             r0, [r1, #ADC_CR_OFFSET]
                    tst             r0, r1
                    bne             1b
0:
                    ldr             r2, = #DMA1_Channel1
                    ldr             r0, [r2, #DMA_Channel_CCR_OFFSET]
                    movs            r1, #DMA_CCR_EN
                    bics            r0, r0, r1
                    str             r0, [r2, #DMA_Channel_CCR_OFFSET]
                    movs            r0, #DMA1_Channel1_IRQn
                    bl              NVIC_clearPendingIRQ

                    ldr             r2, = #Analog_onSamplesReady    @ samples ready flag
                    movs            r0, #0
                    str             r0, [r2]
                    str             r0, [r2, #4]
                    pop             {r7, pc}

    public_function(Analog_start)

@ void Analog_start(bool flag)
@   start the ADC process. If the flag is 0 then the data is stored in the off samples, otherwise the data is stored in
@   the on samples

Analog_start:
                    ldr             r2, = #DMA1_BASE                @ clear interrupt flag
                    movs            r1, #DMA_IFCR_CGIF1
                    str             r1, [r2, #DMA_IFCR_OFFSET]
                    ldr             r2, = #DMA1_Channel1            @ set where to store the samples, based on the flag
                    cmp             r0, #0
                    bne             0f
                    ldr             r0, = #Analog_offSamples
                    b               1f
0:
                    ldr             r0, = #Analog_onSamples
1:
                    str             r0, [r2, #DMA_Channel_CMAR_OFFSET]
                    ldr             r2, = #ADC1_BASE                @ start the ADC process, after clearing any interrupts
                    ldr             r0, [r2, #ADC_ISR_OFFSET]       @ from the last process
                    movs            r1, #ADC_ISR_EOC | ADC_ISR_EOSEQ | ADC_ISR_EOSMP
                    orrs            r0, r0, r1
                    str             r0, [r2, #ADC_ISR_OFFSET]
                    ldr             r0, [r2, #ADC_CR_OFFSET]
                    movs            r1, #ADC_CR_ADSTART
                    orrs            r0, r0, r1
                    str             r0, [r2, #ADC_CR_OFFSET]
                    bx              lr

    public_function(__dma1Channel1IRQHandler)

@ void __dma1Channel1IRQHandler(void)
@   DMA1 Channel1 ISR

__dma1Channel1IRQHandler:
                    ldr             r2, = #DMA1_BASE                @ clear interrupt flag
                    movs            r1, #DMA_IFCR_CGIF1
                    str             r1, [r2, #DMA_IFCR_OFFSET]
                    ldr             r2, = #DMA1_Channel1
                    ldr             r0, [r2, #DMA_Channel_CMAR_OFFSET]
                    ldr             r1, = #Analog_onSamples         @ indicate if we have just finished reading
                    cmp             r1, r0                          @ on or off samples
                    bne             0f
                    ldr             r1, = #Analog_onSamplesReady
                    movs            r0, #1
                    str             r0, [r1]
                    b               1f
0:
                    ldr             r1, = #Analog_offSamples
                    cmp             r1, r0
                    bne             1f
                    ldr             r1, = #Analog_offSamplesReady
                    movs            r0, #1
                    str             r0, [r1]
1:
                    bx              lr

    public_function(Analog_averageSamples)

@   short Analog_averageSamples(bool flag)
@       average the samples and store the results in the values member variables. If the flag is 0 then the off samples
@       are averaged, otherwise the on samples are averaged. In both cases, the sense average value is returned.

Analog_averageSamples:
                    cmp             r0, #0                          @ average off or on samples?
                    bne             0f
                    ldr             r0, = #Analog_offSamples
                    ldr             r1, = #Analog_offValues
                    b               1f
0:
                    cmp             r0, #1
                    bne             1f
                    ldr             r0, = #Analog_onSamples
                    ldr             r1, = #Analog_onValues
1:
                    b               Analog_averageSamplesToValues   @ drop through to private function
2:
                    ldr             r0, = #-1
                    bx              lr

    public_function(Analog_areOnSamplesReady)

@ bool Analog_areOnSamplesReady(void)
@   returns 1 if there are on samples ready, otherwise returns 0

Analog_areOnSamplesReady:
                    ldr             r0, = #Analog_onSamplesReady
                    ldr             r0, [r0]
                    bx              lr

    public_function(Analog_areOffSamplesReady)

@ bool Analog_areOffSamplesReady(void)
@   returns 1 if there are off samples ready, otherwise returns 0

Analog_areOffSamplesReady:
                    ldr             r0, = #Analog_offSamplesReady
                    ldr             r0, [r0]
                    bx              lr

    public_function(Analog_clearSamplesReady)

@ void Analog_clearSamplesReady(bool flag)
@   clear the samples ready flag. If the flag is 0 then the off samples ready flag is cleared, otherwise the on samples
@   ready flag is cleared

Analog_clearSamplesReady:
                    ldr             r1, = #Analog_offSamplesReady
                    cmp             r0, #0
                    beq             0f
                    ldr             r1, = #Analog_onSamplesReady
                    movs            r0, #0
0:
                    cpsid           i                               @ disable interrupts
                    str             r0, [r1]
                    cpsie           i
                    isb
                    bx              lr

    public_function(Analog_getOnValues)

@ uint16_t[] Analog_getOnValues(void)
@   get the current on values

Analog_getOnValues:
                    ldr             r0, = #Analog_onValues
                    bx              lr

    public_function(Analog_getOffValues)

@ uint16_t[] Analog_getOffValues(void)
@   get the current off values

Analog_getOffValues:
                    ldr             r0, = #Analog_offValues
                    bx              lr

    private_function(Analog_averageSamplesToValues)

@ void Analog_averageSamplesToValues(uint16_t* samples, uint16_t* values)
@   average the samples and store the results in the values. returns the sense average value

Analog_averageSamplesToValues:
                    push            {r3-r7, lr}
                    ldr             r7, = #Analog_sum               @ clear the temporary sum data
                    movs            r2, #(QUADIR_NO_VALUES*4)
                    movs            r3, #0
0:
                    str             r3, [r7, r2]
                    subs            r2, r2, #4
                    bcs             0b

                    movs            r6, #2 * (QUADIR_NO_SAMPLES - (QUADIR_USE_SAMPLES * (QUADIR_NO_VALUES + 1)))
                    movs            r5, #0                          @ add all the samples up into sum, one entry
0:                                                                  @ per value and the sense, so we end up with
                    movs            r4, #0                          @ 5 values of the summed ADC values
1:
                    ldr             r3, [r7, r4]
                    ldrh            r2, [r0, r6]
3:
                    adds            r3, r3, r2
                    str             r3, [r7, r4]
                    adds            r6, r6, #2
                    adds            r4, r4, #4
                    cmp             r4, #(QUADIR_NO_VALUES + 1)<<2
                    bne             1b
                    adds            r5, r5, #1
                    cmp             r5, #QUADIR_USE_SAMPLES
                    bne             0b

                    movs            r3, #0
                    movs            r2, #4
2:
                    ldr             r4, [r7, r2]
                    lsrs            r4, r4, #QUADIR_LOG2_USE_SAMPLES
                    strh            r4, [r1, r3]
                    adds            r3, r3, #2
                    adds            r2, r2, #4
                    cmp             r3, #QUADIR_NO_VALUES<<1
                    bne             2b

                    ldr             r0, [r7]
                    lsrs            r0, r0, #QUADIR_LOG2_USE_SAMPLES
                    pop             {r3-r7, pc}

    .end
