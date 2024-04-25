/*#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include <stdbool.h>*/
#include"string1.h"
#define MAX_STRINGS 128
#define MAX_STRING_LENGTH 256

// Function to read strings from input
int read_strings(char *strings[], int max_strings) {
    int nstrings = 0;
    char string[MAX_STRING_LENGTH];

    while (fgets(string, MAX_STRING_LENGTH, stdin)) {
        strings[nstrings] = strdup(string);
        nstrings++;

        if (nstrings >= max_strings)
            break;
    }

    return nstrings;
}

// Function to compare two strings
int compare_strings(const void *a, const void *b) {
    return strcmp((const char *)a, (const char *)b);
}

// Function to sort the strings
void sort_strings(char *strings[], int nstrings) {
    qsort(strings, nstrings, sizeof(char *), compare_strings);
}

// Function to print the sorted strings
void print_strings(char *strings[], int nstrings) {
    for (int i = 0; i < nstrings; i++)
        printf("%s", strings[i]);
}


