#include<stdio.h>
#include<stdlib.h>
#include "main.h"
#define MAX_STRINGS 128
#define MAX_STRING_LENGTH 25

int main() {
    char *strings[MAX_STRINGS];
  int nstrings = 0;


    // Read strings from stdin
    readStrings(strings, &nstrings);

    // Sort the strings
    sortStrings(strings, nstrings);

    // Print the sorted strings
    printStrings(strings, nstrings);

    // Free allocated memory for strdup
    for (int i = 0; i < nstrings; i++) {
        free(strings[i]);
    }

    return 0;
}
