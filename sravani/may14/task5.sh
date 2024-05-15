#!/bin/bash

echo "enter word to search"
read search_word

echo "enter the file name"
read file_name
# Using grep to find occurrences of the word in the file and sorting the results alphabetically
grep -o "\b$search_word\b" "$file_name" | sort
