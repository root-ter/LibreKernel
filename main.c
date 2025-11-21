#include "mem/mem.h"

#include <stdint.h>

extern char _heap_start;
extern char _heap_end;

void kernel_main() {
	size_t heap_size = (size_t)((uintptr_t)&_heap_end - (uintptr_t)&_heap_start);
	malloc_init(&_heap_start, heap_size);

	while (1) {
		// Nop
	}
}
