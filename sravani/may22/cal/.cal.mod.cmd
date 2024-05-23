savedcmd_/home/rps/may22/cal/cal.mod := printf '%s\n'   cal.o | awk '!x[$$0]++ { print("/home/rps/may22/cal/"$$0) }' > /home/rps/may22/cal/cal.mod
