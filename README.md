## LibreKernel
LibreKernel - LibreSYS project to create real fully functional kernel & use it in OS.

## Road
  [x] Memory allocator
  [x] Spinlock
  [x] Switching to long mode
  [x] Kernel string.h
  [ ] Scheduler
  [ ] IDT & interrupts
  [ ] Own syscall interrupt
  [ ] Basic VGA driver
  [ ] Basic PCI/PCIe driver
  [ ] Basic IDE/ATA/SATA/NVMe drivers
  [ ] Basic USB driver
  [ ] IO driver
  [ ] ACPI
  [ ] Time

## Build
You can build LibreKernel via:
  ```bash
  make
  ```
To clean builded kernel use:
  ```bash
  make clean
  ```
To build ISO with kernel.elf, create dir, in this dir create "boot" dir, in "boot" dir create "grub" dir. (Move kernel.elf in "boot" dir)
  In "grub" dir create "grub.cfg" file and write this text to "grub.cfg":
  ```
  set timeout=5

  menuentry "Kernel" {
    multiboot2 /boot/kernel.elf
    boot
  }
  ```
Also to build ISO you need this packages: ```mtools```, ```xorriso```, ```grub-pc-bin```.
To build iso: ```grub-mkrescue -o kernel.iso make``` ("make" is your dir)

## License
This project protected MIT License
