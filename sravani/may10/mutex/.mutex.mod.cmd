savedcmd_/home/rps/may10/mutex/mutex.mod := printf '%s\n'   mutex.o | awk '!x[$$0]++ { print("/home/rps/may10/mutex/"$$0) }' > /home/rps/may10/mutex/mutex.mod
