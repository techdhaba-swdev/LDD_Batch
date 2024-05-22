savedcmd_/home/rps/linux2/mychardev.mod := printf '%s\n'   mychardev.o | awk '!x[$$0]++ { print("/home/rps/linux2/"$$0) }' > /home/rps/linux2/mychardev.mod
