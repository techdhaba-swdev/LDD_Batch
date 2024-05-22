#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

#define DATA_SIZE sizeof(struct user_data)

struct user_data {
    int value;
    char message[20];
};

pthread_mutex_t my_lock;

void* write_data(void* arg) {
    struct user_data data;
    data.value = rand() % 100;  // Example data
    snprintf(data.message, sizeof(data.message), "Message %d", data.value);

    // Simulating user data buffer
    struct user_data* user_buf = &data;

    // Acquire mutex to protect critical section
    pthread_mutex_lock(&my_lock);

    // Process data from user space (replace with your actual logic)
    printf("Received data: value = %d, message = %s\n", user_buf->value, user_buf->message);

    // Release mutex after critical section
    pthread_mutex_unlock(&my_lock);

    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    // Initialize the mutex
    if (pthread_mutex_init(&my_lock, NULL) != 0) {
        fprintf(stderr, "Failed to initialize mutex\n");
        return 1;
    }

    // Create threads to simulate concurrent writes
    if (pthread_create(&thread1, NULL, write_data, NULL) != 0) {
        fprintf(stderr, "Failed to create thread 1\n");
        pthread_mutex_destroy(&my_lock);
        return 1;
    }

    if (pthread_create(&thread2, NULL, write_data, NULL) != 0) {
        fprintf(stderr, "Failed to create thread 2\n");
        pthread_mutex_destroy(&my_lock);
        return 1;
    }

    // Wait for threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // Destroy the mutex
    pthread_mutex_destroy(&my_lock);

    printf("Program completed successfully\n");
    return 0;
}
