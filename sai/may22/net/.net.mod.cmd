savedcmd_/home/rps/may22/net/net.mod := printf '%s\n'   net.o | awk '!x[$$0]++ { print("/home/rps/may22/net/"$$0) }' > /home/rps/may22/net/net.mod
