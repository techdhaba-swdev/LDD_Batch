savedcmd_/home/rps/may21/mmap2/kernel.mod := printf '%s\n'   kernel.o | awk '!x[$$0]++ { print("/home/rps/may21/mmap2/"$$0) }' > /home/rps/may21/mmap2/kernel.mod
