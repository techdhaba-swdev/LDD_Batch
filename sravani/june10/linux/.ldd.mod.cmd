savedcmd_/home/rps/june10/linux/ldd.mod := printf '%s\n'   ldd.o | awk '!x[$$0]++ { print("/home/rps/june10/linux/"$$0) }' > /home/rps/june10/linux/ldd.mod
