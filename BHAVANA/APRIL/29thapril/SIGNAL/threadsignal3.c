#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <signal.h>
#include <unistd.h>

// Function to handle SIGUSR1 signal for each thread
void sigusr1_handler(int signum) {
    printf("Thread ID: %lu - Received SIGUSR1\n", pthread_self());
}

// Function to create threads
void* thread_function(void* arg) {
    // Register signal handler for SIGUSR1
    signal(SIGUSR1, sigusr1_handler);

    // Print thread ID
    printf("Thread ID: %lu - Started\n", pthread_self());

    // Loop indefinitely
    while (1) {
        // Do nothing, waiting for SIGUSR1 signal
        sleep(1);
    }

    return NULL;
}

int main() {
    pthread_t thread1, thread2;
    int ret1, ret2;

    // Create thread 1
    ret1 = pthread_create(&thread1, NULL, thread_function, NULL);
    if (ret1 != 0) {
        fprintf(stderr, "Error creating thread 1\n");
        return EXIT_FAILURE;
    }

    // Create thread 2
    ret2 = pthread_create(&thread2, NULL, thread_function, NULL);
    if (ret2 != 0) {
        fprintf(stderr, "Error creating thread 2\n");
        return EXIT_FAILURE;
    }

    // Send SIGUSR1 signal to each thread
    pthread_kill(thread1, SIGUSR1);
    pthread_kill(thread2, SIGUSR1);

    // Wait for threads to finish (this won't happen in this program)
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}
