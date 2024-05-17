#!/bin/bash
# Check if a directory path is provided
if [ -z "$1" ]; then
    echo "Please provide a directory path as an argument."
    exit 1
fi

# Store the provided directory path
dir_path="$1"

# Initialize the file count and largest file variables
file_count=0
largest_file=""
largest_file_size=0

# Function to recursively count files and find the largest file
count_files() {
    local dir="$1"
    for entry in "$dir"/*; do
        if [ -f "$entry" ]; then
            file_count=$((file_count + 1))
            size=$(du -b "$entry" | cut -f1)
            if [ "$size" -gt "$largest_file_size" ]; then
                largest_file="$entry"
                largest_file_size="$size"
            fi
        elif [ -d "$entry" ]; then
            count_files "$entry"
        fi
    done
}

# Call the function with the provided directory path
count_files "$dir_path"

# Print the results
echo "Number of files: $file_count"
echo "Largest file: $largest_file ($(du -h "$largest_file" | cut -f1))"
