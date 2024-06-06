savedcmd_/home/rps/linux41/light.mod := printf '%s\n'   light.o | awk '!x[$$0]++ { print("/home/rps/linux41/"$$0) }' > /home/rps/linux41/light.mod
