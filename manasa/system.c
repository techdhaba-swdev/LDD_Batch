#include <string.h>
#include "system.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


GraphNode* createGraphNode(int userId, char *name, char *interests) {
    GraphNode node = (GraphNode)malloc(sizeof(GraphNode));
    if (node == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    node->userId = userId;
    strcpy(node->profile.name, name);
    strcpy(node->profile.interests, interests);
    node->next = NULL;
    node->friends = NULL;
    return node;
}

void createUserProfile(GraphNode **graph, char *name, char *interests) {
    static int userId = 0;
    GraphNode *newNode = createGraphNode(userId++, name, interests);
    newNode->next = *graph;
    *graph = newNode;
}

void addFriend(GraphNode *user1, GraphNode *user2) {
    FriendNode newFriend1 = (FriendNode*)malloc(sizeof(FriendNode));
    FriendNode newFriend2 = (FriendNode*)malloc(sizeof(FriendNode));
    if (newFriend1 == NULL || newFriend2 == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newFriend1->user = user2;
    newFriend1->next = user1->friends;
    user1->friends = newFriend1;
    newFriend2->user = user1;
    newFriend2->next = user2->friends;
    user2->friends = newFriend2;
}

GraphNode* searchUserByName(GraphNode *graph, char *name) {
    GraphNode *current = graph;
    while (current != NULL) {
        if (strcmp(current->profile->name, name) == 0)
            return current;
        current = current->next;
    }
    return NULL;
}

void recommendFriends(GraphNode *graph, char *name) {
    GraphNode *user = searchUserByName(graph, name);
    if (user == NULL) {
        printf("User not found.\n");
        return;
    }
    printf("Recommendations for %s:\n", name);
    FriendNode *friendPtr = user->friends;
    while (friendPtr != NULL) {
        GraphNode *friendOfFriend = friendPtr->user;
        FriendNode *mutualFriend = friendOfFriend->friends;
        while (mutualFriend != NULL) {
            if (mutualFriend->user != user && mutualFriend->user != friendOfFriend)
                printf("%s\n", mutualFriend->user->profile->name);
            mutualFriend = mutualFriend->next;
        }
        friendPtr = friendPtr->next;
    }
}

void displayFriendList(GraphNode *user) {
    printf("Friend list of %s:\n", user->profile->name);
    FriendNode *friendPtr = user->friends;
    while (friendPtr != NULL) {
        printf("%s\n", friendPtr->user->profile->name);
        friendPtr = friendPtr->next;
    }
}

void displayNewsFeed(GraphNode *user) {
    printf("News feed of %s:\n", user->profile->name);
    // Simulated news feed or integration with an external API can be implemented here
}
