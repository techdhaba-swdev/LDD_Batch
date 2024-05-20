#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int global_var = 0;

void *increment(void *arg) {
    int i;
    for (i = 0; i < 100000; i++) {
        global_var++; // Race condition vulnerability
    }
    return NULL;
}

int main() {
    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, increment, NULL);
    pthread_create(&thread2, NULL, increment, NULL);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    printf("Global variable value: %d\n", global_var);
    return 0;
}



