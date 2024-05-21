savedcmd_/home/rps/21stmayLDD/PROGRAM/kernel_code.mod := printf '%s\n'   kernel_code.o | awk '!x[$$0]++ { print("/home/rps/21stmayLDD/PROGRAM/"$$0) }' > /home/rps/21stmayLDD/PROGRAM/kernel_code.mod
