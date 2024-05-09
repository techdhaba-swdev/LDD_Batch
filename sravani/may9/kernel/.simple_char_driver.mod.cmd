savedcmd_/home/rps/may9/kernel/simple_char_driver.mod := printf '%s\n'   simple_char_driver.o | awk '!x[$$0]++ { print("/home/rps/may9/kernel/"$$0) }' > /home/rps/may9/kernel/simple_char_driver.mod
