savedcmd_/home/rps/may22/network/net_dev.ko := ld -r -m elf_x86_64 -z noexecstack --build-id=sha1  -T scripts/module.lds -o /home/rps/may22/network/net_dev.ko /home/rps/may22/network/net_dev.o /home/rps/may22/network/net_dev.mod.o;  make -f ./arch/x86/Makefile.postlink /home/rps/may22/network/net_dev.ko
