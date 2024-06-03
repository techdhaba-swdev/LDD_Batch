savedcmd_/home/rps/may29/kthread/thread.mod := printf '%s\n'   thread.o | awk '!x[$$0]++ { print("/home/rps/may29/kthread/"$$0) }' > /home/rps/may29/kthread/thread.mod
