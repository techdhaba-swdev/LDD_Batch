#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define DEVICE_PATH "/dev/interrupt"

int main() {
int fd;
char buffer[256];
ssize_t bytes_read;
fd = open(DEVICE_PATH, O_RDONLY);
if (fd < 0) {
perror("Failed to open the device");
return errno;
}

bytes_read = read(fd, buffer, sizeof(buffer) - 1);
if (bytes_read < 0) {
perror("Failed to read from the device");
close(fd);
return errno;
}

buffer[bytes_read] = '\0';
printf("Read from the device: %s\n", buffer);
close(fd);
return 0;
}
