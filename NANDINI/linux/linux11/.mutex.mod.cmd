savedcmd_/home/rps/linux11/mutex.mod := printf '%s\n'   mutex.o | awk '!x[$$0]++ { print("/home/rps/linux11/"$$0) }' > /home/rps/linux11/mutex.mod
