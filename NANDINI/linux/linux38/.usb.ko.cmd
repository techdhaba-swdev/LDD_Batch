savedcmd_/home/rps/linux38/usb.ko := ld -r -m elf_x86_64 -z noexecstack --build-id=sha1  -T scripts/module.lds -o /home/rps/linux38/usb.ko /home/rps/linux38/usb.o /home/rps/linux38/usb.mod.o;  make -f ./arch/x86/Makefile.postlink /home/rps/linux38/usb.ko
