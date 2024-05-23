savedcmd_/home/rps/may22/blockdri/block.mod := printf '%s\n'   block.o | awk '!x[$$0]++ { print("/home/rps/may22/blockdri/"$$0) }' > /home/rps/may22/blockdri/block.mod
