# Check if the script received at least two arguments
if [ $# -lt 2 ]; then
  echo "Usage: $0 <filename> <destination>"
  exit 1  # Exit with an error code if not enough arguments
fi

# Process the first two arguments
filename="$1"
destination="$2"

# ... (rest of your script using $filename and $destination)
grep -o -i "$filename" "$destination" | sort
