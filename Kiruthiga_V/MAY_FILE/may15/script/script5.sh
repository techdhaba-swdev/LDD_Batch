#!/bin/bash

count_files() {
   
    count=$(find "$1" -type f | wc -l)
    echo "Number of files: $count"
}

find_largest_file() {
 
    largest_file=$(find "$1" -type f -exec du -b {} + | sort -n | tail -n1)
    size=$(echo "$largest_file" | awk '{print $1}')
    file=$(echo "$largest_file" | cut -f2-)
    echo "Largest file: $file ($size bytes)"
}

directory="/home/rps/Desktop/daywise/may15/script"

if [ ! -d "$directory" ]; then
    echo "Error: $directory is not a directory"
    exit 1
fi

count_files "$directory"
find_largest_file "$directory"




