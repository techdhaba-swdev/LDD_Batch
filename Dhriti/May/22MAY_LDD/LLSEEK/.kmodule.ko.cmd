savedcmd_/home/rps/22MAY/LLSEEK/kmodule.ko := ld -r -m elf_x86_64 -z noexecstack --build-id=sha1  -T scripts/module.lds -o /home/rps/22MAY/LLSEEK/kmodule.ko /home/rps/22MAY/LLSEEK/kmodule.o /home/rps/22MAY/LLSEEK/kmodule.mod.o;  make -f ./arch/x86/Makefile.postlink /home/rps/22MAY/LLSEEK/kmodule.ko