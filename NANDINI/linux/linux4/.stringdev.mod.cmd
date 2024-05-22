savedcmd_/home/rps/linux4/stringdev.mod := printf '%s\n'   stringdev.o | awk '!x[$$0]++ { print("/home/rps/linux4/"$$0) }' > /home/rps/linux4/stringdev.mod
