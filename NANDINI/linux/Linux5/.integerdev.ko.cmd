savedcmd_/home/rps/Linux5/integerdev.ko := ld -r -m elf_x86_64 -z noexecstack --build-id=sha1  -T scripts/module.lds -o /home/rps/Linux5/integerdev.ko /home/rps/Linux5/integerdev.o /home/rps/Linux5/integerdev.mod.o;  make -f ./arch/x86/Makefile.postlink /home/rps/Linux5/integerdev.ko
