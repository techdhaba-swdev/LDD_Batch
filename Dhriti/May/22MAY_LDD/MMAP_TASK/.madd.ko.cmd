savedcmd_/home/rps/22MAY/MMAP_TASK/madd.ko := ld -r -m elf_x86_64 -z noexecstack --build-id=sha1  -T scripts/module.lds -o /home/rps/22MAY/MMAP_TASK/madd.ko /home/rps/22MAY/MMAP_TASK/madd.o /home/rps/22MAY/MMAP_TASK/madd.mod.o;  make -f ./arch/x86/Makefile.postlink /home/rps/22MAY/MMAP_TASK/madd.ko