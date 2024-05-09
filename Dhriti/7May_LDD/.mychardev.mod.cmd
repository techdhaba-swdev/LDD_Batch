savedcmd_/home/rps/7May/mychardev.mod := printf '%s\n'   mychardev.o | awk '!x[$$0]++ { print("/home/rps/7May/"$$0) }' > /home/rps/7May/mychardev.mod
