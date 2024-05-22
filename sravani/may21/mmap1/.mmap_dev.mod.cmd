savedcmd_/home/rps/may21/mmap1/mmap_dev.mod := printf '%s\n'   mmap_dev.o | awk '!x[$$0]++ { print("/home/rps/may21/mmap1/"$$0) }' > /home/rps/may21/mmap1/mmap_dev.mod
