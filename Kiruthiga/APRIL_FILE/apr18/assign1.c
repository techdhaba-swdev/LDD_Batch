#include <stdio.h>
#include <pthread.h>

// Define mutex
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Function to print even numbers
void* print_even(void* arg) {
    for (int i = 2; i <= 20; i += 2) {
        pthread_mutex_lock(&mutex);
        printf("%d\n", i);
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

// Function to print odd numbers
void* print_odd(void* arg) {
    for (int i = 1; i <= 20; i += 2) {
        pthread_mutex_lock(&mutex);
        printf("%d\n", i);
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    // Create threads
    pthread_create(&thread1, NULL, print_even, NULL);
    pthread_create(&thread2, NULL, print_odd, NULL);

    // Join threads
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}



