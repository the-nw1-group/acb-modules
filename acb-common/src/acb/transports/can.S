/*
 * Copyright (c) 2015 The NW1 Group
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#include "moduleInfo.inc"

@ public CAN routines, for sending, and receiving messages over the CAN bus

#ifdef ACB_USE_CAN

    module(Can)

    public_function(Can_initForStandardFrames)

#if defined(STM32L431xx)
    #define ACB_PERIPH_CLOCK_ENABLE    _RCC_APB1ENR1
    #define ACB_RCC_APB1ENR_CANEN      RCC_APB1ENR1_CAN1EN
#else
    #define ACB_PERIPH_CLOCK_ENABLE    _RCC_APB1ENR
    #if defined(__STM32F30x)
        #define ACB_RCC_APB1ENR_CANEN      RCC_APB1ENR_CAN1EN
    #else
        #define ACB_RCC_APB1ENR_CANEN      RCC_APB1ENR_CANEN
    #endif
#endif

@ for now default to using CAN1
#if !defined(CAN_BASE)
    #define CAN_BASE CAN1_BASE

    #if !defined(_CAN_sFIFOMailBox)
        #define _CAN_sFIFOMailBox       _CAN1_sFIFOMailBox
    #endif

    #if !defined(_CAN_sFilterRegister)
        #define _CAN_sFilterRegister    _CAN1_sFilterRegister
    #endif

    #if !defined(_CAN_sTxMailBox)
        #define _CAN_sTxMailBox         _CAN1_sTxMailBox
    #endif

    #if !defined(_CAN_FMR)
        #define _CAN_FMR                _CAN1_FMR
    #endif

#endif

@ void CAN_initForStandardFrames()
@   initialise the CAN peripheral hardware and configure to only accept standard frames
@       if required, reconfigure PA9/PA10 to PA11/PA12
@       set up port pins to alternate function (CAN)
@       CAN peripheral: enable the clock; set baudrate and other timing
@   The port the CAN pins are on must already have the clock enabled, before calling this function
@   Only FIFO 0 is currently used

Can_initForStandardFrames:
                    push            {r7, lr}
#if ACB_CAN_REQUIRES_SYSCONFIG == 1
                    bl              Can_setupSystemConfig
#endif
                    bl              Can_setupPort
                    bl              Can_setupPeripheral
                    movs            r0, #0
                    movs            r1, #CAN_RI0R_IDE
                    bl              Can_setupFilter
                    bl              Can_completeSetup
                    pop             {r7, pc}

    public_function(CAN_initForExtendedFrames)

@ void CAN_initForStandardFrames()
@   initialise the CAN peripheral hardware and configure to only accept extended frames
@       if required, reconfigure PA9/PA10 to PA11/PA12
@       set up port pins to alternate function (CAN)
@       CAN peripheral: enable the clock; set baudrate and other timing
@   The port the CAN pins are on must already have the clock enabled, before calling this function
@   Only FIFO 0 is currently used

CAN_initForExtendedFrames:
                    push            {r7, lr}
#if ACB_CAN_REQUIRES_SYSCONFIG == 1
                    bl              Can_setupSystemConfig
#endif
                    bl              Can_setupPort
                    bl              Can_setupPeripheral
                    movs            r0, #CAN_RI0R_IDE
                    movs            r1, r0
                    bl              Can_setupFilter
                    bl              Can_completeSetup
                    pop             {r7, pc}

    public_function(Can_getMsgEx)

@ bool Can_getMsgEx(MSGEX* msg)
@   get the next received message - non-blocking, returns true if message received, otherwise returns false
@   if message received details are placed in the MSG and the buffer in the CAN fifo released
@   assumes message was an extended frame

Can_getMsgEx:
                    ldr             r3, = #CAN_BASE                 @ check if FIFO 0 has a message in it
                    ldr             r1, [r3, #CAN_RF0R_OFFSET]
                    movs            r2, #CAN_RF0R_FMP0
                    tst             r1, r2
                    beq             1f                              @ 0 = no message
                                                                    @ otherwise copy the data out into the MSGEX "structure"
                    push            {r6-r7}
                    ldr             r6,= #_CAN_sFIFOMailBox         @ get the EXID
                    ldr             r1, [r6]
                    lsrs            r2, r1, #3
                    str             r2, [r0, #(ACB_MSGEX_INFO_OFFSET + ACB_MSGEX_INFO_EXID_OFFSET)]
                                                                    @ get the DLC, IDE and RTR
                    movs            r7, #(CAN_RI0R_RTR | CAN_RI0R_IDE)
                    ands            r1, r1, r7
                    lsls            r1, #(ACB_MSG_IDE_OFFSET - (CAN_RI0R_RTR>>1))
                    ldr             r2, [r6, #CAN_TxMailBox_TDTR_OFFSET]
                    movs            r7, #CAN_RDT0R_DLC
                    ands            r2, r2, r7
                    orrs            r2, r2, r1
                    str             r2, [r0, #(ACB_MSGEX_INFO_OFFSET + ACB_MSGEX_INFO_LEN_OFFSET)]

                    adds            r6, r6, #8                      @ load the data bytes
                    adds            r0, r0, #ACB_MSGEX_DATA_OFFSET
                    ldm             r6!, {r1-r2}
                    stm             r0!, {r1-r2}
                    pop             {r6-r7}
0:
                    movs            r1, #CAN_RF0R_RFOM0             @ release this entry
                    ldr             r2, [r3, #CAN_RF0R_OFFSET]
                    orrs            r2, r2, r1
                    str             r2, [r3, #CAN_RF0R_OFFSET]
                    movs            r0, #1                          @ indicate we've got a message
                    b               2f
1:
                    movs            r0, #0                          @ indicate we didn't get a message
2:
                    bx              lr

    public_function(Can_sendMessageEx)

@ void Can_sendMessageEx(MSGEX* msg)
@   transmits an extended frame CAN message - blocking, doesn't return until the message has been queued for
@   sending with the CAN peripheral

Can_sendMessageEx:
                    push            {r7, lr}
                    ldr             r1, = Can_postMessageEx
                    bl              Can_postMessageWrapper
                    pop             {r7, pc}

    public_function(Can_sendMessage)

@ void Can_sendMessage(MSG* msg)
@   transmits an standard frame CAN message - blocking, doesn't return until the message has been queued for
@   sending with the CAN peripheral

Can_sendMessage:
                    push            {r7, lr}
                    ldr             r1, = Can_postMessage
                    bl              Can_postMessageWrapper
                    pop             {r7, pc}

    private_function(Can_postMessageWrapper)

@ void Can_postMessageWrapper(void* msg, void* fnToCall)
@   wraps a postMessage[Ex] call - blocking, doesn't return until the message has been queued for
@   sending with the CAN peripheral

Can_postMessageWrapper:
                    push            {r5-r7, lr}
                    movs            r7, r0                          @ take a copy of the msg
                    movs            r6, r1                          @ take a copy of the function to call
0:
                    blx             r6                              @ try to send the message
                    cmp             r0, #SUCCESS                    @ if it worked, just return
                    beq             1f
                    mov             r0, r7                          @ otherwise try again, and again, and again...
                    b               0b
1:
                    pop             {r5-r7, pc}

    public_function(Can_postMessage)

@ bool Can_postMessage(MSG* msg)
@   transmits an standard frame CAN message - non-blocking, returns true if message is queued for transmission, otherwise returns false
@   if the message is queued, the msg parameter can be freed. Only to be used for standard or RTR frames.

Can_postMessage:
                    push            {r7, lr}
                    movs            r7, r0
                    bl              Can_getNextFreeTxBuffer         @ find the next free buffer
                    cmp             r0, #0                          @ no free buffer?
                    beq             1f                              @ return false
                                                                    @ copy over the data bytes into the tx box
                    ldr             r1, [r7, #ACB_MSG_DATA_OFFSET]
                    str             r1, [r0, #CAN_TxMailBox_TDLR_OFFSET]
                    ldr             r1, [r7, #(ACB_MSG_DATA_OFFSET+4)]
                    str             r1, [r0, #CAN_TxMailBox_TDHR_OFFSET]
                                                                    @ copy DLC
                    ldrb            r1, [r7, #ACB_MSG_INFO_LEN_OFFSET]
                    movs            r2, #ACB_MSG_LEN_MASK           @ mask out just DLC
                    ands            r1, r1, r2
                    str             r1, [r0, #CAN_TxMailBox_TDTR_OFFSET]
                                                                    @ copy STDID | RTR, and request transmit
                    ldr             r1, [r7, #(ACB_MSG_INFO_OFFSET + ACB_MSG_INFO_STID_OFFSET)]
                    lsls            r1, #21
                    ldrb            r2, [r7, #(ACB_MSG_INFO_OFFSET + ACB_MSG_INFO_LEN_OFFSET)]
                    lsrs            r2, #3
                    orrs            r1, r1, r2
                    movs            r2, #CAN_TI0R_IDE
                    bics            r1, r1, r2                      @ ensure IDE is clear
                    movs            r2, #CAN_TI0R_TXRQ
                    orrs            r1, r1, r2
                    str             r1, [r0, #CAN_TxMailBox_TIR_OFFSET]
0:
                    movs            r0, #SUCCESS                    @ message queued, return true
1:
                    pop             {r7, pc}

    public_function(Can_postMessageEx)

@ bool Can_postMessageEx(MSGEX* msg)
@   transmits an extended frame CAN message - non-blocking, returns true if message is queued for transmission, otherwise returns false
@   if the message is queued, the msg parameter can be freed. Only to be used for extended non RTR frames.

Can_postMessageEx:
                    push            {r7, lr}
                    movs            r7, r0
                    bl              Can_getNextFreeTxBuffer         @ find the next free buffer
                    cmp             r0, #0                          @ no free buffer?
                    beq             1f                              @ return false
                                                                    @ copy over the data bytes into the tx box
                    ldr             r1, [r7, #ACB_MSGEX_DATA_OFFSET]
                    str             r1, [r0, #CAN_TxMailBox_TDLR_OFFSET]
                    ldr             r1, [r7, #(ACB_MSGEX_DATA_OFFSET+4)]
                    str             r1, [r0, #CAN_TxMailBox_TDHR_OFFSET]
                                                                    @ copy DLC
                    ldrb            r1, [r7, #ACB_MSGEX_INFO_LEN_OFFSET]
                    movs            r2, #ACB_MSG_LEN_MASK           @ mask out just DLC
                    ands            r1, r1, r2
                    str             r1, [r0, #CAN_TxMailBox_TDTR_OFFSET]
                                                                    @ copy EXID | IDE | RTR, and request transmit
                    ldr             r1, [r7, #(ACB_MSGEX_INFO_OFFSET + ACB_MSGEX_INFO_EXID_OFFSET)]
                    lsls            r1, #3
                    ldrb            r2, [r7, #(ACB_MSGEX_INFO_OFFSET + ACB_MSGEX_INFO_LEN_OFFSET)]
                    lsrs            r2, #3
                    orrs            r1, r1, r2
                    movs            r2, #(CAN_TI0R_IDE | CAN_TI0R_TXRQ) @ ensure IDE is set, and request transmit
                    orrs            r1, r1, r2
                    str             r1, [r0, #CAN_TxMailBox_TIR_OFFSET]
0:
                    movs            r0, #SUCCESS                    @ message queued, return true
1:
                    pop             {r7, pc}

    private_function(Can_setupSystemConfig)

@ void Can_setupSystemConfig()
@   reconfigure PA9/PA10 to PA11/PA12 - on low pin count devices the CAN pins (PA11/PA12), share the same
@   pins as the USB port (PA9/PA10). The default is for the usb device, so this method reassignes them to
@   the can port

Can_setupSystemConfig:
#if ACB_CAN_REQUIRES_SYSCONFIG == 1
                    ldr             r3, = #_RCC_APB2ENR             @ enable SYSCFG peripheral clock
                    ldr             r0, [r3]                        @ which is mildly odd to have to
                    movs            r1, #RCC_APB2ENR_SYSCFGCOMPEN   @ enable...
                    orrs            r0, r0, r1
                    str             r0, [r3]

                    ldr             r3, = #_SYSCFG_CFGR1            @ enable pins pa11/pa12 rather than pa9/pa10
                    ldr             r0, [r3]
                    movs            r1, #SYSCFG_CFGR1_PA11_PA12_RMP
                    orrs            r0, r0, r1
                    str             r0, [r3]
#endif
                    bx              lr

    private_function(Can_setupPort)

@ void Can_setupPort()
@   initialise the CAN hardware port, set the TX and RX pins to alternate function, and high speed

Can_setupPort:
                    ldr             r3, = #ACB_CAN_GPIOBASE         @ setup CANTX/CANRX on port/pins defined in header
                    ldr             r1, [r3, #GPIO_MODER_OFFSET]    @ file
                    ldr             r0, = #(2<<(ACB_CAN_RXPIN<<1))|(2<<(ACB_CAN_TXPIN<<1))
                    orrs            r0, r0, r1
                    str             r0, [r3, #GPIO_MODER_OFFSET]

                    ldr             r1, [r3, #GPIO_OSPEEDR_OFFSET]
                    ldr             r0, = #(3<<(ACB_CAN_RXPIN<<1))|(3<<(ACB_CAN_TXPIN<<1))
                    orrs            r0, r0, r1
                    str             r0, [r3, #GPIO_OSPEEDR_OFFSET]  @ enable high speed for these bits

                    ldr             r1, [r3, #ACB_CAN_GPIO_AFR_OFFSET]
                    ldr             r0, = #(4<<(ACB_CAN_AFR_RXPIN<<2))|(4<<(ACB_CAN_AFR_TXPIN<<2))
                    orrs            r0, r0, r1
                    str             r0, [r3, #ACB_CAN_GPIO_AFR_OFFSET]  @ select CANTX (AF4) / CANRX (AF4)
                    bx              lr

    private_function(Can_setupPeripheral)

@ void Can_setupPeripheral()
@   initialise the CAN peripheral, enable the clock to the device, set the baud rate.
@   leaves the CAN module in initalise mode

Can_setupPeripheral:
                    ldr             r3, = #ACB_PERIPH_CLOCK_ENABLE  @ enable bxCAN clock
                    ldr             r1, [r3]
                    ldr             r0, = #ACB_RCC_APB1ENR_CANEN
                    orrs            r0, r0, r1
                    str             r0, [r3]

                    ldr             r3, = #CAN_BASE
                    movs            r1, #CAN_MCR_SLEEP              @ turn off SLEEP mode
                    ldr             r0, [r3, #CAN_MCR_OFFSET]
                    bics            r0, r0, r1
                    str             r0, [r3, #CAN_MCR_OFFSET]
                    movs            r1, #CAN_MSR_SLAK
0:
                    ldr             r0, [r3, #CAN_MSR_OFFSET]       @ wait into bcCAN has left sleep mode
                    tst             r0, r1
                    beq             0b

                    ldr             r0, [r3, #CAN_MCR_OFFSET]       @ enter CAN init mode
                    movs            r1, #CAN_MCR_INRQ
                    orrs            r0, r0, r1
                    str             r0, [r3, #CAN_MCR_OFFSET]
                    movs            r1, #CAN_MSR_INAK
0:
                    ldr             r0, [r3, #CAN_MSR_OFFSET]       @ wait into bcCAN has entered init mode
                    tst             r0, r1
                    beq             0b

                    ldr             r0, [r3, #CAN_BTR_OFFSET]       @ set baud rate and loopback mode
                    ldr             r1, = #(CAN_BTR_LBKM | CAN_BTR_BRP | CAN_BTR_TS1 | CAN_BTR_TS2 | CAN_BTR_SJW)
                    bics            r0, r0, r1
                    ldr             r1, =  #((ACB_CAN_SJW << 24) | (ACB_CAN_BS2 << 20) | (ACB_CAN_BS1 << 16) | ACB_CAN_BRP)
                    orrs            r0, r0, r1
                    str             r0, [r3, #CAN_BTR_OFFSET]
                    bx              lr

@ void Can_setupFilter(uint32 identifier, uint32 mask)
@   sets the message filter based on the supplied identifier and mask
@   requires the CAN module to be in initalise mode

Can_setupFilter:
                    push            {r4, lr}
                    ldr             r3, = #_CAN_FMR
                    ldr             r4, [r3]                        @ set up the filters
                    ldr             r2, = #CAN_FMR_FINIT
                    orrs            r4, r4, r2
                    str             r4, [r3]

                    movs            r4, #CAN_FS1R_FSC0              @ set filter to 32 bit
                    str             r4, [r3, #(CAN_FS1R_OFFSET-CAN_FMR_OFFSET)]

                    ldr             r3, = #_CAN_sFilterRegister
                    str             r0, [r3]
                    str             r1, [r3, #4]

                    ldr             r3, = #_CAN_FMR
                    movs            r0, #CAN_FA1R_FACT0             @ activate filter 0
                    str             r0, [r3, #(CAN_FA1R_OFFSET-CAN_FMR_OFFSET)]
                    ldr             r0, [r3]                        @ leave filter mode
                    movs            r1, #CAN_FMR_FINIT
                    bics            r0, r0, r1
                    str             r0, [r3]
                    pop             {r4, pc}

    private_function(Can_completeSetup)

@ void Can_completeSetup()
@   complete the initialisation the CAN peripheral, leaving it in ready mode
@   enable CAN interrupts (TODO)

Can_completeSetup:
                    ldr             r3, = #CAN_BASE
                    ldr             r0, [r3, #CAN_MCR_OFFSET]       @ leave CAN init mode
                    movs            r1, #CAN_MCR_INRQ
                    bics            r0, r0, r1
                    str             r0, [r3, #CAN_MCR_OFFSET]
                    movs            r1, #CAN_MSR_INAK
1:
                    ldr             r0, [r3, #CAN_MSR_OFFSET]       @ wait into bcCAN has entered init mode
                    tst             r0, r1
                    bne             1b
                                                                    @ set up CAN interrupts, for errors and FIFO overrun
@                   ldr             r0, = # (CAN_IER_ERRIE | CAN_IER_FOVIE0)
@                   str             r0, [r3, #CAN_IER_OFFSET]

@                   ldr             r3, = #NVIC_ISER                @ enable interrupts through the NVIC
@                   ldr             r0, = #1<<CEC_CAN_IRQn          @ 30 is position of CAN interrupt
@                   ldr             r1, [r0]
@                   orrs            r0, r0, r1
@                   str             r0, [r3]

                    bx              lr

    private_function(Can_getNextFreeTxBuffer)

@ uint32* bootldr_canGetNextFreeTxBuffer()
@   find the next free transmit buffer. returns 0 if no free buffer, otherwise it returns a pointer to the free
@   buffer (CAN_TIxR)

_CAN_sTxMailBox0 = _CAN_sTxMailBox
_CAN_sTxMailBox1 = _CAN_sTxMailBox + CAN_TxMailBox_TDHR_OFFSET + 4
_CAN_sTxMailBox2 = _CAN_sTxMailBox + 2 * (CAN_TxMailBox_TDHR_OFFSET + 4)

Can_getNextFreeTxBuffer:
                    ldr             r0, = #CAN_TSR_TME              @ get which buffer is free from the CAN status
                    ldr             r1, = #CAN_BASE                 @ register
                    ldr             r2, [r1, #CAN_TSR_OFFSET]
                    ands            r0, r0, r2
                    beq             3f                              @ zero if all transmit boxes are full
                    ldr             r2, = #CAN_TSR_TME0
                    tst             r0, r2                          @ check for transmit box 0?
                    beq             1f
                    ldr             r0, =#_CAN_sTxMailBox0
                    bx              lr
1:
                    ldr             r2, = #CAN_TSR_TME1
                    tst             r0, r2                          @ check for transmit box 1?
                    beq             2f
                    ldr             r0, =#_CAN_sTxMailBox1
                    bx              lr
2:
                    ldr             r0, =#_CAN_sTxMailBox2          @ transmit box 2 must be free
                    bx              lr
3:
                    movs            r0, #0                          @ no buffer free, return 0
                    bx              lr

#endif

    .end

