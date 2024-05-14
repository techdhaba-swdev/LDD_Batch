savedcmd_/home/rps/11May/double_num.mod := printf '%s\n'   double_num.o | awk '!x[$$0]++ { print("/home/rps/11May/"$$0) }' > /home/rps/11May/double_num.mod
