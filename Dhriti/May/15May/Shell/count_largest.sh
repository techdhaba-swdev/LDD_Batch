#!/bin/bash

file_check="$1"

# Check if the input is a directory
if test -d "$file_check"; then
    echo "$file_check is a directory"
else    
    echo "$file_check is not a directory"
    exit 1  # Exit the script if not a directory
fi

# Function to count the number of files in a directory
count_files() {
    local dir="$1"
    find "$dir" -type f | wc -l
}      

num_files=$(count_files "$file_check")
echo "Total number of files: $num_files"

# Function to find the largest file in a directory
find_largest() {
    local dir="$1"
    local largest_file=""
    local largest_size=0

    # Loop through each file in the directory
    for entry in "$dir"/*; do
        # Skip if entry is not a regular file
        if [[ -f "$entry" ]]; then
            file_size=$(stat -c %s "$entry")
            if (( file_size > largest_size )); then
                largest_size=$file_size
                largest_file="$entry"
            fi
        fi
    done

    echo "Largest file: $largest_file"
    echo "Size: $largest_size bytes"
}

find_largest "$file_check"

echo "done"


