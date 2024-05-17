#!/bin/bash

# Check if the user provided a directory path
if [ $# -ne 1 ]; then
    echo "Usage: $0 <directory_path>"
    exit 1
fi

# Check if the provided path is a directory
if [ ! -d "$1" ]; then
    echo "$1 is not a directory"
    exit 1
fi

# Count the number of regular files
num_files=$(find "$1" -type f | wc -l)

echo "Number of files: $num_files"

# Find the largest file
largest_file=$(find "$1" -type f -exec du -b {} + | sort -n -r | head -n 1 | cut -f 2)

echo "Largest file: $largest_file"
