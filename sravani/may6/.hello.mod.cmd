savedcmd_/home/rps/may6/hello.mod := printf '%s\n'   hello.o | awk '!x[$$0]++ { print("/home/rps/may6/"$$0) }' > /home/rps/may6/hello.mod
