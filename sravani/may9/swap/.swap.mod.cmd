savedcmd_/home/rps/may9/swap/swap.mod := printf '%s\n'   swap.o | awk '!x[$$0]++ { print("/home/rps/may9/swap/"$$0) }' > /home/rps/may9/swap/swap.mod
