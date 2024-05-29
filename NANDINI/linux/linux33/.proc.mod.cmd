savedcmd_/home/rps/linux33/proc.mod := printf '%s\n'   proc.o | awk '!x[$$0]++ { print("/home/rps/linux33/"$$0) }' > /home/rps/linux33/proc.mod
