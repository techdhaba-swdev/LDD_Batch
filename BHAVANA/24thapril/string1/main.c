#include <stdio.h>
#include "string_utils.h"

int main() {
    char *strings[128];
    char string[256];
    int nstrings = 0;

    while (fgets(string, 256, stdin)) {
        insert_sorted(strings, string, &nstrings);
        if (nstrings >= 128) break;
    }

    print_strings(strings, nstrings);

    return 0;
}
