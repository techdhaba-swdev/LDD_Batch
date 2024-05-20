#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <signal.h>
#include <unistd.h>
#include <stdint.h>

#define NUM_THREADS 3

// Function to handle SIGUSR1 signal for each thread
void* thread_function(void* arg) {
    intptr_t thread_id = (intptr_t)arg;

    // Signal handler for SIGUSR1
    void sigusr1_handler(int signum) {
        printf("Thread %ld received SIGUSR1 signal.\n", (long)thread_id);
    }

    // Register the signal handler for SIGUSR1
    signal(SIGUSR1, sigusr1_handler);

    // Infinite loop to keep the thread alive
    while (1) {
        // Do nothing, waiting for SIGUSR1
        sleep(1); // Sleep for 1 second to prevent high CPU usage
    }

    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    intptr_t thread_ids[NUM_THREADS];

    // Create multiple threads
    for (intptr_t i = 0; i < NUM_THREADS; ++i) {
        thread_ids[i] = i + 1;
        pthread_create(&threads[i], NULL, thread_function, (void*)thread_ids[i]);
    }

    // Send SIGUSR1 signal to each thread
    for (int i = 0; i < NUM_THREADS; ++i) {
        pthread_kill(threads[i], SIGUSR1);
    }

    // Wait for a while to allow threads to print messages
    sleep(1);

    return EXIT_SUCCESS;
}

