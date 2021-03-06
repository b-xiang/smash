#ifndef __STDIO_H__
#define __STDIO_H__

#include "sys/types.h"

typedef char* va_list;
#define ROUND_INT_SIZE(n)  ((sizeof(n) + sizeof(int) - 1) & ~(sizeof(int) - 1))

#define va_start(ap, prev) (ap = (va_list)&prev + ROUND_INT_SIZE(prev))
#define va_arg(ap, type)                    \
({                                          \
    ap += ROUND_INT_SIZE(type);             \
    *(type *)(ap - ROUND_INT_SIZE(type));   \
})
#define va_end(ap)

#define stdin 0
#define stdout 1

void
printf(const char *fmt, ...);

void
vsprintf(char *buf, const char *fmt, va_list args);

#endif
