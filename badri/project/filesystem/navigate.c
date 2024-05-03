#include "header.h"
struct Directory* navigateToSubdirectory(struct Directory* currentDir, const char* subDirName) { // Define a function to navigate to a subdirectory.
    struct Directory* subDirPtr = currentDir->subdirectories; // Initialize a pointer to iterate through subdirectories.
    while (subDirPtr) { // Iterate through subdirectories to find the specified subdirectory.
        if (strcmp(subDirPtr->name, subDirName) == 0) { // Check if the subdirectory name matches the specified name.
            return subDirPtr; // If found, return a pointer to the subdirectory.
        }
        subDirPtr = subDirPtr->subdirectories; // Move to the next subdirectory.
    }
    printf("Subdirectory '%s' not found.\n", subDirName); // Print a message if the subdirectory is not found.
    return NULL; // Return NULL pointer if subdirectory is not found.
}
