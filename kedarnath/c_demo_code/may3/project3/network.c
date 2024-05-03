#include"network.h"

// Structure for user profile
/*struct UserProfile {
    char name[100];
    char interests[100];
    UserConnection* friends;
};

// Structure for user connection
struct UserConnection {
    UserProfile* friend;
    UserConnection* next;
}; */

// Create a new user profile
UserProfile* createUserProfile(const char* name, const char* interests) {
    UserProfile* profile = (UserProfile*)malloc(sizeof(UserProfile));
    if (profile == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    strcpy(profile->name, name);
    strcpy(profile->interests, interests);
    profile->friends = NULL;
    return profile;
}

// Display user profile information
void displayUserProfile(UserProfile* profile) {
    printf("Name: %s\nInterests: %s\n", profile->name, profile->interests);
}

// Add a friend connection between two users
UserConnection* addFriend(UserProfile* user1, UserProfile* user2) {
    UserConnection* connection = (UserConnection*)malloc(sizeof(UserConnection));
    if (connection == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    connection->friend = user2;
    connection->next = user1->friends;
    user1->friends = connection;
    return connection;
}

// Display the list of friends for a user
void displayFriendList(UserProfile* user) {
    printf("Friends of %s:\n", user->name);
    UserConnection* current = user->friends;
    while (current != NULL) {
        printf("- %s\n", current->friend->name);
        current = current->next;
    }
}



// Search for users by name
void searchUserByName(UserProfile* root, const char* name) {
    UserProfile* current = root;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            printf("User '%s' found with interests: %s\n", current->name, current->interests);
            return;
        }
        current = current->next;
    }
    printf("User '%s' not found\n", name);
}

// Search for users by interest
void searchUserByInterest(UserProfile* root, const char* interest) {
    UserProfile* current = root;
    bool found = false;
    while (current != NULL) {
        if (strstr(current->interests, interest) != NULL) {
            printf("User '%s' has interest in '%s'\n", current->name, interest);
            found = true;
        }
        current = current->next;
    }
    if (!found) {
        printf("No users found with interest '%s'\n", interest);
    }
}



// Recommendation algorithm based on mutual connections or interests
void recommendFriends(UserProfile* user) {
    printf("Recommendations for user '%s':\n", user->name);
    UserConnection* currentConnection = user->friends;
    while (currentConnection != NULL) {
        // Implement recommendation logic based on mutual connections or interests
        printf("- %s\n", currentConnection->friend->name);
        currentConnection = currentConnection->next;
    }
}

// Simulated news feed functionality
void displayNewsFeed(UserProfile* user) {
    printf("News feed for user '%s':\n", user->name);
    // Simulated news feed content
    const char* newsFeed[] = {
        "Alice posted a new photo",
        "Bob liked your post",
        "Charlie shared a funny video",
        "Alice commented on your status"
    };
    // Displaying simulated news feed items
    srand(time(NULL)); // Seed for randomization
    for (int i = 0; i < 3; i++) {
        int index = rand() % 4; // Generate random index
        printf("- %s\n", newsFeed[index]);
    }
}


