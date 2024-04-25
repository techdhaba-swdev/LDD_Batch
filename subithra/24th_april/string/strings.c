#include"main.h"
#include <stdlib.h>
#include <string.h>
#include "strings.h"

void read_and_sort_strings(char *strings[], int *nstrings) {
    char string[MAX_LENGTH];
    int i, j;

    while ((*nstrings) < MAX_STRINGS && fgets(string, MAX_LENGTH, stdin)) {
        // Remove trailing newline character if present
        size_t len = strlen(string);
        if (string[len - 1] == '\n') {
            string[len - 1] = '\0';
        }

        // Find the correct position to insert the string
        for (i = 0; i < (*nstrings); i++) {
            if (strcmp(string, strings[i]) < 0) {
                break;
            }
        }

        // Shift strings to make room for the new string
        for (j = (*nstrings); j > i; j--) {
            strings[j] = strings[j - 1];
        }

        // Insert the new string
        strings[i] = strdup(string);
        (*nstrings)++;

        // Check if maximum strings limit reached
        if ((*nstrings) >= MAX_STRINGS) break;
    }
}

void print_strings(char *strings[], int nstrings) {
    for (int i = 0; i < nstrings; i++) {
        printf("%s\n", strings[i]);
    }
}

void free_strings(char *strings[], int nstrings) {
    for (int i = 0; i < nstrings; i++) {
        free(strings[i]);
    }
}
