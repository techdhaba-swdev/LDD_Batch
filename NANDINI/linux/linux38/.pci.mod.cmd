savedcmd_/home/rps/linux38/pci.mod := printf '%s\n'   pci.o | awk '!x[$$0]++ { print("/home/rps/linux38/"$$0) }' > /home/rps/linux38/pci.mod
