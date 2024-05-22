#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define DEVICE_PATH "/dev/mmap_10"
#define MEMORY_SIZE 4096 // 4KB
#define NUM_COUNT 10

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

    // Collect numbers from the user
    int numbers[NUM_COUNT];
    printf("Enter 10 numbers:\n");
    for (int i = 0; i < NUM_COUNT; i++) {
        printf("Number %d: ", i + 1);
        scanf("%d", &numbers[i]);
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

    printf("Adiition of 10 numbers are %d\n", result);

    // Clean up
    if (munmap(mapped_mem, MEMORY_SIZE) == -1) {
        perror("munmap");
    }
    close(fd);

    return 0;
}


