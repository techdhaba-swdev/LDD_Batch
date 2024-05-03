#ifndef NODE_H // Header guard to prevent multiple inclusion.
#define NODE_H

struct Node { // Declare a struct for a node in the linked list.
  int vertex; // Vertex value of the node.
  struct Node* next; // Pointer to the next node.
};

struct Node* createNode(int vertex); // Declaration of the createNode function.

#endif // End of header guard.
