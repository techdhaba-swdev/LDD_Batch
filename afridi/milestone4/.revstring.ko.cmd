savedcmd_/home/rps/milestone4/revstring.ko := ld -r -m elf_x86_64 -z noexecstack --build-id=sha1  -T scripts/module.lds -o /home/rps/milestone4/revstring.ko /home/rps/milestone4/revstring.o /home/rps/milestone4/revstring.mod.o;  make -f ./arch/x86/Makefile.postlink /home/rps/milestone4/revstring.ko
