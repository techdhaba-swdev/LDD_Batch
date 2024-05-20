savedcmd_/home/rps/16May_LDD/Data_transfer/device.mod := printf '%s\n'   device.o | awk '!x[$$0]++ { print("/home/rps/16May_LDD/Data_transfer/"$$0) }' > /home/rps/16May_LDD/Data_transfer/device.mod
