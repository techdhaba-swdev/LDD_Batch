savedcmd_/home/rps/Linux21/lincal.mod := printf '%s\n'   lincal.o | awk '!x[$$0]++ { print("/home/rps/Linux21/"$$0) }' > /home/rps/Linux21/lincal.mod
