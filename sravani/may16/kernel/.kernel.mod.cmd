savedcmd_/home/rps/may16/kernel/kernel.mod := printf '%s\n'   kernel.o | awk '!x[$$0]++ { print("/home/rps/may16/kernel/"$$0) }' > /home/rps/may16/kernel/kernel.mod
