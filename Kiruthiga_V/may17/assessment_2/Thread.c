#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_LINE_LENGTH 1024

// Structure to hold thread data
typedef struct {
    FILE *inpFile;
    FILE *outFileEven;
    FILE *outFileOdd;
    pthread_mutex_t *mutex;
    int lineNum;
} ThreadData;

void *process_lines(void *arg) {
    ThreadData *data = (ThreadData *)arg;
    char line[MAX_LINE_LENGTH];

    while (fgets(line, MAX_LINE_LENGTH, data->inpFile) != NULL) {
        pthread_mutex_lock(data->mutex);
        if (data->lineNum % 2 == 0)
            fputs(line, data->outFileEven);
        else
            fputs(line, data->outFileOdd);
        pthread_mutex_unlock(data->mutex);
        data->lineNum++;
    }

    pthread_exit(NULL);
}

// Function to read and print content from a file
void *read_and_print_file(void *filename) {
    char line[MAX_LINE_LENGTH];
    FILE *file = fopen((char *)filename, "r");

    if (file == NULL) {
        fprintf(stderr, "Error opening file %s\n", (char *)filename);
        pthread_exit(NULL);
    }

    printf("\nContent of %s:\n", (char *)filename);
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        printf("%s", line);
    }

    fclose(file);
    pthread_exit(NULL);
}

int main() {
    char inpFilename[MAX_LINE_LENGTH];
    char outFilenameEven[MAX_LINE_LENGTH];
    char outFilenameOdd[MAX_LINE_LENGTH];

  
    printf("Enter the input filename: ");
    fgets(inpFilename, MAX_LINE_LENGTH, stdin);
    inpFilename[strcspn(inpFilename, "\n")] = '\0'; 

    
    FILE *inpFile = fopen(inpFilename, "r");
    if (inpFile == NULL) {
        fprintf(stderr, "Error opening input file %s\n", inpFilename);
        return 1;
    }

    
    printf("Enter the output filename for even lines: ");
    fgets(outFilenameEven, MAX_LINE_LENGTH, stdin);
    outFilenameEven[strcspn(outFilenameEven, "\n")] = '\0'; 

    printf("Enter the output filename for odd lines: ");
    fgets(outFilenameOdd, MAX_LINE_LENGTH, stdin);
    outFilenameOdd[strcspn(outFilenameOdd, "\n")] = '\0'; 

    // Initialize mutex
    pthread_mutex_t mutex;
    pthread_mutex_init(&mutex, NULL);

    ThreadData threadData = {inpFile, fopen(outFilenameEven, "w"), fopen(outFilenameOdd, "w"), &mutex, 0};

    pthread_t threads[2];
    for (int i = 0; i < 2; ++i) {
        pthread_create(&threads[i], NULL, process_lines, (void *)&threadData);
    }

    for (int i = 0; i < 2; ++i) {
        pthread_join(threads[i], NULL);
    }
    fclose(inpFile);
    fclose(threadData.outFileEven);
    fclose(threadData.outFileOdd);

    pthread_t threadReadEven, threadReadOdd;
    pthread_create(&threadReadEven, NULL, read_and_print_file, outFilenameEven);
    pthread_create(&threadReadOdd, NULL, read_and_print_file, outFilenameOdd);

    pthread_join(threadReadEven, NULL);
    pthread_join(threadReadOdd, NULL);

    pthread_mutex_destroy(&mutex);

    return 0;
}


