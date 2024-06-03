#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define DEVICE_NODE "/dev/mychardev"
#define BUFFER_SIZE 256

int main() {
    int file_desc;
    char receive_buffer[BUFFER_SIZE];

    // Open the device file
    file_desc = open(DEVICE_NODE, O_RDONLY);
    if (file_desc < 0) {
        perror("Failed to open the device file");
        return EXIT_FAILURE;
    }

    // Read data from the device
    printf("hello from user\n");
    if (read(file_desc, receive_buffer, BUFFER_SIZE) < 0) {
        perror("Failed to read from the device");
        close(file_desc);
        return EXIT_FAILURE;
    }

    // Display the received data
    printf("%s\n", receive_buffer);

    // Close the device file
    close(file_desc);

    return EXIT_SUCCESS;
}
