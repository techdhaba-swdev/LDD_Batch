#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define DEVICE_PATH "/dev/revstr_drive"

int main() {
    int fd;
    char input_string[100];
    char reversed_string[100];
    ssize_t bytes_written, bytes_read;

    // Prompt the user for a string
    printf("Enter a string to reverse: ");
    scanf("%99s", input_string); // Using %99s to limit the input and prevent buffer overflow

    // Open the device file
    fd = open(DEVICE_PATH, O_RDWR);
    if (fd < 0) {
        perror("Failed to open the device file");
        return 1;
    }

    // Write the string to the device
    bytes_written = write(fd, input_string, strlen(input_string));
    if (bytes_written < 0) {
        perror("Failed to write to the device");
        close(fd);
        return 1;
    }

    // Read the reversed string from the device
    bytes_read = read(fd, reversed_string, sizeof(reversed_string) - 1); // Leave space for null terminator
    if (bytes_read < 0) {
        perror("Failed to read from the device");
        close(fd);
        return 1;
    }

    // Null-terminate the received string
    reversed_string[bytes_read] = '\0';

    printf("Reversed string received from kernel: %s\n", reversed_string);

    // Close the device file
    close(fd);

    return 0;
}
