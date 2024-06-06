#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define DEVICE_PATH "/dev/usb_example"

int main() {
    int fd;
    char read_buf[512];
    const char *write_buf = "Hello, USB device!";
    ssize_t ret;

    
    fd = open(DEVICE_PATH, O_RDWR);
    if (fd < 0) {
        perror("Failed to open the device");
        return errno;
    }

   
    ret = write(fd, write_buf, strlen(write_buf));
    if (ret < 0) {
        perror("Failed to write to the device");
        close(fd);
        return errno;
    }
    printf("Wrote %ld bytes to the device: %s\n", ret, write_buf);

   
    ret = read(fd, read_buf, sizeof(read_buf));
    if (ret < 0) {
        perror("Failed to read from the device");
        close(fd);
        return errno;
    }
    read_buf[ret] = '\0'; 
    printf("Read %ld bytes from the device: %s\n", ret, read_buf);

  
    close(fd);

    return 0;
}
