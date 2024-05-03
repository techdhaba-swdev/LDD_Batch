// social_network.h

#ifndef SOCIAL_NETWORK_H
#define SOCIAL_NETWORK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>

#define MAX_NAME_LENGTH 50
#define MAX_INTERESTS_LENGTH 100


//typedef struct UserProfile UserProfile; 
//typedef struct Node Node;
//typedef struct Graph Graph;

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



#endif /* SOCIAL_NETWORK_H */

