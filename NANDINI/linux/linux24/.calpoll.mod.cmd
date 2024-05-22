savedcmd_/home/rps/linux24/calpoll.mod := printf '%s\n'   calpoll.o | awk '!x[$$0]++ { print("/home/rps/linux24/"$$0) }' > /home/rps/linux24/calpoll.mod
