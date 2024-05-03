#include "header.h"
void delete(struct Directory* parentDir, const char* name) { // Define a function to delete a file or directory.
    struct File* filePtr = parentDir->files; // Initialize a pointer to iterate through files.
    struct File* prevFile = NULL; // Pointer to keep track of the previous file while iterating.
    while (filePtr) { // Iterate through files to find the specified file for deletion.
        if (strcmp(filePtr->name, name) == 0) { // Check if the file name matches the specified name.
            if (prevFile) { // If the file is not the first in the list.
                prevFile->next = filePtr->next; // Update the previous file's next pointer.
            } else { // If the file is the first in the list.
                parentDir->files = filePtr->next; // Update the parent directory's file pointer.
            }
            free(filePtr); // Free memory allocated for the file.
            printf("File '%s' deleted.\n", name); // Print a message indicating file deletion.
            return;
        }
        prevFile = filePtr; // Update the previous file pointer.
        filePtr = filePtr->next; // Move to the next file.
    }
    printf("File '%s' not found.\n", name); // Print a message if the file is not found.
}
