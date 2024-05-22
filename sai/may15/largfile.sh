#!/bin/bash

path="/home/rps/Downloads"
filecount=$( find "$path" -type f | wc -l)


echo "number file : $filecount"
largestfile=$(find "$path" -type f -exec ls -s {} + | sort -nr | head -n 1)
size=$(stat -c %s "$largestfile")
if [ -z "$largestfile" ]
then
	echo "No files found in the directory"
else
	echo "largest file: $largestfile"
	echo "Size : $size "
fi
