#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h>

#define DEVICE_PATH "/dev/double_integer"

void *read_from_device(void *arg) {
    int fd = *(int *)arg;
    int output_value;

    // Read the doubled value from the device
    read(fd, &output_value, sizeof(int));

    printf("Doubled value received from kernel: %d\n", output_value);

    pthread_exit(NULL);
}

int main() {
    int fd;
    int input_value;
    pthread_t thread;

    printf("Enter an integer value: ");
    scanf("%d", &input_value);

    // Open the device file
    fd = open(DEVICE_PATH, O_RDWR);
    if (fd < 0) {
        perror("Failed to open the device file");
        return 1;
    }

    // Create a new thread to read from the device
    if (pthread_create(&thread, NULL, read_from_device, &fd)) {
        perror("Failed to create thread");
        close(fd);
        return 1;
    }

    // Write the input value to the device
    write(fd, &input_value, sizeof(int));

    // Wait for the thread to complete
    pthread_join(thread, NULL);

    // Close the device file
    close(fd);

    return 0;
}
