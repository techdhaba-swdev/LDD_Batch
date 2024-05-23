#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <string.h>

#define DEVICE_PATH "/dev/cal_char_driver"
#define BUF_SIZE 4096
#define NUM 10

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

    // Sending ten expressions with different operations to the kernel space
    char *expressions[NUM] = {"10+20", "13-24", "53*26", "77/11", "19+100", "121-11", "13*14", "51/17", "118+18", "69*69"};

    // Constructing the string to pass to kernel space
    char data[BUF_SIZE];
    data[0] = '\0'; // making the string is empty initially
    for (int i = 0; i < NUM; i++) {
        strcat(data, expressions[i]); //concatinating the strings
        if (i != NUM - 1) {
            strcat(data, ";"); // Delimiting between expressions
        }
    }

    // Copying the constructed string to mapped memory
    strncpy(mapped_mem, data, BUF_SIZE);

    // Writing to the device using write system call to trigger printk in kernel space
    write(fd, mapped_mem, strlen(mapped_mem) + 1);

    // Reading the result from the kernel space
    printf("reading from kernel space: %s\n", mapped_mem);

    if (munmap(mapped_mem, BUF_SIZE) == -1) {
        perror("munmap");
    }

    close(fd);
    return EXIT_SUCCESS;
}
