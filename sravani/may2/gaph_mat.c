
#include "graph.h"
#include <stdio.h>

int adjMatrix[MAX_VERTICES][MAX_VERTICES];

// Function to initialize the graph with no edges
void initializeGraph(int numVertices) {
    // Ensure numVertices does not exceed the maximum allowed
    if (numVertices > MAX_VERTICES) {
        printf("Error: Number of vertices exceeds the maximum allowed limit.\n");
        return;
    }
    // Initialize the adjacency matrix with zeros
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            adjMatrix[i][j] = 0;
        }
    }
}

// Function to add a directed edge from src to dest
void addEdge(int src, int dest,int numVertices) {
    // Ensure numVertices does not exceed the maximum allowed
    if (numVertices > MAX_VERTICES) {
        printf("Error: Number of vertices exceeds the maximum allowed limit.\n");
        return;
    }
    // Check if src and dest are within the valid range
    if (src >= 0 && src < numVertices && dest >= 0 && dest < numVertices) {
        adjMatrix[src][dest] = 1; // Mark 1 to indicate an edge
    } else {
        printf("Error: Invalid vertex indices.\n");
    }
}

// Function to print the adjacency matrix representation of the graph
void printGraph(int numVertices) {
    // Ensure numVertices does not exceed the maximum allowed
    if (numVertices > MAX_VERTICES) {
        printf("Error: Number of vertices exceeds the maximum allowed limit.\n");
        return;
    }
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
}
