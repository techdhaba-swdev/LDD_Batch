savedcmd_/home/rps/20MAY_LDD/POLL/kernel1.mod := printf '%s\n'   kernel1.o | awk '!x[$$0]++ { print("/home/rps/20MAY_LDD/POLL/"$$0) }' > /home/rps/20MAY_LDD/POLL/kernel1.mod
