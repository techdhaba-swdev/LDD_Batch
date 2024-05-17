#!/bin/bash
#check the script recieve one arugument
if [ $# -ne 1 ];
then
	echo "usage: $0 <directory>"
	exit 1
fi
directory=$1
file_count=0
largest_file=""
largest_size=0
#function to count the filess
count_files() {
	local dir="$1"
	local files=("$dir"/*)
	for file in "${files[@]}"; 
	do
		if [ -f "$file" ];
		then 
			file_size=$(du -b "$file" | cut -f1)
			file_count=$(($file_count + 1))

			if [ $file_size -gt $largest_size ]; then
				$largest_size=$file_size
				$largest_file="$file"
			fi
		fi
	done
}
count_files "$directory"
echo "number of files : $file_count"
echo "largest file : "$largest_file"


