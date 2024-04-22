#include <stdio.h>
#include <pthread.h>

#define MAX_SIZE 5

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t notFull = PTHREAD_COND_INITIALIZER;
pthread_cond_t notEmpty = PTHREAD_COND_INITIALIZER;
int count;

void producer(char* buf) {
    for (;;) {
        pthread_mutex_lock(&lock);

        while (count == MAX_SIZE)
            pthread_cond_wait(&notFull, &lock);

        buf[count] = getchar(); // Assuming getChar() reads a character from stdin
        count++;

        pthread_cond_signal(&notEmpty);
        pthread_mutex_unlock(&lock);
    }
}

void consumer(char* buf) {
    for (;;) {
        pthread_mutex_lock(&lock);

        while (count == 0)
            pthread_cond_wait(&notEmpty, &lock);

        putchar(buf[count - 1]); // Assuming useChar() prints a character to stdout
        count--;

        pthread_cond_signal(&notFull);
        pthread_mutex_unlock(&lock);
    }
}

int main() {
    char buffer[MAX_SIZE];
    pthread_t p;

    count = 0;

    pthread_create(&p, NULL, (void*)producer, buffer);
    consumer(buffer);

    pthread_mutex_destroy(&lock);
    pthread_cond_destroy(&notFull);
    pthread_cond_destroy(&notEmpty);

    return 0;
}




