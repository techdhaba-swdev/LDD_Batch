#include "main.h"
#include "strings.h"

int main() {
    char *strings[MAX_STRINGS];
    int nstrings = 0;

    read_and_sort_strings(strings, &nstrings);

    print_strings(strings, nstrings);

    free_strings(strings, nstrings);

    return 0;
}
