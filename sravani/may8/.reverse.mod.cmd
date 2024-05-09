savedcmd_/home/rps/may8/reverse.mod := printf '%s\n'   reverse.o | awk '!x[$$0]++ { print("/home/rps/may8/"$$0) }' > /home/rps/may8/reverse.mod
