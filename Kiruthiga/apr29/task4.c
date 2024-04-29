#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <signal.h>
#include <unistd.h>

#define NUM_THREADS 5

// Signal handler function
void signal_handler(int signum) {
    if (signum == SIGUSR1) {
        printf("Thread %ld: Custom signal (SIGUSR1) received.\n", pthread_self());
    }
}

// Thread function
void *thread_function(void *arg) {
    // Register signal handler for SIGUSR1
    if (signal(SIGUSR1, signal_handler) == SIG_ERR) {
        perror("Unable to set up signal handler");
        pthread_exit(NULL);
    }
    
    // Infinite loop to keep the thread running
    while (1) {
        sleep(1);
    }

    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];

    // Create multiple threads
    for (int i = 0; i < NUM_THREADS; i++) {
        if (pthread_create(&threads[i], NULL, thread_function, NULL) != 0) {
            perror("pthread_create");
            exit(EXIT_FAILURE);
        }
    }

    // Send SIGUSR1 signal to each thread
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_kill(threads[i], SIGUSR1);
    }

    // Join threads
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}


