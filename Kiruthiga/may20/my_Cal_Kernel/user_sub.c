#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h>
#include <poll.h>
#include <string.h>

#define DEVICE_PATH "/dev/cal_kernel"

typedef struct {
    int num1;
    int num2;
    char operation;
} calc_data;

void *thread_func(void *arg) {
    calc_data *data = (calc_data *)arg;
    int fd = open(DEVICE_PATH, O_RDWR);
    if (fd < 0) {
        perror("Failed to open device");
        return NULL;
    }

    char buffer[sizeof(int) * 2 + sizeof(char)];
    memcpy(buffer, &data->num1, sizeof(int));
    memcpy(buffer + sizeof(int), &data->num2, sizeof(int));
    memcpy(buffer + sizeof(int) * 2, &data->operation, sizeof(char));

    if (write(fd, buffer, sizeof(buffer)) < 0) {
        perror("Failed to write to device");
        close(fd);
        return NULL;
    }

    struct pollfd pfd = {fd, POLLIN, 0};
    poll(&pfd, 1, -1);

    int result;
    if (read(fd, &result, sizeof(result)) < 0) {
        perror("Failed to read from device");
        close(fd);
        return NULL;
    }

    printf("Result of %d - %d = %d\n", data->num1, data->num2, result);

    close(fd);
    return NULL;
}

int main() {
    pthread_t thread_sub;
    calc_data data_sub;

    printf("Enter the first number: ");
    scanf("%d", &data_sub.num1);
    printf("Enter the second number: ");
    scanf("%d", &data_sub.num2);
    data_sub.operation = '-';

    pthread_create(&thread_sub, NULL, thread_func, &data_sub);

    pthread_join(thread_sub, NULL);

    return 0;
}


