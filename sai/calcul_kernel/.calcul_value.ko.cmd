savedcmd_/home/rps/calcul_kernel/calcul_value.ko := ld -r -m elf_x86_64 -z noexecstack --build-id=sha1  -T scripts/module.lds -o /home/rps/calcul_kernel/calcul_value.ko /home/rps/calcul_kernel/calcul_value.o /home/rps/calcul_kernel/calcul_value.mod.o;  make -f ./arch/x86/Makefile.postlink /home/rps/calcul_kernel/calcul_value.ko
