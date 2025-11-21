#ifndef MEM_H
#define MEM_H

#include <stddef.h>
#include "../lib/string.h"

void malloc_init(void *heap_start, size_t heap_size);
void *malloc(size_t size);
void free(void *ptr);
void *realloc(void *ptr, size_t new_size);

#endif
