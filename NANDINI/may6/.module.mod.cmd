savedcmd_/home/rps/may6/module.mod := printf '%s\n'   module.o | awk '!x[$$0]++ { print("/home/rps/may6/"$$0) }' > /home/rps/may6/module.mod
