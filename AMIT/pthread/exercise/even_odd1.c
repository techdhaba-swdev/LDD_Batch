#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
int count = 1; // Shared counter variable

void* print_even(void* arg) {
    while (count <= 20) {
        pthread_mutex_lock(&mutex);
        if (count % 2 == 0) {
            printf("Even: %d\n", count);
            count++;
            pthread_cond_signal(&cond);
        } else {
            pthread_cond_wait(&cond, &mutex);
        }
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

void* print_odd(void* arg) {
    while (count <= 20) {
        pthread_mutex_lock(&mutex);
        if (count % 2 != 0) {
            printf("Odd: %d\n", count);
            count++;
            pthread_cond_signal(&cond);
        } else {
            pthread_cond_wait(&cond, &mutex);
        }
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main() {
    pthread_t even_thread, odd_thread;

    pthread_create(&even_thread, NULL, print_even, NULL);
    pthread_create(&odd_thread, NULL, print_odd, NULL);

    pthread_join(even_thread, NULL);
    pthread_join(odd_thread, NULL);

    return 0;
}
