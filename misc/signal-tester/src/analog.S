/*
 * Copyright (c) 2015 The NW1 Group
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#include "moduleInfo.inc"

@ "Analog" code for the Signal/Servo tester - used for reading the Red, Green and Blue values.
@ Uses the ADC and Timer 2 to trigger conversions

    module(Analog)

noSamples = 128                                                     @ number of samples in the averaging buffer
avgDivider = 7                                                      @ log2(noSamples)

    private_data(Main_private)

Analog_sampleBuffer:
                    .space          3 * 2 * noSamples, 0            @ average buffer, each sample is 2 bytes
Analog_redValue:    .short          0                               @ calculated red value
Analog_greenValue:  .short          0                               @ calculated green value
Analog_blueValue:   .short          0                               @ calculated blue value

    public_function(Analog_init)

@ void Analog_init()
@   Setup the ADCs and associated variables, etc...

Analog_init:
                    push            {r7, lr}
                    ldr             r2, = #RCC_BASE                 @ enable ADC clock
                    ldr             r1, [r2, #RCC_APB2ENR_OFFSET]
                    ldr             r0, = #RCC_APB2ENR_ADCEN
                    orrs            r0, r0, r1
                    str             r0, [r2, #RCC_APB2ENR_OFFSET]
                    ldr             r1, [r2, #RCC_AHBENR_OFFSET]    @ enable the DMA controller
                    movs            r0, #RCC_AHBENR_DMAEN
                    orrs            r0, r0, r1
                    str             r0, [r2, #RCC_AHBENR_OFFSET]

dmaConfig = DMA_CCR_PL_0 | DMA_CCR_MSIZE_0 | DMA_CCR_PSIZE_1 | DMA_CCR_MINC | DMA_CCR_CIRC | DMA_CCR_TCIE | DMA_CCR_EN

                    ldr             r2, = #DMA1_Channel1            @ configure the DMA to move the converted data from
                    ldr             r0, = #noSamples * 3            @ the adc to Analog_sampleBuffer, transfer noSamples
                    str             r0, [r2, #DMA_Channel_CNDTR_OFFSET] @ from ADC DR register to Analog_sampleBuffer
                    ldr             r0, = #_ADC1_DR
                    str             r0, [r2, #DMA_Channel_CPAR_OFFSET]
                    ldr             r0, = #Analog_sampleBuffer
                    str             r0, [r2, #DMA_Channel_CMAR_OFFSET]
                    ldr             r0, = #dmaConfig
                    str             r0, [r2, #DMA_Channel_CCR_OFFSET]

                    movs            r0, #DMA1_Channel1_IRQn         @ enable DMA channel 1 interrupt
                    bl              NVIC_enableIRQ

                    ldr             r2, = #ADC1_BASE                @ configure the ADC
                    ldr             r0, = #ADC_CR_ADCAL             @ calibrate the ADC
                    str             r0, [r2, #ADC_CR_OFFSET]
0:
                    ldr             r1, [r2, #ADC_CR_OFFSET]        @ wait for the calibration to finish
                    tst             r0, r1
                    bne             0b

                    movs            r0, #ADC_CR_ADEN                @ enable the ADC so we can configure it
                    str             r0, [r2, #ADC_CR_OFFSET]        @ set continous, overwrite, triggered from Timer 2 update, using DMA in circular mode
                    ldr             r0, = #ADC_CFGR1_CONT | ADC_CFGR1_OVRMOD | ADC_CFGR1_EXTEN_0 | ADC_CFGR1_EXTSEL_1 | ADC_CFGR1_DMACFG | ADC_CFGR1_DMAEN
                    str             r0, [r2, #ADC_CFGR1_OFFSET]
                    ldr             r0, = #ADC_CFGR2_CKMODE_0       @ use PCLK/2
                    str             r0, [r2, #ADC_CFGR2_OFFSET]
                    movs            r0, #ADC_SMPR_SMP_0             @ set sample time of 7.5 ADC clock cycles
                    str             r0, [r2, #ADC_SMPR_OFFSET]
                    movs            r0, #ADC_CHSELR_CHSEL0 | ADC_CHSELR_CHSEL1 | ADC_CHSELR_CHSEL2 @ channels 0-2 converted
                    str             r0, [r2, #ADC_CHSELR_OFFSET]
                    movs            r0, #ADC_CR_ADEN | ADC_CR_ADSTART @ start converting (based on Timer 2)
                    str             r0, [r2, #ADC_CR_OFFSET]

                    ldr             r2, = #_RCC_APB1ENR             @ enable Timer 2 clock
                    ldr             r1, [r2]
                    movs            r0, #RCC_APB1ENR_TIM2EN
                    orrs            r0, r0, r1
                    str             r0, [r2]

                    ldr             r2, = #TIM2_BASE                @ set TIM2 to trigger ADC conversions, running @ 0.5ms
                    ldr             r0, = #TIM_CR2_MMS_2            @ upcounter, master mode "compare OC1REF" to trigger TRGO
                    str             r0, [r2, #TIM_CR2_OFFSET]
                    ldr             r0, = #23999
                    str             r0, [r2, #TIM_ARR_OFFSET]
                    movs            r0, #TIM_CCMR1_OC1M_0           @ set OC1REF high when counter matches CCR1
                    str             r0, [r2, #TIM_CCMR1_OFFSET]     @ so that it forces a trigger "event" (TRGO)
                    movs            r0, #TIM_CR1_CEN                @ enable the timer...
                    str             r0, [r2, #TIM_CR1_OFFSET]
                    pop             {r7, pc}

   public_function(__dma1Channel1IRQHandler)

@ void __dma1Channel1IRQHandler (void)
@   DMA interrupt service routine for channel 1 (ADC)

__dma1Channel1IRQHandler:
                    push            {r7, lr}
                    bl              Analog_averageSamples           @ average the samples
9:
                    ldr             r2, = #DMA1_BASE                @ clear the interrupt flag
                    movs            r0, #DMA_IFCR_CGIF1
                    str             r0, [r2, #DMA_IFCR_OFFSET]
                    pop             {r7, pc}

    private_function(Analog_averageSamples)

@ void Analog_averageSamples(void)
@   Average the samples from the Analog_sampleBuffer and place the results into  Analog_redValue, Analog_greenValue
@   and Analog_blueValue. The values are kept as 12 bit values.

Analog_averageSamples:
                    push            {r5-r7, lr}
                    ldr             r7, = #Analog_sampleBuffer
                    movs            r6, #noSamples
                    movs            r0, #0                          @ blue sum
                    movs            r1, #0                          @ green sum
                    movs            r2, #0                          @ red sum
0:
                    ldrh            r5, [r7]                        @ add to the red sum
                    adds            r0, r0, r5
                    adds            r7, r7, #2
                    ldrh            r5, [r7]                        @ add to the green sum
                    adds            r1, r1, r5
                    adds            r7, r7, #2
                    ldrh            r5, [r7]                        @ add to the blue sum
                    adds            r2, r2, r5
                    adds            r7, r7, #2
                    subs            r6, r6, #1
                    bne             0b
                    lsrs            r0, r0, #avgDivider             @ and divide the red sum by the number of samples
                    lsrs            r1, r1, #avgDivider             @ and divide the green sum by the number of samples
                    lsrs            r2, r2, #avgDivider             @ and divide the blue sum by the number of samples
                    ldr             r5, = #Analog_redValue          @ store results back
                    strh            r0, [r5, #4]
                    strh            r1, [r5, #2]
                    strh            r2, [r5]
                    pop             {r5-r7, pc}

    .end
