savedcmd_/home/rps/MAY/May31/PCI_Device/pci_device.mod := printf '%s\n'   pci_device.o | awk '!x[$$0]++ { print("/home/rps/MAY/May31/PCI_Device/"$$0) }' > /home/rps/MAY/May31/PCI_Device/pci_device.mod
