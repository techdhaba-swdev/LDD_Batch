savedcmd_/home/rps/june3/led.mod := printf '%s\n'   led.o | awk '!x[$$0]++ { print("/home/rps/june3/"$$0) }' > /home/rps/june3/led.mod
