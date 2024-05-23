#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <string.h>

#define DEVICE_PATH "/dev/mmap_char_device"
#define BUF_SIZE 4096

int main() {
    int fd = open(DEVICE_PATH, O_RDWR);
    if (fd < 0) {
        perror("open");
        return EXIT_FAILURE;
    }

    char *mapped_mem = mmap(NULL, BUF_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (mapped_mem == MAP_FAILED) {
        perror("mmap");
        close(fd);
        return EXIT_FAILURE;
    }

    const char *expressions[] = {"10+5", "10-5", "20+5", "20-5", "30+5", "30-5", "40+5", "40-5", "50+5", "50-5"};
   
    for (int i = 0; i < 10; i++) {
        // Writing arithmetic expression to the device
        size_t len = strlen(expressions[i]) + 1; // +1 to include null terminator
        memcpy(mapped_mem, expressions[i], len);
        printf("User wrote: %s\n", expressions[i]);

        // Reading result from the device
        printf("User read result: %ld\n", strtol(mapped_mem, NULL, 10));
    }

    if (munmap(mapped_mem, BUF_SIZE) == -1) {
        perror("munmap");
    }

    close(fd);
    return EXIT_SUCCESS;
}
