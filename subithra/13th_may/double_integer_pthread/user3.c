#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h>

#define DEVICE_PATH "/dev/double_ip"

int input_value, output_value;
pthread_mutex_t mutex;

void* thread_function(void* arg) {
    int fd = *(int*)arg;

    while (1) {
        pthread_mutex_lock(&mutex);
        printf("Enter an integer value : ");
        scanf("%d", &input_value);
        pthread_mutex_unlock(&mutex);

       
        // Write the input value to the device
        write(fd, &input_value, sizeof(int));

        // Read the doubled value from the device
        read(fd, &output_value, sizeof(int));

        printf("Doubled value received from kernel: %d\n", output_value);
    }

    return NULL;
}

int main() {
    int fd;
    pthread_t thread_id;

    // Initialize mutex
    if (pthread_mutex_init(&mutex, NULL) != 0) {
        perror("Mutex initialization failed");
        return 1;
    }

    // Open the device file
    fd = open(DEVICE_PATH, O_RDWR);
    if (fd < 0) {
        perror("Failed to open the device file");
        return 1;
    }

    // Create thread
    if (pthread_create(&thread_id, NULL, thread_function, &fd) != 0) {
        perror("Thread creation failed");
        close(fd);
        return 1;
    }

    // Wait for the thread to finish
    pthread_join(thread_id, NULL);

    // Destroy mutex
    pthread_mutex_destroy(&mutex);

    return 0;
}
