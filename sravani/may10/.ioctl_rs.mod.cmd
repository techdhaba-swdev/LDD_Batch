savedcmd_/home/rps/may10/ioctl_rs.mod := printf '%s\n'   ioctl_rs.o | awk '!x[$$0]++ { print("/home/rps/may10/"$$0) }' > /home/rps/may10/ioctl_rs.mod
