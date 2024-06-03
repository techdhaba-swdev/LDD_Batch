savedcmd_/home/rps/may29/kthread12/even_odd.mod := printf '%s\n'   even_odd.o | awk '!x[$$0]++ { print("/home/rps/may29/kthread12/"$$0) }' > /home/rps/may29/kthread12/even_odd.mod
