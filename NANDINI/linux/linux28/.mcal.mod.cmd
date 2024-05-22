savedcmd_/home/rps/linux28/mcal.mod := printf '%s\n'   mcal.o | awk '!x[$$0]++ { print("/home/rps/linux28/"$$0) }' > /home/rps/linux28/mcal.mod
