#!/bin/bash
path="/home/rps/amanraj/LDD_Batch/aman"
filecount=$( find "$path" -type f | wc -l)
echo "number file : $filecount"
largestfile=$(find "$path" -type f -exec ls -s {} + | sort -nr | head -n 1)

if [ -z "$largestfile" ]
then
	echo "No files found in the directory"
else
	echo "largest file: $largestfile"
fi
