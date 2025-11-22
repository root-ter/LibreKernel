#include "mmio.h"

void mmio_barrier(void) {
    asm volatile(""::: "memory");
}

uint8_t mmio_read8(volatile uint8_t *addr) {
    uint8_t val = *addr;
    mmio_barrier();
    return val;
}

uint16_t mmio_read16(volatile uint16_t *addr) {
    uint16_t val = *addr;
    mmio_barrier();
    return val;
}

uint32_t mmio_read32(volatile uint32_t *addr) {
    uint32_t val = *addr;
    mmio_barrier();
    return val;
}

uint64_t mmio_read64(volatile uint64_t *addr) {
    uint64_t val = *addr;
    mmio_barrier();
    return val;
}

void mmio_write8(volatile uint8_t *addr, uint8_t val) {
    *addr = val;
    mmio_barrier();
}

void mmio_write16(volatile uint16_t *addr, uint16_t val) {
    *addr = val;
    mmio_barrier();
}

void mmio_write32(volatile uint32_t *addr, uint32_t val) {
    *addr = val;
    mmio_barrier();
}

void mmio_write64(volatile uint64_t *addr, uint64_t val) {
    *addr = val;
    mmio_barrier();
}
