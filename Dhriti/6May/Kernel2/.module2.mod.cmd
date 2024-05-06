savedcmd_/home/rps/6May/Kernel2/module2.mod := printf '%s\n'   module2.o | awk '!x[$$0]++ { print("/home/rps/6May/Kernel2/"$$0) }' > /home/rps/6May/Kernel2/module2.mod
