savedcmd_/home/rps/may17/blocking/kernel.ko := ld -r -m elf_x86_64 -z noexecstack --build-id=sha1  -T scripts/module.lds -o /home/rps/may17/blocking/kernel.ko /home/rps/may17/blocking/kernel.o /home/rps/may17/blocking/kernel.mod.o;  make -f ./arch/x86/Makefile.postlink /home/rps/may17/blocking/kernel.ko
