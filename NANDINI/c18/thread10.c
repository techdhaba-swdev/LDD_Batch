#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define BUFFER_SIZE 1024

typedef struct {
    FILE *source;
    FILE *dest;
    long long total_size;
    long long bytes_copied;
} CopyInfo;

void *copyThread(void *arg) {
    CopyInfo *info = (CopyInfo *)arg;
    char buffer[BUFFER_SIZE];
    size_t bytes_read;

    while ((bytes_read = fread(buffer, 1, sizeof(buffer), info->source)) > 0) {
        fwrite(buffer, 1, bytes_read, info->dest);
        info->bytes_copied += bytes_read;
    }

    return NULL;
}

void *progressThread(void *arg) {
    CopyInfo *info = (CopyInfo *)arg;
    float progress;

    while (info->bytes_copied < info->total_size) {
        progress = ((float)info->bytes_copied / info->total_size) * 100;
        printf("Progress: %.2f%%\n", progress);
        // Adjust sleep time as per your preference
        sleep(1);
    }

    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s source_file destination_file\n", argv[0]);
        return 1;
    }

    FILE *source = fopen(argv[1], "rb");
    if (source == NULL) {
        perror("Error opening source file");
        return 1;
    }

    FILE *dest = fopen(argv[2], "wb");
    if (dest == NULL) {
        perror("Error opening destination file");
        fclose(source);
        return 1;
    }

    fseek(source, 0, SEEK_END);
    long long total_size = ftell(source);
    rewind(source);

    CopyInfo info = {source, dest, total_size, 0};

    pthread_t copy_tid, progress_tid;
    pthread_create(&copy_tid, NULL, copyThread, &info);
    pthread_create(&progress_tid, NULL, progressThread, &info);

    pthread_join(copy_tid, NULL);
    pthread_join(progress_tid, NULL);

    printf("File copy completed.\n");

    fclose(source);
    fclose(dest);

    return 0;
}

