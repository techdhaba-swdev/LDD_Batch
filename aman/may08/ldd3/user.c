#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define DEVICE_FILE "/dev/calculator"
#define BUF_LEN 80

int main() {
    int fd;
    char expression[BUF_LEN];
    char result[BUF_LEN];

    // Open the device file
    fd = open(DEVICE_FILE, O_RDWR);
    if (fd == -1) {
        perror("Failed to open the device file");
        return EXIT_FAILURE;
    }

    // Write an expression to the device
    printf("Enter an arithmetic expression (e.g., 5+3): ");
    fgets(expression, BUF_LEN, stdin);
    write(fd, expression, sizeof(expression));

    // Read the result from the device
    read(fd, result, sizeof(result));
    printf("Result: %s", result);

    // Close the device file
    close(fd);

    return EXIT_SUCCESS;
}
