savedcmd_/home/rps/may29/interrupt/int.mod := printf '%s\n'   int.o | awk '!x[$$0]++ { print("/home/rps/may29/interrupt/"$$0) }' > /home/rps/may29/interrupt/int.mod
