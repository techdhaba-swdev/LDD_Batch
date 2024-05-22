savedcmd_/home/rps/kernel2/Device.mod := printf '%s\n'   Device.o | awk '!x[$$0]++ { print("/home/rps/kernel2/"$$0) }' > /home/rps/kernel2/Device.mod
