#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "string_utils.h"

void insert_sorted(char *strings[], char *string, int *nstrings) {
    char *p1, *p2;
    int found;
    int i, j;

    for (i = 0; i < *nstrings; i++) {
        found = 1;
        for (p1 = string, p2 = strings[i]; *p1 && *p2; p1++, p2++) {
            if (*p1 > *p2) {
                found = 0;
                break;
            }
        }
        if (found) break;
    }

    for (j = *nstrings; j > i; j--)
        strings[j] = strings[j - 1];
    
    strings[i] = strdup(string);
    (*nstrings)++;
}

void print_strings(char *strings[], int nstrings) {
    for (int i = 0; i < nstrings; i++)
        fprintf(stdout, "%s", strings[i]);
}
