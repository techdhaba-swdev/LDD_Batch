#include"network.h"

int main() {
    // Create user profiles
    UserProfile* user1 = createUserProfile("Alice", "Programming, Reading");
    UserProfile* user2 = createUserProfile("Bob", "Gaming, Music");
    UserProfile* user3 = createUserProfile("Charlie", "Sports, Cooking");

    // Add friends
    addFriend(user1, user2);
    addFriend(user1, user3);
    addFriend(user2, user3);

    // Display user profiles and friend lists
    printf("User Profiles:\n");
    displayUserProfile(user1);
    displayUserProfile(user2);
    displayUserProfile(user3);

    printf("\nFriend Lists:\n");
    displayFriendList(user1);
    displayFriendList(user2);
    displayFriendList(user3);

    // Search for users by name and interest
    printf("\nSearch by Name:\n");
    searchUserByName(user1, "Alice");
    searchUserByName(user1, "Eve");

    printf("\nSearch by Interest:\n");
    searchUserByInterest(user1, "Programming");
    searchUserByInterest(user1, "Music");

    // Recommend friends and display news feed
    recommendFriends(user1);
    displayNewsFeed(user1);

    // Free memory
    free(user1);
    free(user2);
    free(user3);

    return 0;
}

