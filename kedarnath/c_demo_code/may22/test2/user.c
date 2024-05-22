#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <string.h>

#define DEVICE_PATH "/dev/add4" 
#define BUF_SIZE (sizeof(struct expression) * 10)
#define NUM_EXPRESSIONS 10

struct expression {
    int num1;
    int num2;
    char op;
    int result;
};

int main() {
    int fd = open(DEVICE_PATH, O_RDWR);
    if (fd < 0) {
        perror("open");
        return EXIT_FAILURE;
    }

    struct expression *mapped_mem = mmap(NULL, BUF_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (mapped_mem == MAP_FAILED) {
        perror("mmap");
        close(fd);
        return EXIT_FAILURE;
    }

    // Prepare expressions
    struct expression expressions[NUM_EXPRESSIONS] = {
        {4, 3, '+', 0}, // Expression 1
        {5, 2, '-', 0}, // Expression 2
        {6, 3, '*', 0}, // Expression 3
        {10, 2, '/', 0}, // Expression 4
        // Add more expressions here...
    };

    // Write expressions to device
    write(fd, expressions, sizeof(expressions));

    // Read results from device
    struct expression results[NUM_EXPRESSIONS];
    read(fd, results, sizeof(results));

    // Display results
    printf("Results received from kernel:\n");
    for (int i = 0; i < NUM_EXPRESSIONS; i++) {
        printf("%d %c %d = %d\n", results[i].num1, results[i].op, results[i].num2, results[i].result);
    }

    // Clean up
    munmap(mapped_mem, BUF_SIZE);
    close(fd);

    return EXIT_SUCCESS;
}



