#include "DeleteNode.h"
#include <stdlib.h>

// Deletes a node and all its children from the file system, freeing the memory.
void deleteNode(Node* node) {
    if (node == NULL) {
        return; // If the node is NULL, there is nothing to delete.
    }
    Node* current = node->firstChild;
    // Recursively delete all children of the node.
    while (current != NULL) {
        Node* next = current->nextSibling;
        deleteNode(current);
        current = next;
    }
    free(node->name); // Free the memory allocated for the node's name.
    free(node); // Free the memory allocated for the node itself.
}


