#!/bin/bash

# Define the function to print the number of lines in a file
print_lines() {
    local file="$1"
    local num_lines=$(wc -l < "$file")
    echo "File: $file has $num_lines lines."
}

# List of file names to iterate over
file_list=("file1.txt" "file2.txt" "file3.txt")

# Loop through the list of file names
for file in "${file_list[@]}"; do
    # Call the function for each file
    print_lines "$file"
done