savedcmd_/home/rps/22MAY/LLSEEK/kmodule.mod := printf '%s\n'   kmodule.o | awk '!x[$$0]++ { print("/home/rps/22MAY/LLSEEK/"$$0) }' > /home/rps/22MAY/LLSEEK/kmodule.mod
