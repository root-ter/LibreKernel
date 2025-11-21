#include "spinlock.h"
#include <stdint.h>

/**
 * Атомарно устанавливает значение и возвращает старое.
 * Реализовано через x86‑64 LOCK XCHG.
 */
static inline uint32_t atomic_xchg(volatile uint32_t *ptr, uint32_t val) {
    uint32_t result;
    asm volatile(
        "lock xchgl %0, %1"
        : "=r" (result)
        : "m" (*ptr), "0" (val)
        : "memory"
    );
    return result;
}

void spin_lock(spinlock_t *lock) {
    while (1) {
        // Пытаемся захватить
        if (atomic_xchg(&lock->locked, 1) == 0) {
            return;  // Успешно захватили
        }

        // Лок занят — ждём с пассивным ожиданием (PAUSE) для энергоэффективности
        asm volatile("pause");
    }
}

void spin_unlock(spinlock_t *lock) {
    // Просто сбрасываем флаг (атомарно не требуется, т. к. только один поток пишет)
    lock->locked = 0;
    // Обеспечиваем видимость изменения для других CPU
    asm volatile("" : : : "memory");
}

int spin_trylock(spinlock_t *lock) {
    // Пытаемся захватить без ожидания
    return (atomic_xchg(&lock->locked, 1) == 0);
}

int spin_is_locked(spinlock_t *lock) {
	asm volatile("" : : : "memory");
    return lock->locked != 0;
}
