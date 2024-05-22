#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define DEVICE_PATH "/dev/addition" // Path to the device file
#define MEMORY_SIZE 4096  // 4KB

int main() {
    int fd = open(DEVICE_PATH, O_RDWR); // Open the device file
    if (fd < 0) {
        perror("open"); // Print error message if opening fails
        return -1;
    }

    int numbers[10];
    for (int i = 0; i < 10; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &numbers[i]); // Take input from the user
    }

    if (write(fd, numbers, sizeof(numbers)) < 0) {
        perror("write"); // Print error message if writing fails
        close(fd); // Close the device file
        return -1;
    }

    int result;
    if (read(fd, &result, sizeof(result)) < 0) {
        perror("read"); // Print error message if reading fails
        close(fd); // Close the device file
        return -1;
    }

    printf("Result of adding the 10 numbers: %d\n", result); // Print the result

    close(fd); // Close the device file
    return 0;
}


