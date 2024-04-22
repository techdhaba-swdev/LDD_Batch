#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

double progress = 0.0;
FILE *source, *destination;

long get_file_size(FILE *file) {
    fseek(file, 0L, SEEK_END);
    long size = ftell(file);
    fseek(file, 0L, SEEK_SET);
    return size;
}

void *copy_file(void *arg) {
    char buffer[BUFFER_SIZE];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, source)) > 0) {
        fwrite(buffer, 1, bytes_read, destination);
        progress = (ftell(source) / (double)get_file_size(source)) * 100.0;
    }
    return NULL;
}

void *print_progress(void *arg) {
    while (1) {
        printf("Progress: %.2f%%\n", progress);
        sleep(1);
    }
    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s source_file destination_file\n", argv[0]);
        return 1;
    }

    source = fopen(argv[1], "rb");
    if (source == NULL) {
        printf("Error: Unable to open source file.\n");
        return 1;
    }

    destination = fopen(argv[2], "wb");
    if (destination == NULL) {
        printf("Error: Unable to open destination file.\n");
        fclose(source);
        return 1;
    }

    pthread_t copy_thread, progress_thread;
    pthread_create(&copy_thread, NULL, copy_file, NULL);
    pthread_create(&progress_thread, NULL, print_progress, NULL);

    pthread_join(copy_thread, NULL);
    pthread_cancel(progress_thread);
    pthread_join(progress_thread, NULL);

    fclose(source);
    fclose(destination);

    printf("File copy completed.\n");

    return 0;
}
