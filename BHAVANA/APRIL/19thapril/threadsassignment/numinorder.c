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
        if (counter % 2 == 0) {
            printf("%d\n", counter);
            counter++;
            pthread_cond_signal(&cond_odd);
        } else {
            pthread_cond_wait(&cond_even, &mutex);
        }
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

void *print_odd(void *arg) {
    while (counter <= MAX_NUMBER) {
        pthread_mutex_lock(&mutex);
        if (counter % 2 != 0) {
            printf("%d\n", counter);
            counter++;
            pthread_cond_signal(&cond_even);
        } else {
            pthread_cond_wait(&cond_odd, &mutex);
        }
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main() {
    pthread_t thread_even, thread_odd;
    
    pthread_create(&thread_even, NULL, print_even, NULL);
    pthread_create(&thread_odd, NULL, print_odd, NULL);
    
    pthread_join(thread_even, NULL);
    pthread_join(thread_odd, NULL);
    
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond_even);
    pthread_cond_destroy(&cond_odd);
    
    return 0;
}
