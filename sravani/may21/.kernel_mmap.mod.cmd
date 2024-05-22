savedcmd_/home/rps/may21/kernel_mmap.mod := printf '%s\n'   kernel_mmap.o | awk '!x[$$0]++ { print("/home/rps/may21/"$$0) }' > /home/rps/may21/kernel_mmap.mod
