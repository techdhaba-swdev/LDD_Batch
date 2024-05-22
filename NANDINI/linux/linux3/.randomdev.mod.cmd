savedcmd_/home/rps/linux3/randomdev.mod := printf '%s\n'   randomdev.o | awk '!x[$$0]++ { print("/home/rps/linux3/"$$0) }' > /home/rps/linux3/randomdev.mod
