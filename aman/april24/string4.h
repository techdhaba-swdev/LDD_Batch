#ifndef STRING4_H
#define STRING4_H
#define MAX_STRINGS 128
#define MAX_LENGTH 255
void readStrings(char *strings[], int *nstrings);
void sortStrings(char *strings[], int nstrings);
void printStrings(char *strings[], int nstrings);
void freeStrings(char *strings[], int nstrings);
#endif
