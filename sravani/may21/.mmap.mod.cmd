savedcmd_/home/rps/may21/mmap.mod := printf '%s\n'   mmap.o | awk '!x[$$0]++ { print("/home/rps/may21/"$$0) }' > /home/rps/may21/mmap.mod
