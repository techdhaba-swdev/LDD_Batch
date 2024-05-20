savedcmd_/home/rps/may17/ioctl.mod := printf '%s\n'   ioctl.o | awk '!x[$$0]++ { print("/home/rps/may17/"$$0) }' > /home/rps/may17/ioctl.mod
