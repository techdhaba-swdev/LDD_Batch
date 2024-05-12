#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define DEVICE_NAME "/dev/operation_dev"

int main() {
    int fd;
    char buffer[128];

    // Open the device file
    fd = open(DEVICE_NAME, O_RDWR);
    if (fd < 0) {
        perror("Failed to open device file");
        return 1;
    }

    // Prompt the user for input
    printf("Enter the operation (+, -, *, /): ");
    scanf(" %c", &buffer[0]);
    printf("Enter operand 1: ");
    scanf("%d", (int*)&buffer[1]);
    printf("Enter operand 2: ");
    scanf("%d", (int*)&buffer[5]);

    // Write the operation and operands to the device
    write(fd, buffer, strlen(buffer));

    // Read the result from the device
    printf("Result: ");
    read(fd, buffer, sizeof(buffer));
    printf("%s", buffer);

    // Close the device file
    close(fd);

    return 0;
}



