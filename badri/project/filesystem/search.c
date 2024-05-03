#include "header.h"
void searchFilesByName(const struct Directory* dir, const char* fileName) { // Define a function to search for files by name.
    struct File* filePtr = dir->files; // Initialize a pointer to iterate through files.
    while (filePtr) { // Iterate through files to find the specified file name.
        if (strcmp(filePtr->name, fileName) == 0) { // Check if the file name matches the specified name.
            printf("Found file: %s\n", fileName); // Print a message if the file is found.
            return;
        }
        filePtr = filePtr->next; // Move to the next file.
    }
    printf("File '%s' not found.\n", fileName); // Print a message if the file is not found.
}
