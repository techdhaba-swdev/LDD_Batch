savedcmd_/home/rps/milestone4/revstring.mod := printf '%s\n'   revstring.o | awk '!x[$$0]++ { print("/home/rps/milestone4/"$$0) }' > /home/rps/milestone4/revstring.mod
