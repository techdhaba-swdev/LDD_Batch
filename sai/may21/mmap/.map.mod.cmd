savedcmd_/home/rps/may21/mmap/map.mod := printf '%s\n'   map.o | awk '!x[$$0]++ { print("/home/rps/may21/mmap/"$$0) }' > /home/rps/may21/mmap/map.mod
