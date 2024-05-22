savedcmd_/home/rps/may20/poll_opr.mod := printf '%s\n'   poll_opr.o | awk '!x[$$0]++ { print("/home/rps/may20/"$$0) }' > /home/rps/may20/poll_opr.mod
