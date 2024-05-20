#ifndef GRAPH2_H
#define GRAPH2_H

// Structure to represent a node in the linked list
struct Node {
  int vertex;
  struct Node* next;
};

// Structure to represent the graph
struct Graph {
  int numVertices;
  struct Node** adjLists;  // Array of pointers to linked list heads
};

// Function declarations
struct Node* createNode(int vertex);
struct Graph* createGraph(int numVertices);
void addEdge(struct Graph* graph, int src, int dest);
void printGraph(struct Graph* graph);

#endif
