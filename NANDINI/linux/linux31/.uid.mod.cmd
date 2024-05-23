savedcmd_/home/rps/linux31/uid.mod := printf '%s\n'   uid.o | awk '!x[$$0]++ { print("/home/rps/linux31/"$$0) }' > /home/rps/linux31/uid.mod
