files=("add.c" "array.c" "main.c" "sim.c")
for (( i =0; i<4; i++))
do
	echo "no of lines for file ${files[i]} is $(wc -l ${files[i]})";
done
