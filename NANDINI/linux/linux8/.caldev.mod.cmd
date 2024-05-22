savedcmd_/home/rps/linux8/caldev.mod := printf '%s\n'   caldev.o | awk '!x[$$0]++ { print("/home/rps/linux8/"$$0) }' > /home/rps/linux8/caldev.mod
