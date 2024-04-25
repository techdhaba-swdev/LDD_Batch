#include"string2.h"

void ReadStrings(char **strings, int *nstrings, int maxstrings, FILE *fp) {
    char string[MAX_STRING_LENGTH];
    *nstrings = 0;
    while (fgets(string, MAX_STRING_LENGTH, fp)) {
        strings[(*nstrings)++] = strdup(string);
        if (*nstrings >= maxstrings)
            break;
    }
}
