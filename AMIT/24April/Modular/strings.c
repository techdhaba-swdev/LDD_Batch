#include"string2.h"

int main() {
    char *strings[MAX_STRINGS];
    int nstrings;
    ReadStrings(strings, &nstrings, MAX_STRINGS, stdin);
    SortStrings(strings, nstrings);
    WriteStrings(strings, nstrings, stdout);

    // Free allocated memory
    for (int i = 0; i < nstrings; i++)
        free(strings[i]);

    return 0;
}
