savedcmd_/home/rps/subithra_s/Documents/29th_may/procfs/procfs.mod := printf '%s\n'   procfs.o | awk '!x[$$0]++ { print("/home/rps/subithra_s/Documents/29th_may/procfs/"$$0) }' > /home/rps/subithra_s/Documents/29th_may/procfs/procfs.mod