savedcmd_/home/rps/linux38/usb.mod := printf '%s\n'   usb.o | awk '!x[$$0]++ { print("/home/rps/linux38/"$$0) }' > /home/rps/linux38/usb.mod
