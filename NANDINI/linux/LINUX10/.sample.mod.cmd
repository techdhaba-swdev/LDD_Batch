savedcmd_/home/rps/LINUX10/sample.mod := printf '%s\n'   sample.o | awk '!x[$$0]++ { print("/home/rps/LINUX10/"$$0) }' > /home/rps/LINUX10/sample.mod
