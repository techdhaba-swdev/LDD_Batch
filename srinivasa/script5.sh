#!/bin/bash
if [ $# -ne 1 ];
then 
	echo "usage : $0 <directory>"
	exit 1
fi
directory=$1
file_count=$(find "$directory" -type f | wc -l)
echo "number of files : $file_count"
largest_file=$(find "$directory" -type f -exec du -h {} + | sort -rh | head -n 1 | awk '{print $2}')
echo "largest file : $largest_file"

