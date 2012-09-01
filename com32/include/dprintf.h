/*
 * dprintf.h
 */

#ifndef _DPRINTF_H
#define _DPRINTF_H

#if !defined(DEBUG_PORT) && !defined(DEBUG_STDIO)
# undef CORE_DEBUG
#endif

#ifdef CORE_DEBUG

# include <stdio.h>

# ifdef DEBUG_STDIO
#  define dprintf  printf
#  define vdprintf vprintf
# else
void dprintf(const char *, ...);
void vdprintf(const char *, va_list);
# endif

#else

# define dprintf(fmt, ...)	((void)(0))
# define vdprintf(fmt, ap)	((void)(0))

#endif /* CORE_DEBUG */

# if CORE_DEBUG >= 2
/* Really verbose debugging... */
#  define dprintf2  dprintf
#  define vdprintf2 vdprintf
# else
#  define dprintf2(fmt, ...)	((void)(0))
#  define vdprintf2(fmt, ap)	((void)(0))
# endif

#endif /* _DPRINTF_H */
