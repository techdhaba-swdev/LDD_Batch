#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define DEVICE_PATH "/dev/add"
#define MEMORY_SIZE 4096  // 4KB

int main() {
    int fd = open(DEVICE_PATH, O_RDWR);
    if (fd < 0) {
        perror("open");
        return -1;
    }

    void *mapped_memory = mmap(NULL, MEMORY_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (mapped_memory == MAP_FAILED) {
        perror("mmap");
        close(fd);
        return -1;
    }

   
    // Reading user-provided numbers
    char input[50]; // Assuming the user won't provide more than 50 characters
    printf("Enter two numbers to add (separated by a space): ");
    fgets(input, sizeof(input), stdin);

    int num1, num2;
    sscanf(input, "%d %d", &num1, &num2);

    // Calculate the sum
    int sum =  num1 + num2;

    // Update the device data with the new sum
    sprintf((char *)mapped_memory, "%d", sum);

    // Example: Reading from the mapped memory
    printf("Result after addition: %s\n", (char *)mapped_memory);

    if (munmap(mapped_memory, MEMORY_SIZE) == -1) {
        perror("munmap");
    }

    close(fd);
    return 0;
}


