//Print Numbers in Order: Write a program using 
//two threads where one thread prints even numbers and
// the other prints odd numbers, both in ascending order, 
//from 1 to 20. Ensure proper synchronization to avoid race conditions.


#include <stdio.h>
#include <pthread.h>

// Global variables
int current_number = 1;
pthread_mutex_t lock;

// Function to print odd numbers
void *print_odd(void *arg) {
    while (current_number <= 20) {
        pthread_mutex_lock(&lock);
        if (current_number % 2 != 0) {
            printf("%d\n", current_number);
            current_number++;
        }
        pthread_mutex_unlock(&lock);
    }
    pthread_exit(NULL);
}

// Function to print even numbers
void *print_even(void *arg) {
    while (current_number <= 20) {
        pthread_mutex_lock(&lock);
        if (current_number % 2 == 0) {
            printf("%d\n", current_number);
            current_number++;
        }
        pthread_mutex_unlock(&lock);
    }
    pthread_exit(NULL);
}

int main() {
    // Initialize mutex
    pthread_mutex_init(&lock, NULL);

    // Declare thread IDs
    pthread_t odd_thread, even_thread;

    // Create threads
    pthread_create(&odd_thread, NULL, print_odd, NULL);
    pthread_create(&even_thread, NULL, print_even, NULL);

    // Wait for threads to finish
    pthread_join(odd_thread, NULL);
    pthread_join(even_thread, NULL);

    // Destroy mutex
    pthread_mutex_destroy(&lock);

    return 0;
}
