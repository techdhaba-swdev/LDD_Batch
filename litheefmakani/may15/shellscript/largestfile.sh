#!/bin/bash

#checks if directory argument is provided

if [ $# -ne 1 ]; then 
	echo "usage: $0 directory _path"
	exit 1
fi

directory = $1

#check if directory exists

if [ ! -d "$directory" ]; then 
	echo "Directory '$directory' does not exists."
	exit 1
fi

#find and lsit the top 10 largest files within in the directory structure
find "$directory" -type f -exec du -h {} + | sort -rh | head -n 10
