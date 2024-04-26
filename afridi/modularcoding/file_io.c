#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file_io.h"

void ReadStringsFromFile(char **strings, int *nstrings, int maxstrings, const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        exit(1);
    }
    ReadStrings(strings, nstrings, maxstrings, fp);
    fclose(fp);
}

void WriteStringsToFile(char **strings, int nstrings, const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        exit(1);
    }
    WriteStrings(strings, nstrings, fp);
    fclose(fp);
}
