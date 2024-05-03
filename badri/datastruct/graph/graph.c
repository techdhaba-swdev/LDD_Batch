#include <stdio.h> // Include standard input/output library.
#include <stdlib.h> // Include standard library.
#include "graph.h" // Include the header file containing the declaration of Graph struct and related functions.
#include "node.h" // Include the header file containing the declaration of Node struct.

struct Graph* createGraph(int numVertices) { // Define the createGraph function which creates a new graph with the given number of vertices.
  struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph)); // Allocate memory for the new graph.
  if (graph == NULL) { // Check if memory allocation was successful.
    fprintf(stderr, "Memory allocation failed.\n"); // Print an error message to standard error stream.
    exit(EXIT_FAILURE); // Exit the program with a failure status.
  }
  graph->numVertices = numVertices; // Assign the number of vertices to the graph.
  graph->adjLists = (struct Node*)malloc(numVertices * sizeof(struct Node)); // Allocate memory for adjacency lists.
  if (graph->adjLists == NULL) { // Check if memory allocation was successful.
    fprintf(stderr, "Memory allocation failed.\n"); // Print an error message to standard error stream.
    free(graph); // Free the previously allocated memory for the graph.
    exit(EXIT_FAILURE); // Exit the program with a failure status.
  }
  for (int i = 0; i < numVertices; ++i) { // Initialize all adjacency lists as NULL.
    graph->adjLists[i] = NULL;
  }
  return graph; // Return the newly created graph.
}

void addEdge(struct Graph* graph, int src, int dest) { // Define the addEdge function which adds an edge between source and destination vertices.
  if (graph == NULL || src < 0 || dest < 0 || src >= graph->numVertices || dest >= graph->numVertices) { // Check for invalid inputs.
    fprintf(stderr, "Invalid input.\n"); // Print an error message to standard error stream.
    return; // Return from the function.
  }
  struct Node* newNode = createNode(dest); // Create a new node for the destination vertex.
  newNode->next = graph->adjLists[src]; // Add the new node to the front of the adjacency list of the source vertex.
  graph->adjLists[src] = newNode; // Update the adjacency list of the source vertex.
  newNode = createNode(src); // Create a new node for the source vertex (for undirected graph).
  newNode->next = graph->adjLists[dest]; // Add the new node to the front of the adjacency list of the destination vertex.
  graph->adjLists[dest] = newNode; // Update the adjacency list of the destination vertex.
}

void printGraph(struct Graph* graph) { // Define the printGraph function which prints the adjacency list representation of the graph.
  if (graph == NULL) { // Check if the graph is NULL.
    fprintf(stderr, "Graph is NULL.\n"); // Print an error message to standard error stream.
    return; // Return from the function.
  }
  for (int i = 0; i < graph->numVertices; ++i) { // Iterate through each vertex.
    printf("Adjacency list of vertex %d\n", i); // Print the vertex number.
    struct Node* temp = graph->adjLists[i]; // Initialize a temporary pointer to traverse the adjacency list.
    while (temp) { // Iterate through the adjacency list.
      printf("%d -> ", temp->vertex); // Print the adjacent vertex.
      temp = temp->next; // Move to the next node in the adjacency list.
    }
    printf("NULL\n"); // Print NULL to signify the end of the adjacency list.
  }
}


