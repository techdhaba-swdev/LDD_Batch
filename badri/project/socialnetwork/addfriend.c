#include "profile.h"
void addFriend(GraphNode* graph[], UserProfile* user1, UserProfile* user2) { // Function to add a friend connection between two users.
    GraphNode* node1 = (GraphNode*)malloc(sizeof(GraphNode)); // Allocating memory for graph node.
    GraphNode* node2 = (GraphNode*)malloc(sizeof(GraphNode)); // Allocating memory for graph node.
    if (node1 == NULL || node2 == NULL) { // Checking if memory allocation is successful.
        printf("Memory allocation failed.\n"); // Printing error message if memory allocation failed.
        return; // Returning from the function.
    }
    node1->profile = user1; // Assigning user1 to the profile pointer of node1.
    node2->profile = user2; // Assigning user2 to the profile pointer of node2.
    node1->next = graph[user1->name[0] - 'A']; // Assigning the current head of the adjacency list to the next of node1.
    node2->next = graph[user2->name[0] - 'A']; // Assigning the current head of the adjacency list to the next of node2.
    graph[user1->name[0] - 'A'] = node2; // Updating the head of the adjacency list for user1.
    graph[user2->name[0] - 'A'] = node1; // Updating the head of the adjacency list for user2.
}

