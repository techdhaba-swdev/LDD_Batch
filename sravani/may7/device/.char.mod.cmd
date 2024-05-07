savedcmd_/home/rps/may7/device/char.mod := printf '%s\n'   char.o | awk '!x[$$0]++ { print("/home/rps/may7/device/"$$0) }' > /home/rps/may7/device/char.mod
