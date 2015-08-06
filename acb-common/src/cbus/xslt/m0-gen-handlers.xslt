<?xml version="1.0" encoding="utf-8"?>
<xsl:transform version="3.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
	xmlns:f="http://www.thenw1group.com/xslt/functions">

	<xsl:output method="text" indent="no" omit-xml-declaration="yes"/>

	<xsl:strip-space elements="*"/>

	<!-- Functions - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -->

	<!-- copied, with respect, 
		from http://stackoverflow.com/questions/22905134/convert-a-hexadecimal-number-to-an-integer-in-xslt -->
	<xsl:function name="f:hexToDec">
    	<xsl:param name="hex"/>
    	<xsl:variable name="dec" select="string-length(substring-before('0123456789ABCDEF', substring($hex,1,1)))"/>
    	<xsl:choose>
	        <xsl:when test="matches($hex, '([0-9]*|[A-F]*)')">
    	        <xsl:value-of
        				select="if ($hex = '') then 0
        				else $dec * f:power(16, string-length($hex) - 1) + f:hexToDec(substring($hex,2))"/>
        	</xsl:when>
        	<xsl:otherwise>
            	<xsl:message>Provided value is not hexadecimal...</xsl:message>
            	<xsl:value-of select="$hex"/>
        	</xsl:otherwise>
    	</xsl:choose>
	</xsl:function>

	<xsl:function name="f:power">
	    <xsl:param name="base"/>
	    <xsl:param name="exp"/>
	    <xsl:sequence
    	    select="if ($exp lt 0) then f:power(1.0 div $base, -$exp)
        	        else if ($exp eq 0)
            	    then 1e0
                	else $base * f:power($base, $exp - 1)"
				    />
	</xsl:function>

	<xsl:function name="f:decToHex">
    	<xsl:param name="dec"/>
    	<xsl:if test="$dec > 0">
	        <xsl:value-of
    	        select="f:decToHex(floor($dec div 16)),substring('0123456789ABCDEF', (($dec mod 16) + 1), 1)"
        	    separator=""/>
    	</xsl:if>
	</xsl:function>

	<xsl:function name="f:string-left-pad">
  		<xsl:param name="padString"/>
  		<xsl:param name="padChar"/>
  		<xsl:param name="padCount"/>
  		<xsl:sequence select="concat(string-join((for $i in 1 to $padCount - (string-length($padString)) return $padChar), ''), $padString)"/>
	</xsl:function>

	<!-- End of Functions  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -->

	<xsl:template match="/CBUS_Message_List">/*
 * Copyright (c) 2015 The NW1 Group
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */
	
@ Generated File (<xsl:value-of select="current-dateTime()"/>
		<xsl:text/>) based on version <xsl:value-of select="version"/>
		<xsl:text> </xsl:text><xsl:value-of select="gendate"/>
@ Revision History
		<xsl:apply-templates select="revisionHistory/revision"/>

#include "acb_common.inc"

	module(cbus_messages)
		<xsl:call-template name="vector-map"/>
		<xsl:call-template name="default-message-handlers"/>
		<xsl:call-template name="handle-cbus-message"/>

	.end
	</xsl:template>

	<xsl:template match="*"/>
  
  	<xsl:template match="revision">
@ Revision <xsl:value-of select="version"/>
<xsl:text>&#x9;</xsl:text><xsl:value-of select="date"/>
<xsl:text>&#x9;</xsl:text><xsl:value-of select="author"/>
<xsl:text>&#x9;</xsl:text><xsl:value-of select="comment"/>
  	</xsl:template>
  
	<xsl:template name="vector-map">
	private_function(CBUS_vectorTable)

CBUS_vectorTable:													@ Note: + 1 to ensure the processor stays in thumb mode<xsl:apply-templates select="message" mode="jump-table">				
			<xsl:sort select="f:hexToDec(opcode)" order="ascending" data-type="number"/>
		</xsl:apply-templates>

	</xsl:template>

	<xsl:template name="default-message-handlers">

@ provide weak aliases for all the message handlers
		<xsl:for-each select="distinct-values(message/acronym)">
			<xsl:sort select="." order="ascending" data-type="text"/>
    .extern			CBUS_on<xsl:value-of select="."/>
    .weak 			CBUS_on<xsl:value-of select="."/>
  	.thumb_set 		CBUS_on<xsl:value-of select="."/>, CBUS_defaultMessageHandler</xsl:for-each>

	public_override(CBUS_defaultMessageHandler)

@ void CBUS_defaultMessageHandler(cbusMessage* pcbusMessage)
@	the default message handler - which simply returns. Is a weak reference, so can be overridden.

CBUS_defaultMessageHandler:  	
					bx				lr								@ simply return
	</xsl:template>

	<xsl:template name="handle-cbus-message">
	
	public_function(CBUS_handleMessage)

@ void CBUS_handleMessage(cbusMessage* pcbusMessage)
@	processes a cbus message by calling the appropriate message handler. If no handler defined then calls the default
@	message handler. Message handlers are called on&lt;opcode&gt;, for example: onNNULN and on onPARAMS. For those messages
@	where the opcode isn't defined an onRESERVED is called.

CBUS_handleMessage:													@ handle a cbus message
@ TODO @ TODO @ TODO @ TODO @ TODO @ TODO @ TODO @ TODO @ TODO @ TODO @ TODO @ TODO @ TODO @ TODO @ TODO @ TODO @ TODO
	</xsl:template>


  	<xsl:template match="message" mode="jump-table"><xsl:choose>
	  	<xsl:when test="compare(acronym,'RESERVED')=0">
	.word			CBUS_on<xsl:value-of select="acronym"/> + 1								@ Reserved for future use (<xsl:value-of select="opcode"/>)</xsl:when>
		<xsl:when test="string-length(acronym) > 4">
	.word			CBUS_on<xsl:value-of select="acronym"/> + 1								@ <xsl:value-of select="description"/> (<xsl:value-of select="opcode"/>)</xsl:when>
	  	<xsl:otherwise>
	.word			CBUS_on<xsl:value-of select="acronym"/> + 1									@ <xsl:value-of select="description"/> (<xsl:value-of select="opcode"/>)</xsl:otherwise>
		</xsl:choose>
		<!-- test that we have all opcodes from 0x00 to 0xFF -->
		<xsl:choose>
		<xsl:when test="compare(opcode, '0x00')=0">
			<xsl:if test="exists(parent::node()/message[compare(opcode, '0x01')=0])=false()">
				<xsl:message terminate="yes">Missing opcode 0x01. Please check source XML document</xsl:message>
			</xsl:if>
		</xsl:when>
		<xsl:when test="compare(opcode, '0xFF')=0">
			<xsl:if test="exists(parent::node()/message[compare(opcode, '0xFE')=0])=false()">
				<xsl:message terminate="yes">Missing opcode 0xFE. Please check source XML document</xsl:message>
			</xsl:if>
		</xsl:when>
		<xsl:otherwise>
			<xsl:variable name="next-opcode" select="concat('0x', f:string-left-pad(f:decToHex(f:hexToDec(opcode)+1), '0', 2))"/>
			<xsl:variable name="prev-opcode" select="concat('0x', f:string-left-pad(f:decToHex(f:hexToDec(opcode)-1), '0', 2))"/>
			<xsl:if test="exists(parent::node()/message[compare(opcode, $prev-opcode)=0])=false()">
				<xsl:message terminate="yes">Missing opcode <xsl:value-of select="$prev-opcode"/>. Please check source XML document</xsl:message>
			</xsl:if>
			<xsl:if test="exists(parent::node()/message[compare(opcode, $next-opcode)=0])=false()">
				<xsl:message terminate="yes">Missing opcode <xsl:value-of select="$next-opcode"/>. Please check source XML document</xsl:message>
			</xsl:if>
		</xsl:otherwise>
		</xsl:choose>
	</xsl:template>
	
</xsl:transform>
