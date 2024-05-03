#ifndef NETWORK
#define NETWORK

// User profile structure
struct UserProfile {
    char name[100];
    char interests[200];
    // Add other profile-related fields as needed
    struct UserProfile* next;
};

// Graph node for user connections
struct GraphNode {
    int userId;
    struct GraphNode* next;
};

// Social network graph (adjacency list)
struct Graph {
    int numUsers;
    struct GraphNode** adjacencyList;
};

struct UserProfile* createUserProfile(const char* name, const char* interests);
struct Graph* createGraph(int numUsers);
void addFriend(struct Graph* graph, int user1, int user2);
void searchUsers(const struct UserProfile* profiles, const char* query);
void recommendFriends(const struct Graph* graph, int userId);
void displayFriendList(const struct Graph* graph, int userId);

#endif
