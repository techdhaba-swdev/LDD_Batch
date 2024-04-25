#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include<stdlib.h>



int read_strings(char *strings[], int max_strings);
int compare_strings(const void *a, const void *b);
void sort_strings(char *strings[], int nstrings);
void print_strings(char *strings[], int nstrings);
