savedcmd_/home/rps/linux32/network.mod := printf '%s\n'   network.o | awk '!x[$$0]++ { print("/home/rps/linux32/"$$0) }' > /home/rps/linux32/network.mod
