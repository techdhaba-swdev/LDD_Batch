#include"string2.h"

int CompareStrings(const char *string1, const char *string2) {
    while (*string1 && *string2) {
        if (*string1 < *string2)
            return -1;
        else if (*string1 > *string2)
            return 1;
        string1++;
        string2++;
    }
    return 0;
}
