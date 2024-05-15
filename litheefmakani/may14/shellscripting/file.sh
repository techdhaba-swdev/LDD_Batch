#!/bin/bash

# Prompt the user to enter the word to search for
echo "Enter the word to search for:"
read search_word

# Prompt the user to enter the file name
echo "Enter the file name:"
read file_name

# Use grep to find and list all occurrences of the specific word in the file,
# then pipe the output to sort to display the results alphabetically
grep -o "\b$search_word\b" "$file_name" | sort

#!/bin/bash

# Function to print the number of lines in a file
print_lines() {
    local file="$1"
    local num_lines=$(wc -l < "$file")
    echo "Number of lines in $file: $num_lines"
}

# List of file names
files=("file1.txt" "file2.txt" "file3.txt")

# Loop to iterate over the list of file names
for file in "${files[@]}"; do
    # Call the function for each file
    print_lines "$file"
done

