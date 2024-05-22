savedcmd_/home/rps/linux7/add.mod := printf '%s\n'   add.o | awk '!x[$$0]++ { print("/home/rps/linux7/"$$0) }' > /home/rps/linux7/add.mod
