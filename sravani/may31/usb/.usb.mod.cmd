savedcmd_/home/rps/may31/usb/usb.mod := printf '%s\n'   usb.o | awk '!x[$$0]++ { print("/home/rps/may31/usb/"$$0) }' > /home/rps/may31/usb/usb.mod
