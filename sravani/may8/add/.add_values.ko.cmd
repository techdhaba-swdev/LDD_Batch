savedcmd_/home/rps/may8/add/add_values.ko := ld -r -m elf_x86_64 -z noexecstack --build-id=sha1  -T scripts/module.lds -o /home/rps/may8/add/add_values.ko /home/rps/may8/add/add_values.o /home/rps/may8/add/add_values.mod.o;  make -f ./arch/x86/Makefile.postlink /home/rps/may8/add/add_values.ko
