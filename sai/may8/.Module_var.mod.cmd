savedcmd_/home/rps/may8/Module_var.mod := printf '%s\n'   Module_var.o | awk '!x[$$0]++ { print("/home/rps/may8/"$$0) }' > /home/rps/may8/Module_var.mod
