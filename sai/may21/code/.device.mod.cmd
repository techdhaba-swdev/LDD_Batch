savedcmd_/home/rps/may21/code/device.mod := printf '%s\n'   device.o | awk '!x[$$0]++ { print("/home/rps/may21/code/"$$0) }' > /home/rps/may21/code/device.mod
