#!/bin/bash
echo "enter the word to be sorted"
read sort_word
echo "enter the file name"
read file_name

grep "$sort_word" "$file_name" | sort
