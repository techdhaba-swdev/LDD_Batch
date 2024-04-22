#include <stdio.h>
#include <pthread.h>

#define NTHREADS 20

void *thread_function(void *);

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
int counter = 0;

int main() {
    pthread_t thread_id[NTHREADS]; // Corrected array declaration
    int i, j;

    for (i = 0; i < NTHREADS; i++) {
        pthread_create(&thread_id[i], NULL, thread_function, NULL); // Pass individual thread IDs
    }

    for (j = 0; j < NTHREADS; j++) {
        pthread_join(thread_id[j], NULL);
    }

    printf("Final counter value: %d\n", counter);
    return 0;
}

void *thread_function(void *dummyPtr) {
    printf("Thread number %ld\n", pthread_self());
   // pthread_mutex_lock(&mutex1);
    counter++;
    //pthread_mutex_unlock(&mutex1);
    printf("Counter value: %d\n",counter);
    return NULL; // Added return statement
}

