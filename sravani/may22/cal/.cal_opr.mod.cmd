savedcmd_/home/rps/may22/cal/cal_opr.mod := printf '%s\n'   cal_opr.o | awk '!x[$$0]++ { print("/home/rps/may22/cal/"$$0) }' > /home/rps/may22/cal/cal_opr.mod
