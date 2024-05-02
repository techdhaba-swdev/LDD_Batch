#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <pthread.h>

// Signal handler function for SIGUSR1
void sigusr1_handler(int signum) {
    printf("received SIGUSR1 signal in thread %ld\n", pthread_self());
}

// Thread function
void *thread_function(void *arg) {
    // Register signal handler for SIGUSR1 in the thread
    signal(SIGUSR1, sigusr1_handler);

    // Print thread ID
    printf("thread created with id %ld\n", pthread_self());

   
    while (1) {
        sleep(1);
    }

    return NULL;
}

int main() {
    
    signal(SIGUSR1,sigusr1_handler);
    pthread_t thread;//create thread
    if (pthread_create(&thread, NULL, thread_function, NULL) != 0) {
        perror("pthread_create");
        return EXIT_FAILURE;
    }

    // Send SIGUSR1 signal to the thread
    pthread_kill(thread, SIGUSR1);

  
    pthread_join(thread, NULL);

    return EXIT_SUCCESS;
}
