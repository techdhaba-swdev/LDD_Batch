#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#define MAX_COUNT 20

pthread_mutex_t mutex;
pthread_cond_t cond_even;
pthread_cond_t cond_odd;
int counter = 1;

void *evenThread(void *arg) {
    while (counter <= MAX_COUNT) {
        pthread_mutex_lock(&mutex);
        if (counter % 2 == 0) {
            printf("Even Thread: %d\n", counter++);
            pthread_cond_signal(&cond_odd);
        } else {
            pthread_cond_wait(&cond_even, &mutex);
        }
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

void *oddThread(void *arg) {
    while (counter <= MAX_COUNT) {
        pthread_mutex_lock(&mutex);
        if (counter % 2 != 0) {
            printf("Odd Thread: %d\n", counter++);
            pthread_cond_signal(&cond_even);
        } else {
            pthread_cond_wait(&cond_odd, &mutex);
        }
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main() 
{
    pthread_t even_tid, odd_tid;
    
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond_even, NULL);
    pthread_cond_init(&cond_odd, NULL);

    pthread_create(&even_tid, NULL, evenThread, NULL);
    pthread_create(&odd_tid, NULL, oddThread, NULL);

    pthread_join(even_tid, NULL);
    pthread_join(odd_tid, NULL);

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond_even);
    pthread_cond_destroy(&cond_odd);

    return 0;
}

