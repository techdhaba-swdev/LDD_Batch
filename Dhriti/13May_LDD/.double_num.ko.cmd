savedcmd_/home/rps/11May/double_num.ko := ld -r -m elf_x86_64 -z noexecstack --build-id=sha1  -T scripts/module.lds -o /home/rps/11May/double_num.ko /home/rps/11May/double_num.o /home/rps/11May/double_num.mod.o;  make -f ./arch/x86/Makefile.postlink /home/rps/11May/double_num.ko