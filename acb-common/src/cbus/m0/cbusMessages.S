/*
 * Copyright (c) 2015 The NW1 Group
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */
	
@ Generated File (2015-08-06T08:11:02.073+01:00) based on version 7.08 2012-08-20
@ Revision History
		
@ Revision 8a	2012-08-14	Richard Tearle	Based on CBUS 4.0 Specification Rev. 8a, dated 18/02/2012
@ Revision 8c	2012-08-20	Richard Tearle	Added OpCodes ENUM and CANID.

#include "acb_common.inc"

	module(cbus_messages)
		
	private_function(CBUS_vectorTable)

CBUS_vectorTable:													@ Note: + 1 to ensure the processor stays in thumb mode
	.word			CBUS_onACK + 1									@ General Acknowledgement (0x00)
	.word			CBUS_onNAK + 1									@ General No Ack (0x01)
	.word			CBUS_onHLT + 1									@ Bus Halt (0x02)
	.word			CBUS_onBON + 1									@ Bus ON (0x03)
	.word			CBUS_onTOF + 1									@ Track OFF (0x04)
	.word			CBUS_onTON + 1									@ Track ON (TON) (0x05)
	.word			CBUS_onESTOP + 1								@ Track Stopped (0x06)
	.word			CBUS_onARST + 1									@ System Reset (0x07)
	.word			CBUS_onRTOF + 1									@ Request Track OFF (0x08)
	.word			CBUS_onRTON + 1									@ Request Track ON (0x09)
	.word			CBUS_onRESTP + 1								@ Request Emergency Stop ALL (0x0A)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0x0B)
	.word			CBUS_onRSTAT + 1								@ Request node Status (0x0C)
	.word			CBUS_onQNN + 1									@ Query node number (0x0D)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0x0E)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0x0F)
	.word			CBUS_onRQNP + 1									@ Request node parameters (0x10)
	.word			CBUS_onRQMN + 1									@ Request module name (0x11)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0x12)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0x13)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0x14)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0x15)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0x16)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0x17)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0x18)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0x19)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0x1A)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0x1B)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0x1C)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0x1D)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0x1E)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0x1F)
	.word			CBUS_onSTAT + 1									@ Command Station status report  (0x20)
	.word			CBUS_onKLOC + 1									@ Release Engine (0x21)
	.word			CBUS_onQLOC + 1									@ Query Engine (0x22)
	.word			CBUS_onDKEEP + 1								@ Session keep alive (0x23)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0x24)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0x25)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0x26)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0x27)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0x28)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0x29)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0x2A)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0x2B)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0x2C)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0x2D)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0x2E)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0x2F)
	.word			CBUS_onDBG1 + 1									@ Debug with one data byte (0x30)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0x31)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0x32)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0x33)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0x34)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0x35)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0x36)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0x37)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0x38)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0x39)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0x3A)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0x3B)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0x3C)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0x3D)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0x3E)
	.word			CBUS_onEXTC + 1									@ Extended OPC without data byte packets. (0x3F)
	.word			CBUS_onRLOC + 1									@ Request engine session (0x40)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0x41)
	.word			CBUS_onSNN + 1									@ Set Node Number (0x42)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0x43)
	.word			CBUS_onSTMOD + 1								@ Set CAB session mode (0x44)
	.word			CBUS_onPCON + 1									@ Consist Engine (0x45)
	.word			CBUS_onKCON + 1									@ Remove Engine From Consist (0x46)
	.word			CBUS_onDSPD + 1									@ Set Engine Speed And Direction (0x47)
	.word			CBUS_onDFLG + 1									@ Set Engine Flags (0x48)
	.word			CBUS_onDFNON + 1								@ Set Engine function on (0x49)
	.word			CBUS_onDFNOF + 1								@ Set Engine function off (0x4A)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0x4B)
	.word			CBUS_onSSTAT + 1								@ Service Mode Status (0x4C)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0x4D)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0x4E)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0x4F)
	.word			CBUS_onRQNN + 1									@ Request node number (0x50)
	.word			CBUS_onNNREL + 1								@ Node Number Release (0x51)
	.word			CBUS_onNNACK + 1								@ Node number acknowledge (0x52)
	.word			CBUS_onNNLRN + 1								@ Set node into learn mode (0x53)
	.word			CBUS_onNNULN + 1								@ Release node from learn mode (0x54)
	.word			CBUS_onNNCLR + 1								@ Clear All Events from a node (0x55)
	.word			CBUS_onNNEVN + 1								@ Read number of events available in a node  (0x56)
	.word			CBUS_onNERD + 1									@ Read back all stored events in a node (0x57)
	.word			CBUS_onRQEVN + 1								@ Request to read number of stored events (0x58)
	.word			CBUS_onWRACK + 1								@ Write acknowledge. (0x59)
	.word			CBUS_onRQDAT + 1								@ Request node data event (0x5A)
	.word			CBUS_onRQDDS + 1								@ Request device data - short mode (0x5B)
	.word			CBUS_onBOOTM + 1								@ Put node into bootload mode. (0x5C)
	.word			CBUS_onENUM + 1									@ Force a self enumeration cycle for use with CAN (0x5D)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0x5E)
	.word			CBUS_onEXTC1 + 1								@ Extended OPC with 1 data byte packets. (0x5F)
	.word			CBUS_onDFUN + 1									@ Set Engine functions (0x60)
	.word			CBUS_onGLOC + 1									@ Get engine session (0x61)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0x62)
	.word			CBUS_onERR + 1									@ Command Station Error report (0x63)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0x64)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0x65)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0x66)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0x67)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0x68)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0x69)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0x6A)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0x6B)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0x6C)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0x6D)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0x6E)
	.word			CBUS_onCMDERR + 1								@ Error messages from nodes during configuration (0x6F)
	.word			CBUS_onEVNLF + 1								@ Event Space Reply (0x70)
	.word			CBUS_onNVRD + 1									@ Request Node Variable (0x71)
	.word			CBUS_onNENRD + 1								@ Request read of stored events by event index (0x72)
	.word			CBUS_onRQNPN + 1								@ Request read of a node parameter by index. (0x73)
	.word			CBUS_onNUMEV + 1								@ Number of events stored in node (0x74)
	.word			CBUS_onCANID + 1								@ Set a CAN_ID in existing FLiM node (0x75)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0x76)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0x77)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0x78)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0x79)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0x7A)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0x7B)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0x7C)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0x7D)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0x7E)
	.word			CBUS_onEXTC2 + 1								@ Extended OPC with 2 data byte packets. (0x7F)
	.word			CBUS_onRDCC3 + 1								@ Request 3-byte DCC Packet (0x80)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0x81)
	.word			CBUS_onWCVO + 1									@  Write CV in Ops mode (0x82)
	.word			CBUS_onWCVB + 1									@ Write CV (bit) in OPS mode. (0x83)
	.word			CBUS_onQCVS + 1									@ Read CV (0x84)
	.word			CBUS_onPCVS + 1									@ Report CV (0x85)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0x86)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0x87)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0x88)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0x89)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0x8A)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0x8B)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0x8C)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0x8D)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0x8E)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0x8F)
	.word			CBUS_onACON + 1									@ Accessory ON (0x90)
	.word			CBUS_onACOF + 1									@ Accessory OFF (0x91)
	.word			CBUS_onAREQ + 1									@ Accessory Request Event (0x92)
	.word			CBUS_onARON + 1									@ Accessory On Response Event (0x93)
	.word			CBUS_onAROF + 1									@ Accessory Off Response Event (0x94)
	.word			CBUS_onEVULN + 1								@ Unlearn an event In learn mode (0x95)
	.word			CBUS_onNVSET + 1								@ Set A Node Variable Value (0x96)
	.word			CBUS_onNVANS + 1								@ Returned Node Variable Value (0x97)
	.word			CBUS_onASON + 1									@ Accessory Short ON (0x98)
	.word			CBUS_onASOF + 1									@ Accessory Short OFF (0x99)
	.word			CBUS_onASRQ + 1									@ Accessory Request Event (0x9A)
	.word			CBUS_onPARAN + 1								@ Response to request for individual node parameter (0x9B)
	.word			CBUS_onREVAL + 1								@ Request for read of an event variable (0x9C)
	.word			CBUS_onARSON + 1								@ Accessory Short Response Event (0x9D)
	.word			CBUS_onARSOF + 1								@ Accessory Short Response Event (0x9E)
	.word			CBUS_onEXTC3 + 1								@ Extended OPC with 3 data byte packets. (0x9F)
	.word			CBUS_onRDCC4 + 1								@ Request 4-byte DCC Packet (0xA0)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0xA1)
	.word			CBUS_onWCVS + 1									@ Write CV in Service mode (0xA2)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0xA3)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0xA4)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0xA5)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0xA6)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0xA7)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0xA8)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0xA9)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0xAA)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0xAB)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0xAC)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0xAD)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0xAE)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0xAF)
	.word			CBUS_onACON1 + 1								@ Accessory ON Event With 1 Data (0xB0)
	.word			CBUS_onACOF1 + 1								@ Accessory Off Event With 1 Data (0xB1)
	.word			CBUS_onREQEV + 1								@ Request Event With 1 Data (0xB2)
	.word			CBUS_onARON1 + 1								@ Accessory Response Event (0xB3)
	.word			CBUS_onAROF1 + 1								@ Accessory Response Event (0xB4)
	.word			CBUS_onNEVAL + 1								@ Response to request for read of EV value (0xB5)
	.word			CBUS_onPNN + 1									@ Response to Query Node (0xB6)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0xB7)
	.word			CBUS_onASON1 + 1								@ Accessory Short ON (0xB8)
	.word			CBUS_onASOF1 + 1								@ Accessory Short OFF (0xB9)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0xBA)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0xBB)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0xBC)
	.word			CBUS_onARSON1 + 1								@ Accessory Short Response Event (0xBD)
	.word			CBUS_onARSOF1 + 1								@ Accessory Short Response Event (0xBE)
	.word			CBUS_onEXTC4 + 1								@ Extended OPC with 4 data byte packets. (0xBF)
	.word			CBUS_onRDCC5 + 1								@ Request 5-byte DCC Packet (0xC0)
	.word			CBUS_onWCVOA + 1								@ Write CV (byte) in OPS mode by address (0xC1)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0xC2)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0xC3)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0xC4)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0xC5)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0xC6)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0xC7)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0xC8)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0xC9)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0xCA)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0xCB)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0xCC)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0xCD)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0xCE)
	.word			CBUS_onFCLK + 1									@ Fast Clock (0xCF)
	.word			CBUS_onACON2 + 1								@ Accessory ON Event With 2 data bytes (0xD0)
	.word			CBUS_onACOF2 + 1								@ Accessory OFF Event With 2 Data (0xD1)
	.word			CBUS_onEVLRN + 1								@ Teach an event in learn mode. (0xD2)
	.word			CBUS_onEVANS + 1								@ Response to a request for an EV value in a node in learn mode (0xD3)
	.word			CBUS_onARON2 + 1								@ Accessory Response Event (0xD4)
	.word			CBUS_onAROF2 + 1								@ Accessory Response OFF Event (0xD5)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0xD6)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0xD7)
	.word			CBUS_onASON2 + 1								@ Accessory Short ON (0xD8)
	.word			CBUS_onASOF2 + 1								@ Accessory Short OFF (0xD9)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0xDA)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0xDB)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0xDC)
	.word			CBUS_onARSON2 + 1								@ Accessory Short Response Event (0xDD)
	.word			CBUS_onARSOF2 + 1								@ Accessory Short Response Event (0xDE)
	.word			CBUS_onEXTC5 + 1								@ Extended OPC with 5 data bytes (0xDF)
	.word			CBUS_onRDCC6 + 1								@ Request 6-byte DCC Packet (0xE0)
	.word			CBUS_onPLOC + 1									@ Engine report (0xE1)
	.word			CBUS_onNAME + 1									@ Response to request for node name string (0xE2)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0xE3)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0xE4)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0xE5)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0xE6)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0xE7)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0xE8)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0xE9)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0xEA)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0xEB)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0xEC)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0xED)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0xEE)
	.word			CBUS_onPARAMS + 1								@ Response to request for node parameters (0xEF)
	.word			CBUS_onACON3 + 1								@ Accessory On Event With 3 Data (0xF0)
	.word			CBUS_onACOF3 + 1								@ Accessory Off Event With 3 Data (0xF1)
	.word			CBUS_onENRSP + 1								@ Response to request to read node events (0xF2)
	.word			CBUS_onARON3 + 1								@ Response Event With 3 Data (0xF3)
	.word			CBUS_onAROF3 + 1								@ Accessory Response Event (0xF4)
	.word			CBUS_onEVLRNI + 1								@ Teach an event in learn mode using event indexing (0xF5)
	.word			CBUS_onACDAT + 1								@ Accessory node data event (0xF6)
	.word			CBUS_onARDAT + 1								@ Accessory node data Response (0xF7)
	.word			CBUS_onASON3 + 1								@ Accessory Short ON (0xF8)
	.word			CBUS_onASOF3 + 1								@ Accessory Short OFF (0xF9)
	.word			CBUS_onDDES + 1									@ Device data event (short mode) (0xFA)
	.word			CBUS_onDDRS + 1									@ Device data response (short mode) (0xFB)
	.word			CBUS_onRESERVED + 1								@ Reserved for future use (0xFC)
	.word			CBUS_onARSON3 + 1								@ Accessory Short Response Event (0xFD)
	.word			CBUS_onARSOF3 + 1								@ Accessory Short Response Event (0xFE)
	.word			CBUS_onEXTC6 + 1								@ Extended op-code with 6 data bytes (0xFF)

@ provide weak aliases for all the message handlers
		
    .extern			CBUS_onACDAT
    .weak 			CBUS_onACDAT
  	.thumb_set 		CBUS_onACDAT, CBUS_defaultMessageHandler
    .extern			CBUS_onACK
    .weak 			CBUS_onACK
  	.thumb_set 		CBUS_onACK, CBUS_defaultMessageHandler
    .extern			CBUS_onACOF
    .weak 			CBUS_onACOF
  	.thumb_set 		CBUS_onACOF, CBUS_defaultMessageHandler
    .extern			CBUS_onACOF1
    .weak 			CBUS_onACOF1
  	.thumb_set 		CBUS_onACOF1, CBUS_defaultMessageHandler
    .extern			CBUS_onACOF2
    .weak 			CBUS_onACOF2
  	.thumb_set 		CBUS_onACOF2, CBUS_defaultMessageHandler
    .extern			CBUS_onACOF3
    .weak 			CBUS_onACOF3
  	.thumb_set 		CBUS_onACOF3, CBUS_defaultMessageHandler
    .extern			CBUS_onACON
    .weak 			CBUS_onACON
  	.thumb_set 		CBUS_onACON, CBUS_defaultMessageHandler
    .extern			CBUS_onACON1
    .weak 			CBUS_onACON1
  	.thumb_set 		CBUS_onACON1, CBUS_defaultMessageHandler
    .extern			CBUS_onACON2
    .weak 			CBUS_onACON2
  	.thumb_set 		CBUS_onACON2, CBUS_defaultMessageHandler
    .extern			CBUS_onACON3
    .weak 			CBUS_onACON3
  	.thumb_set 		CBUS_onACON3, CBUS_defaultMessageHandler
    .extern			CBUS_onARDAT
    .weak 			CBUS_onARDAT
  	.thumb_set 		CBUS_onARDAT, CBUS_defaultMessageHandler
    .extern			CBUS_onAREQ
    .weak 			CBUS_onAREQ
  	.thumb_set 		CBUS_onAREQ, CBUS_defaultMessageHandler
    .extern			CBUS_onAROF
    .weak 			CBUS_onAROF
  	.thumb_set 		CBUS_onAROF, CBUS_defaultMessageHandler
    .extern			CBUS_onAROF1
    .weak 			CBUS_onAROF1
  	.thumb_set 		CBUS_onAROF1, CBUS_defaultMessageHandler
    .extern			CBUS_onAROF2
    .weak 			CBUS_onAROF2
  	.thumb_set 		CBUS_onAROF2, CBUS_defaultMessageHandler
    .extern			CBUS_onAROF3
    .weak 			CBUS_onAROF3
  	.thumb_set 		CBUS_onAROF3, CBUS_defaultMessageHandler
    .extern			CBUS_onARON
    .weak 			CBUS_onARON
  	.thumb_set 		CBUS_onARON, CBUS_defaultMessageHandler
    .extern			CBUS_onARON1
    .weak 			CBUS_onARON1
  	.thumb_set 		CBUS_onARON1, CBUS_defaultMessageHandler
    .extern			CBUS_onARON2
    .weak 			CBUS_onARON2
  	.thumb_set 		CBUS_onARON2, CBUS_defaultMessageHandler
    .extern			CBUS_onARON3
    .weak 			CBUS_onARON3
  	.thumb_set 		CBUS_onARON3, CBUS_defaultMessageHandler
    .extern			CBUS_onARSOF
    .weak 			CBUS_onARSOF
  	.thumb_set 		CBUS_onARSOF, CBUS_defaultMessageHandler
    .extern			CBUS_onARSOF1
    .weak 			CBUS_onARSOF1
  	.thumb_set 		CBUS_onARSOF1, CBUS_defaultMessageHandler
    .extern			CBUS_onARSOF2
    .weak 			CBUS_onARSOF2
  	.thumb_set 		CBUS_onARSOF2, CBUS_defaultMessageHandler
    .extern			CBUS_onARSOF3
    .weak 			CBUS_onARSOF3
  	.thumb_set 		CBUS_onARSOF3, CBUS_defaultMessageHandler
    .extern			CBUS_onARSON
    .weak 			CBUS_onARSON
  	.thumb_set 		CBUS_onARSON, CBUS_defaultMessageHandler
    .extern			CBUS_onARSON1
    .weak 			CBUS_onARSON1
  	.thumb_set 		CBUS_onARSON1, CBUS_defaultMessageHandler
    .extern			CBUS_onARSON2
    .weak 			CBUS_onARSON2
  	.thumb_set 		CBUS_onARSON2, CBUS_defaultMessageHandler
    .extern			CBUS_onARSON3
    .weak 			CBUS_onARSON3
  	.thumb_set 		CBUS_onARSON3, CBUS_defaultMessageHandler
    .extern			CBUS_onARST
    .weak 			CBUS_onARST
  	.thumb_set 		CBUS_onARST, CBUS_defaultMessageHandler
    .extern			CBUS_onASOF
    .weak 			CBUS_onASOF
  	.thumb_set 		CBUS_onASOF, CBUS_defaultMessageHandler
    .extern			CBUS_onASOF1
    .weak 			CBUS_onASOF1
  	.thumb_set 		CBUS_onASOF1, CBUS_defaultMessageHandler
    .extern			CBUS_onASOF2
    .weak 			CBUS_onASOF2
  	.thumb_set 		CBUS_onASOF2, CBUS_defaultMessageHandler
    .extern			CBUS_onASOF3
    .weak 			CBUS_onASOF3
  	.thumb_set 		CBUS_onASOF3, CBUS_defaultMessageHandler
    .extern			CBUS_onASON
    .weak 			CBUS_onASON
  	.thumb_set 		CBUS_onASON, CBUS_defaultMessageHandler
    .extern			CBUS_onASON1
    .weak 			CBUS_onASON1
  	.thumb_set 		CBUS_onASON1, CBUS_defaultMessageHandler
    .extern			CBUS_onASON2
    .weak 			CBUS_onASON2
  	.thumb_set 		CBUS_onASON2, CBUS_defaultMessageHandler
    .extern			CBUS_onASON3
    .weak 			CBUS_onASON3
  	.thumb_set 		CBUS_onASON3, CBUS_defaultMessageHandler
    .extern			CBUS_onASRQ
    .weak 			CBUS_onASRQ
  	.thumb_set 		CBUS_onASRQ, CBUS_defaultMessageHandler
    .extern			CBUS_onBON
    .weak 			CBUS_onBON
  	.thumb_set 		CBUS_onBON, CBUS_defaultMessageHandler
    .extern			CBUS_onBOOTM
    .weak 			CBUS_onBOOTM
  	.thumb_set 		CBUS_onBOOTM, CBUS_defaultMessageHandler
    .extern			CBUS_onCANID
    .weak 			CBUS_onCANID
  	.thumb_set 		CBUS_onCANID, CBUS_defaultMessageHandler
    .extern			CBUS_onCMDERR
    .weak 			CBUS_onCMDERR
  	.thumb_set 		CBUS_onCMDERR, CBUS_defaultMessageHandler
    .extern			CBUS_onDBG1
    .weak 			CBUS_onDBG1
  	.thumb_set 		CBUS_onDBG1, CBUS_defaultMessageHandler
    .extern			CBUS_onDDES
    .weak 			CBUS_onDDES
  	.thumb_set 		CBUS_onDDES, CBUS_defaultMessageHandler
    .extern			CBUS_onDDRS
    .weak 			CBUS_onDDRS
  	.thumb_set 		CBUS_onDDRS, CBUS_defaultMessageHandler
    .extern			CBUS_onDFLG
    .weak 			CBUS_onDFLG
  	.thumb_set 		CBUS_onDFLG, CBUS_defaultMessageHandler
    .extern			CBUS_onDFNOF
    .weak 			CBUS_onDFNOF
  	.thumb_set 		CBUS_onDFNOF, CBUS_defaultMessageHandler
    .extern			CBUS_onDFNON
    .weak 			CBUS_onDFNON
  	.thumb_set 		CBUS_onDFNON, CBUS_defaultMessageHandler
    .extern			CBUS_onDFUN
    .weak 			CBUS_onDFUN
  	.thumb_set 		CBUS_onDFUN, CBUS_defaultMessageHandler
    .extern			CBUS_onDKEEP
    .weak 			CBUS_onDKEEP
  	.thumb_set 		CBUS_onDKEEP, CBUS_defaultMessageHandler
    .extern			CBUS_onDSPD
    .weak 			CBUS_onDSPD
  	.thumb_set 		CBUS_onDSPD, CBUS_defaultMessageHandler
    .extern			CBUS_onENRSP
    .weak 			CBUS_onENRSP
  	.thumb_set 		CBUS_onENRSP, CBUS_defaultMessageHandler
    .extern			CBUS_onENUM
    .weak 			CBUS_onENUM
  	.thumb_set 		CBUS_onENUM, CBUS_defaultMessageHandler
    .extern			CBUS_onERR
    .weak 			CBUS_onERR
  	.thumb_set 		CBUS_onERR, CBUS_defaultMessageHandler
    .extern			CBUS_onESTOP
    .weak 			CBUS_onESTOP
  	.thumb_set 		CBUS_onESTOP, CBUS_defaultMessageHandler
    .extern			CBUS_onEVANS
    .weak 			CBUS_onEVANS
  	.thumb_set 		CBUS_onEVANS, CBUS_defaultMessageHandler
    .extern			CBUS_onEVLRN
    .weak 			CBUS_onEVLRN
  	.thumb_set 		CBUS_onEVLRN, CBUS_defaultMessageHandler
    .extern			CBUS_onEVLRNI
    .weak 			CBUS_onEVLRNI
  	.thumb_set 		CBUS_onEVLRNI, CBUS_defaultMessageHandler
    .extern			CBUS_onEVNLF
    .weak 			CBUS_onEVNLF
  	.thumb_set 		CBUS_onEVNLF, CBUS_defaultMessageHandler
    .extern			CBUS_onEVULN
    .weak 			CBUS_onEVULN
  	.thumb_set 		CBUS_onEVULN, CBUS_defaultMessageHandler
    .extern			CBUS_onEXTC
    .weak 			CBUS_onEXTC
  	.thumb_set 		CBUS_onEXTC, CBUS_defaultMessageHandler
    .extern			CBUS_onEXTC1
    .weak 			CBUS_onEXTC1
  	.thumb_set 		CBUS_onEXTC1, CBUS_defaultMessageHandler
    .extern			CBUS_onEXTC2
    .weak 			CBUS_onEXTC2
  	.thumb_set 		CBUS_onEXTC2, CBUS_defaultMessageHandler
    .extern			CBUS_onEXTC3
    .weak 			CBUS_onEXTC3
  	.thumb_set 		CBUS_onEXTC3, CBUS_defaultMessageHandler
    .extern			CBUS_onEXTC4
    .weak 			CBUS_onEXTC4
  	.thumb_set 		CBUS_onEXTC4, CBUS_defaultMessageHandler
    .extern			CBUS_onEXTC5
    .weak 			CBUS_onEXTC5
  	.thumb_set 		CBUS_onEXTC5, CBUS_defaultMessageHandler
    .extern			CBUS_onEXTC6
    .weak 			CBUS_onEXTC6
  	.thumb_set 		CBUS_onEXTC6, CBUS_defaultMessageHandler
    .extern			CBUS_onFCLK
    .weak 			CBUS_onFCLK
  	.thumb_set 		CBUS_onFCLK, CBUS_defaultMessageHandler
    .extern			CBUS_onGLOC
    .weak 			CBUS_onGLOC
  	.thumb_set 		CBUS_onGLOC, CBUS_defaultMessageHandler
    .extern			CBUS_onHLT
    .weak 			CBUS_onHLT
  	.thumb_set 		CBUS_onHLT, CBUS_defaultMessageHandler
    .extern			CBUS_onKCON
    .weak 			CBUS_onKCON
  	.thumb_set 		CBUS_onKCON, CBUS_defaultMessageHandler
    .extern			CBUS_onKLOC
    .weak 			CBUS_onKLOC
  	.thumb_set 		CBUS_onKLOC, CBUS_defaultMessageHandler
    .extern			CBUS_onNAK
    .weak 			CBUS_onNAK
  	.thumb_set 		CBUS_onNAK, CBUS_defaultMessageHandler
    .extern			CBUS_onNAME
    .weak 			CBUS_onNAME
  	.thumb_set 		CBUS_onNAME, CBUS_defaultMessageHandler
    .extern			CBUS_onNENRD
    .weak 			CBUS_onNENRD
  	.thumb_set 		CBUS_onNENRD, CBUS_defaultMessageHandler
    .extern			CBUS_onNERD
    .weak 			CBUS_onNERD
  	.thumb_set 		CBUS_onNERD, CBUS_defaultMessageHandler
    .extern			CBUS_onNEVAL
    .weak 			CBUS_onNEVAL
  	.thumb_set 		CBUS_onNEVAL, CBUS_defaultMessageHandler
    .extern			CBUS_onNNACK
    .weak 			CBUS_onNNACK
  	.thumb_set 		CBUS_onNNACK, CBUS_defaultMessageHandler
    .extern			CBUS_onNNCLR
    .weak 			CBUS_onNNCLR
  	.thumb_set 		CBUS_onNNCLR, CBUS_defaultMessageHandler
    .extern			CBUS_onNNEVN
    .weak 			CBUS_onNNEVN
  	.thumb_set 		CBUS_onNNEVN, CBUS_defaultMessageHandler
    .extern			CBUS_onNNLRN
    .weak 			CBUS_onNNLRN
  	.thumb_set 		CBUS_onNNLRN, CBUS_defaultMessageHandler
    .extern			CBUS_onNNREL
    .weak 			CBUS_onNNREL
  	.thumb_set 		CBUS_onNNREL, CBUS_defaultMessageHandler
    .extern			CBUS_onNNULN
    .weak 			CBUS_onNNULN
  	.thumb_set 		CBUS_onNNULN, CBUS_defaultMessageHandler
    .extern			CBUS_onNUMEV
    .weak 			CBUS_onNUMEV
  	.thumb_set 		CBUS_onNUMEV, CBUS_defaultMessageHandler
    .extern			CBUS_onNVANS
    .weak 			CBUS_onNVANS
  	.thumb_set 		CBUS_onNVANS, CBUS_defaultMessageHandler
    .extern			CBUS_onNVRD
    .weak 			CBUS_onNVRD
  	.thumb_set 		CBUS_onNVRD, CBUS_defaultMessageHandler
    .extern			CBUS_onNVSET
    .weak 			CBUS_onNVSET
  	.thumb_set 		CBUS_onNVSET, CBUS_defaultMessageHandler
    .extern			CBUS_onPARAMS
    .weak 			CBUS_onPARAMS
  	.thumb_set 		CBUS_onPARAMS, CBUS_defaultMessageHandler
    .extern			CBUS_onPARAN
    .weak 			CBUS_onPARAN
  	.thumb_set 		CBUS_onPARAN, CBUS_defaultMessageHandler
    .extern			CBUS_onPCON
    .weak 			CBUS_onPCON
  	.thumb_set 		CBUS_onPCON, CBUS_defaultMessageHandler
    .extern			CBUS_onPCVS
    .weak 			CBUS_onPCVS
  	.thumb_set 		CBUS_onPCVS, CBUS_defaultMessageHandler
    .extern			CBUS_onPLOC
    .weak 			CBUS_onPLOC
  	.thumb_set 		CBUS_onPLOC, CBUS_defaultMessageHandler
    .extern			CBUS_onPNN
    .weak 			CBUS_onPNN
  	.thumb_set 		CBUS_onPNN, CBUS_defaultMessageHandler
    .extern			CBUS_onQCVS
    .weak 			CBUS_onQCVS
  	.thumb_set 		CBUS_onQCVS, CBUS_defaultMessageHandler
    .extern			CBUS_onQLOC
    .weak 			CBUS_onQLOC
  	.thumb_set 		CBUS_onQLOC, CBUS_defaultMessageHandler
    .extern			CBUS_onQNN
    .weak 			CBUS_onQNN
  	.thumb_set 		CBUS_onQNN, CBUS_defaultMessageHandler
    .extern			CBUS_onRDCC3
    .weak 			CBUS_onRDCC3
  	.thumb_set 		CBUS_onRDCC3, CBUS_defaultMessageHandler
    .extern			CBUS_onRDCC4
    .weak 			CBUS_onRDCC4
  	.thumb_set 		CBUS_onRDCC4, CBUS_defaultMessageHandler
    .extern			CBUS_onRDCC5
    .weak 			CBUS_onRDCC5
  	.thumb_set 		CBUS_onRDCC5, CBUS_defaultMessageHandler
    .extern			CBUS_onRDCC6
    .weak 			CBUS_onRDCC6
  	.thumb_set 		CBUS_onRDCC6, CBUS_defaultMessageHandler
    .extern			CBUS_onREQEV
    .weak 			CBUS_onREQEV
  	.thumb_set 		CBUS_onREQEV, CBUS_defaultMessageHandler
    .extern			CBUS_onRESERVED
    .weak 			CBUS_onRESERVED
  	.thumb_set 		CBUS_onRESERVED, CBUS_defaultMessageHandler
    .extern			CBUS_onRESTP
    .weak 			CBUS_onRESTP
  	.thumb_set 		CBUS_onRESTP, CBUS_defaultMessageHandler
    .extern			CBUS_onREVAL
    .weak 			CBUS_onREVAL
  	.thumb_set 		CBUS_onREVAL, CBUS_defaultMessageHandler
    .extern			CBUS_onRLOC
    .weak 			CBUS_onRLOC
  	.thumb_set 		CBUS_onRLOC, CBUS_defaultMessageHandler
    .extern			CBUS_onRQDAT
    .weak 			CBUS_onRQDAT
  	.thumb_set 		CBUS_onRQDAT, CBUS_defaultMessageHandler
    .extern			CBUS_onRQDDS
    .weak 			CBUS_onRQDDS
  	.thumb_set 		CBUS_onRQDDS, CBUS_defaultMessageHandler
    .extern			CBUS_onRQEVN
    .weak 			CBUS_onRQEVN
  	.thumb_set 		CBUS_onRQEVN, CBUS_defaultMessageHandler
    .extern			CBUS_onRQMN
    .weak 			CBUS_onRQMN
  	.thumb_set 		CBUS_onRQMN, CBUS_defaultMessageHandler
    .extern			CBUS_onRQNN
    .weak 			CBUS_onRQNN
  	.thumb_set 		CBUS_onRQNN, CBUS_defaultMessageHandler
    .extern			CBUS_onRQNP
    .weak 			CBUS_onRQNP
  	.thumb_set 		CBUS_onRQNP, CBUS_defaultMessageHandler
    .extern			CBUS_onRQNPN
    .weak 			CBUS_onRQNPN
  	.thumb_set 		CBUS_onRQNPN, CBUS_defaultMessageHandler
    .extern			CBUS_onRSTAT
    .weak 			CBUS_onRSTAT
  	.thumb_set 		CBUS_onRSTAT, CBUS_defaultMessageHandler
    .extern			CBUS_onRTOF
    .weak 			CBUS_onRTOF
  	.thumb_set 		CBUS_onRTOF, CBUS_defaultMessageHandler
    .extern			CBUS_onRTON
    .weak 			CBUS_onRTON
  	.thumb_set 		CBUS_onRTON, CBUS_defaultMessageHandler
    .extern			CBUS_onSNN
    .weak 			CBUS_onSNN
  	.thumb_set 		CBUS_onSNN, CBUS_defaultMessageHandler
    .extern			CBUS_onSSTAT
    .weak 			CBUS_onSSTAT
  	.thumb_set 		CBUS_onSSTAT, CBUS_defaultMessageHandler
    .extern			CBUS_onSTAT
    .weak 			CBUS_onSTAT
  	.thumb_set 		CBUS_onSTAT, CBUS_defaultMessageHandler
    .extern			CBUS_onSTMOD
    .weak 			CBUS_onSTMOD
  	.thumb_set 		CBUS_onSTMOD, CBUS_defaultMessageHandler
    .extern			CBUS_onTOF
    .weak 			CBUS_onTOF
  	.thumb_set 		CBUS_onTOF, CBUS_defaultMessageHandler
    .extern			CBUS_onTON
    .weak 			CBUS_onTON
  	.thumb_set 		CBUS_onTON, CBUS_defaultMessageHandler
    .extern			CBUS_onWCVB
    .weak 			CBUS_onWCVB
  	.thumb_set 		CBUS_onWCVB, CBUS_defaultMessageHandler
    .extern			CBUS_onWCVO
    .weak 			CBUS_onWCVO
  	.thumb_set 		CBUS_onWCVO, CBUS_defaultMessageHandler
    .extern			CBUS_onWCVOA
    .weak 			CBUS_onWCVOA
  	.thumb_set 		CBUS_onWCVOA, CBUS_defaultMessageHandler
    .extern			CBUS_onWCVS
    .weak 			CBUS_onWCVS
  	.thumb_set 		CBUS_onWCVS, CBUS_defaultMessageHandler
    .extern			CBUS_onWRACK
    .weak 			CBUS_onWRACK
  	.thumb_set 		CBUS_onWRACK, CBUS_defaultMessageHandler

	public_override(CBUS_defaultMessageHandler)

@ void CBUS_defaultMessageHandler(cbusMessage* pcbusMessage)
@	the default message handler - which simply returns. Is a weak reference, so can be overridden.

CBUS_defaultMessageHandler:  	
					bx				lr								@ simply return
	
	
	public_function(CBUS_handleMessage)

@ void CBUS_handleMessage(cbusMessage* pcbusMessage)
@	processes a cbus message by calling the appropriate message handler. If no handler defined then calls the default
@	message handler. Message handlers are called on<opcode>, for example: onNNULN and on onPARAMS. For those messages
@	where the opcode isn't defined an onRESERVED is called.

CBUS_handleMessage:													@ handle a cbus message
@ TODO @ TODO @ TODO @ TODO @ TODO @ TODO @ TODO @ TODO @ TODO @ TODO @ TODO @ TODO @ TODO @ TODO @ TODO @ TODO @ TODO
	

	.end
	