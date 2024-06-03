savedcmd_/home/rps/may29/tasklet1/tasklet1.mod := printf '%s\n'   tasklet1.o | awk '!x[$$0]++ { print("/home/rps/may29/tasklet1/"$$0) }' > /home/rps/may29/tasklet1/tasklet1.mod
