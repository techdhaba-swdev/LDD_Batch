savedcmd_/home/rps/21MAY_LDD/MMAP/mmap.mod := printf '%s\n'   mmap.o | awk '!x[$$0]++ { print("/home/rps/21MAY_LDD/MMAP/"$$0) }' > /home/rps/21MAY_LDD/MMAP/mmap.mod
