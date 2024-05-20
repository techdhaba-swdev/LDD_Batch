#include <stdio.h>
#include <string.h>
#include "strings.h"

void sort_strings(char *strings[], int *nstrings) {
    char string[256];
    char *p1, *p2;
    int found;
    int i, j;

    while (fgets(string, 256, stdin)) {
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

        for (j = *nstrings; j > i; j--) {
            strings[j] = strings[j-1];
        }

        strings[i] = strdup(string);
        (*nstrings)++;

        if (*nstrings >= 128) break;
    }
}
