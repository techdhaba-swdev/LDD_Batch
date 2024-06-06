#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define DEVICE_NAME "/dev/reverse_string"

int main() {
  int fd;
  char message[100] = "This is a test string!";
  char reversed_message[100];
  ssize_t message_len;

  // Open the device file
  fd = open(DEVICE_NAME, O_RDWR);
  if (fd < 0) {
    perror("Failed to open device");
    return errno;
  }

  // Send the string to the device
  message_len = write(fd, message,strlen(message) + 1);
  if (message_len < 0) {
    perror("Failed to write to device");
    close(fd);
    return errno;
  }

  // Read the reversed string
  message_len = read(fd, reversed_message, sizeof(reversed_message));
  if (message_len < 0) {
    perror("Failed to read from device");
    close(fd);
    return errno;
  }
  reversed_message[message_len] = '\0';

  // Print the original and reversed strings
  printf("Original string: %s\n", message);
  printf("Reversed string: %s\n", reversed_message);

  // Close the device file
  close(fd);

  return 0;
}
