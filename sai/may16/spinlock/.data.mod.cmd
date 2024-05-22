savedcmd_/home/rps/may16/spinlock/data.mod := printf '%s\n'   data.o | awk '!x[$$0]++ { print("/home/rps/may16/spinlock/"$$0) }' > /home/rps/may16/spinlock/data.mod
