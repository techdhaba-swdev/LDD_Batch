#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <string.h>

#define DEVICE_PATH "/dev/mmap_char_device"
#define BUF_SIZE 4096

struct Expression {
    int num1;
    int num2;
    char operation;
};

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

    // array of expressions
    struct Expression expressions[10] = {
        {4,3, '+'},
        {9,5, '*'},
        {16,4, '/'},
         {10,2, '%'},
	 {6,8, '-'},
	 {4,3, '+'},
        {9,5, '*'},
        {16,4, '/'},
         {10,2, '%'},
         {6,8, '-'},

       
    };

    // Send expressions to the kernel space
    for (int i = 0; i < 10; ++i) {
        snprintf(mapped_mem,BUF_SIZE,"%d%c%d" , expressions[i].num1,expressions[i].operation,expressions[i].num2);
        write(fd, mapped_mem, strlen(mapped_mem) + 1);
        printf("User sent: %d %c %d\n", expressions[i].num1,expressions[i].operation,expressions[i].num2);
    }

    // Reading the results from the kernel space (optional)
    printf("\nResults from kernel space:\n");
    for (int i = 0; i < 10; ++i) {
        read(fd, mapped_mem, BUF_SIZE);
        printf("User read: %s\n", mapped_mem);
    }

    if (munmap(mapped_mem, BUF_SIZE) == -1) {
        perror("munmap");
    }

    close(fd);
    return EXIT_SUCCESS;
}
