savedcmd_/home/rps/may29/sys.ko := ld -r -m elf_x86_64 -z noexecstack --build-id=sha1  -T scripts/module.lds -o /home/rps/may29/sys.ko /home/rps/may29/sys.o /home/rps/may29/sys.mod.o;  make -f ./arch/x86/Makefile.postlink /home/rps/may29/sys.ko
