savedcmd_/home/rps/21MAY_LDD/MMAP_ADD/add.mod := printf '%s\n'   add.o | awk '!x[$$0]++ { print("/home/rps/21MAY_LDD/MMAP_ADD/"$$0) }' > /home/rps/21MAY_LDD/MMAP_ADD/add.mod
