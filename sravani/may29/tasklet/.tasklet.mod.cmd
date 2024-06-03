savedcmd_/home/rps/may29/tasklet/tasklet.mod := printf '%s\n'   tasklet.o | awk '!x[$$0]++ { print("/home/rps/may29/tasklet/"$$0) }' > /home/rps/may29/tasklet/tasklet.mod
