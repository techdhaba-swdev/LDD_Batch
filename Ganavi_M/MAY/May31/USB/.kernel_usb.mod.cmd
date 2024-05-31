savedcmd_/home/rps/MAY/May31/USB/kernel_usb.mod := printf '%s\n'   kernel_usb.o | awk '!x[$$0]++ { print("/home/rps/MAY/May31/USB/"$$0) }' > /home/rps/MAY/May31/USB/kernel_usb.mod
