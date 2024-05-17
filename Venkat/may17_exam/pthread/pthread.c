#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define EVEN_FILE "even_lines.txt"
#define ODD_FILE "odd_lines.txt"

pthread_mutex_t lock;
FILE *sourceFile, *evenFile, *oddFile;

void *writeEven(void *arg) {
    int lineNum = 0;
    char buffer[256];
    while (fgets(buffer, sizeof(buffer), sourceFile) != NULL) {
        lineNum++;
        if (lineNum % 2 == 0) {
            pthread_mutex_lock(&lock);
            fputs(buffer, evenFile);
            pthread_mutex_unlock(&lock);
        }
    }
    return NULL;
}

void *writeOdd(void *arg) {
    int lineNum = 0;
    char buffer[256];
    rewind(sourceFile);
    while (fgets(buffer, sizeof(buffer), sourceFile) != NULL) {
        lineNum++;
        if (lineNum % 2 != 0) {
            pthread_mutex_lock(&lock);
            fputs(buffer, oddFile);
            pthread_mutex_unlock(&lock);
        }
    }
    return NULL;
}

void *readAndPrint(void *arg) {
    FILE *file = (FILE *)arg;
    char buffer[256];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }
    return NULL;
}

int main() {
    pthread_t threads[4];

    if (pthread_mutex_init(&lock, NULL) != 0) {
        printf("Mutex initialization has failed\n");
        return 1;
    }

    sourceFile = fopen("source.txt", "r");
    evenFile = fopen(EVEN_FILE, "w");
    oddFile = fopen(ODD_FILE, "w");

    if (sourceFile == NULL || evenFile == NULL || oddFile == NULL) {
        printf("Error opening files\n");
        return 1;
    }

    pthread_create(&threads[0], NULL, writeEven, NULL);
    pthread_create(&threads[1], NULL, writeOdd, NULL);

    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);

    fclose(evenFile);
    fclose(oddFile);

    evenFile = fopen(EVEN_FILE, "r");
    oddFile = fopen(ODD_FILE, "r");

    pthread_create(&threads[2], NULL, readAndPrint, (void *)evenFile);
    pthread_create(&threads[3], NULL, readAndPrint, (void *)oddFile);

    pthread_join(threads[2], NULL);
    pthread_join(threads[3], NULL);

    fclose(sourceFile);
    fclose(evenFile);
    fclose(oddFile);

    pthread_mutex_destroy(&lock);
    return 0;
}
