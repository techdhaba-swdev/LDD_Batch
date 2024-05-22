savedcmd_/home/rps/may21/mmap/mmap_add.mod := printf '%s\n'   mmap_add.o | awk '!x[$$0]++ { print("/home/rps/may21/mmap/"$$0) }' > /home/rps/may21/mmap/mmap_add.mod
