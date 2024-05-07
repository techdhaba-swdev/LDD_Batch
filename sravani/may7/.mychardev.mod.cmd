savedcmd_/home/rps/may7/mychardev.mod := printf '%s\n'   mychardev.o | awk '!x[$$0]++ { print("/home/rps/may7/"$$0) }' > /home/rps/may7/mychardev.mod
