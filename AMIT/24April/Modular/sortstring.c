#include"string2.h"

void SortStrings(char **strings, int nstrings) {
    for (int i = 0; i < nstrings; i++) {
        for (int j = i + 1; j < nstrings; j++) {
            if (CompareStrings(strings[i], strings[j]) > 0) {
                char *swap = strings[i];
                strings[i] = strings[j];
                strings[j] = swap;
            }
        }
    }
}
