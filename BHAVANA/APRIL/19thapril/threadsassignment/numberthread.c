#include <stdio.h>
#include <pthread.h>

int current_number = 1;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *print_even(void *arg) {
    while (current_number <= 20) {
        pthread_mutex_lock(&mutex);
        if (current_number % 2 == 0) {
            printf("%d\n", current_number);
            current_number++;
        }
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

void *print_odd(void *arg) {
    while (current_number <= 20) {
        pthread_mutex_lock(&mutex);
        if (current_number % 2 != 0) {
            printf("%d\n", current_number);
            current_number++;
        }
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main() {
    pthread_t tid1, tid2;
    pthread_create(&tid1, NULL, print_even, NULL);
    pthread_create(&tid2, NULL, print_odd, NULL);
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    pthread_mutex_destroy(&mutex);
    return 0;
}
