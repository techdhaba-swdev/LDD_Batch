savedcmd_/home/rps/linux26/mman.mod := printf '%s\n'   mman.o | awk '!x[$$0]++ { print("/home/rps/linux26/"$$0) }' > /home/rps/linux26/mman.mod
