savedcmd_/home/rps/may22/uid/kernel_uid.mod := printf '%s\n'   kernel_uid.o | awk '!x[$$0]++ { print("/home/rps/may22/uid/"$$0) }' > /home/rps/may22/uid/kernel_uid.mod
