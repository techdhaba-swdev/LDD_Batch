savedcmd_/home/rps/may20/mmap/mmap.mod := printf '%s\n'   mmap.o | awk '!x[$$0]++ { print("/home/rps/may20/mmap/"$$0) }' > /home/rps/may20/mmap/mmap.mod
