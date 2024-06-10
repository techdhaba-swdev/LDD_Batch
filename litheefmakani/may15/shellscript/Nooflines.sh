#count the number of lines :it should be count the regular files (not directories )within the specified directory and its subdirectories
#!/bin/bash
#check if a directory is provided as an argument
if [ $# -ne 1 ]; then
	echo "usage: $0 directory"
	exit 1
fi

directory="$1"

#check if the directory exists
if [ ! -d "$directory" ]; then 
	echo "errors:directory '$directory' does not exis."
	exit 1
fi
#count the number of regular files
file_count=$(find "$directory" -type f | wc -l)
echo "number of regular files in '$directory' and its subdirectories : $file_count"
