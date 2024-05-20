savedcmd_/home/rps/may15/system_call.mod := printf '%s\n'   system_call.o | awk '!x[$$0]++ { print("/home/rps/may15/"$$0) }' > /home/rps/may15/system_call.mod
