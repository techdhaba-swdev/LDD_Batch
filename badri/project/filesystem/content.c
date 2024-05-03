#include "header.h"
void listDirectoryContents(const struct Directory* dir) { // Define a function to list the contents of a directory.
    printf("Contents of directory '%s':\n", dir->name); // Print the name of the directory.
    struct File* filePtr = dir->files; // Initialize a pointer to iterate through files.
    while (filePtr) { // Iterate through files and print their names.
        printf("File: %s\n", filePtr->name);
        filePtr = filePtr->next;
    }
    struct Directory* subDirPtr = dir->subdirectories; // Initialize a pointer to iterate through subdirectories.
    while (subDirPtr) { // Iterate through subdirectories and print their names.
        printf("Subdirectory: %s\n", subDirPtr->name);
        subDirPtr = subDirPtr->subdirectories;
    }
}
