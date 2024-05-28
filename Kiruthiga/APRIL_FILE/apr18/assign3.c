#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

// Global variables
FILE *source, *destination;
long file_size;
long bytes_copied = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Function to get file size
long get_file_size(FILE *file) {
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    rewind(file);
    return size;
}

// Function to read from source and write to destination
void* copy_file(void* arg) {
    char buffer[BUFFER_SIZE];
    int bytes_read;

    while ((bytes_read = fread(buffer, 1, sizeof(buffer), source)) > 0) {
        pthread_mutex_lock(&mutex);

        fwrite(buffer, 1, bytes_read, destination);
        bytes_copied += bytes_read;

        pthread_mutex_unlock(&mutex);
    }

    return NULL;
}

// Function to print progress
void* print_progress(void* arg) {
    while (1) {
        pthread_mutex_lock(&mutex);

        float progress = ((float)bytes_copied / file_size) * 100;
        printf("Progress: %.2f%%\n", progress);

        pthread_mutex_unlock(&mutex);

        usleep(500000); // Sleep for 0.5 seconds
    }

    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s source_file destination_file\n", argv[0]);
        return 1;
    }

    // Open source and destination files
    source = fopen(argv[1], "rb");
    if (source == NULL) {
        perror("Error opening source file");
        return 1;
    }

    destination = fopen(argv[2], "wb");
    if (destination == NULL) {
        perror("Error opening destination file");
        fclose(source);
        return 1;
    }

    // Get file size
    file_size = get_file_size(source);

    pthread_t copy_thread, progress_thread;

    // Create copy thread
    pthread_create(&copy_thread, NULL, copy_file, NULL);

    // Create progress thread
    pthread_create(&progress_thread, NULL, print_progress, NULL);

    // Join copy thread
    pthread_join(copy_thread, NULL);

    // Join progress thread (this won't be reached as it's an infinite loop)
    pthread_join(progress_thread, NULL);

    // Close files
    fclose(source);
    fclose(destination);

    return 0;
}


