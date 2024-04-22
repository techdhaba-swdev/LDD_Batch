#include <stdio.h>
#include <pthread.h>

#define MAX_NUM 20

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

int current_number = 1;

void* print_even(void* arg) {
    while (current_number <= MAX_NUM) {
        pthread_mutex_lock(&mutex);
        if (current_number % 2 == 0) {
            printf("Even Thread: %d\n", current_number);
            current_number++;
            pthread_cond_signal(&cond); // Notify the odd thread to print
        } else {
            pthread_cond_wait(&cond, &mutex); // Wait for the odd thread to print
        }
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

void* print_odd(void* arg) {
    while (current_number <= MAX_NUM) {
        pthread_mutex_lock(&mutex);
        if (current_number % 2 != 0) {
            printf("Odd Thread: %d\n", current_number);
            current_number++;
            pthread_cond_signal(&cond); // Notify the even thread to print
        } else {
            pthread_cond_wait(&cond, &mutex);  // Wait for the even thread to print
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

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);

    return 0;
}




