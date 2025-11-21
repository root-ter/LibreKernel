#ifndef SPINLOCK_H
#define SPINLOCK_H

#include <stdint.h>

typedef struct {
    volatile uint32_t locked;  // 0 = свободен, 1 = занят
} spinlock_t;

#define SPINLOCK_INIT { .locked = 0 }

/**
 * Захватывает спинлок.
 * Блокируется, пока лок не станет доступным.
 */
void spin_lock(spinlock_t *lock);

/**
 * Освобождает спинлок.
 */
void spin_unlock(spinlock_t *lock);

/**
 * Пытается захватить спинлок.
 * Возвращает 1, если удалось, 0 — если занят.
 */
int spin_trylock(spinlock_t *lock);

/**
 * Проверяет, захвачен ли лок.
 * Возвращает 1, если занят, 0 — если свободен.
 */
int spin_is_locked(spinlock_t *lock);

#endif
