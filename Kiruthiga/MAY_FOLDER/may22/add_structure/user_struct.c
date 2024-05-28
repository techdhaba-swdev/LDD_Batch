#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define DEVICE_PATH "/dev/buffer_structure_add"
#define NUMBERS_COUNT 10

typedef struct {
    int numbers[NUMBERS_COUNT];
    char operation;
} CalculationRequest;

int main() {
    int fd = open(DEVICE_PATH, O_RDWR);
    if (fd < 0) {
        perror("open");
        return -1;
    }

    CalculationRequest req;
   
    printf("Enter 10 numbers separated by spaces: ");
    for (int i = 0; i < NUMBERS_COUNT; ++i) {
        scanf("%d", &req.numbers[i]);
    }

    printf("Enter operation (+ or -): ");
    scanf(" %c", &req.operation);

    if (write(fd, &req, sizeof(req)) < 0) {
        perror("write");
        close(fd);
        return -1;
    }

    int result;
    if (read(fd, &result, sizeof(result)) < 0) {
        perror("read");
        close(fd);
        return -1;
    }

    printf("Calculation result: %d\n", result);

    close(fd);
    return 0;
}



