savedcmd_/home/rps/22MAY/NETWORKING/net_device.ko := ld -r -m elf_x86_64 -z noexecstack --build-id=sha1  -T scripts/module.lds -o /home/rps/22MAY/NETWORKING/net_device.ko /home/rps/22MAY/NETWORKING/net_device.o /home/rps/22MAY/NETWORKING/net_device.mod.o;  make -f ./arch/x86/Makefile.postlink /home/rps/22MAY/NETWORKING/net_device.ko