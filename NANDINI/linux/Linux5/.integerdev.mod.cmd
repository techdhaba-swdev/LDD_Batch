savedcmd_/home/rps/Linux5/integerdev.mod := printf '%s\n'   integerdev.o | awk '!x[$$0]++ { print("/home/rps/Linux5/"$$0) }' > /home/rps/Linux5/integerdev.mod
