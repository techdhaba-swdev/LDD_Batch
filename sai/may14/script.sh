#!/bin/bash


print_lines(){

	local file="$1"
	local count=$(wc -L < "$file")

	echo "File:$file has $count lines."
}

file=("avg.c")

for file in "${file[@]}"
do
	print_lines "$file"
done
