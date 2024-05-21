savedcmd_/home/rps/21stmayLDD/BUFFER/kernel.mod := printf '%s\n'   kernel.o | awk '!x[$$0]++ { print("/home/rps/21stmayLDD/BUFFER/"$$0) }' > /home/rps/21stmayLDD/BUFFER/kernel.mod
