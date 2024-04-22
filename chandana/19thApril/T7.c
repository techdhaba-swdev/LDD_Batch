#include <stdio.h>
#include <pthread.h>

#define MAX_SIZE 5

pthread_mutex_t bufLock;
int count;

void producer(char* buf) {
    for (;;) {
        while (count == MAX_SIZE);

        pthread_mutex_lock(&bufLock);
        buf[count] = getchar();
        count++;
        pthread_mutex_unlock(&bufLock);
    }
}
void consumeChar(char c){
        printf("Consumed character %c\n",c);
}

void consumer1(char* buf) {
    for (;;) {
        while (count == 0);

        pthread_mutex_lock(&bufLock);
        consumeChar(buf[count - 1]);
        count--;
        pthread_mutex_unlock(&bufLock);
    }
}
void consumer2(char* buf) {
    for (;;) {
        while (count == 0);

        pthread_mutex_lock(&bufLock);
        consumeChar(buf[count - 1]);
        count--;
        pthread_mutex_unlock(&bufLock);
    }
}


int main() {
    char buffer[MAX_SIZE];
    pthread_t p, c1,c2;

    count = 0;
    pthread_mutex_init(&bufLock, NULL);

    pthread_create(&p, NULL, (void*)producer, buffer);
    pthread_create(&c1, NULL, (void*)consumer1, buffer);
    pthread_create(&c2,NULL,(void*)consumer2,buffer);

    pthread_join(p, NULL);
    pthread_join(c1, NULL);
    pthread_join(c2,NULL);

    return 0;
}

