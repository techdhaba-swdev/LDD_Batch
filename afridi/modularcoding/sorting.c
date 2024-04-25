#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sorting.h"

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
