#include <stdio.h>
#include <stdlib.h>
#include "string_operations.h"
#include "sorting.h"
#include "file_io.h"

#define MAX_STRINGS 128
#define MAX_STRING_LENGTH 256

int main() {
    char *strings[MAX_STRINGS];
    int nstrings;
    ReadStringsFromFile(strings, &nstrings, MAX_STRINGS, "input.txt");
    SortStrings(strings, nstrings);
    WriteStringsToFile(strings, nstrings, "output.txt");
    return 0;
}
