#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRINGS 128
#define MAX_STRING_LENGTH 256

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

int CompareStrings(char *string1, char *string2) {
    return strcmp(string1, string2);
}

void SortStrings(char **strings, int nstrings) {
    int i, j;
    for (i = 0; i < nstrings; i++) {
        for (j = i + 1; j < nstrings; j++) {
            if (CompareStrings(strings[i], strings[j]) > 0) {
                char *swap = strings[i];
                strings[i] = strings[j];
                strings[j] = swap;
            }
        }
    }
}

int main() {
    char *strings[MAX_STRINGS];
    int nstrings;
    ReadStrings(strings, &nstrings, MAX_STRINGS, stdin);
    SortStrings(strings, nstrings);
    WriteStrings(strings, nstrings, stdout);
    return 0;
}
