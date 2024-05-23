savedcmd_/home/rps/22MAY/MMAP_TASK/madd.mod := printf '%s\n'   madd.o | awk '!x[$$0]++ { print("/home/rps/22MAY/MMAP_TASK/"$$0) }' > /home/rps/22MAY/MMAP_TASK/madd.mod
