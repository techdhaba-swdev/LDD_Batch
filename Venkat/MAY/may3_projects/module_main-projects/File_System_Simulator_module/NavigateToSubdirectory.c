#include "NavigateToSubdirectory.h"
#include <string.h>

// Navigates to a subdirectory with the given name within the specified directory.
Node* navigateToSubdirectory(Node* currentDirectory, const char* subdirectoryName) {
    Node* current = currentDirectory->firstChild;
    // Loop through each child node to find the subdirectory with the matching name.
    while (current != NULL) {
        if (strcmp(current->name, subdirectoryName) == 0) {
            return current; // Return the subdirectory node if found.
        }
        current = current->nextSibling;
    }
    return NULL; // Return NULL if the subdirectory is not found.
}


