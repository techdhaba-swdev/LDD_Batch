savedcmd_/home/rps/may21/mmap2/kernel_program.ko := ld -r -m elf_x86_64 -z noexecstack --build-id=sha1  -T scripts/module.lds -o /home/rps/may21/mmap2/kernel_program.ko /home/rps/may21/mmap2/kernel_program.o /home/rps/may21/mmap2/kernel_program.mod.o;  make -f ./arch/x86/Makefile.postlink /home/rps/may21/mmap2/kernel_program.ko