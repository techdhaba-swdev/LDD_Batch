#include "file_operations.h"
#include <stdlib.h>

// Function to open a file for reading and writing
FILE* openFileReadWrite(const char* filename) {
    FILE* fp = fopen(filename, "r+");
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    return fp;
}

// Function to read and print the contents of a file
void readAndPrintFile(FILE* fp) {
    printf("Contents of the file:\n");
    int c;
    while ((c = fgetc(fp)) != EOF) {
        putchar(c);
    }
}

// Function to write additional content to a file
void writeAdditionalContent(FILE* fp, const char* additionalContent) {
    fprintf(fp, "\n%s", additionalContent);
}
