savedcmd_/home/rps/linux1/cdev.mod := printf '%s\n'   cdev.o | awk '!x[$$0]++ { print("/home/rps/linux1/"$$0) }' > /home/rps/linux1/cdev.mod
