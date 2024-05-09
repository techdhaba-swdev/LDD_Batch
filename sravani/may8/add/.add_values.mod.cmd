savedcmd_/home/rps/may8/add/add_values.mod := printf '%s\n'   add_values.o | awk '!x[$$0]++ { print("/home/rps/may8/add/"$$0) }' > /home/rps/may8/add/add_values.mod
