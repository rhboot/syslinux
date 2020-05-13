/*
 * string.h
 */

#ifndef _STRING_H
#define _STRING_H

#include <stddef.h>

/* Standard routines */
#define memcpy(a,b,c)	__builtin_memcpy(a,b,c)
#define memmove(a,b,c)	__builtin_memmove(a,b,c)
#define memset(a,b,c)	__builtin_memset(a,b,c)
#define strcpy(a,b)	__builtin_strcpy(a,b)
#define strlen(a)	inline_strlen(a)

/* replacement for builtin strlen that appears to get optimized away */
static inline size_t inline_strlen(const char *str)
{
    size_t l;
    for (l = 0; *str++; l++);
    return l;
}

/* This only returns true or false */
static inline int memcmp(const void *__m1, const void *__m2, unsigned int __n)
{
    _Bool rv;
    asm volatile ("cld ; repe ; cmpsb ; setne %0":"=abd" (rv), "+D"(__m1),
		  "+S"(__m2), "+c"(__n));
    return rv;
}

extern char *strchr(const char *s, int c);

#endif /* _STRING_H */
