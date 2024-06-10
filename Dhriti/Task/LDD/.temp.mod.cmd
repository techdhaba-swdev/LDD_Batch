savedcmd_/home/rps/Task/LDD/temp.mod := printf '%s\n'   temp.o | awk '!x[$$0]++ { print("/home/rps/Task/LDD/"$$0) }' > /home/rps/Task/LDD/temp.mod
