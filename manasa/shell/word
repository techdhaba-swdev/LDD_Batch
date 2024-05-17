#!/bin/bash

# Check if the correct number of arguments is given
if [ "$#" -ne 2 ]; then
    echo "Usage: $0 word filename"
    exit 1
fi

word=$1
filename=$2

# Check if the file exists
if [ ! -f "$filename" ]; then
    echo "File $filename not found!"
    exit 1
fi

# Use grep to find the occurrences of the word and pipe to sort
grep -i "$word" "$filename" | sort
