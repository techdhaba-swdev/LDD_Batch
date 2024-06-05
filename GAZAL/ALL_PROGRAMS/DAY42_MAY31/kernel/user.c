#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define DEVICE_NODE "/dev/my_device_char"
#define BUF_LEN 256

int main() {
    int file_desc;
    char input_buffer[BUF_LEN];
    char output_buffer[BUF_LEN];
    ssize_t bytes_read, bytes_written;

    // Open the device node
    file_desc = open(DEVICE_NODE, O_RDWR);
    if (file_desc < 0) {
        perror("Failed to open the device node");
        return EXIT_FAILURE;
    }

    // Get input from the user
    printf("Enter a string to send to kernel space: ");
    fgets(input_buffer, sizeof(input_buffer), stdin);

    // Write the input to the device
    bytes_written = write(file_desc, input_buffer, strlen(input_buffer));
    if (bytes_written < 0) {
        perror("Failed to write to device");
        close(file_desc);
        return EXIT_FAILURE;
    }

    // Read the response from the device
    bytes_read = read(file_desc, output_buffer, sizeof(output_buffer));
    if (bytes_read < 0) {
        perror("Failed to read from device");
        close(file_desc);
        return EXIT_FAILURE;
    }

    // Print the response from kernel space
    printf("Message from kernel space: %s\n", output_buffer);

    // Close the device node
    close(file_desc);

 return EXIT_SUCCESS;
}
