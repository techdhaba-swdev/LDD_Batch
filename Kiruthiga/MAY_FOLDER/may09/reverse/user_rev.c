#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define DEVICE_NAME "/dev/reverse"

int main() {
    int fd;
    char input[100];
    char output[100];
    int nbytes;

    // Open the device file
    fd = open(DEVICE_NAME, O_RDWR);
    if (fd < 0) {
        perror("Failed to open device file");
        return 1;
    }

    // Prompt the user for input
    printf("Enter a string: ");
    scanf("%s", input);

    // Reverse the string
    int length = strlen(input);
    for (int i = 0; i < length; i++) {
        output[length - i - 1] = input[i];
    }
    output[length] = '\0'; // Add null terminator

    // Write the reversed string to the device
    nbytes = write(fd, output, strlen(output));
    if (nbytes < 0) {
        perror("Failed to write to device");
        close(fd);
        return 1;
    }

    // Read the original string from the device
    printf("Reversed string: ");
    nbytes = read(fd, input, sizeof(input));
    if (nbytes < 0) {
        perror("Failed to read from device");
        close(fd);
        return 1;
    }

    // Print the original string
    printf("%s", input);

    // Close the device file
    close(fd);

    return 0;
}


