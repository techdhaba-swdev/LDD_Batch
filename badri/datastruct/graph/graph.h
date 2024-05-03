#ifndef GRAPH_H // Header guard to prevent multiple inclusion.
#define GRAPH_H

#include "node.h" // Include the header file containing the declaration of Node struct.

struct Graph { // Declare a struct for a graph.
  int numVertices; // Number of vertices in the graph.
  struct Node** adjLists; // Array of pointers to linked lists representing adjacency lists.
};

struct Graph* createGraph(int numVertices); // Declaration of the createGraph function.
void addEdge(struct Graph* graph, int src, int dest); // Declaration of the addEdge function.
void printGraph(struct Graph* graph); // Declaration of the printGraph function.

#endif // End of header guard.
