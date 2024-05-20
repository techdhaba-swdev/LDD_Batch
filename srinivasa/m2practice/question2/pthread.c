#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pthread.h"

pthread_mutex_t file_mutex;
// function to write lines
void* write_lines(void* arg) {
    thread_data_t *data = (thread_data_t*)arg;
    FILE *input_fp = fopen(data->input_file, "r");
    FILE *output_fp = fopen(data->output_file, "w");

    if (input_fp == NULL || output_fp == NULL) {
        perror("File open error");
        pthread_exit(NULL);
    }

    char line[MAX_LINE_LENGTH];
    int line_number = 0;

    while (fgets(line, sizeof(line), input_fp) != NULL) {
        line_number++;
        if ((line_number % 2 == 0 && data->is_even) || (line_number % 2 != 0 && !data->is_even)) {
            fprintf(output_fp, "%s", line);
        }
    }

    fclose(input_fp);
    fclose(output_fp);
    pthread_exit(NULL);
}
// function to read lines 
void* read_lines(void* arg) {
    const char output_file = (const char)arg;
    FILE *output_fp = fopen(output_file, "r");

    if (output_fp == NULL) {
        perror("File open error");
        pthread_exit(NULL);
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), output_fp) != NULL) {
        printf("%s: %s", output_file, line);
    }

    fclose(output_fp);
    pthread_exit(NULL);
}
