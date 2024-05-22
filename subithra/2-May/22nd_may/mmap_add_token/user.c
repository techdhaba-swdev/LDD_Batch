#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define DEVICE_PATH "/dev/mmap_add10"
#define MEMORY_SIZE 4096 // 4KB

int main() {
    int fd = open(DEVICE_PATH, O_RDWR);
    if (fd < 0) {
        perror("open");
        return -1;
    }

    // Memory map the device
    int *mapped_mem = mmap(NULL, MEMORY_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (mapped_mem == MAP_FAILED) {
        perror("mmap");
        close(fd);
        return -1;
    }

    // Collect input string from the user
    char input_str[256];
    printf("Enter the 10 numbers to be added :\n");
    scanf("%s", input_str);

    // Parse the input string to extract numbers
    int numbers[10], count = 0;
    char *token = strtok(input_str, "+");
    while (token != NULL && count < 10) {
        numbers[count++] = atoi(token);
        token = strtok(NULL, "+");
    }

    if (count != 10) {
        fprintf(stderr, "Error: enter exactly 10 numbers.\n");
        munmap(mapped_mem, MEMORY_SIZE);
        close(fd);
        return -1;
    }

    // Copy numbers to the mapped memory
    memcpy(mapped_mem, numbers, sizeof(numbers));

    // Trigger the write operation
    if (write(fd, mapped_mem, sizeof(numbers)) < 0) {
        perror("write");
        munmap(mapped_mem, MEMORY_SIZE);
        close(fd);
        return -1;
    }

    // Read the result from the mapped memory
    int result;
    if (read(fd, &result, sizeof(result)) < 0) {
        perror("read");
        munmap(mapped_mem, MEMORY_SIZE);
        close(fd);
        return -1;
    }

    printf("Sum of numbers: %d\n", result);

    // Clean up
    if (munmap(mapped_mem, MEMORY_SIZE) == -1) {
        perror("munmap");
    }
    close(fd);

    return 0;
}

