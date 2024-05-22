#!/bin/bash

# Check if a directory path is provided
if [ -z "$1" ]; then
    echo "Usage: $0 <directory_path>"
    exit 1
fi

# Assign the provided directory path to a variable
DIR_PATH=$1

# Check if the provided path is a valid directory
if [ ! -d "$DIR_PATH" ]; then
    echo "Error: $DIR_PATH is not a valid directory."
    exit 1
fi

# Count the number of regular files within the directory and its subdirectories
file_count=$(find "$DIR_PATH" -type f | wc -l)
echo "Number of files: $file_count"

# Find the largest file within the directory and its subdirectories
largest_file=$(find "$DIR_PATH" -type f -exec ls -s {} + | sort -n -r | head -n 1 | awk '{print $2}')
if [ -z "$largest_file" ]; then
    echo "No files found in the directory."
else
    largest_file_size=$(stat -c%s "$largest_file")
    echo "Largest file: $largest_file"
    echo "Size: $largest_file_size bytes"
fi
