#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define DEVICE_PATH "/dev/my_device"
#define MEMORY_SIZE 4096  // 4KB

int main() {
    // Open the device file for reading and writing
    int fd = open(DEVICE_PATH, O_RDWR);
    if (fd < 0) {
        perror("open");
        return -1;
    }

    // Prompt the user to enter two numbers and an operation
    int num1, num2;
    char operation;
    printf("Enter first number: ");
    scanf("%d", &num1);
    printf("Enter second number: ");
    scanf("%d", &num2);
    printf("Enter operation + : ");
    scanf(" %c", &operation);

    // Prepare the data to be written to the device
    char buffer[sizeof(int) * 2 + sizeof(char)];
    memcpy(buffer, &num1, sizeof(int));
    memcpy(buffer + sizeof(int), &num2, sizeof(int));
    memcpy(buffer + sizeof(int) * 2, &operation, sizeof(char));

    // Write the data to the device
    if (write(fd, buffer, sizeof(buffer)) < 0) {
        perror("write");
        close(fd);
        return -1;
    }

    // Map the device memory to user space
    void *mapped_memory = mmap(NULL, MEMORY_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (mapped_memory == MAP_FAILED) {
        perror("mmap");
        close(fd);
        return -1;
    }

    // Read the result from the mapped memory
    int result;
    memcpy(&result, mapped_memory, sizeof(int));
    printf("Calculation result: %d\n", result);

    // Unmap the device memory
    if (munmap(mapped_memory, MEMORY_SIZE) == -1) {
        perror("munmap");
    }

    // Close the device file descriptor
    close(fd);
    return 0;
}

