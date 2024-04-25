#include <stdio.h>
#include "string_function.h"
#include "file_io.h"

int main() {
    char *strings[128];
    int nstrings = 0;
    processStrings(strings, &nstrings);
    printStrings(strings, nstrings);
    return 0;
}
