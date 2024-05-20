#include "pthread.h"
void* write_lines(void* arg) {
    thread_data_t *data = (thread_data_t *) arg;
    FILE *output_file = fopen(data->filename, "w");
    if (!output_file) {
        perror("Failed to open output file");
        pthread_exit(NULL);
    }

    for (int i = data->start_index; i < line_count; i += data->step) {
        pthread_mutex_lock(&file_mutex);
        if (lines[i]) {
            fprintf(output_file, "%s", lines[i]);
        }
        pthread_mutex_unlock(&file_mutex);
    }

    fclose(output_file);
    pthread_exit(NULL);
}

void* read_lines(void* arg) {
    char *filename = (char *) arg;
    FILE *input_file = fopen(filename, "r");
    if (!input_file) {
        perror("Failed to open input file");
        pthread_exit(NULL);
    }

    char buffer[MAX_LINE_LENGTH];
    while (fgets(buffer, sizeof(buffer), input_file)) {
        pthread_mutex_lock(&file_mutex);
        printf("%s", buffer);
        pthread_mutex_unlock(&file_mutex);
    }

    fclose(input_file);
    pthread_exit(NULL);
}

