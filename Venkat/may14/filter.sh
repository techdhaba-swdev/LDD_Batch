#!/bin/bash

read -p "enter the word to search :" search_word

read -p "enter the file nmae :" file_name

if [ ! -f "$file_name" ]; then 
	echo "filw $file_name does not exists"
fi


grep -o "$search_word" "$file_name" | sort 
