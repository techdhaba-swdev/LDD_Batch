savedcmd_/home/rps/linux23/poll.mod := printf '%s\n'   poll.o | awk '!x[$$0]++ { print("/home/rps/linux23/"$$0) }' > /home/rps/linux23/poll.mod
