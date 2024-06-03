savedcmd_/home/rps/may29/sys.mod := printf '%s\n'   sys.o | awk '!x[$$0]++ { print("/home/rps/may29/"$$0) }' > /home/rps/may29/sys.mod
