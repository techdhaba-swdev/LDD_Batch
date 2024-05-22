#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define DEVICE_PATH "/dev/add_10"
#define NUMBERS_COUNT 10

int main() {
    int fd = open(DEVICE_PATH, O_RDWR);
    if (fd < 0) {
        perror("open");
        return -1;
    }

    int numbers[NUMBERS_COUNT];
    char operation;
   
    printf("Enter 10 numbers separated by spaces: ");
    for (int i = 0; i < NUMBERS_COUNT; ++i) {
        scanf("%d", &numbers[i]);
    }

    printf("Enter operation + / - : ");
    scanf(" %c", &operation);

    char buffer[sizeof(int) * NUMBERS_COUNT + sizeof(char)];
    memcpy(buffer, numbers, sizeof(int) * NUMBERS_COUNT);
    memcpy(buffer + sizeof(int) * NUMBERS_COUNT, &operation, sizeof(char));

    if (write(fd, buffer, sizeof(buffer)) < 0) {
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

    printf("result: %d\n", result);

    close(fd);
    return 0;
}


