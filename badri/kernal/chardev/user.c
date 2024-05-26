#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define DEVICE_FILE "/dev/BUFFER"

int main() {
    int fd;
    char buffer[300]; 
    
    fd = open(DEVICE_FILE, O_RDWR);
    if (fd < 0) {
        perror("Failed to open the device file");
        return EXIT_FAILURE;
    }

    
    
    char write_data[] = "Hello user!";
    if (write(fd, write_data, strlen(write_data)) < 0) {
        perror("Failed to write to the device");
        close(fd);
        return EXIT_FAILURE;
    }

   
    printf("Reading data from the device...\n");
    if (read(fd, buffer, sizeof(buffer)) < 0) {
        perror("Failed to read from the device");
        close(fd);
        return EXIT_FAILURE;
    }
    printf("Data read from the device: %s\n", buffer);

    
    close(fd);

    return EXIT_SUCCESS;
}
