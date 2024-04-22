#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define BUFFER_SIZE 1024

// Global variables
FILE *source_file, *dest_file;
long total_bytes = 0, copied_bytes = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Function to calculate the percentage copied
int calculate_percentage() {
    return (int)(((double)copied_bytes / total_bytes) * 100);
}

// Thread function to copy data from source file to destination file
void* copy_thread(void* arg) {
    char buffer[BUFFER_SIZE];
    size_t bytes_read;

    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, source_file)) > 0) {
        pthread_mutex_lock(&mutex);
        fwrite(buffer, 1, bytes_read, dest_file);
        copied_bytes += bytes_read;
        pthread_mutex_unlock(&mutex);
    }

    return NULL;
}

// Thread function to print progress of copy operation
void* progress_thread(void* arg) {
    int last_percentage = -1;

    while (1) {
        pthread_mutex_lock(&mutex);
        int percentage = calculate_percentage();
        pthread_mutex_unlock(&mutex);

        if (percentage != last_percentage) {
            printf("Progress: %d%%\n", percentage);
            last_percentage = percentage;
        }

        if (copied_bytes >= total_bytes) {
            break;
        }

        sleep(1);  // Sleep for 1 second
    }

    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <source_file> <dest_file>\n", argv[0]);
        return 1;
    }

    source_file = fopen(argv[1], "rb");
    if (!source_file) {
        perror("Error opening source file");
        return 1;
    }

    dest_file = fopen(argv[2], "wb");
    if (!dest_file) {
        perror("Error opening destination file");
        fclose(source_file);
        return 1;
    }

    fseek(source_file, 0, SEEK_END);
    total_bytes = ftell(source_file);
    fseek(source_file, 0, SEEK_SET);

    pthread_t copy_tid, progress_tid;
    pthread_create(&copy_tid, NULL, copy_thread, NULL);
    pthread_create(&progress_tid, NULL, progress_thread, NULL);

    pthread_join(copy_tid, NULL);
    pthread_join(progress_tid, NULL);

    fclose(source_file);
    fclose(dest_file);

    return 0;
}
