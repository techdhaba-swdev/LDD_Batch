#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file.h"

#define MAX_STRINGS 128
#define MAX_STRING_LENGTH 25
char *strings[MAX_STRINGS];
  int nstrings = 0;

void readStrings(char *strings[], int *nstrings) {
    char string[MAX_STRING_LENGTH];
    while (fgets(string, MAX_STRING_LENGTH, stdin)) {
        insertStringInOrder(strings, nstrings, string);
        if (*nstrings >= MAX_STRINGS) break;
    }
}

void insertStringInOrder(char *strings[], int *nstrings, const char *string) {
    int i, j;
    int found;
    char *p1, *p2;

    for (i = 0; i < *nstrings; i++) {
        found = 1;
        for (p1 = (char *)string, p2 = strings[i]; *p1 && *p2; p1++, p2++) {
            if (*p1 > *p2) {
                found = 0;
                break;
            }
        }
        if (found) break;
    }

    for (j = *nstrings; j > i; j--) {
        strings[j] = strings[j - 1];
    }
    strings[i] = strdup(string);
    (*nstrings)++;
}
void sortStrings(char *strings[], int nstrings) {
    char *temp;
    for (int i = 0; i < nstrings - 1; i++) {
        for (int j = i + 1; j < nstrings; j++) {
            if (strcmp(strings[i], strings[j]) > 0) {
                // Swap strings[i] and strings[j]
                temp = strings[i];
                strings[i] = strings[j];
                strings[j] = temp;
            }
        }
    }
}

// Function to print strings to stdout
void printStrings(char *strings[], int nstrings) {
    for (int i = 0; i < nstrings; i++) {
        fprintf(stdout, "%s", strings[i]);
    }
}
