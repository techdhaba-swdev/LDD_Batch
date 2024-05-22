savedcmd_/home/rps/linux27/mmap.mod := printf '%s\n'   mmap.o | awk '!x[$$0]++ { print("/home/rps/linux27/"$$0) }' > /home/rps/linux27/mmap.mod
