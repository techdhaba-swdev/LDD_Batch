savedcmd_/home/rps/calcul_kernel/calcul_value.mod := printf '%s\n'   calcul_value.o | awk '!x[$$0]++ { print("/home/rps/calcul_kernel/"$$0) }' > /home/rps/calcul_kernel/calcul_value.mod
