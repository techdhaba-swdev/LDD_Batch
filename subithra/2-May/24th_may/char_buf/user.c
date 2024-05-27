#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define DEVICE_PATH "/dev/char_buf"

int main() {
int fd;
char write_buf[256] = "hi this is user";
char read_buf[256];

fd = open(DEVICE_PATH, O_RDWR);
if (fd < 0) {
perror("Failed to open the device");
return 1; 
}

printf("Writing to the device: %s\n", write_buf);
if (write(fd, write_buf, strlen(write_buf)) < 0) {
perror("Failed to write to the device");
close(fd);
return 1; 
}

if (read(fd, read_buf, sizeof(read_buf)) < 0) {
perror("Failed to read from the device");
close(fd);
return 1; 
}

printf("Read from the device: %s\n", read_buf);

close(fd);

return 0; 
}
