#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h>

#define DEVICE_PATH "/dev/pthread_double_integer"

// Mutex for synchronizing access to the device
pthread_mutex_t lock;

void *write_to_device(void *arg) {
    int fd;
    int *input_value = (int *)arg;

    // Lock the mutex before accessing the device
    pthread_mutex_lock(&lock);

    // Open the device file
    fd = open(DEVICE_PATH, O_RDWR);
    if (fd < 0) {
        perror("Failed to open the device file");
        pthread_mutex_unlock(&lock);
        return NULL;
    }

    // Write the input value to the device
    write(fd, input_value, sizeof(int));

    // Close the device file
    close(fd);

    // Unlock the mutex after accessing the device
    pthread_mutex_unlock(&lock);

    return NULL;
}

void *read_from_device(void *arg) {
    int fd;
    int *output_value = (int *)arg;

    // Lock the mutex before accessing the device
    pthread_mutex_lock(&lock);

    // Open the device file
    fd = open(DEVICE_PATH, O_RDWR);
    if (fd < 0) {
        perror("Failed to open the device file");
        pthread_mutex_unlock(&lock);
        return NULL;
    }

    // Read the doubled value from the device
    read(fd, output_value, sizeof(int));

    // Close the device file
    close(fd);

    // Unlock the mutex after accessing the device
    pthread_mutex_unlock(&lock);

    return NULL;
}

int main() {
    int input_value, output_value;
    pthread_t write_thread, read_thread;

    printf("Enter an integer value: ");
    scanf("%d", &input_value);

    // Initialize the mutex
    if (pthread_mutex_init(&lock, NULL) != 0) {
        printf("Mutex init has failed\n");
        return 1;
    }

    // Create the write thread
    if (pthread_create(&write_thread, NULL, write_to_device, &input_value) != 0) {
        printf("Failed to create the write thread\n");
        return 1;
    }

    // Create the read thread
    if (pthread_create(&read_thread, NULL, read_from_device, &output_value) != 0) {
        printf("Failed to create the read thread\n");
        return 1;
    }

    // Wait for the threads to finish
    pthread_join(write_thread, NULL);
    pthread_join(read_thread, NULL);

    printf("Doubled value received from kernel: %d\n", output_value);

    // Destroy the mutex
    pthread_mutex_destroy(&lock);

    return 0;
}
