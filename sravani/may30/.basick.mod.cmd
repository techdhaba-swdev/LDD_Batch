savedcmd_/home/rps/may30/basick.mod := printf '%s\n'   basick.o | awk '!x[$$0]++ { print("/home/rps/may30/"$$0) }' > /home/rps/may30/basick.mod
