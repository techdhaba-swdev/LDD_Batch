savedcmd_/home/rps/may20/poll/example.mod := printf '%s\n'   example.o | awk '!x[$$0]++ { print("/home/rps/may20/poll/"$$0) }' > /home/rps/may20/poll/example.mod
