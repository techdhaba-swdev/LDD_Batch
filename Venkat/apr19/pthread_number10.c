#include <stdio.h>
#include <pthread.h>

pthread_mutex_t mutex;
pthread_cond_t cond;
int counter = 1; // shared counter variable

void *printEven(void *arg) {
    while (counter <= 10) {
        pthread_mutex_lock(&mutex);
        if (counter % 2 == 0) {
            printf("Even: %d\n", counter);
            counter++;
        }
        pthread_cond_signal(&cond); // signal odd thread
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(NULL);
}

void *printOdd(void *arg) {
    while (counter <= 10) {
        pthread_mutex_lock(&mutex);
        if (counter % 2 != 0) {
            pthread_cond_wait(&cond, &mutex); // wait for signal from even thread
            printf("Odd: %d\n", counter);
            counter++;
        }
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t evenThread, oddThread;

    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond, NULL);

    pthread_create(&evenThread, NULL, printEven, NULL);
    pthread_create(&oddThread, NULL, printOdd, NULL);

    pthread_join(evenThread, NULL);
    pthread_join(oddThread, NULL);

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);

    return 0;
}
