#include <stdio.h>
#include <stdlib.h>
#include "file_io.h"

void printStrings(char *strings[], int nstrings) {
    for (int i = 0; i < nstrings; i++)
        fprintf(stdout, "%s", strings[i]);
}
