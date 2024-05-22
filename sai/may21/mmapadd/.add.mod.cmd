savedcmd_/home/rps/may21/mmapadd/add.mod := printf '%s\n'   add.o | awk '!x[$$0]++ { print("/home/rps/may21/mmapadd/"$$0) }' > /home/rps/may21/mmapadd/add.mod
