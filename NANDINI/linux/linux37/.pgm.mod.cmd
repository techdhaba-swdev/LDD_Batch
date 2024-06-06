savedcmd_/home/rps/linux37/pgm.mod := printf '%s\n'   pgm.o | awk '!x[$$0]++ { print("/home/rps/linux37/"$$0) }' > /home/rps/linux37/pgm.mod
