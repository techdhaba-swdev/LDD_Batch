#include "header.h"
// Create a new directory
struct Directory* createDirectory(const char* name) { // Define a function to create a new directory with the given name.
    struct Directory* newDir = (struct Directory*)malloc(sizeof(struct Directory)); // Allocate memory for the new directory.
    strcpy(newDir->name, name); // Copy the name of the directory to the newly created directory structure.
    newDir->subdirectories = NULL; // Initialize the subdirectory pointer to NULL.
    newDir->files = NULL; // Initialize the file pointer to NULL.
    return newDir; // Return a pointer to the newly created directory.
}
