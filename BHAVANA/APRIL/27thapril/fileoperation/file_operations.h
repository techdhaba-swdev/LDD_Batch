#ifndef FILE_OPERATIONS_H
#define FILE_OPERATIONS_H

#include <stdio.h>

// Function to open a file for reading and writing
FILE* openFileReadWrite(const char* filename);

// Function to read and print the contents of a file
void readAndPrintFile(FILE* fp);

// Function to write additional content to a file
void writeAdditionalContent(FILE* fp, const char* additionalContent);

#endif /* FILE_OPERATIONS_H */
