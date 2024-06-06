savedcmd_/home/rps/linux40/led.mod := printf '%s\n'   led.o | awk '!x[$$0]++ { print("/home/rps/linux40/"$$0) }' > /home/rps/linux40/led.mod
