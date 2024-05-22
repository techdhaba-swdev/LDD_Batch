savedcmd_/home/rps/may20/calculator/cal.mod := printf '%s\n'   cal.o | awk '!x[$$0]++ { print("/home/rps/may20/calculator/"$$0) }' > /home/rps/may20/calculator/cal.mod
