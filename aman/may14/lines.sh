#!/bin/bash
print_lines() {
	filename=$1
	num_lines=$(wc -l < "$filename")
	echo "File $filename has $num_lines lines."
}
files_names=("sample.txt")
for file in "${file_names[@]}"; do
	print_lines "$file"
done
