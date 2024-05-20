#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *write_even_lines(void *arg) {
    char *input_file = (char *)arg;
    FILE *input = fopen(input_file, "r");
    FILE *even_output = fopen("even_lines.txt", "w");

    if (!input || !even_output) {
        perror("File opening failed");
        pthread_exit(NULL);
    }

    char line[MAX_LINE_LENGTH];
    int line_number = 1;

    pthread_mutex_lock(&mutex);
    while (fgets(line, sizeof(line), input)) {
        if (line_number % 2 == 0) {
            fputs(line, even_output);
        }
        line_number++;
    }
    pthread_mutex_unlock(&mutex);

    fclose(input);
    fclose(even_output);
    pthread_exit(NULL);
}

void *write_odd_lines(void *arg) {
    char *input_file = (char *)arg;
    FILE *input = fopen(input_file, "r");
    FILE *odd_output = fopen("odd_lines.txt", "w");

    if (!input || !odd_output) {
        perror("File opening failed");
        pthread_exit(NULL);
    }

    char line[MAX_LINE_LENGTH];
    int line_number = 1;

    pthread_mutex_lock(&mutex);
    while (fgets(line, sizeof(line), input)) {
        if (line_number % 2 != 0) {
            fputs(line, odd_output);
        }
        line_number++;
    }
    pthread_mutex_unlock(&mutex);

    fclose(input);
    fclose(odd_output);
    pthread_exit(NULL);
}

void *read_and_print_even(void *arg) {
    FILE *even_input = fopen("even_lines.txt", "r");

    if (!even_input) {
        perror("File opening failed");
        pthread_exit(NULL);
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), even_input)) {
        printf("Even: %s", line);
    }

    fclose(even_input);
    pthread_exit(NULL);
}

void *read_and_print_odd(void *arg) {
    FILE *odd_input = fopen("odd_lines.txt", "r");

    if (!odd_input) {
        perror("File opening failed");
        pthread_exit(NULL);
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), odd_input)) {
        printf("Odd: %s", line);
    }

    fclose(odd_input);
    pthread_exit(NULL);
}

int main() {
    char input_filename[MAX_LINE_LENGTH];

   
    printf("Enter input file name: ");
    scanf("%s", input_filename);

    pthread_t writer1, writer2, reader1, reader2;

    
    if (pthread_create(&writer1, NULL, write_even_lines, input_filename) != 0) {
        perror("Failed to create thread for even lines");
        return 1;
    }
    if (pthread_create(&writer2, NULL, write_odd_lines, input_filename) != 0) {
        perror("Failed to create thread for odd lines");
        return 1;
    }

    pthread_join(writer1, NULL);
    pthread_join(writer2, NULL);

    if (pthread_create(&reader1, NULL, read_and_print_even, NULL) != 0) {
        perror("Failed to create thread for reading even lines");
        return 1;
    }
    if (pthread_create(&reader2, NULL, read_and_print_odd, NULL) != 0) {
        perror("Failed to create thread for reading odd lines");
        return 1;
    }

    // Wait for reading threads to finish
    pthread_join(reader1, NULL);
    pthread_join(reader2, NULL);

    pthread_mutex_destroy(&mutex);
    return 0;
}


