#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"network.h"


// Create a new user profile
struct UserProfile* createUserProfile(const char* name, const char* interests) {
    struct UserProfile* newUser = (struct UserProfile*)malloc(sizeof(struct UserProfile));
    strcpy(newUser->name, name);
    strcpy(newUser->interests, interests);
    newUser->next = NULL;
    return newUser;
}

// Initialize the social network graph
struct Graph* createGraph(int numUsers) {
    struct Graph* newGraph = (struct Graph*)malloc(sizeof(struct Graph));
    newGraph->numUsers = numUsers;
    newGraph->adjacencyList = (struct GraphNode*)malloc(numUsers * sizeof(struct GraphNode));
    for (int i = 0; i < numUsers; ++i) {
        newGraph->adjacencyList[i] = NULL;
    }
    return newGraph;
}

// Add a friend connection (edge) between users
void addFriend(struct Graph* graph, int user1, int user2) {
    // Add user2 to user1's adjacency list and vice versa
    struct GraphNode* newNode1 = (struct GraphNode*)malloc(sizeof(struct GraphNode));
    newNode1->userId = user2;
    newNode1->next = graph->adjacencyList[user1];
    graph->adjacencyList[user1] = newNode1;

    struct GraphNode* newNode2 = (struct GraphNode*)malloc(sizeof(struct GraphNode));
    newNode2->userId = user1;
    newNode2->next = graph->adjacencyList[user2];
    graph->adjacencyList[user2] = newNode2;
}
// Search for users by name or interest
void searchUsers(const struct UserProfile* profiles, const char* query) {
    struct UserProfile* currProfile = profiles;
    while (currProfile) {
        if (strstr(currProfile->name, query) || strstr(currProfile->interests, query)) {
            printf("Found user: %s\n", currProfile->name);
        }
        currProfile = currProfile->next;
    }
}

// Recommend friends based on mutual connections or interests
void recommendFriends(const struct Graph* graph, int userId) {
    printf("Recommended friends for user %d:\n", userId);
    struct GraphNode* currNode = graph->adjacencyList[userId];
    while (currNode) {
        int friendId = currNode->userId;
        // You can further filter recommendations based on interests or other criteria
        printf("Friend: %d\n", friendId);
        currNode = currNode->next;
    }
}

// Display a user's friend list
void displayFriendList(const struct Graph* graph, int userId) {
    printf("Friend list for user %d:\n", userId);
    struct GraphNode* currNode = graph->adjacencyList[userId];
    while (currNode) {
        printf("Friend: %d\n", currNode->userId);
        currNode = currNode->next;
    }
}
