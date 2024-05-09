savedcmd_/home/rps/may9/calculator.mod := printf '%s\n'   calculator.o | awk '!x[$$0]++ { print("/home/rps/may9/"$$0) }' > /home/rps/may9/calculator.mod
