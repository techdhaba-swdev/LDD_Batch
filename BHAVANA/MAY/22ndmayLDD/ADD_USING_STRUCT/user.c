#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define DEVICE_PATH "/dev/sum"

// Define a struct to store numbers and length
struct Data {
    int numbers[10];
    int length;
};

int main() {
    int fd = open(DEVICE_PATH, O_RDWR);
    if (fd < 0) {
        perror("open");
        return -1;
    }

    struct Data data; // Create an instance of the struct
    printf("Enter 10 numbers separated by '+': ");
    char input[256];
    scanf("%s", input);

    char *token = strtok(input, "+");
    int i = 0;
    while (token != NULL && i < 10) {
        data.numbers[i++] = atoi(token);
        token = strtok(NULL, "+");
    }

    data.length = i; // Store the count of numbers entered

    if (write(fd, &data, sizeof(data)) < 0) {
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

    printf("Result of addition: %d\n", result);

    close(fd);
    return 0;
}


