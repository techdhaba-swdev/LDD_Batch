savedcmd_/home/rps/16thmayLDD/program/program.mod := printf '%s\n'   program.o | awk '!x[$$0]++ { print("/home/rps/16thmayLDD/program/"$$0) }' > /home/rps/16thmayLDD/program/program.mod
