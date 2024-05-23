savedcmd_/home/rps/22MAY/NETWORKING/net_device.mod := printf '%s\n'   net_device.o | awk '!x[$$0]++ { print("/home/rps/22MAY/NETWORKING/"$$0) }' > /home/rps/22MAY/NETWORKING/net_device.mod
