#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define DEVICE_PATH "/dev/my_device_addition" // Path to the device file
#define MEMORY_SIZE 4096  // 4KB

int main() {
    int fd = open(DEVICE_PATH, O_RDWR); // Open the device file
    if (fd < 0) {
        perror("open"); // Print error message if opening fails
        return -1;
    }

    char input[256];
    int numbers[10];

    printf("Enter 10 numbers separated by '+': ");
    scanf("%s", input); // Take input from the user

    // Parse the input string to extract numbers
    char *token = strtok(input, "+");
    for (int i = 0; i < 10 && token != NULL; i++) {
        numbers[i] = atoi(token);
        token = strtok(NULL, "+");
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
