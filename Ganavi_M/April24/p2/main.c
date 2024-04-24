#include "main.h"
#include "string_operations.h"

#define MAX_STRINGS 128

int main() {
    char *strings[MAX_STRINGS];
    int nstrings;
    ReadStrings(strings, &nstrings, MAX_STRINGS, stdin);
    SortStrings(strings, nstrings);
    WriteStrings(strings, nstrings, stdout);
    return 0;
}
