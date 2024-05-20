#include "readstrings.h"
#include <stdlib.h>
#include <string.h>
#define MAX_STRING_LENGTH 100

void ReadStrings(char **strings, int *nstrings, int maxstrings, FILE *fp)
{
    char string[MAX_STRING_LENGTH];
    *nstrings = 0;
    while (fgets(string, MAX_STRING_LENGTH, fp)) {
        strings[(*nstrings)++] = strdup(string);
        if (*nstrings >= maxstrings) break;
    }
}
