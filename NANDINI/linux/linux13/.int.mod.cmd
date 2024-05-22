savedcmd_/home/rps/linux13/int.mod := printf '%s\n'   int.o | awk '!x[$$0]++ { print("/home/rps/linux13/"$$0) }' > /home/rps/linux13/int.mod
