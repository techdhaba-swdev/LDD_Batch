#!/bin/bash

path="/home/rps/Documents/demo_repo_ldd/LDD_Batch/manasa/shell"

filecount=$( find "$path" -type f | wc -l)

echo "number file: $filecount"

findlarge=$(find "$path" -type f -exec ls -s {} + | sort -nr | head -n 1)

if [ -z "$findlarge" ]

then

	echo "No files found in the directory"

else

	echo "largest file: $findlarge"
fi
