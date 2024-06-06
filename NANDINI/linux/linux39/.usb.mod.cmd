savedcmd_/home/rps/linux39/usb.mod := printf '%s\n'   usb.o | awk '!x[$$0]++ { print("/home/rps/linux39/"$$0) }' > /home/rps/linux39/usb.mod
