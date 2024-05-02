#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <pthread.h>

pthread_mutex_t lock;

void sigByThread(int sig) {
    pthread_t thread_id = pthread_self();
    printf("\nThread ID: %lu\n", (unsigned long)thread_id);
}

void *thread_function(void *arg) {
    pthread_mutex_lock(&lock);
    kill(pthread_self(), SIGUSR1); // Sending SIGUSR1 to the thread itself
    pthread_mutex_unlock(&lock);
    return NULL;
}

int main() {
    signal(SIGUSR1, sigByThread);
    pthread_mutex_init(&lock, NULL);
    pthread_t p1, p2;
    pthread_create(&p1, NULL, thread_function, NULL);
    pthread_create(&p2, NULL, thread_function, NULL);
    pthread_join(p1, NULL);
    pthread_join(p2, NULL);
    return 0;
}

