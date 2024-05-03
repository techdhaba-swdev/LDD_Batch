#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_INTERESTS_LENGTH 100

// Structures
typedef struct UserProfile {
    char name[MAX_NAME_LENGTH];
    char interests[MAX_INTERESTS_LENGTH];
    // Add more fields as needed
} UserProfile;

typedef struct Node {
    UserProfile user;
    struct Node* next;
} Node;

typedef struct Graph {
    int V; // Number of vertices
    Node** adjList; // Array of adjacency lists
} Graph;

// Function prototypes
Node* createUserProfile(char name[], char interests[]);
void addFriend(Graph* graph, char user1[], char user2[]);
void searchUsers(Node* head, char query[]);
void recommendFriends(Graph* graph, char user[]);
void displayFriendList(Graph* graph, char user[]);
void displayNewsFeed(char user[]);
void destroyGraph(Graph* graph);

// Function definitions
Node* createUserProfile(char name[], char interests[]) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    strcpy(newNode->user.name, name);
    strcpy(newNode->user.interests, interests);
    newNode->next = NULL;
    return newNode;
}

void addFriend(Graph* graph, char user1[], char user2[]) {
    // Assume both users exist in the graph
    int v1 = -1, v2 = -1;
    for (int i = 0; i < graph->V; i++) {
        if (strcmp(graph->adjList[i]->user.name, user1) == 0)
            v1 = i;
        if (strcmp(graph->adjList[i]->user.name, user2) == 0)
            v2 = i;
        if (v1 != -1 && v2 != -1)
            break;
    }
    // Add connection between users
    Node* newNode1 = createUserProfile(user1, "");
    newNode1->next = graph->adjList[v2]->next;
    graph->adjList[v2]->next = newNode1;

    Node* newNode2 = createUserProfile(user2, "");
    newNode2->next = graph->adjList[v1]->next;
    graph->adjList[v1]->next = newNode2;
}

void searchUsers(Node* head, char query[]) {
    Node* current = head;
    while (current != NULL) {
        if (strstr(current->user.name, query) != NULL || strstr(current->user.interests, query) != NULL) {
            printf("Name: %s, Interests: %s\n", current->user.name, current->user.interests);
        }
        current = current->next;
    }
}

void recommendFriends(Graph* graph, char user[]) {
    // Find the index of the user in the graph
    int userIndex = -1;
    for (int i = 0; i < graph->V; i++) {
        if (strcmp(graph->adjList[i]->user.name, user) == 0) {
            userIndex = i;
            break;
        }
    }
    if (userIndex == -1) {
        printf("User not found.\n");
        return;
    }

    // Iterate through user's friends
    Node* current = graph->adjList[userIndex]->next;
    printf("Recommendations for %s:\n", user);
    while (current != NULL) {
        // For each friend, recommend their friends
        int friendIndex = -1;
        for (int i = 0; i < graph->V; i++) {
            if (strcmp(graph->adjList[i]->user.name, current->user.name) == 0) {
                friendIndex = i;
                break;
            }
        }
        if (friendIndex != -1) {
            // Print recommendations (friends of friends)
            Node* friendNode = graph->adjList[friendIndex]->next;
            while (friendNode != NULL) {
                // Check if the recommended friend is not the user and not already a friend
                if (strcmp(friendNode->user.name, user) != 0 &&
                    strcmp(friendNode->user.name, user) != 0) {
                    printf("- %s\n", friendNode->user.name);
                }
                friendNode = friendNode->next;
            }
        }
        current = current->next;
    }
}

void displayNewsFeed(char user[]) {
    // Simulated news feed data
    char* newsFeed[] = {
        "Post 1 by friend A",
        "Post 2 by friend B",
        "Post 3 by friend C",
        // Add more posts as needed
    };
    int numPosts = sizeof(newsFeed) / sizeof(newsFeed[0]);

    // Display the news feed
    printf("News feed for %s:\n", user);
    for (int i = 0; i < numPosts; i++) {
        printf("%s\n", newsFeed[i]);
    }
}

void displayFriendList(Graph* graph, char user[]) {
    // Find the user in the graph
    int index = -1;
    for (int i = 0; i < graph->V; i++) {
        if (strcmp(graph->adjList[i]->user.name, user) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("User not found.\n");
        return;
    }

    // Print friend list
    Node* current = graph->adjList[index]->next;
    printf("Friend list for %s:\n", user);
    while (current != NULL) {
        printf("%s\n", current->user.name);
        current = current->next;
    }
}



void destroyGraph(Graph* graph) {
    for (int i = 0; i < graph->V; i++) {
        Node* current = graph->adjList[i];
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(graph->adjList);
    free(graph);
}

// Main function
int main() {
    // Create a sample graph
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    if (graph == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return EXIT_FAILURE;
    }
    graph->V = 3; // Number of users
    graph->adjList = (Node**)malloc(graph->V * sizeof(Node*));
    if (graph->adjList == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        free(graph);
        return EXIT_FAILURE;
    }

    // Initialize adjacency lists
    for (int i = 0; i < graph->V; i++) {
        graph->adjList[i] = createUserProfile("", ""); // Dummy node for each user
    }

    // Add connections (friends)
    addFriend(graph, "Alice", "Bob");
    addFriend(graph, "Alice", "Charlie");
    addFriend(graph, "Bob", "Charlie");

    // Example usage
    displayFriendList(graph, "Alice");
    displayFriendList(graph, "Bob");
    displayFriendList(graph, "Charlie");

    // Clean up
    destroyGraph(graph);

    return 0;
}




