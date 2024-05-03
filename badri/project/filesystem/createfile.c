#include "header.h"
struct File* createFile(const char* name) { // Define a function to create a new file with the given name.
    struct File* newFile = (struct File*)malloc(sizeof(struct File)); // Allocate memory for the new file.
    strcpy(newFile->name, name); // Copy the name of the file to the newly created file structure.
    newFile->next = NULL; // Initialize the next pointer to NULL.
    return newFile; // Return a pointer to the newly created file.
}
