#!/bin/bash


if [ -z "$1" ]; then
  echo "Usage: $0 <directory_path>"
  exit 1
fi

DIR_PATH=$1

if [! -d "DIR_PATH"]; then
  echo "It is not the directory path"
  exit 1
fi  


file_count=0


for file in $(find "$1" -type f); do
 
  ((file_count++))
done


echo "Number of files: $file_count"
