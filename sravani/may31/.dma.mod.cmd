savedcmd_/home/rps/may31/dma.mod := printf '%s\n'   dma.o | awk '!x[$$0]++ { print("/home/rps/may31/"$$0) }' > /home/rps/may31/dma.mod
