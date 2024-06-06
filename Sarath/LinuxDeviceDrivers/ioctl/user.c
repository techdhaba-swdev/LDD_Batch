#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>

#define IOCTL_SET_MSG _IOW('q', 1, char *)

int main() {
    int fd;
    int message_len;
    char reverse_string[100];
    char message[100] = "New message for the driver";

    fd = open("/dev/simple_char_driver", O_RDWR);
    if (fd < 0) {
        perror("Failed to open the device");
        return -1;
    }

    ioctl(fd, IOCTL_SET_MSG, message);

    //close(fd);
    message_len = strlen(message);
  if (write(fd, message, message_len) != message_len) {
    perror("Failed to write to device");
    close(fd);
    return 1;
  }

  // Read the reversed string
  message_len = read(fd, reverse_string, sizeof(reverse_string));
  if (message_len < 0) {
    perror("Failed to read from device");
    close(fd);
    return 1;
  }
    close(fd);
    return 0;
}
