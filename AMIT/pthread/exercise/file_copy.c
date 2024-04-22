#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define BUFFER_SIZE 1024

FILE* source_file;
FILE* dest_file;
unsigned long total_bytes;
unsigned long copied_bytes = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* read_file(void* arg) {
    char buffer[BUFFER_SIZE];
    size_t bytes_read;

    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, source_file)) > 0) {
        pthread_mutex_lock(&mutex);
        copied_bytes += bytes_read;
        pthread_mutex_unlock(&mutex);
        fwrite(buffer, 1, bytes_read, dest_file);
    }

    return NULL;
}

void* print_progress(void* arg) {
    while (1) {
        pthread_mutex_lock(&mutex);
        double progress = (double)copied_bytes / total_bytes * 100;
        printf("Progress: %.2f%%\n", progress);
        pthread_mutex_unlock(&mutex);
        usleep(500000); // Sleep for 500 ms
    }

    return NULL;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: %s <source_file> <dest_file>\n", argv[0]);
        return 1;
    }

    source_file = fopen(argv[1], "rb");
    dest_file = fopen(argv[2], "wb");
    if (!source_file || !dest_file) {
        perror("Error opening files");
        return 1;
    }

    fseek(source_file, 0, SEEK_END);
    total_bytes = ftell(source_file);
    fseek(source_file, 0, SEEK_SET);

    pthread_t read_thread, progress_thread;
    pthread_create(&read_thread, NULL, read_file, NULL);
    pthread_create(&progress_thread, NULL, print_progress, NULL);

    pthread_join(read_thread, NULL);
    pthread_cancel(progress_thread); // Stop the progress thread

    fclose(source_file);
    fclose(dest_file);

    return 0;
}
