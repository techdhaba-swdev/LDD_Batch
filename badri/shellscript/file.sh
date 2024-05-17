#!/bin/bash

print_lines()
{
	local file="$1"
	local line_count=$(wc -l < "$file")
	echo "File: $file has $line_count lines."
}

files=("avg.c")


for file in "${files[@]}";
do
	print_lines "$file"

done
