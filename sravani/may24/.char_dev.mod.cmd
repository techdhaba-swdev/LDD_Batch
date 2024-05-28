savedcmd_/home/rps/may24/char_dev.mod := printf '%s\n'   char_dev.o | awk '!x[$$0]++ { print("/home/rps/may24/"$$0) }' > /home/rps/may24/char_dev.mod
