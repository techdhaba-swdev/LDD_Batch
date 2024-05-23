savedcmd_/home/rps/may22/network/net_dev.mod := printf '%s\n'   net_dev.o | awk '!x[$$0]++ { print("/home/rps/may22/network/"$$0) }' > /home/rps/may22/network/net_dev.mod
