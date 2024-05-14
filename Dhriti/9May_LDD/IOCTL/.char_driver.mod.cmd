savedcmd_/home/rps/9May_LDD/IOCTL/char_driver.mod := printf '%s\n'   char_driver.o | awk '!x[$$0]++ { print("/home/rps/9May_LDD/IOCTL/"$$0) }' > /home/rps/9May_LDD/IOCTL/char_driver.mod
