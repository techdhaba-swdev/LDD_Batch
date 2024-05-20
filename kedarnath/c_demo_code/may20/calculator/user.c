#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h>
#include <poll.h>

#define DEVICE_PATH "/dev/calculator_device"

struct calc_data {
    int operand1;
    int operand2;
    char operator;
    int result;
};

void* calculation_thread(void* arg) {
    int fd = *((int*)arg);
    struct calc_data data;

    if (read(fd, &data, sizeof(struct calc_data)) < 0) {
        perror("Failed to read from device");
        return NULL;
    }

    if (data.result == -1) {
        printf("Error: Division by zero\n");
    } else {
        printf("Result: %d\n", data.result);
    }

    close(fd);
    return NULL;
}

int main() {
    int fd;
    struct calc_data data;
    pthread_t tid;
    struct pollfd fds[1];
    int ret;

    fd = open(DEVICE_PATH, O_RDWR);
    if (fd < 0) {
        perror("Failed to open the device");
        return EXIT_FAILURE;
    }

    printf("Enter first operand: ");
    scanf("%d", &data.operand1);
    printf("Enter second operand: ");
    scanf("%d", &data.operand2);
    printf("Enter operator (+, -, *, /): ");
    scanf(" %c", &data.operator);

    // Write data to the device
    if (write(fd, &data, sizeof(struct calc_data)) < 0) {
        perror("Failed to write to device");
        close(fd);
        return EXIT_FAILURE;
    }

    // Prepare poll structure
    fds[0].fd = fd;
    fds[0].events = POLLIN;

    // Poll for data availability
    ret = poll(fds, 1, -1);
    if (ret < 0) {
        perror("Poll error");
        close(fd);
        return EXIT_FAILURE;
    }

    // Check if the device is ready for reading
    if (fds[0].revents & POLLIN) {
        // Start calculation thread
        pthread_create(&tid, NULL, calculation_thread, &fd);
        pthread_join(tid, NULL);
    } else {
        printf("Device not ready for reading\n");
    }

    return EXIT_SUCCESS;
}



