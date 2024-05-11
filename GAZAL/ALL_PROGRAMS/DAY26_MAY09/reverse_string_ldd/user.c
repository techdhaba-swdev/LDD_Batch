#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define DEVICE_PATH "/dev/reverse_string"

int main() {
    int fd;
    char input_string[100];
    char reversed_string[100];

    printf("Enter a string: ");
    fgets(input_string, sizeof(input_string), stdin);
    input_string[strcspn(input_string, "\n")] = '\0'; 

    // Open the device file
    fd = open(DEVICE_PATH, O_RDWR);
    if (fd < 0) {
        perror("Failed to open the device file");
        return 1;
    }

    // Write the input string to the device
    write(fd, input_string, strlen(input_string));

    // Read the reversed string from the device
    read(fd, reversed_string, sizeof(reversed_string));

    printf("Reversed string received from kernel: %s\n", reversed_string);

    // Close the device file
    close(fd);

    return 0;
}
