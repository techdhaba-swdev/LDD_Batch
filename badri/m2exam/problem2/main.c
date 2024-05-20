#include "pthread.h"
int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *input_file = fopen(argv[1], "r");
    if (!input_file) {
        perror("Failed to open input file");
        exit(EXIT_FAILURE);
    }

    char buffer[MAX_LINE_LENGTH];
    while (fgets(buffer, sizeof(buffer), input_file) && line_count < MAX_LINES) {
        lines[line_count] = strdup(buffer);
        line_count++;
    }
    fclose(input_file);

    pthread_t writer_threads[2];
    thread_data_t writer_data[2] = {
        {"even_lines.txt", 1, 2},
        {"odd_lines.txt", 0, 2}
    };

    for (int i = 0; i < 2; i++) {
        if (pthread_create(&writer_threads[i], NULL, write_lines, &writer_data[i])) {
            perror("Failed to create writer thread");
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i < 2; i++) {
        pthread_join(writer_threads[i], NULL);
    }

    pthread_t reader_threads[2];
    char *output_files[2] = {"even_lines.txt", "odd_lines.txt"};

    for (int i = 0; i < 2; i++) {
        if (pthread_create(&reader_threads[i], NULL, read_lines, output_files[i])) {
            perror("Failed to create reader thread");
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i < 2; i++) {
        pthread_join(reader_threads[i], NULL);
    }

    for (int i = 0; i < line_count; i++) {
        free(lines[i]);
    }

    pthread_mutex_destroy(&file_mutex);

    return 0;
}

