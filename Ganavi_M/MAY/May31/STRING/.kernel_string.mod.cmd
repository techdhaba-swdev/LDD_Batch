savedcmd_/home/rps/MAY/May31/STRING/kernel_string.mod := printf '%s\n'   kernel_string.o | awk '!x[$$0]++ { print("/home/rps/MAY/May31/STRING/"$$0) }' > /home/rps/MAY/May31/STRING/kernel_string.mod
