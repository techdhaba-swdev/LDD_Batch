#!/bin/bash

# Function to count lines in a file
count_lines() {
    lines=$(wc -l < "$1")
    echo "File $1 has $lines lines."
}

# List of file names
files=("file1.txt" "file2.txt" "file3.txt")

# Iterate over each file and call count_lines function
for file in "${files[@]}"; do
    count_lines "$file"
done
