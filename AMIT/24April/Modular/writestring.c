
#include"string2.h"

void WriteStrings(char **strings, int nstrings, FILE *fp) {
    for (int i = 0; i < nstrings; i++)
        fprintf(fp, "%s", strings[i]);
}
