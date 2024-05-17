#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <pthread.h>

pthread_mutex_t lock;

void sigByThread(int sig) {
    pthread_t thread_id = pthread_self();
   printf("\nThread ID: %lu\n", (unsigned long)thread_id);
   
   //write(1,"hello",5);
}

void* thread_function(){

    pthread_mutex_lock(&lock);
    pthread_kill(pthread_self(), SIGUSR1); 
    pthread_mutex_unlock(&lock);
    return NULL;
}

int main() {
    signal(SIGUSR1, sigByThread);
    pthread_mutex_init(&lock, NULL);
    pthread_t p1, p2;
    pthread_create(&p1, NULL, (void*) thread_function,NULL);
    pthread_create(&p2, NULL, (void*) thread_function,NULL);
    pthread_join(p1, NULL);
    pthread_join(p2, NULL);
    return 0;
}


