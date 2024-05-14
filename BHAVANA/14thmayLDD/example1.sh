# Run a command (replace command with your actual command)
command

# Check the exit status
if [ $? -eq 0 ]; then
  echo "Command executed successfully."
else
  echo "Command failed with exit status: $?."
fi
