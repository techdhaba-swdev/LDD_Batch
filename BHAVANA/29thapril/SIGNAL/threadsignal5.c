#include <stdio.h>
#include <pthread.h>
#include <signal.h>
#include <unistd.h>

// Signal handler function
void sigusr1_handler(int signum) {
    printf("Thread %lu received SIGUSR1\n", (unsigned long)pthread_self());
}

// Thread function
void* thread_function(void* arg) {
    // Register the signal handler for SIGUSR1
    signal(SIGUSR1, sigusr1_handler);

    // Infinite loop to keep the thread alive
    while (1) {
        sleep(1);
    }

    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    // Create thread 1
    if (pthread_create(&thread1, NULL, thread_function, NULL) != 0) {
        perror("pthread_create");
        return 1;
    }

    // Create thread 2
    if (pthread_create(&thread2, NULL, thread_function, NULL) != 0) {
        perror("pthread_create");
        return 1;
    }

    // Print the PID of the program
    printf("PID of the program: %d\n", getpid());

    // Don't wait for threads to finish, let them run indefinitely
    // The main thread will also run indefinitely to keep the program running
    while (1) {
        sleep(1);
    }

    return 0;
}

