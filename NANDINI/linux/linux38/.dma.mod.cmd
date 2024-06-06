savedcmd_/home/rps/linux38/dma.mod := printf '%s\n'   dma.o | awk '!x[$$0]++ { print("/home/rps/linux38/"$$0) }' > /home/rps/linux38/dma.mod
