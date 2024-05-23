savedcmd_/home/rps/may22/blockdri/my_net_dev.mod := printf '%s\n'   my_net_dev.o | awk '!x[$$0]++ { print("/home/rps/may22/blockdri/"$$0) }' > /home/rps/may22/blockdri/my_net_dev.mod
