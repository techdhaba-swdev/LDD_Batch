#!/bin/bash

# Function to search for a word in a file and sort the results alphabetically
search_and_sort() {
  grep -o "\<$1\>" "$2" | sort 
   
}

# Usage: ./search_and_sort.sh <word> <file>
search_and_sort "$1" "$2" 



