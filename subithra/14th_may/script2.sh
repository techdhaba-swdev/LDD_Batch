#!/bin/bash

print_lines() {
    lines=$(wc -l < "$1")
    echo "File $1 has $lines lines."
}

files=("subi.txt" "subithra.txt" "file1.txt")

for file in "${files[@]}"; do
    print_lines "$file"
done
