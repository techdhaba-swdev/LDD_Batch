#include <stdio.h>

#include <stdlib.h>

#include <unistd.h>

#include <pthread.h>

#include <signal.h>
 
#define NUM_THREADS 3  // macro set to value 3
 
// here declares gloable varibles no need to declare again in the function if not its need to pass as an agument to function

volatile sig_atomic_t running = 1; // the value of this varibles by signals like ctrl+c invokes SIGINT this count is increased
 
// Thread function

void *thread_function(void *arg) {

    int thread_id = *((int *)arg);

    while (running) {

        printf("Thread %d is running\n", thread_id);

        sleep(1);

    }

    printf("Thread %d exiting\n", thread_id);

    pthread_exit(NULL);

}
 
// Signal handler function for SIGINT

void sigint_handler(int signum) {

    printf("Caught SIGINT. Stopping threads...\n");

    running = 0;

}
 
int main() {


    signal(SIGINT, sigint_handler); // when ever i use ctrl+c it invokes SIGINT signal its self as an argument 
 
    // Create threads

    pthread_t threads[NUM_THREADS];

    int thread_ids[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; ++i) {

        thread_ids[i] = i + 1;

        pthread_create(&threads[i], NULL, thread_function, &thread_ids[i]);

    }
 
    // Wait for threads to finish

    for (int i = 0; i < NUM_THREADS; ++i) {

        pthread_join(threads[i], NULL);

    }
 
    printf("All threads have finished\n");
 
    return 0;

}


