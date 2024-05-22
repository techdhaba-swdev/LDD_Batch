savedcmd_/home/rps/may21/mmap2/kernel_program.mod := printf '%s\n'   kernel_program.o | awk '!x[$$0]++ { print("/home/rps/may21/mmap2/"$$0) }' > /home/rps/may21/mmap2/kernel_program.mod
