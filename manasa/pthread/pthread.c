#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    const char *input_file;
    const char *output_file;
    int start_line;
} ThreadData;

pthread_mutex_t file_mutex = PTHREAD_MUTEX_INITIALIZER;

void *write_lines(void *arg) {
    ThreadData *data = (ThreadData *)arg;
    FILE *input_fp = fopen(data->input_file, "r");
    FILE *output_fp = fopen(data->output_file, "w");
    if (!input_fp || !output_fp) {
        perror("File opening failed");
        pthread_exit(NULL);
    }

    char line[MAX_LINE_LENGTH];
    int line_number = 1;

    while (fgets(line, sizeof(line), input_fp)) {
        if ((line_number % 2 == 0 && data->start_line == 2) ||
            (line_number % 2 != 0 && data->start_line == 1)) {
            pthread_mutex_lock(&file_mutex);
            fputs(line, output_fp);
            pthread_mutex_unlock(&file_mutex);
        }
        line_number++;
    }

    fclose(input_fp);
    fclose(output_fp);
    pthread_exit(NULL);
}

void *read_and_print(void *arg) {
    const char *file = (const char *)arg;
    FILE *fp = fopen(file, "r");
    if (!fp) {
        perror("File opening failed");
        pthread_exit(NULL);
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), fp)) {
        printf("%s", line);
    }

    fclose(fp);
    pthread_exit(NULL);
}

int main() {
    pthread_t writer1, writer2, reader1, reader2;
    ThreadData writer_data1 = {"input.txt", "odd_lines.txt", 1};
    ThreadData writer_data2 = {"input.txt", "even_lines.txt", 2};

    if (pthread_create(&writer1, NULL, write_lines, &writer_data1) != 0) {
        perror("Failed to create thread 1");
        exit(EXIT_FAILURE);
    }

    if (pthread_create(&writer2, NULL, write_lines, &writer_data2) != 0) {
        perror("Failed to create thread 2");
        exit(EXIT_FAILURE);
    }

    pthread_join(writer1, NULL);
    pthread_join(writer2, NULL);

    if (pthread_create(&reader1, NULL, read_and_print, "odd_lines.txt") != 0) {
        perror("Failed to create reader thread 1");
        exit(EXIT_FAILURE);
    }

    if (pthread_create(&reader2, NULL, read_and_print, "even_lines.txt") != 0) {
        perror("Failed to create reader thread 2");
        exit(EXIT_FAILURE);
    }

    pthread_join(reader1, NULL);
    pthread_join(reader2, NULL);

    pthread_mutex_destroy(&file_mutex);
    return 0;
}
