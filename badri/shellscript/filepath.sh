
#!/bin/bash

# Check if directory path is provided
if [ $# -ne 1 ];
then
    echo "Usage: $0 <directory_path>"
    exit 1
fi

directory=$1

# Check if the directory exists
if [ ! -d "$directory" ];
then
    echo "Error: Directory $directory does not exist."
    exit 1
fi

# Function to count number of files recursively
count_files() {
    local dir="$1"
    local count=0

    for item in "$dir"/*; do
        if [ -f "$item" ]; then
            count=$((count+1))
        elif [ -d "$item" ]; then
            count=$((count+$(count_files "$item")))
        fi
    done

    echo "$count"
}

# Function to find largest file
find_largest_file() {
    local dir="$1"
    local largest_file=""
    local largest_size=0

    for item in "$dir"/*; do
        if [ -f "$item" ]; then
            size=$(stat -c "%s" "$item")
            if [ $size -gt $largest_size ]; then
                largest_size=$size
                largest_file="$item"
            fi
        elif [ -d "$item" ]; then
            file=$(find_largest_file "$item")
            size=$(stat -c "%s" "$file")
            if [ $size -gt $largest_size ]; then
                largest_size=$size
                largest_file="$file"
            fi
        fi
    done

    echo "$largest_file"
}

# Count files
file_count=$(count_files "$directory")
echo "Number of files: $file_count"

# Find largest file
largest_file=$(find_largest_file "$directory")
if [ -z "$largest_file" ]; then
    echo "No files found."
else
    echo "Largest file: $largest_file"
    echo "Size: $(stat -c "%s bytes" "$largest_file")"
fi
