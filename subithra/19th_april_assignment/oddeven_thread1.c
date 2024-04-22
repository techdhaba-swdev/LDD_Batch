#include <stdio.h>
#include <pthread.h>

#define MAX_NUMBER 20

int counter = 1;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond_even = PTHREAD_COND_INITIALIZER;
pthread_cond_t cond_odd = PTHREAD_COND_INITIALIZER;

void *print_even(void *arg) {
    while (counter <= MAX_NUMBER) {
        pthread_mutex_lock(&mutex);

        while (counter % 2 != 0) {
            pthread_cond_wait(&cond_even, &mutex);
        }

        printf("%d\n", counter);
        counter++;

        pthread_cond_signal(&cond_odd);
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(NULL);
}

void *print_odd(void *arg) {
    while (counter <= MAX_NUMBER) {
        pthread_mutex_lock(&mutex);

        while (counter % 2 == 0) {
            pthread_cond_wait(&cond_odd, &mutex);
        }

        printf("%d\n", counter);
        counter++;

        pthread_cond_signal(&cond_even);
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t even_thread, odd_thread;

    pthread_create(&even_thread, NULL, print_even, NULL);
    pthread_create(&odd_thread, NULL, print_odd, NULL);

    pthread_join(even_thread, NULL);
    pthread_join(odd_thread, NULL);

    return 0;
}
