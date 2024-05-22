savedcmd_/home/rps/linux25/mmap.mod := printf '%s\n'   mmap.o | awk '!x[$$0]++ { print("/home/rps/linux25/"$$0) }' > /home/rps/linux25/mmap.mod
