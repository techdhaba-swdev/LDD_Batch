#include <stdio.h> // Include standard input/output library.
#include <stdlib.h> // Include standard library.
#include "node.h" // Include the header file containing the declaration of createNode function.

struct Node* createNode(int vertex) { // Define the createNode function which creates a new node with the given vertex.
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); // Allocate memory for the new node.
  if (newNode == NULL) { // Check if memory allocation was successful.
    fprintf(stderr, "Memory allocation failed.\n"); // Print an error message to standard error stream.
    exit(EXIT_FAILURE); // Exit the program with a failure status.
  }
  newNode->vertex = vertex; // Assign the vertex value to the new node.
  newNode->next = NULL; // Set the next pointer of the new node to NULL.
  return newNode; // Return the newly created node.
}
