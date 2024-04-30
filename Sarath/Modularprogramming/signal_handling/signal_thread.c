#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <signal.h>
#include <unistd.h>

#define NUM_THREADS 3

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void *thread_function(void *arg);
void signal_handler(int sig);

void *thread_function(void *arg) {
    pthread_t tid = pthread_self();
    signal(SIGUSR1, signal_handler);

    pthread_mutex_lock(&lock);
    printf("Thread ID: %ld - Thread started\n", (long)tid);
    pthread_mutex_unlock(&lock);

    while(1) {
        // Keep the thread alive
        sleep(1);
    }

    return NULL;
}

void signal_handler(int sig) {
    pthread_t tid = pthread_self();

    pthread_mutex_lock(&lock);
    printf("Thread ID: %ld - Custom Message: Signal SIGUSR1 received\n", (long)tid);
    pthread_mutex_unlock(&lock);
}

int main() {
    pthread_t threads[NUM_THREADS];

    for(int i = 0; i < NUM_THREADS; i++) {
        if(pthread_create(&threads[i], NULL, thread_function, NULL) != 0) {
            perror("pthread_create");
            exit(EXIT_FAILURE);
        }
    }

    // Send SIGUSR1 to each thread
    for(int i = 0; i < NUM_THREADS; i++) {
        pthread_kill(threads[i], SIGUSR1);
    }

    // Wait for threads to finish
    for(int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
