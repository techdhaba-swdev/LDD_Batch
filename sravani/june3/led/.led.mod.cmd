savedcmd_/home/rps/june3/led/led.mod := printf '%s\n'   led.o | awk '!x[$$0]++ { print("/home/rps/june3/led/"$$0) }' > /home/rps/june3/led/led.mod
