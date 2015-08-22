/*
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, version 3 of the License, as set out
 *  at <http:;www.gnu.org/licenses/>.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *  See the GNU General Public License for more details.
 *
 *  As set out in the GNU General Public License, you must retain and acknowledge
 *  the statements above relating to copyright and licensing. You must also
 *  state clearly any modifications made.  Please therefore retain this header
 *  and add documentation of any changes you make. If you distribute a changed
 *  version, you must make those changes publicly available.
 *
 *  The GNU license requires that if you distribute this software, changed or
 *  unchanged, or software which includes code from this software, including
 *  the supply of hardware that incorporates this software, you MUST either
 *  include the source code or a link to a location where you make the source
 *  publicly available. The best way to make your changes publicly available is
 *  via the MERG online resources.  See <www.merg.co.uk>
 */

/*
 * This is a clean up/copy of cbusdefs8j.h using generic comment format to make it compatible with as many GNU AS
 * versions as possible (i.e. ARM uses @ for single line comments, where's PIC24/dsPIC33 uses ;)
 */

/*
 * cbusdefs8j.inc
 */

/*
 * Manufacturers
 */

MANU_MERG           = 165                                           /* http://www.merg.co.uk */
MANU_ROCRAIL        = 70                                            /* http://www.rocrail.net */
MANU_SPECTRUM       = 80                                            /* http://animatedmodeler.com  (Spectrum Engineering) */
MANU_THENW1GROUP    = 7                                             /* M772 mod 255 */

/*
 * MERG Module types
 */

MTYP_SLIM           = 0                                             /* default type code for SLiM nodes */
MTYP_CANACC4        = 1                                             /* Solenoid point driver */
MTYP_CANACC5        = 2                                             /* Motorised point driver */
MTYP_CANACC8        = 3                                             /* 8 digital outputs */
MTYP_CANACE3        = 4                                             /* Control panel switch/button encoder */
MTYP_CANACE8C       = 5                                             /* 8 digital inputs */
MTYP_CANLED         = 6                                             /* 64 led driver */
MTYP_CANLED64       = 7                                             /* 64 led driver (multi leds per event) */
MTYP_CANACC4_2      = 8                                             /* 12v version of CANACC4 */
MTYP_CANCAB         = 9                                             /* CANCAB hand throttle */
MTYP_CANCMD         = 10                                            /* CANCMD command station */
MTYP_CANSERVO       = 11                                            /* 8 servo driver (on canacc8 or similar hardware) */
MTYP_CANBC          = 12                                            /* BC1a command station */
MTYP_CANRPI         = 13                                            /* RPI and RFID interface */
MTYP_CANTTCA        = 14                                            /* Turntable controller (turntable end) */
MTYP_CANTTCB        = 15                                            /* Turntable controller (control panel end) */
MTYP_CANHS          = 16                                            /* Handset controller for old BC1a type handsets */
MTYP_CANTOTI        = 17                                            /* Track occupancy detector */

MTYP_CAN8I8O        = 18                                            /* 8 input/8 output */
MTYP_CANSERVO8C     = 19                                            /* Combi version of CANSERVO */
MTYP_CANRFID        = 20                                            /* RFID module */
MTYP_CANTC4         = 21
MTYP_CANACE16C      = 22                                            /* 16 input version of CANACE8C */
MTYP_CANIO8         = 23
MTYP_CANSNDx        = 24
MTYP_CANETHER       = 25                                            /* Ethernet interface module */
MTYP_CANSIG64       = 26                                            /* CANSIG firmware for CANLED64 hardware */
MTYP_CANSIG8        = 27                                            /* CANSIG firmware for CANACC8 hardware */
MTYP_CANCOND8C      = 28                                            /* CAN conditional module */
MTYP_CANPAN         = 29                                            /* Combines 32 switches and 32 LEDs */
MTYP_CANACE3C       = 30                                            /* Enhanced version of CANACE3 */
MTYP_CANPanel       = 31                                            /* Combines 64 switches with 64 LEDs */
MTYP_CANMIO         = 32                                            /* Multiple IO module */
MTYP_CANACE8MIO     = 33                                            /* Multiple IO module emulating ACE8C */
MTYP_CANSOL         = 34                                            /* Solenoid driver module */
MTYP_CANBIP         = 35                                            /* Bipolar IO module with additional 8 I/O pins */
MTYP_CANCDU         = 36                                            /* Solenoid driver module with additional 6 I/O pins */
MTYP_CANACC4CDU     = 37                                            /* CANACC4 firmware modified for CANCDU */
MTYP_CANWiBase      = 38                                            /* CAN to MiWi base station */
MTYP_WiCAB          = 39                                            /* Wireless cab using MiWi protocol */
MTYP_CANWiFi        = 40                                            /* CAN to WiFi connection with Withrottle to CBUS protocol conversion */
MTYP_CANFTT         = 41                                            /* Turntable controller configured using FLiM */

MTYP_CAN_SW         = 0xFF                                          /* Software nodes */
MTYP_EMPTY          = 0xFE                                          /* Empty module, bootloader only */
MTYP_CANUSB         = 0xFD                                          /* Reserved for future use */

/*
 * Rocrail Module types
 */

MTYP_CANGC1         = 1                                             /* RS232 PC interface */
MTYP_CANGC2         = 2                                             /* 16 I/O */
MTYP_CANGC3         = 3                                             /* Command station (derived from cancmd) */
MTYP_CANGC4         = 4                                             /* 8 channel RFID reader */
MTYP_CANGC5         = 5                                             /* Cab for fixed panels (derived from cancab) */
MTYP_CANGC6         = 6                                             /* 4 channel servo controller */
MTYP_CANGC7         = 7                                             /* Fast clock module */
MTYP_CANGC1e        = 11                                            /* CAN<->Ethernet interface */

/*
 * Spectrum Engineering Animated Modeller module types
 */

MTYP_AMCTRLR        = 1                                             /* Animation controller (firmware derived from cancmd) */
MTYP_DUALCAB        = 2                                             /* Dual cab based on cancab */

/*
 * The NW1 Group Module types
 */

MTYP_ACB_4TC        = 0x80                                          /* 4 servo/relay and 8 detect inputs */
MTYP_ACB_8IO        = 0x81                                          /* 8 input/output */
MTYP_ACB_8IOMV      = 0x82                                          /* 8 input/output multi-voltage */
MTYP_ACB_16IO       = 0x83                                          /* 16 input/output */
MTYP_ACB_16LED      = 0x84                                          /* 16 LED output */
MTYP_ACB_MATRIX     = 0x85                                          /* 10x7 LED matrix output */
MTYP_ACB_RF         = 0x86                                          /* CAN to Wifi (MiWI) bridge */
MTYP_ACB_BRIDGE     = 0x87                                          /* CAN to CAN bridge */
MTYP_ACB_ETH        = 0x88                                          /* CAN to Ethernet bridge */

/*
 * Opcodes removed from this document
 */

/*
 * Modes for STMOD
 */

TMOD_SPD_MASK       = 3
TMOD_SPD_128        = 0
TMOD_SPD_14         = 1
TMOD_SPD_28I        = 2
TMOD_SPD_28         = 3

/*
 * Error codes for OPC_ERR
 */

ERR_LOCO_STACK_FULL     = 1
ERR_LOCO_ADDR_TAKEN     = 2
ERR_SESSION_NOT_PRESENT = 3
ERR_CONSIST_EMPTY       = 4
ERR_LOCO_NOT_FOUND      = 5
ERR_CMD_RX_BUF_OFLOW    = 6
ERR_INVALID_REQUEST     = 7
ERR_SESSION_CANCELLED   = 8

/*
 * Status codes for OPC_SSTAT
 */

SSTAT_NO_ACK        = 1
SSTAT_OVLD          = 2
SSTAT_WR_ACK        = 3
SSTAT_BUSY          = 4
SSTAT_CV_ERROR      = 5

/*
 * Error codes for OPC_CMDERR
 *  CMDERR_NO_EV (5) and CMDERR_INV_EN_IDX(8) now reserved
 */

CMDERR_INV_CMD         = 1
CMDERR_NOT_LRN         = 2
CMDERR_NOT_SETUP       = 3
CMDERR_TOO_MANY_EVENTS = 4
CMDERR_INV_EV_IDX      = 6
CMDERR_INVALID_EVENT   = 7
CMDERR_INV_PARAM_IDX   = 9
CMDERR_INV_NV_IDX      = 10
CMDERR_INV_EV_VALUE    = 11
CMDERR_INV_NV_VALUE    = 12

/*
 * Parameter index numbers (readable by OPC_RQNPN, returned in OPC_PARAN)
 * Index numbers count from 1, subtract 1 for offset into parameter block
 * Note that RQNPN with index 0 returns the parameter count
 */

PAR_MANU            = 1                                             /* Manufacturer id */
PAR_MINVER          = 2                                             /* Minor version letter */
PAR_MTYP            = 3                                             /* Module type code */
PAR_EVTNUM          = 4                                             /* Number of events supported */
PAR_EVNUM           = 5                                             /* Event variables per event */
PAR_NVNUM           = 6                                             /* Number of Node variables */
PAR_MAJVER          = 7                                             /* Major version number */
PAR_FLAGS           = 8                                             /* Node flags */
PAR_CPUID           = 9                                             /* Processor type */
PAR_BUSTYPE         = 10                                            /* Bus type */
PAR_LOAD            = 11                                            /* load address, 4 bytes */
PAR_CPUMID          = 15                                            /* CPU manufacturer's id as read from the chip
                                                                       config space, 4 bytes (note - read from cpu at
                                                                       runtime, so not included in checksum) */
PAR_CPUMAN          = 19                                            /* CPU manufacturer code */
PAR_BETA            = 20                                            /* Beta revision (numeric), or 0 if release */

/*
 * Offsets to other values stored at the top of the parameter block.
 * These are not returned by opcode PARAN, but are present in the hex
 * file for FCU.
 */

PAR_COUNT           = 0x18                                          /* Number of parameters implemented */
PAR_NAME            = 0x1A                                          /* 4 byte Address of Module type name, up to 8
                                                                       characters null terminated */
PAR_CKSUM           = 0x1E                                          /* Checksum word at end of parameters */

/*
 * Flags in PAR_FLAGS
 */

PF_NOEVENTS         = 0
PF_CONSUMER         = 1
PF_PRODUCER         = 2
PF_COMBI            = 3
PF_FLiM             = 4
PF_BOOT             = 8

/*
 * BUS type that module is connected to
 */

PB_CAN              = 1
PB_ETH              = 2
PB_MIWI             = 3

/*
 * Processor type codes (identifies to FCU for bootload compatiblity)
 * Version d changed (P18F25K80-P18F66K80) to align with constants. inc and FCU usage
 */

P18F2480            = 1
P18F4480            = 2
P18F2580            = 3
P18F4580            = 4
P18F2585            = 5
P18F4585            = 6
P18F2680            = 7
P18F4680            = 8
P18F2682            = 9
P18F4682            = 10
P18F2685            = 11
P18F4685            = 12

P18F25K80           = 13
P18F45K80           = 14
P18F26K80           = 15
P18F46K80           = 16
P18F65K80           = 17
P18F66K80           = 18

P32MX534F064        = 30
P32MX564F064        = 31
P32MX564F128        = 32
P32MX575F256        = 33
P32MX575F512        = 34
P32MX764F128        = 35
P32MX775F256        = 36
P32MX775F512        = 37
P32MX795F512        = 38

STM32F042xF6        = 0x80

/*
 * Processor manufacturer codes
 */

CPUM_MICROCHIP      = 1
CPUM_ATMEL          = 2
CPUM_STMICRO        = 0x80
