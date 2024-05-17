#!/bin/bash

path="/home/rps/Desktop/demo/LDD_Batch/badri/shellscript"
filecount=$(find "$path" -type f | wc -l)
echo "number file : $filecount"
largestfile=$(find "$path" -type f -exec ls -s {} + | sort -nr | head -n 1)

if [ -z "$largestfile" ]
then
        echo " no files found in the directory"
else
        echo "Largest file: $largestfile"
fi
