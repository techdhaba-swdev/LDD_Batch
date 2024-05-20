#include "ListDirectoryContents.h"
#include <stdio.h>

// Lists the contents of a directory node by printing the names of its children.
void listDirectoryContents(Node* directory) {
    Node* current = directory->firstChild;
    // Loop through each child node and print its name.
    while (current != NULL) {
        printf("%s\n", current->name);
        current = current->nextSibling;
    }
}


