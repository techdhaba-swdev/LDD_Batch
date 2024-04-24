#include <stdio.h>
#include <string.h>
#include "strings.h"

int main() {
    char *strings[128];
    int nstrings = 0;
    int i;

    sort_strings(strings, &nstrings);

    for (i = 0; i < nstrings; i++) {
        fprintf(stdout, "%s", strings[i]);
    }

    return 0;
}
