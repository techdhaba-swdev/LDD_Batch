#!/bin/bash

file_check="$1"


if test -d "$file_check";
then 
	echo "$file_check is a directory"
else
	echo "$file_check is not a direccctory"
fi

count_files(){
	dir="$1"
	find "$dir" -type f | wc -l
}

num_files=$(count_files "$file_check")

echo "Total no of files: $num_files"

find_largest() { 
	 dir="$1" 
	largest_file="" 
	largest_size=0
       	# Loop through each file in the directory
       	for entry in "$dir/"*; do 
		# Skip if entry is a hidden file or not a regular file
	       if [[ -f "$entry" ]] then
		       # Check file size
	       	file_size=$(stat -c %s "$entry") 
		if (( file_size > largest_size )); then 
			largest_size=$file_size 
			largest_file="$entry"
		       	fi
	             fi
	       	done

		echo "largesr file: $largest_file"
		echo "Size: $largest_size bytes"
	}
	find_largest "$file_check"
	echo "done"
