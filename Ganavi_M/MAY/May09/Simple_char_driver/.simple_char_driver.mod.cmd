savedcmd_/home/rps/MAY/May9/Simple_char_driver/simple_char_driver.mod := printf '%s\n'   simple_char_driver.o | awk '!x[$$0]++ { print("/home/rps/MAY/May9/Simple_char_driver/"$$0) }' > /home/rps/MAY/May9/Simple_char_driver/simple_char_driver.mod