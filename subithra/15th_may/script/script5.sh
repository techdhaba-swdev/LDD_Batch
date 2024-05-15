#!/bin/bash

count_files() {
    dir="$1"
    count=$(find "$dir" -type f | wc -l)
    echo "Number of files: $count"
}

find_largest_file() {
    dir="$1"
    largest_file=$(find "$dir" -type f -exec du -b {} + | sort -n | tail -n1)
    size=$(echo "$largest_file" | awk '{print $1}')
    file=$(echo "$largest_file" | cut -f2-)
    echo "Largest file: $file ($size bytes)"
}



directory="$1"

if [ ! -d "$directory" ]; then
    echo "Error: $directory is not a directory"
    exit 1
fi

count_files "$directory"
find_largest_file "$directory"
