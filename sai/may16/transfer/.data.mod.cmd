savedcmd_/home/rps/may16/transfer/data.mod := printf '%s\n'   data.o | awk '!x[$$0]++ { print("/home/rps/may16/transfer/"$$0) }' > /home/rps/may16/transfer/data.mod
