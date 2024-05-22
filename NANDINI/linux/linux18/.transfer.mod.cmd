savedcmd_/home/rps/linux18/transfer.mod := printf '%s\n'   transfer.o | awk '!x[$$0]++ { print("/home/rps/linux18/"$$0) }' > /home/rps/linux18/transfer.mod
