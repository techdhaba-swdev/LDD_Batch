savedcmd_/home/rps/may22/cred/cred.mod := printf '%s\n'   cred.o | awk '!x[$$0]++ { print("/home/rps/may22/cred/"$$0) }' > /home/rps/may22/cred/cred.mod
