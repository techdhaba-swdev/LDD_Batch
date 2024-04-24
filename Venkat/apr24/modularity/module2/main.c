#include <stdio.h>
#include <stdlib.h>
#include "readstrings.h"
#include "sortstrings.h"
#include "writestrings.h"

#define MAX_STRINGS 128
#define MAX_STRING_LENGTH 256

int main()
{
    char *strings[MAX_STRINGS];
    int nstrings;
    
    ReadStrings(strings, &nstrings, MAX_STRINGS, stdin);
    SortStrings(strings, nstrings);
    WriteStrings(strings, nstrings, stdout);

    // Free dynamically allocated memory
    for (int i = 0; i < nstrings; i++) {
        free(strings[i]);
    }

    return 0;
}
