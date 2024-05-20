#!/bin/bash
DIR_PATH="/home/rps/Desktop/GAZAL/ALL_PROGRAMS/DAY29_MAY14/mine"

file_count=$(find "$DIR_PATH" -type f | wc -l)
echo "number of files : $file_count"

largest_file=$(find "$DIR_PATH" -type f -exec ls -s {} + | sort -n -r | head -n 1 | awk '{print $2}')
echo "largest file:$largest_file"
