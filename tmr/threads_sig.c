#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 3

// Structure to pass thread ID to the signal handler
struct ThreadData {
    pthread_t tid;
};

// Signal handler for SIGUSR1
void sigusr1_handler(int signum, siginfo_t *info, void *context) {
    printf("Thread %ld received SIGUSR1\n", (long)info->si_value.sival_ptr);
}

// Thread function
void *thread_function(void *arg) {
    struct ThreadData *data = (struct ThreadData *)arg;
    pthread_t tid = data->tid;

    // Set up signal handler for SIGUSR1
    struct sigaction sa;
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = sigusr1_handler;
    sigemptyset(&sa.sa_mask);
    if (sigaction(SIGUSR1, &sa, NULL) == -1) {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    // Loop infinitely
    while (1) {
        sleep(1); // Sleep to keep the thread alive
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    struct ThreadData thread_data[NUM_THREADS];

    // Create threads
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, thread_function, &thread_data[i]);
        thread_data[i].tid = threads[i];
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

