savedcmd_/home/rps/may9_LDD/ioc/device.mod := printf '%s\n'   device.o | awk '!x[$$0]++ { print("/home/rps/may9_LDD/ioc/"$$0) }' > /home/rps/may9_LDD/ioc/device.mod
