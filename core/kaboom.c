/*
 * kaboom.c
 */

#include "core.h"

#ifdef CORE_DEBUG

#include <dprintf.h>

__noreturn __bad_SEG(const volatile void *p)
{
    dprintf("SEG() passed an invalid pointer: %p\n", p);
    kaboom();
}

#endif

#undef kaboom

__noreturn _kaboom(void)
{
    extern void kaboom(void);
    call16(kaboom, &zero_regs, NULL);
    /* Do this if kaboom somehow returns... */
    for (;;)
	asm volatile("hlt");
}
