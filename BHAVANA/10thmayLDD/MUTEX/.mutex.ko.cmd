savedcmd_/home/rps/10thmayLDD/MUTEX/mutex.ko := ld -r -m elf_x86_64 -z noexecstack --build-id=sha1  -T scripts/module.lds -o /home/rps/10thmayLDD/MUTEX/mutex.ko /home/rps/10thmayLDD/MUTEX/mutex.o /home/rps/10thmayLDD/MUTEX/mutex.mod.o;  make -f ./arch/x86/Makefile.postlink /home/rps/10thmayLDD/MUTEX/mutex.ko