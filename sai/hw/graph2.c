#include "graph2.h"
#include<stdio.h>
#include<stdlib.h>

// Function to create a new node
struct Node* createNode(int vertex) {
    // Allocate memory for the new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode != NULL) {
        // Initialize the node with the given vertex value and NULL next pointer
        newNode->vertex = vertex;
        newNode->next = NULL;
    }
    return newNode;
}

// Function to create a graph with numVertices vertices
struct Graph* createGraph(int numVertices) {
    // Allocate memory for the graph structure
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    if (graph != NULL) {
        // Initialize the number of vertices
        graph->numVertices = numVertices;
        // Allocate memory for the array of adjacency lists
        graph->adjLists = (struct Node*)malloc(numVertices * sizeof(struct Node));
        if (graph->adjLists != NULL) {
            // Initialize all adjacency lists as empty
            for (int i = 0; i < numVertices; ++i) {
                graph->adjLists[i] = NULL;
            }
        } else {
            // Free allocated memory if memory allocation fails
            free(graph);
            graph = NULL;
        }
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Check if the graph and vertices are valid
    if (graph != NULL && src >= 0 && src < graph->numVertices && dest >= 0 && dest < graph->numVertices) {
        // Create a new node for the destination vertex
        struct Node* newNode = createNode(dest);
        if (newNode != NULL) {
            // Add the new node to the front of the adjacency list of the source vertex
            newNode->next = graph->adjLists[src];
            graph->adjLists[src] = newNode;
        }
    }
}

// Function to print the graph
void printGraph(struct Graph* graph) {
    // Check if the graph is valid
    if (graph != NULL) {
        // Iterate through all vertices
        for (int v = 0; v < graph->numVertices; ++v) {
            // Print the adjacency list of each vertex
            printf("\nAdjacency list of vertex %d\n head ", v);
            struct Node* temp = graph->adjLists[v];
            while (temp != NULL) {
                // Print each vertex in the adjacency list
                printf("-> %d ", temp->vertex);
                temp = temp->next;
            }
            printf("\n");
        }
    }
}
