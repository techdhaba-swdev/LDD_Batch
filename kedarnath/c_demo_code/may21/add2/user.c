#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <string.h>

#define DEVICE_PATH "/dev/add2" 
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

    // Send two numbers (e.g., 4 and 3) to the kernel space
    int num1 = 4;
    int num2 = 3;
    sprintf(mapped_mem, "%d+%d", num1, num2);

    // Reading from the device (optional)
    printf("User wrote: %s\n", mapped_mem);

    // Writing to the device using write system call to trigger printk in kernel space
    write(fd, mapped_mem, strlen(mapped_mem) + 1);

    // Reading the result from the kernel space
    printf("User read: %s\n", mapped_mem);

    if (munmap(mapped_mem, BUF_SIZE) == -1) {
        perror("munmap");
    }

    close(fd);
    return EXIT_SUCCESS;
}


