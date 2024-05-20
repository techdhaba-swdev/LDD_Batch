
#ifndef NODE_H
#define NODE_H

// Node structure for representing a file or directory in a file system.
typedef struct Node {
    char* name; // Name of the file or directory.
    struct Node* firstChild; // Pointer to the first child node (used for directories).
    struct Node* nextSibling; // Pointer to the next sibling node (used for maintaining a list of files/directories within a directory).
} Node;

#endif // NODE_H
