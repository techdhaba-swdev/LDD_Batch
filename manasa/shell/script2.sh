#!/bin/bash

# Function to print the number of lines in a file
print_lines() {
    local file="$1"
    local line_count=$(wc -l < "$file")
    echo "File: $file has $line_count lines."
}

# List of file names
files=("file1.txt" "file2.txt" "file3.txt")

# Loop over the list of file names
for file in "${files[@]}"; do
    # Call the function for each file
    print_lines "$file"
done
