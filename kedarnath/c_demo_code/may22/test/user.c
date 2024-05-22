#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <string.h>

#define DEVICE_PATH "/dev/add3" 
#define BUF_SIZE 4096
#define NUM_EXPRESSIONS 10

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

    // Send ten expressions with different operations (e.g., "1+2", "3-4", ...) to the kernel space
    char *expressions[NUM_EXPRESSIONS] = {"1+2", "3-4", "5*6", "7/8", "9+10", "11-12", "13*14", "15/16", "17+18", "19*20"};
    //printf("User read: %s\n", expressions);

    // Construct the string to pass to kernel space
    char data[BUF_SIZE];
    data[0] = '\0'; // Ensure the string is initially empty
    for (int i = 0; i < NUM_EXPRESSIONS; i++) {
        strcat(data, expressions[i]);
        if (i != NUM_EXPRESSIONS - 1) {
            strcat(data, ";"); // Delimiter between expressions
        }
    }

    // Copy the constructed string to mapped memory
    strncpy(mapped_mem, data, BUF_SIZE);

    // Writing to the device using write system call to trigger printk in kernel space
    printf("User write: %s\n", mapped_mem); 
    write(fd, mapped_mem, strlen(mapped_mem) + 1);

    // Reading the result from the kernel space
    printf("User read: %s\n", mapped_mem);

    if (munmap(mapped_mem, BUF_SIZE) == -1) {
        perror("munmap");
    }

    close(fd);
    return EXIT_SUCCESS;
}



