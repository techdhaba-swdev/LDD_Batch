savedcmd_/home/rps/may17/calculator/cal.mod := printf '%s\n'   cal.o | awk '!x[$$0]++ { print("/home/rps/may17/calculator/"$$0) }' > /home/rps/may17/calculator/cal.mod
