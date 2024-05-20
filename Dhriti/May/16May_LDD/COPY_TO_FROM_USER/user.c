#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define DEVICE_NAME "/dev/my_device" // Define the device file path

int main() {
  int fd; // File descriptor for the device file
  char buffer[50]; // Buffer for reading data from the device

  // Open the device file with read/write permissions
  fd = open(DEVICE_NAME, O_RDWR);
  if (fd == -1) { // Check if the open operation failed
    perror("open"); // Print an error message if open fails
    return 1; // Exit the program with an error status
  }

  // Read data from the device into the buffer
  ssize_t read_size = read(fd, buffer, sizeof(buffer));
  if (read_size < 0) { // Check if the read operation failed
    perror("read"); // Print an error message if read fails
    close(fd); // Close the device file descriptor
    return 1; // Exit the program with an error status
  }

  printf("Read from device: %s\n", buffer); // Print the data read from the device

  // Prepare data to write to the device
  const char *data_to_write = "Data from user space";
  
  // Write data to the device
  ssize_t write_size = write(fd, data_to_write, strlen(data_to_write));
  if (write_size < 0) { // Check if the write operation failed
    perror("write"); // Print an error message if write fails
    close(fd); // Close the device file descriptor
    return 1; // Exit the program with an error status
  }

  printf("Successfully wrote %zd bytes to device\n", write_size); // Print the number of bytes successfully written

  close(fd); // Close the device file descriptor
  return 0; // Exit the program with success status
}


