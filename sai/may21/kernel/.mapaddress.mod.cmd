savedcmd_/home/rps/may21/kernel/mapaddress.mod := printf '%s\n'   mapaddress.o | awk '!x[$$0]++ { print("/home/rps/may21/kernel/"$$0) }' > /home/rps/may21/kernel/mapaddress.mod
