#include <stdio.h>
#include <stdlib.h>
#include "graph_ver.h"

// Function to create a new node
struct Node* createNode(int vertex) {
  // Allocate memory for the new node
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->vertex = vertex;  // Set the vertex number of the new node
  newNode->next = NULL;      // Initialize the next pointer to NULL
  return newNode;            // Return the pointer to the new node
}

// Function to create a graph with numVertices vertices
struct Graph* createGraph(int numVertices) {
  // Allocate memory for the graph structure
  struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
  graph->numVertices = numVertices;  // Set the number of vertices in the graph

  // Create an array of pointers to Node to represent adjacency lists
  graph->adjLists = (struct Node**)malloc(numVertices * sizeof(struct Node*));

  // Initialize all adjacency lists as empty
  for (int i = 0; i < numVertices; ++i) {
    graph->adjLists[i] = NULL;  // Set each adjacency list pointer to NULL
  }

  return graph;  // Return the pointer to the graph
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
  // Create a new node for the destination vertex
  struct Node* newNode = createNode(dest);

// Add the node to the front of the adjacency list of the source vertex
  newNode->next = graph->adjLists[src];  // Set the next pointer of the new node to the current head of the list
  graph->adjLists[src] = newNode;        // Update the head of the list to point to the new node
}

// Function to print the graph
void printGraph(struct Graph* graph) {
  for (int v = 0; v < graph->numVertices; ++v) {
    printf("\nAdjacency list of vertex %d\n head ", v);
    struct Node* temp = graph->adjLists[v];  // Get the head of the adjacency list for vertex v
    while (temp) {
      printf("-> %d ", temp->vertex);  // Print the vertex number stored in the current node
      temp = temp->next;  // Move to the next node in the adjacency list
    }
    printf("\n");
  }
}

