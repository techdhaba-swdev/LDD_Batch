//File Copy with Progress: Create a program using threads where one thread
// reads data from a source file and another writes data to a destination file.
// Include a third thread that periodically prints the progress of the copy
// operation (e.g., percentage complete).


#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define BUFFER_SIZE 1024

// Global variables
char source_file[] = "source.txt";
char dest_file[] = "destination.txt";
int total_bytes = 0;
int copied_bytes = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Function to print copy progress
void *print_progress(void *arg) {
    while (1) {
        pthread_mutex_lock(&mutex);
        float progress = (float)copied_bytes / total_bytes * 100;
        printf("Progress: %.2f%%\n", progress);
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
}

// Function to copy data from source to destination file
void *copy_file(void *arg) {
    FILE *src, *dest;
    char buffer[BUFFER_SIZE];
    int bytes_read;

    src = fopen(source_file, "rb");
    dest = fopen(dest_file, "wb");

    if (src == NULL || dest == NULL) {
        printf("Error opening files.\n");
        exit(1);
    }

    fseek(src, 0L, SEEK_END);
    total_bytes = ftell(src);
    fseek(src, 0L, SEEK_SET);

    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, src)) > 0) {
        pthread_mutex_lock(&mutex);
        fwrite(buffer, 1, bytes_read, dest);
        copied_bytes += bytes_read;
        pthread_mutex_unlock(&mutex);
    }

    fclose(src);
    fclose(dest);

    
}

int main() {
    pthread_t copy_thread, progress_thread;

    // Create threads
    pthread_create(&copy_thread, NULL, copy_file, NULL);
    pthread_create(&progress_thread, NULL, print_progress, NULL);

    // Wait for threads to finish
    pthread_join(copy_thread, NULL);
    pthread_join(progress_thread, NULL);

    return 0;
}
