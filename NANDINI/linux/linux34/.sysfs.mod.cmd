savedcmd_/home/rps/linux34/sysfs.mod := printf '%s\n'   sysfs.o | awk '!x[$$0]++ { print("/home/rps/linux34/"$$0) }' > /home/rps/linux34/sysfs.mod
