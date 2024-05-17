#include <stdio.h>
#include <pthread.h>

#define MAX_LINE_LENGTH 1024

pthread_mutex_t file_mutex = PTHREAD_MUTEX_INITIALIZER;

void *write_lines(void *args) {
    FILE input = fopen(((const char *)args)[0], "r");
    FILE output = fopen(((const char *)args)[1], "w");

    char line[MAX_LINE_LENGTH];
    int line_number = 0;

    while (fgets(line, MAX_LINE_LENGTH, input)) {
        if (((int *)args)[2] ? ++line_number % 2 == 0 : ++line_number % 2 != 0) {
            pthread_mutex_lock(&file_mutex);
            fputs(line, output);
            pthread_mutex_unlock(&file_mutex);
        }
    }

    fclose(input);
    fclose(output);
    return NULL;
}

void *read_and_print(void *filename) {
    FILE *file = fopen((const char *)filename, "r");
    char line[MAX_LINE_LENGTH];

    while (fgets(line, MAX_LINE_LENGTH, file)) {
        printf("%s", line);
    }

    fclose(file);
    return NULL;
}

int main() {
    const char *input = "input.txt";
    const char *even_output = "even_lines.txt";
    const char *odd_output = "odd_lines.txt";

    pthread_t writer1, writer2, reader1, reader2;

    pthread_create(&writer1, NULL, write_lines, (void *[3]){input, even_output, (void *)1});
    pthread_create(&writer2, NULL, write_lines, (void *[3]){input, odd_output, (void *)0});

    pthread_join(writer1, NULL);
    pthread_join(writer2, NULL);

    pthread_create(&reader1, NULL, read_and_print, (void *)even_output);
    pthread_create(&reader2, NULL, read_and_print, (void *)odd_output);

    pthread_join(reader1, NULL);
    pthread_join(reader2, NULL);

    return 0;
}
