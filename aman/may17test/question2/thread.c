#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

#define MAX_LINES 1000 // Maximum lines in the input file
#define MAX_LENGTH 100 // Maximum length of a line


char inputFileName[] = "test.txt";
char evenOutputFileName[] = "even.txt";
char oddOutputFileName[] = "odd.txt";
char evenLines[MAX_LINES][MAX_LENGTH];
char oddLines[MAX_LINES][MAX_LENGTH];
int evenCount = 0, oddCount = 0;
pthread_mutex_t mutex;

void* readLines(void* arg) {
    FILE* file = fopen(inputFileName, "r");
    char line[MAX_LENGTH];
    int lineNumber = 1;
    
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    while (fgets(line, sizeof(line), file) != NULL) {
        pthread_mutex_lock(&mutex);
        if (lineNumber % 2 == 0) {
            strcpy(evenLines[evenCount++], line);
        } else {
            strcpy(oddLines[oddCount++], line);
        }
        pthread_mutex_unlock(&mutex);
        lineNumber++;
    }

    fclose(file);
    pthread_exit(NULL);
}

void* writeLines(void* arg) {
    char (*lines)[MAX_LENGTH];
    int count;

    if (strcmp((char*)arg, "even") == 0) {
        lines = evenLines;
        count = evenCount;
    } else {
        lines = oddLines;
        count = oddCount;
    }

    FILE* file = fopen((strcmp((char*)arg, "even") == 0) ? evenOutputFileName : oddOutputFileName, "w");
    
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < count; i++) {
        fputs(lines[i], file);
    }

    fclose(file);
    pthread_exit(NULL);
}

int main() {
    pthread_t readThread, evenWriteThread, oddWriteThread;
    pthread_mutex_init(&mutex, NULL);

    if (pthread_create(&readThread, NULL, readLines, NULL)) {
        perror("Error creating read thread");
        exit(EXIT_FAILURE);
    }

    if (pthread_join(readThread, NULL)) {
        perror("Error joining read thread");
        exit(EXIT_FAILURE);
    }

    
    if (pthread_create(&evenWriteThread, NULL, writeLines, "even")) {
        perror("Error creating even write thread");
        exit(EXIT_FAILURE);
    }

    if (pthread_create(&oddWriteThread, NULL, writeLines, "odd")) {
        perror("Error creating odd write thread");
        exit(EXIT_FAILURE);
    }

  
    if (pthread_join(evenWriteThread, NULL)) {
        perror("Error joining even write thread");
        exit(EXIT_FAILURE);
    }

    if (pthread_join(oddWriteThread, NULL)) {
        perror("Error joining odd write thread");
        exit(EXIT_FAILURE);
    }

    pthread_mutex_destroy(&mutex);
    printf("Even lines:\n");
    system("cat even.txt");
    printf("\nOdd lines:\n");
    system("cat odd.txt");

    return 0;
}
