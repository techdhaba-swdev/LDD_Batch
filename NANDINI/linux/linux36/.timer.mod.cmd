savedcmd_/home/rps/linux36/timer.mod := printf '%s\n'   timer.o | awk '!x[$$0]++ { print("/home/rps/linux36/"$$0) }' > /home/rps/linux36/timer.mod
