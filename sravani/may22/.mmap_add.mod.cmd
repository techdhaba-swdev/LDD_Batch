savedcmd_/home/rps/may22/mmap_add.mod := printf '%s\n'   mmap_add.o | awk '!x[$$0]++ { print("/home/rps/may22/"$$0) }' > /home/rps/may22/mmap_add.mod
