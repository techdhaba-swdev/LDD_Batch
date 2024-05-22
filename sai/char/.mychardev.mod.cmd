savedcmd_/home/rps/char/mychardev.mod := printf '%s\n'   mychardev.o | awk '!x[$$0]++ { print("/home/rps/char/"$$0) }' > /home/rps/char/mychardev.mod
