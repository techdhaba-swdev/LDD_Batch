#include "SearchFile.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Helper function to search for a file by name and track the path.
static Node* searchFileHelper(Node* directory, const char* fileName, char* path, int depth) {
    if (directory == NULL) {
        return NULL; // If directory is NULL, file not found
    }
    // Append the current directory's name to the path if not root
    if (depth > 0) {
        strcat(path, "/");
        strcat(path, directory->name);
    }
    // Check if the current node is the file we're looking for
    if (strcmp(directory->name, fileName) == 0) {
        return directory; // Return the file node if found
    }
    Node* current = directory->firstChild;
    // Recursively search in each child
    while (current != NULL) {
        char* newPath = strdup(path); // Duplicate path for recursive call
        Node* found = searchFileHelper(current, fileName, newPath, depth + 1);
        if (found != NULL) {
            // If file is found, copy the path to the original path variable
            strcpy(path, newPath);
            free(newPath);
            return found;
        }
        free(newPath); // Free the duplicated path if not found
        current = current->nextSibling;
    }
    return NULL; // Return NULL if file not found in any child
}

// Searches for a file by name within the file system and prints the path if found.
Node* searchFile(Node* directory, const char* fileName) {
    char* path = strdup(""); // Initialize path as an empty string.
    Node* found = searchFileHelper(directory, fileName, path, 0);
    if (found != NULL) {
        printf("File '%s' found at path: %s\n", fileName, path); // Print the path to the file.
    } else {
        printf("File '%s' not found.\n", fileName); // Print a message if the file is not found.
    }
    free(path); // Free the memory allocated for the path.
    return found; // Return the found file node or NULL.
}
