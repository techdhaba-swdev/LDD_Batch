savedcmd_/home/rps/LDD_Batch/Sarath/LinuxDeviceDrivers/chardev/mychardev.mod := printf '%s\n'   mychardev.o | awk '!x[$$0]++ { print("/home/rps/LDD_Batch/Sarath/LinuxDeviceDrivers/chardev/"$$0) }' > /home/rps/LDD_Batch/Sarath/LinuxDeviceDrivers/chardev/mychardev.mod