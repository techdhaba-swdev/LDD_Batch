savedcmd_/home/rps/may15/sys_call/custom_syscall.mod := printf '%s\n'   custom_syscall.o | awk '!x[$$0]++ { print("/home/rps/may15/sys_call/"$$0) }' > /home/rps/may15/sys_call/custom_syscall.mod
