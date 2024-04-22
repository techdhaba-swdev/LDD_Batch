#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define BUFFER_SIZE 5

typedef struct {
    int buffer[BUFFER_SIZE];
    int size;
    int in;
    int out;
    pthread_mutex_t mutex;
    pthread_cond_t empty;
    pthread_cond_t full;
} Buffer;

void initBuffer(Buffer *buf) {
    buf->size = 0;
    buf->in = 0;
    buf->out = 0;
    pthread_mutex_init(&buf->mutex, NULL);
    pthread_cond_init(&buf->empty, NULL);
    pthread_cond_init(&buf->full, NULL);
}

void cleanupBuffer(Buffer *buf) {
    pthread_mutex_destroy(&buf->mutex);
    pthread_cond_destroy(&buf->empty);
    pthread_cond_destroy(&buf->full);
}

void addItem(Buffer *buf, int item) {
    pthread_mutex_lock(&buf->mutex);
    while (buf->size == BUFFER_SIZE) {
        pthread_cond_wait(&buf->full, &buf->mutex);
    }
    buf->buffer[buf->in] = item;
    buf->in = (buf->in + 1) % BUFFER_SIZE;
    buf->size++;
    pthread_cond_signal(&buf->empty);
    pthread_mutex_unlock(&buf->mutex);
}

int removeItem(Buffer *buf) {
    pthread_mutex_lock(&buf->mutex);
    while (buf->size == 0) {
        pthread_cond_wait(&buf->empty, &buf->mutex);
    }
    int item = buf->buffer[buf->out];
    buf->out = (buf->out + 1) % BUFFER_SIZE;
    buf->size--;
    pthread_cond_signal(&buf->full);
    pthread_mutex_unlock(&buf->mutex);
    return item;
}

void *producer(void *arg) {
    Buffer *buf = (Buffer *)arg;
    while (1) {
        int item = rand() % 100;
        addItem(buf, item);
        printf("Produced: %d\n", item);
        sleep(1);
    }
    return NULL;
}

void *consumer(void *arg) {
    Buffer *buf = (Buffer *)arg;
    while (1) {
        int item = removeItem(buf);
        printf("Consumed: %d\n", item);
        sleep(1);
    }
    return NULL;
}

int main() {
    Buffer buf;
    initBuffer(&buf);

    pthread_t prod, cons;
    pthread_create(&prod, NULL, producer, &buf);
    pthread_create(&cons, NULL, consumer, &buf);

    pthread_join(prod, NULL);
    pthread_join(cons, NULL);

    cleanupBuffer(&buf);

    return 0;
}
