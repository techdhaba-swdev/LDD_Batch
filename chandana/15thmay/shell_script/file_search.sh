#!/bin/bash

# define the directory path
directory="shell"

# count the number of files
num_files=$(find "$directory" -type f | wc -l)

# find the largest file
largest_file=$(find "$directory" -type f -exec ls -lS {} + | head -n 1)

# output the results

echo "Number of files in directory '$directory':$num_files"
echo "Largest file in directory structure:"
echo "$largest_file"
