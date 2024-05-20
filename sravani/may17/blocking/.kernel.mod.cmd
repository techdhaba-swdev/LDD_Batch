savedcmd_/home/rps/may17/blocking/kernel.mod := printf '%s\n'   kernel.o | awk '!x[$$0]++ { print("/home/rps/may17/blocking/"$$0) }' > /home/rps/may17/blocking/kernel.mod
