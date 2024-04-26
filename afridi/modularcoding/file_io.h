#ifndef FILE_IO_H
#define FILE_IO_H

#include <stdio.h>

void ReadStringsFromFile(char **strings, int *nstrings, int maxstrings, const char *filename);
void WriteStringsToFile(char **strings, int nstrings, const char *filename);

#endif /* FILE_IO_H */
