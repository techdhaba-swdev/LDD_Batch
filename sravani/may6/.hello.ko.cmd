savedcmd_/home/rps/may6/hello.ko := ld -r -m elf_x86_64 -z noexecstack --build-id=sha1  -T scripts/module.lds -o /home/rps/may6/hello.ko /home/rps/may6/hello.o /home/rps/may6/hello.mod.o;  make -f ./arch/x86/Makefile.postlink /home/rps/may6/hello.ko
