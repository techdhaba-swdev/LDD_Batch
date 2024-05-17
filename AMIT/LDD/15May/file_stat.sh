#!/bin/bash


directory_path="/home/rps/Desktop/Demo/LDD_Batch/AMIT/LDD/14May"

# Validate if the provided path exists and is a directory
if [ ! -d "$directory_path" ]; then
    echo "Error: '$directory_path' is not a valid directory."
    exit 1
fi


# Count the number of regular files (not directories)
file_count=$(find "$directory_path" -type f | wc -l)

# Find the largest file (by size)
largest_file=$(find "$directory_path" -type f -exec du -b {} + | sort -n | tail -n 1 | cut -f 2)

echo "Number of files in '$directory_path': $file_count"
echo "Largest file in '$directory_path': $largest_file"
