#include "mem/mem.h"
#include "vga/kprintf.h"
#include "vga/vga.h"

#include <stdint.h>

extern char _heap_start;
extern char _heap_end;

void kernel_main() {
	size_t heap_size = (size_t)((uintptr_t)&_heap_end - (uintptr_t)&_heap_start);
	malloc_init(&_heap_start, heap_size);
	uint64_t size64 = (uint64_t)heap_size;
	uint32_t high = (uint32_t)(size64 >> 32);
	uint32_t low = (uint32_t)size64;
	clean_screen();
	kprintf(KPRINTF_SUCCESS, "MEM: Initialized successfully.\n");
	if (high == 0) {
        kprintf(KPRINTF_LOG, "MEM: Heap size: %u bytes\n", low);
    } else {
        kprintf(KPRINTF_LOG, "MEM: Heap size: 0x%x%08x bytes\n", high, low);
    }

	while (1) {
		// Nop
	}
}
