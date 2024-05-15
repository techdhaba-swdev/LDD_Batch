#!/bin/bash

# Check if a directory path is provided as an argument
if [ $# -ne 1 ]; then
    echo "Usage: $0 <directory_path>"
    exit 1
fi

# Count the number of files in the directory and its subdirectories
file_count=$(find "$1" -type f | wc -l)
echo "Number of files in $1: $file_count"

# Find the largest file in the directory and its subdirectories
largest_file=$(find "$1" -type f -exec du -a {} + | sort -nr | head -n 1 | cut -f 2-)
echo "Largest file in $1: $largest_file"
