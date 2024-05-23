#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define DEVICE_NAME "/dev/reverse_string"
#define BUFFER_SIZE 100

int main() {
    int fd;
    char message[BUFFER_SIZE] = "This is a test string!";
    char reversed_message[BUFFER_SIZE];

    // Open the device file
    fd = open(DEVICE_NAME, O_RDWR);
    if (fd < 0) {
        perror("Failed to open device");
        return 1;
    }

    // Send the string to the device
    int message_len = strlen(message);
    if (write(fd, message, message_len) != message_len) {
        perror("Failed to write to device");
        close(fd);
        return 1;
    }

    // Read the reversed string
    message_len = read(fd, reversed_message, sizeof(reversed_message));
    if (message_len < 0) {
        perror("Failed to read from device");
        close(fd);
        return 1;
    }

    // Add null terminator to the reversed message
    reversed_message[message_len] = '\0';

    // Print the original and reversed strings
    printf("Original string: %s\n", message);
    printf("Reversed string: %s\n", reversed_message);

    // Close the device file
    close(fd);

    return 0;
}