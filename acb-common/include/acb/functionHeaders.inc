/*
 * Copyright (c) 2015 The NW1 Group
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

/*
 * General very commmon definitions
 */

FALSE = 0
TRUE  = 1

/*
 * Easy to use module, function and data pseudo functions
 * Note: ; replaces newline which is hard to generate in standard C macros
 */

/*
 * macro to define a source module - name currently unused
 */

#if (__CORTEX_M == 0x00)

#define module(name)\
    .syntax         unified;                                        @ use unified ARM and Thumb syntax\
    .cpu            cortex-m0;                                      @ targeting cortex-m0\
    .fpu            softvfp;                                        @ device does not have a hardware FPU\
    .thumb;                                                         @ cortex only support thumb mode\
    .list;                                                          @ produce a list file\
    .eabi_attribute Tag_ABI_align_needed, 1;\
    .eabi_attribute Tag_ABI_align_preserved, 1;

#elif (__CORTEX_M == 0x04)

#if (__FPU_PRESENT == 1)
#define FPU_TYPE fpv4-sp-d16                                        /* device has single precision FPU */
#else
#define FPU_TYPE softvfp                                            /* device does not have a hardware FPU */
#endif


#define module(name)\
    .syntax         unified;                                        @ use unified ARM and Thumb syntax\
    .cpu            cortex-m4;                                      @ targeting cortex-m0\
    .fpu            FPU_TYPE
    .thumb;                                                         @ cortex only support thumb mode\
    .list;                                                          @ produce a list file\
    .eabi_attribute Tag_ABI_align_needed, 1;\
    .eabi_attribute Tag_ABI_align_preserved, 1;
#else
#error Define processor type before including this file. Hint include core_cmX.inc before including this file
#endif

/*
 * macro to define a function
 */

#define __function(secname,fnname)\
    .section        #secname, "ax", %progbits;\
    .type           fnname, %function;\
    .size           fnname, .-fnname;\
    .balign         2;\
    .align          2;\
    .code           16;\
    .thumb_func;

/*
 * macro to define a function
 */

#define _function(secname,fnname) __function(.text.#secname, fnname)

/*
 * macro to define a function that goes into the after_vectors section
 */

#define _av_function(secname,fnname) __function(.after_vectors.#secname, fnname)

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
 * macro to define a functions (into after_vectors section)
 * for only the cortex m0 variants
 */

#if (__CORTEX_M == 0x00) && defined(ACB_APPLICATION)
#define av_private_function(name)\
    _av_function(name,name)

#define av_public_function(name)\
    _av_function(.public.##name,name)\
    .global         name;
#else
#define av_private_function(name)\
    _function(name,name)

#define av_public_function(name)\
    _function(.public.##name,name)\
    .global         name;
#endif

#define av_public_override(name)\
    av_public_function(name)\
    .weak           name;

/*
 * macro to define static data (that's stored in flash)
 */

#define static_data(secname)\
    .section        .rodata.##secname, "a", %progbits;\
    .type           .rodata.##secname, %function;\
    .size           secname, .-secname;\
    .balign         2;\
    .align          2;

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
