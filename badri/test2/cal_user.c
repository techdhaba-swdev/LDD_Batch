#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <string.h>

#define DEVICE_PATH "/dev/my_device_calc"
#define MEMORY_SIZE 4096  // 4KB

int main() {
    int fd = open(DEVICE_PATH, O_RDWR);
    if (fd < 0) {
        perror("open");
        return -1;
    }

    // Get input from user
    char operation[20];
    printf("Enter the addition operation (num1 + num2): ");
    scanf("%s", operation);

    // Write the operation to the device
    if (write(fd, operation, strlen(operation)) == -1) {
        perror("write");
        close(fd);
        return -1;
    }

    // Read the result from the device
    char result_buffer[20];
    if (read(fd, result_buffer, sizeof(result_buffer)) == -1) {
        perror("read");
        close(fd);
        return -1;
    }

    // Print the result
    printf("Result from kernel space: %s\n", result_buffer);

    close(fd);
    return 0;
}
