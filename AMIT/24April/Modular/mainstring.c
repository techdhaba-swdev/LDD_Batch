/*#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include<stdlib.h>*/
#include"string1.h"

#define MAX_STRINGS 128
#define MAX_STRING_LENGTH 256





int main() {
    char *strings[MAX_STRINGS];
    int nstrings;

    nstrings = read_strings(strings, MAX_STRINGS);
    sort_strings(strings, nstrings);
    print_strings(strings, nstrings);

    // Free allocated memory
    for (int i = 0; i < nstrings; i++)
        free(strings[i]);

    return 0;
}
