savedcmd_/home/rps/linux22/linux.mod := printf '%s\n'   linux.o | awk '!x[$$0]++ { print("/home/rps/linux22/"$$0) }' > /home/rps/linux22/linux.mod
