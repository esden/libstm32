/* Linker script for Olimex STM32-H103 eval board.
 *
 * Version: 0.1
 *
 *  Copyright 2007 CodeSourcery.
 *
 * The authors hereby grant permission to use, copy, modify, distribute,
 * and license this software and its documentation for any purpose, provided
 * that existing copyright notices are retained in all copies and that this
 * notice is included verbatim in any distributions. No written agreement,
 * license, or royalty fee is required for any of the authorized uses.
 * Modifications to this software may be copyrighted by their authors
 * and need not follow the licensing terms described here, provided that
 * the new terms are clearly indicated on the first page of each file where
 * they apply.
 *
 * Modified by Olimex
 * 2009-04-07: Modified by Piotr Esden-Tempski <piotr@esden.net>
 */

SEARCH_DIR("../../src");

MEMORY
{
  ram (rwx) : ORIGIN = 0x20000000, LENGTH = 20K
  rom (rx) : ORIGIN = 0x00000000, LENGTH = 128K
}
SECTIONS
  {
	.  = 0x0;          /* From 0x00000000 */
    .text : {
    *(vectors)      /* Vector table */
    *(.text)        /* Program code */
    *(.rodata)      /* Read only data */
    } >rom
        .  = 0x20000000;   /* From 0x20000000 */      
    .data : {
    *(.data)        /* Data memory */
    } >ram AT > rom
  .bss : {
    *(.bss)         /* Zero-filled run time allocate data memory */
    } >ram AT > rom
 }  
/*========== end of file ==========*/
