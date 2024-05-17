#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_LENGTH 1024

FILE *input_file;
FILE *output_file_even;
FILE *output_file_odd;
pthread_mutex_t mutex;

void *process_even(void *arg) {
    char line[MAX_LENGTH];
    int line_number = 1;

    while (fgets(line, MAX_LENGTH, input_file)) {
        if (line_number % 2 == 0) {
            pthread_mutex_lock(&mutex);
            fputs(line, output_file_even);
            pthread_mutex_unlock(&mutex);
        }
        line_number++;
    }

    pthread_exit(NULL);
}

void *process_odd(void *arg) {
    char line[MAX_LENGTH];
    int line_number = 1;

    while (fgets(line, MAX_LENGTH, input_file)) {
        if (line_number % 2 != 0) {
            pthread_mutex_lock(&mutex);
            fputs(line, output_file_odd);
            pthread_mutex_unlock(&mutex);
        }
        line_number++;
    }

    pthread_exit(NULL);
}
void *read_and_print(void *filename) {
    char line[MAX_LENGTH];
    FILE *file = fopen((char *)filename, "r");
    if (!file) {
        perror("Error opening file for reading");
        exit(EXIT_FAILURE);
    }

    while (fgets(line, MAX_LENGTH, file)) {
        printf("%s", line);
    }

    fclose(file);
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    input_file = fopen(argv[1], "r");
    if (!input_file) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    output_file_even = fopen("even_lines.txt", "w");
    if (!output_file_even) {
        perror("Error creating output file for even lines");
        exit(EXIT_FAILURE);
    }

    output_file_odd = fopen("odd_lines.txt", "w");
    if (!output_file_odd) {
        perror("Error creating output file for odd lines");
        exit(EXIT_FAILURE);
    }

    pthread_mutex_init(&mutex, NULL);

    pthread_t thread1, thread2, thread3, thread4;

    pthread_create(&thread1, NULL, process_even, NULL);
    pthread_create(&thread2, NULL, process_odd, NULL);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    pthread_create(&thread3, NULL, read_and_print, "even_lines.txt");
    pthread_create(&thread4, NULL, read_and_print, "odd_lines.txt");
    pthread_join(thread3, NULL);
    pthread_join(thread4, NULL);

    pthread_mutex_destroy(&mutex);

    fclose(input_file);
    fclose(output_file_even);
    fclose(output_file_odd);

    return 0;
}
