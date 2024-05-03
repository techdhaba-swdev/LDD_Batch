#include <stdio.h>
#include <string.h>
#include "network.h"

void add_user(Graph *graph, const char *name, const char *interests) {
    if (graph->num_users >= MAX_USERS) {
        printf("Cannot add more users.\n");
        return;
    }
    User *user = &graph->users[graph->num_users++];
    strcpy(user->name, name);
    strcpy(user->interests, interests);
    user->num_friends = 0;
}

void add_friendship(Graph *graph, const char *user1_name, const char *user2_name) {
    User *user1 = NULL, *user2 = NULL;
    for (int i = 0; i < graph->num_users; i++) {
        if (strcmp(graph->users[i].name, user1_name) == 0) {
            user1 = &graph->users[i];
        }
        if (strcmp(graph->users[i].name, user2_name) == 0) {
            user2 = &graph->users[i];
        }
    }
    if (user1 && user2) {
        user1->friends[user1->num_friends++] = user2;
        user2->friends[user2->num_friends++] = user1;
    }
}

void search_users_by_name(Graph *graph, const char *name) {
    printf("Users with name '%s':\n", name);
    for (int i = 0; i < graph->num_users; i++) {
        if (strstr(graph->users[i].name, name)) {
            printf("%s\n", graph->users[i].name);
        }
    }
}

void search_users_by_interest(Graph *graph, const char *interest) {
    printf("Users interested in '%s':\n", interest);
    for (int i = 0; i < graph->num_users; i++) {
        if (strstr(graph->users[i].interests, interest)) {
            printf("%s\n", graph->users[i].name);
        }
    }
}

void recommend_friends(Graph *graph, const char *name) {
    printf("Recommended friends for %s:\n", name);
    for (int i = 0; i < graph->num_users; i++) {
        if (strcmp(graph->users[i].name, name) == 0) {
            User *user = &graph->users[i];
            for (int j = 0; j < user->num_friends; j++) {
                User *friend = user->friends[j];
                for (int k = 0; k < friend->num_friends; k++) {
                    User *potential_friend = friend->friends[k];
                    if (strcmp(potential_friend->name, name) != 0 &&
                        !is_friend_of_user(user, potential_friend)) {
                        printf("%s\n", potential_friend->name);
                    }
                }
            }
            break;
        }
    }
}

bool is_friend_of_user(User *user, User *potential_friend) {
    for (int i = 0; i < user->num_friends; i++) {
        if (user->friends[i] == potential_friend) {
            return true;
        }
    }
    return false;
}
