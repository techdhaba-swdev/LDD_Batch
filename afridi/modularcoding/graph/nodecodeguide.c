#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // For boolean data type

// Structure to represent a node in the linked list
struct Node {
    int vertex;         // Vertex number
    struct Node* next;  // Pointer to the next node
};

// Structure to represent the graph
struct Graph {
    int numVertices;    // Number of vertices in the graph
    struct Node** adjLists;  // Array of pointers to linked list heads
};

// Function to create a new node
struct Node* createNode(int vertex) {
    // Allocate memory for a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {  // Check if memory allocation is successful
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->vertex = vertex;  // Set the vertex number
    newNode->next = NULL;      // Initialize next pointer as NULL
    return newNode;
}

// Function to create a graph with numVertices vertices
struct Graph* createGraph(int numVertices) {
    // Allocate memory for the graph structure
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    if (graph == NULL) {  // Check if memory allocation is successful
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    graph->numVertices = numVertices;  // Set the number of vertices

    // Create an array of pointers to Node to represent adjacency lists
    graph->adjLists = (struct Node*)malloc(numVertices * sizeof(struct Node));
    if (graph->adjLists == NULL) {  // Check if memory allocation is successful
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    // Initialize all adjacency lists as empty (NULL)
    for (int i = 0; i < numVertices; ++i) {
        graph->adjLists[i] = NULL;
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Check if source and destination vertices are valid
    if (src < 0 || src >= graph->numVertices || dest < 0 || dest >= graph->numVertices) {
        fprintf(stderr, "Invalid vertex\n");
        return;
    }

    // Create a new node for the destination vertex
    struct Node* newNode = createNode(dest);

    // Add the node to the front of the adjacency list of source vertex
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // For undirected graph, add an edge from dest to src as well
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Function to print the graph
void printGraph(struct Graph* graph) {
    for (int v = 0; v < graph->numVertices; ++v) {
        printf("\nAdjacency list of vertex %d\n head ", v);
        struct Node* temp = graph->adjLists[v];
        while (temp) {
            printf("-> %d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Function to free memory allocated for the graph
void freeGraph(struct Graph* graph) {
    if (graph == NULL) return;  // Check if graph pointer is NULL
    // Free memory allocated for each adjacency list and its nodes
    for (int i = 0; i < graph->numVertices; ++i) {
        struct Node* current = graph->adjLists[i];
        while (current) {
            struct Node* next = current->next;
            free(current);
            current = next;
        }
    }
    free(graph->adjLists);  // Free memory allocated for the array of adjacency lists
    free(graph);            // Free memory allocated for the graph structure
}

// Main function
int main() {
    int numVertices = 4;
    struct Graph* graph = createGraph(numVertices);  // Create the graph

    // Add edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);

    // Print the adjacency list representation of the graph
    printGraph(graph);

    // Free memory allocated for the graph
    freeGraph(graph);

    return 0;  // Exit the program
}
