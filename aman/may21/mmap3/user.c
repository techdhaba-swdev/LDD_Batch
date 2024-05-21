#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <string.h>

#define DEVICE_PATH "/dev/mmap3_char_device"
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

    // Writing to the device
    const char *message = "Hello from user space!";
    strcpy(mapped_mem, message);
    printf("User wrote: %s\n", message);

    // Reading from the device
    printf("User read: %s\n", mapped_mem);

    // Writing to the device using write system call to trigger printk in kernel space
    write(fd, message, strlen(message) + 1);

    if (munmap(mapped_mem, BUF_SIZE) == -1) {
        perror("munmap");
    }

    close(fd);
    return EXIT_SUCCESS;
}
