savedcmd_/home/rps/may6/linux/kernel.mod := printf '%s\n'   kernel.o | awk '!x[$$0]++ { print("/home/rps/may6/linux/"$$0) }' > /home/rps/may6/linux/kernel.mod
