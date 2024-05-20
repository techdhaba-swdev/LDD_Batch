#include <stdio.h>
#include "string_utils.h"

#define MAX_STRINGS 128
#define MAX_STRING_LENGTH 256
int main() {
    char *strings[MAX_STRINGS];
    int nstrings;
    FILE *fp = stdin;
    

    ReadStrings(strings, &nstrings, MAX_STRINGS, fp);
    SortStrings(strings, nstrings);
    WriteStrings(strings, nstrings, stdout);

    return 0;
}
