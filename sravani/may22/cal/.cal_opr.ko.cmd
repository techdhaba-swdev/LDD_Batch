savedcmd_/home/rps/may22/cal/cal_opr.ko := ld -r -m elf_x86_64 -z noexecstack --build-id=sha1  -T scripts/module.lds -o /home/rps/may22/cal/cal_opr.ko /home/rps/may22/cal/cal_opr.o /home/rps/may22/cal/cal_opr.mod.o;  make -f ./arch/x86/Makefile.postlink /home/rps/may22/cal/cal_opr.ko