/*
 * Copyright (c) 2015 The NW1 Group
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

/*
 * Easy to use module, function and data pseudo functions
 * Note: ; replaces newline which is hard to generate in standard C macros
 */

/*
 * macro to define a source module - name currently unused
 */

#define module(name)\
    .syntax         unified;                                        @ use unified ARM and Thumb syntax\
    .cpu            cortex-m0;                                      @ targeting cortex-m0\
    .fpu            softvfp;                                        @ device does not have a hardware FPU\
    .thumb;                                                         @ cortex only support thumb mode\
    .list;                                                          @ produce a list file\
    .eabi_attribute Tag_ABI_align_needed, 1;\
    .eabi_attribute Tag_ABI_align_preserved, 1;

/*
 * macro to define a function
 */

#define _function(secname,fnname)\
    .section        .text.#secname, "ax", %progbits;\
    .type           fnname, %function;\
    .size           fnname, .-fnname;\
    .balign         2;\
    .thumb_func;

/*   */

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
    .global         name;

/*
 * macro to define a public function that can be overridden
 */

#define public_override(name)\
    public_function(name)\
    .weak           name;

/*
 * macro to define a private data
 */

#define private_data(secname)\
    .section        .data.##secname, "aw", %progbits;\
    .type           .data.##secname, %object;\
    .data;\
    .balign         4;

/*
 * macro to define a public data - no different from private data, and you must include .global on any labels
 * you want exported, but at least the intent is made clear
 */

#define public_data(secname) private_data(secname)
