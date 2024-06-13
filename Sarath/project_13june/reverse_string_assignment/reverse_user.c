#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include<string.h>
int main() {
  int fd;
  char message[100];

  // Open the device file
  fd = open("/dev/reverse_dev", O_RDWR);
  if (fd == -1) {
    perror("open");
    return 1;
  }

  // Write a string to the device
  const char *str = "This is a string";
  write(fd, str, strlen(str));

  // Read the reversed string from the device (assuming implemented in kernel)
  read(fd, message, sizeof(message));

  // Print the reversed string
  printf("Reversed string: %s\n", message);

  // Close the device
  close(fd);

  return 0;
}

