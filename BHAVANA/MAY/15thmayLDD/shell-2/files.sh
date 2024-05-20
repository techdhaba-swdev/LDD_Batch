#!/bin/bash

file1="file1.txt"
file2="file2.txt"
file3="file3.txt"

for file in "$file1" "$file2" "$file3"; do
	num_lines=$(wc -l < "$file")
	echo "File: $file , Number of lines: $num_lines"
done
