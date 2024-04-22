#include <stdio.h>
#include <pthread.h>

#define MAX_SIZE 5

pthread_mutex_t bufLock;
int count;

void* producer(char* buf) {
   
    for (;;) {

        while (count == MAX_SIZE)
            pthread_mutex_lock(&bufLock);
        buf[count] = getchar();
        count++;
        pthread_mutex_unlock(&bufLock);
    }
}

void consumer(char* buf) {
    for (;;) {
        while (count == 0)
            pthread_mutex_lock(&bufLock);
        usechar(buf[count - 1]);
        count--;
        pthread_mutex_unlock(&bufLock);
    }
}

int main() {
    char buffer[MAX_SIZE];
    pthread_t p;

    count = 0;
    pthread_mutex_init(&bufLock, NULL);

    pthread_create(&p, NULL, producer, buffer);
    consumer(buffer);

    // Clean up: Destroy the mutex
    pthread_mutex_destroy(&bufLock);

    return 0;
}
