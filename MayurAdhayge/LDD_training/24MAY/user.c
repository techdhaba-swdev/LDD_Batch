#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define DEVICE_FILE "/dev/simple_driver"

int main() {
    int fd;
    char inData[20] = "Hello, kernel!";
    char outData[20];

    // Open the device file for writing
    fd = open(DEVICE_FILE, O_RDWR);
    if (fd < 0) {
        perror("Failed to open the device file");
        return EXIT_FAILURE;
    }

    // Write data to the device
    if (write(fd, inData, sizeof(char)*strlen(inData))==0) {
        perror("Failed to write to the device");
        close(fd);
        return EXIT_FAILURE;
    }
    
    printf("Data successfully written to the device\n");
   if (read(fd, outData, sizeof(char)*strlen(inData))==0) {
        perror("Failed to read to the device");
        close(fd);
        return EXIT_FAILURE;
    }
    
    printf("Data successfully read from  the device \n");
    printf("readed data:- %s",outData);
    
     // Close the device file
    close(fd);

    return EXIT_SUCCESS;
}
