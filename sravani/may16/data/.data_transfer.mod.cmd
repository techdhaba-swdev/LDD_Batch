savedcmd_/home/rps/may16/data/data_transfer.mod := printf '%s\n'   data_transfer.o | awk '!x[$$0]++ { print("/home/rps/may16/data/"$$0) }' > /home/rps/may16/data/data_transfer.mod
