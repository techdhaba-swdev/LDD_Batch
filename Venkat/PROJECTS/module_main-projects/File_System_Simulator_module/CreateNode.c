#include "CreateNode.h"
#include <stdlib.h>
#include <string.h>

// Creates a new file system node with the given name.
Node* createNode(const char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node)); // Allocate memory for the new node.
    newNode->name = strdup(name); // Duplicate the name and assign it to the node.
    newNode->firstChild = NULL; // Initialize the first child to NULL (no children yet).
    newNode->nextSibling = NULL; // Initialize the next sibling to NULL (no siblings yet).
    return newNode; // Return the pointer to the new node.
}
