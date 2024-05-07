savedcmd_/home/rps/may7/device/device1/device.mod := printf '%s\n'   device.o | awk '!x[$$0]++ { print("/home/rps/may7/device/device1/"$$0) }' > /home/rps/may7/device/device1/device.mod
