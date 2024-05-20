//  including the required header files 
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include "pthread.h"

// main function
int main() {
    
    pthread_t writer_threads[2], reader_threads[2];
    thread_data_t writer_data[2] = {
        {"input.txt", "even_lines.txt", 1},
        {"input.txt", "odd_lines.txt", 0}
    };

    // Initialize mutex
    if (pthread_mutex_init(&file_mutex, NULL) != 0) {
        perror("Mutex init failed");
        return 1;
    }

    // Create writer threads
    for (int i = 0; i < 2; i++) {
        if (pthread_create(&writer_threads[i], NULL, write_lines, &writer_data[i]) != 0) {
            perror("Failed to create writer thread");
            return 1;
        }
    }

    // Wait for writer threads to finish
    for (int i = 0; i < 2; i++) {
        pthread_join(writer_threads[i], NULL);
    }

    const char *output_files[2] = {"even_lines.txt", "odd_lines.txt"};

    // Create reader threads
    for (int i = 0; i < 2; i++) {
        if (pthread_create(&reader_threads[i], NULL, read_lines, (void*)output_files[i]) != 0) {
            perror("Failed to create reader thread");
            return 1;
        }
    }

    // Wait for reader threads to finish
    for (int i = 0; i < 2; i++) {
        pthread_join(reader_threads[i], NULL);
    }

    pthread_mutex_destroy(&file_mutex);
    return 0;
}
