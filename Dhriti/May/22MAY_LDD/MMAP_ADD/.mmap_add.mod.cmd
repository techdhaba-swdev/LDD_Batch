savedcmd_/home/rps/22MAY/MMAP_ADD/mmap_add.mod := printf '%s\n'   mmap_add.o | awk '!x[$$0]++ { print("/home/rps/22MAY/MMAP_ADD/"$$0) }' > /home/rps/22MAY/MMAP_ADD/mmap_add.mod
