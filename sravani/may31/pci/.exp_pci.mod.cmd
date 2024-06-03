savedcmd_/home/rps/may31/pci/exp_pci.mod := printf '%s\n'   exp_pci.o | awk '!x[$$0]++ { print("/home/rps/may31/pci/"$$0) }' > /home/rps/may31/pci/exp_pci.mod
