#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define DEVICE "/dev/mychardev" // Path to the device file

int main()
{
    int file_desc;
    int bytes_read;
    int bytes_written;
    char read_buffer[256];
    char write_buffer[] = "Hello from user space!";

    // Open the device file
    file_desc = open(DEVICE, O_RDWR);
    if (file_desc < 0) {
        printf("Error opening the device file\n");
        return -1;
    }

    // Write to the device
    bytes_written = write(file_desc, write_buffer, strlen(write_buffer));
    if (bytes_written < 0) {
        printf("Error writing to the device\n");
        close(file_desc);
        return -1;
    }
    printf("Wrote \"%s\" to the device\n", write_buffer);

    // Read from the device
    bytes_read = read(file_desc, read_buffer, sizeof(read_buffer));
    if (bytes_read < 0) {
        printf("Error reading from the device\n");
        close(file_desc);
        return -1;
    }
    read_buffer[bytes_read] = '\0';
    printf("Read \"%s\" from the device\n", read_buffer);

    // Close the device file
    close(file_desc);

    return 0;
}
