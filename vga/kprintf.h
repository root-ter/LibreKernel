#ifndef KPRINTF_H
#define KPRINTF_H

#include <stdint.h>

enum kprintf_type
{
    KPRINTF_LOG,
    KPRINTF_ERROR,
    KPRINTF_SUCCESS,
    KPRINTF_NORMAL,
};

int kprintf(const uint8_t type, const char *format, ...);

#endif
