savedcmd_/home/rps/13thmayLDD/IRQ/kernel_irq.ko := ld -r -m elf_x86_64 -z noexecstack --build-id=sha1  -T scripts/module.lds -o /home/rps/13thmayLDD/IRQ/kernel_irq.ko /home/rps/13thmayLDD/IRQ/kernel_irq.o /home/rps/13thmayLDD/IRQ/kernel_irq.mod.o;  make -f ./arch/x86/Makefile.postlink /home/rps/13thmayLDD/IRQ/kernel_irq.ko