savedcmd_/home/rps/may17/ioctl/ioctl_mul.mod := printf '%s\n'   ioctl_mul.o | awk '!x[$$0]++ { print("/home/rps/may17/ioctl/"$$0) }' > /home/rps/may17/ioctl/ioctl_mul.mod
