#include "AddChildNode.h"
#include <stddef.h>
// Adds a child node to a parent node in the file system.
void addChildNode(Node* parent, Node* child) {
    if (parent->firstChild == NULL) {
        parent->firstChild = child; // If the parent has no children, add the child as the first child.
    } else {
        Node* current = parent->firstChild;
        // Traverse to the end of the sibling list and add the child there.
        while (current->nextSibling != NULL) {
            current = current->nextSibling;
        }
        current->nextSibling = child; // Add the child as the next sibling of the last child.
    }
}


