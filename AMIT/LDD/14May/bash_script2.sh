#!/bin/bash

# Function to print number of lines in a file
print_num_lines() {
    echo "Number of lines in $1: $(wc -l < "$1")"
}

# List of file names
file_names=("text1.txt" "text2.txt" "text3.txt")

# Iterate over the list of file names
for file in "${file_names[@]}"; do
    print_num_lines "$file"
done
