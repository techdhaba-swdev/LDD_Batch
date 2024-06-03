savedcmd_/home/rps/may30/timer.mod := printf '%s\n'   timer.o | awk '!x[$$0]++ { print("/home/rps/may30/"$$0) }' > /home/rps/may30/timer.mod
