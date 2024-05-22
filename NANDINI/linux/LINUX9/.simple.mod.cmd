savedcmd_/home/rps/LINUX9/simple.mod := printf '%s\n'   simple.o | awk '!x[$$0]++ { print("/home/rps/LINUX9/"$$0) }' > /home/rps/LINUX9/simple.mod
