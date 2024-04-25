#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "string_function.h"

void processStrings(char *strings[], int *nstrings) {
    char string[256];
    while (fgets(string, 256, stdin)) {
        int i, j, found;
        char *p1, *p2;
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
            strings[j] = strings[j-1];
        strings[i] = strdup(string);
        (*nstrings)++;
        if (*nstrings >= 128) break;
    }
}

