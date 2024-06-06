savedcmd_/home/rps/7May/Kernel2/char.mod := printf '%s\n'   char.o | awk '!x[$$0]++ { print("/home/rps/7May/Kernel2/"$$0) }' > /home/rps/7May/Kernel2/char.mod
