savedcmd_/home/rps/linux17/data.mod := printf '%s\n'   data.o | awk '!x[$$0]++ { print("/home/rps/linux17/"$$0) }' > /home/rps/linux17/data.mod
