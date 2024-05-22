savedcmd_/home/rps/linux19/magic.mod := printf '%s\n'   magic.o | awk '!x[$$0]++ { print("/home/rps/linux19/"$$0) }' > /home/rps/linux19/magic.mod
