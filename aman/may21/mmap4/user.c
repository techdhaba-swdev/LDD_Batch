#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stdlib.h>

#define SHARED_BUFFER_SIZE 4096
#define DEVICE_PATH "/dev/mmap4_device"
int main() {
    int fd;
    char *mapped_mem;
    int num1, num2, result;

    fd = open("/dev/mymmap", O_RDWR);
    if (fd < 0) {
        perror("open");
        return -1;
    }

    mapped_mem = (char *)mmap(NULL, SHARED_BUFFER_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (mapped_mem == MAP_FAILED) {
        perror("mmap");
        close(fd);
        return -1;
    }

    // Writing numbers to the shared memory
    num1 = 4;
    num2 = 3;
    snprintf(mapped_mem, SHARED_BUFFER_SIZE, "%d %d", num1, num2);

    // Simulate the kernel doing the addition
    // The kernel part should ideally do this
    sscanf(mapped_mem, "%d %d", &num1, &num2);
    result = num1 + num2;
    snprintf(mapped_mem, SHARED_BUFFER_SIZE, "%d", result);

    // Reading the result from the shared memory
    printf("Result: %s\n", mapped_mem);

    munmap(mapped_mem, SHARED_BUFFER_SIZE);
    close(fd);

    return 0;
}
