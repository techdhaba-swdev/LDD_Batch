savedcmd_/home/rps/linux12/calmutex.mod := printf '%s\n'   calmutex.o | awk '!x[$$0]++ { print("/home/rps/linux12/"$$0) }' > /home/rps/linux12/calmutex.mod
