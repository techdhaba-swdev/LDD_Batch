#ifndef SORT_STRINGS_H
#define SORT_STRINGS_H

#define MAX_STRINGS 128
#define MAX_STRING_LENGTH 256

void sort_strings();
void read_strings(char *strings[], char string[], int *nstrings);
void sort_and_print(char *strings[], int nstrings);

#endif

