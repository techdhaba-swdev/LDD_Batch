#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <signal.h>
#include <unistd.h>

#define NUM_THREADS 5


void sigusr1_handler(int sig) {
    printf("Thread %lu received SIGUSR1\n", pthread_self());
}


void *thread_function(void *arg) {
   
    signal(SIGUSR1, sigusr1_handler);

    while (1) {
       // sleep(1); 
    }

    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int i;

    
    for (i = 0; i < NUM_THREADS; i++) {
        if (pthread_create(&threads[i], NULL, thread_function, NULL) != 0) {
            perror("pthread_create");
            exit(EXIT_FAILURE);
        }
    }

    
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_kill(threads[i], SIGUSR1);
    }


    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
