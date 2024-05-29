savedcmd_/home/rps/linux35/interrupt.mod := printf '%s\n'   interrupt.o | awk '!x[$$0]++ { print("/home/rps/linux35/"$$0) }' > /home/rps/linux35/interrupt.mod
