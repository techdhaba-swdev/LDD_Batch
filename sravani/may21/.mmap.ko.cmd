savedcmd_/home/rps/may21/mmap.ko := ld -r -m elf_x86_64 -z noexecstack --build-id=sha1  -T scripts/module.lds -o /home/rps/may21/mmap.ko /home/rps/may21/mmap.o /home/rps/may21/mmap.mod.o;  make -f ./arch/x86/Makefile.postlink /home/rps/may21/mmap.ko