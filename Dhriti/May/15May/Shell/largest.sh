#!/bin/bash

if [ -z "$1" ]; then
  echo "Usage: $0 <directory_path>"
  exit 1
fi


dir_path=$1


if [! -d "$dir_path" ]; then
  echo "it is not a directory path"
  exit 1
fi

largest_size=0


largest_file=""

for file in "$dir_path/*"; do
  
  if [-f "$file" ]; then
   
    file_size=$(du -b "$file" | cut -f1)
      
      largest_size=$file_size
      largest_file="$file"
    fi
  
done


echo "Largest file: $largest_file"
echo "Size: $largest_size bytes"
