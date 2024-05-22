savedcmd_/home/rps/linux20/pgm.mod := printf '%s\n'   pgm.o | awk '!x[$$0]++ { print("/home/rps/linux20/"$$0) }' > /home/rps/linux20/pgm.mod
