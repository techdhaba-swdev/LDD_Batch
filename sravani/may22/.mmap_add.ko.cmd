savedcmd_/home/rps/may22/mmap_add.ko := ld -r -m elf_x86_64 -z noexecstack --build-id=sha1  -T scripts/module.lds -o /home/rps/may22/mmap_add.ko /home/rps/may22/mmap_add.o /home/rps/may22/mmap_add.mod.o;  make -f ./arch/x86/Makefile.postlink /home/rps/may22/mmap_add.ko