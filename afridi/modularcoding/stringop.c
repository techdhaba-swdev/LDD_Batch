#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "string_operations.h"

void ReadStrings(char **strings, int *nstrings, int maxstrings, FILE *fp) {
    char string[MAX_STRING_LENGTH];
    *nstrings = 0;
    while (fgets(string, MAX_STRING_LENGTH, fp)) {
        strings[(*nstrings)++] = strdup(string);
        if (*nstrings >= maxstrings) break;
    }
}

void WriteStrings(char **strings, int nstrings, FILE *fp) {
    int i;
    for (i = 0; i < nstrings; i++)
        fprintf(fp, "%s", strings[i]);
}
