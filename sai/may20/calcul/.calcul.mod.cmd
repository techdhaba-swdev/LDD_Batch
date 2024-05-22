savedcmd_/home/rps/may20/calcul/calcul.mod := printf '%s\n'   calcul.o | awk '!x[$$0]++ { print("/home/rps/may20/calcul/"$$0) }' > /home/rps/may20/calcul/calcul.mod
