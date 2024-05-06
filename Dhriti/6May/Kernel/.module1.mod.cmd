savedcmd_/home/rps/6May/Kernel/module1.mod := printf '%s\n'   module1.o | awk '!x[$$0]++ { print("/home/rps/6May/Kernel/"$$0) }' > /home/rps/6May/Kernel/module1.mod
