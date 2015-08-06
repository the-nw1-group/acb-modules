/*
 * Copyright (c) 2015 The NW1 Group
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

/*
 * Common defines across the range of ACB modules
 * Note: ; replaces newline which is hard to generate in standard C macros
 */

/*
 * macro to define a source module - name currently unused
 */

#define module(name)\
	.syntax			unified;										@ use unified ARM and Thumb syntax\
	.cpu			cortex-m0;										@ targeting cortex-m0\
	.fpu			softvfp;										@ device does not have a hardware FPU\
	.thumb;															@ cortex only support thumb mode\
	.list;															@ produce a list file\
	.eabi_attribute	Tag_ABI_align_needed, 1;\
	.eabi_attribute	Tag_ABI_align_preserved, 1;

/*
 * macro to define a function
 */

#define _function(secname,fnname)\
	.section		.text.#secname, "ax", %progbits;\
	.type			fnname, %function;\
	.size			fnname, .-fnname;\
	.balign			2;\
	.thumb_func;

/* 	 */

/*
 * macro to define a private function
 */

#define private_function(name)\
	_function(name,name)

/*
 * macro to define a public function
 */

#define public_function(name)\
	_function(.public.##name,name)\
	.global			name;

/*
 * macro to define a public function that can be overridden
 */

#define public_override(name)\
	public_function(name)\
	.weak			name;

/*
 * macro to define a private data
 */

#define private_data(secname)\
	.section		.data.##secname, "aw", %progbits;\
	.type			.data.##secname, %object;\
	.data;\
	.balign			4;

/*
 * macro to define a public data - no different from private data, and you must include .global on any labels
 * you want exported, but at least the intent is made clear
 */

#define public_data(secname) private_data(secname)


/*
 * Define locations of standard Inputs and Outputs on the ACB boards.
 * These are the green and yellow LEDs, generally on SWD pins,
 * and the FLiM Switch, generally on BOOT0 (which changes, per device)
 *
 * Unlike other processors (PICs for example), if the SWD are reassigned away from
 * alternate function/SWD, then you can't debug, so when in debug mode these
 * pins should be left alone
 *
 * For custom LED placement, define ACB_LED_CUSTOM and define the other ACB_LED_*
 * defines. Note, for now, the LEDs must be on the same port.
 *
 * For custom FLiM switch placement, define ACB_FLIM_CUSTOM and define the other ACB_FLIM_*
 * defines.
 *
 */

#if !defined(ACB_LED_CUSTOM)
#define ACB_LED_USE			!DEBUG
#define ACB_LED_AHBENR		RCC_AHBENR_GPIOAEN
#define ACB_LED_PORT 		GPIOA_BASE
#define ACB_LED_GREEN_BIT	13
#define ACB_LED_YELLOW_BIT	14
#elif !defined(ACB_LED_USE)
#error You must manually define ACB_LED_USE when ACB_LED_CUSTOM is defined
#elif (ACB_LED_USE==1) && (!defined(ACB_LED_AHBENR) || !defined(ACB_LED_PORT) || !defined(ACB_LED_GREEN_BIT) || !defined(ACB_LED_YELLOW_BIT))
#error You must manually define all of: ACB_LED_AHBENR; ACB_LED_PORT; ACB_LED_GREEN_BIT; ACB_LED_YELLOW_BIT, when ACB_LED_CUSTOM is defined and ACB_LED_USE = 1
#endif

#if !defined(ACB_FLIMSW_CUSTOM)
#define ACB_FLIMSW_USE		1
#define ACB_FLIMSW_AHBENR	RCC_AHBENR_GPIOBEN
#define ACB_FLIMSW_PORT		GPIOB_BASE
#define ACB_FLIMSW_BIT		8
#elif !defined(ACB_FLIMSW_USE)
#error You must manually define ACB_FLIMSW_USE when ACB_FLIMSW_CUSTOM is defined
#elif (ACB_FLIMSW_USE==1) && (!defined(ACB_FLIMSW_AHBENR) || !defined(ACB_FLIMSW_PORT) || !defined(ACB_FLIMSW_BIT))
#error You must manually define all of: ACB_FLIMSW_AHBENR; ACB_FLIMSW_PORT; ACB_FLIMSW_BIT; when ACB_FLIMSW_CUSTOM is defined and ACB_FLIMSW_USE = 1
#endif

