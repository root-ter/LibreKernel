CC      := gcc
LD      := ld
AS      := nasm
QEMU    := qemu-system-x86_64

# Флаги компилятора
BASE_CFLAGS := -m64
DEBUG_CFLAGS := -m64 -g -O0 -DDEBUG

# Флаги линковки
LDFLAGS  := -m elf_x86_64 -T link.ld

# Флаги ассемблера
ASMFLAGS       := -f elf64
ASMFLAGS_DEBUG := -f elf64 -g -F dwarf

# Источники
SRCS_AS := entry/entry.asm
SRCS_C  := main.c spinlock/spinlock.c mem/mem.c lib/string.c
# Объекты
ASM_OBJS := $(patsubst %.asm,build/%.asm.o,$(SRCS_AS))
C_OBJS   := $(patsubst %.c,build/%.c.o,$(SRCS_C))
OBJECTS  := $(ASM_OBJS) $(C_OBJS)

BUILD_KERNEL := build/kernel.elf
QEMU_OPTS ?=

.PHONY: all clean builddir run debug

all: builddir $(BUILD_KERNEL)

builddir:
	@mkdir -p build

# Правила для asm
build/%.asm.o: %.asm
	@mkdir -p $(dir $@)
	$(AS) $(ASMFLAGS) $< -o $@

# Правила для c
build/%.c.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(BASE_CFLAGS) $(EXTRA_CFLAGS) -c $< -o $@

$(BUILD_KERNEL): $(OBJECTS) link.ld
	@mkdir -p $(dir $@)
	$(LD) $(LDFLAGS) -o $@ $(OBJECTS)

# debug-сборка: подменяем флаги
debug: EXTRA_CFLAGS=$(DEBUG_CFLAGS)
debug: ASMFLAGS=$(ASMFLAGS_DEBUG)
debug: all
	$(QEMU) -kernel $(BUILD_KERNEL) -serial stdio $(QEMU_OPTS)

run: all
	$(QEMU) -kernel $(BUILD_KERNEL) $(QEMU_OPTS)

clean:
	rm -rf build
