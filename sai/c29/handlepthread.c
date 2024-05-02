#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<signal.h>

#define NUM_THREADS 25

// Custom data structure to pass thread ID to signal handler
typedef struct {
    int thread_id;
} ThreadData;

// Signal handler function for SIGUSR1
void sigusr1_handler(int signum, siginfo_t *info, void *context) {
    printf("Thread %d received SIGUSR1: Custom message\n", info->si_value.sival_int);
}

// Thread function
void *thread_function(void *arg) {
    ThreadData *data = (ThreadData *)arg;

    // Set up signal handler for SIGUSR1
    struct sigaction sa;
    sa.sa_sigaction = sigusr1_handler;
    sa.sa_flags = SA_SIGINFO;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGUSR1, &sa, NULL);

    // Print thread ID
    printf("Thread %d created\n", data->thread_id);

    // Keep the thread alive
    while (1) {
        // Do something...
    }

    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    ThreadData thread_data[NUM_THREADS];

    // Create threads
       for (int i = 0; i < NUM_THREADS; i++) {
        thread_data[i].thread_id = i + 1;
        if (pthread_create(&threads[i], NULL, thread_function, (void *)&thread_data[i]) != 0) {
            fprintf(stderr, "Error creating thread %d\n", i + 1);
            exit(EXIT_FAILURE);
        }
    }

    // Send SIGUSR1 signal to each thread
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_kill(threads[i], SIGUSR1);
    }

    // Wait for threads to finish (which they won't in this example)
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
