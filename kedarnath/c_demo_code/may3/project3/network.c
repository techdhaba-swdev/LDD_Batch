#include"network.h"


void add_user(Graph* graph, const char* name, const char* interests) {
    if (graph->num_users >= MAX_USERS) {
        printf("Cannot add more users.\n");
        return;
    }
    User* user = &graph->users[graph->num_users++];
    strncpy(user->name, name, MAX_NAME_LENGTH - 1);
    user->name[MAX_NAME_LENGTH - 1] = '\0'; // Ensure null-terminated string
    strncpy(user->interests, interests, MAX_INTEREST_LENGTH - 1);
    user->interests[MAX_INTEREST_LENGTH - 1] = '\0'; // Ensure null-terminated string
    user->num_friends = 0;
}

bool are_friends(User* user1, User* user2) {
    for (int i = 0; i < user1->num_friends; i++) {
        if (user1->friends[i] == user2) {
            return true;
        }
    }
    return false;
}

void add_friendship(Graph* graph, const char* user1_name, const char* user2_name) {
    User* user1 = NULL, * user2 = NULL;
    for (int i = 0; i < graph->num_users; i++) {
        if (strcmp(graph->users[i].name, user1_name) == 0) {
            user1 = &graph->users[i];
        }
        if (strcmp(graph->users[i].name, user2_name) == 0) {
            user2 = &graph->users[i];
        }
    }
    if (!user1 || !user2) {
        printf("One or both users not found.\n");
        return;
    }
    if (user1->num_friends >= MAX_USERS || user2->num_friends >= MAX_USERS) {
        printf("Cannot add more friends for one or both users.\n");
        return;
    }
    if (are_friends(user1, user2)) {
        printf("Users are already friends.\n");
        return;
    }
    user1->friends[user1->num_friends++] = user2;
    user2->friends[user2->num_friends++] = user1;
}

void search_users_by_name(Graph* graph, const char* name) {
    printf("Users with name '%s':\n", name);
    bool found = false;
    for (int i = 0; i < graph->num_users; i++) {
        if (strstr(graph->users[i].name, name)) {
            printf("%s\n", graph->users[i].name);
            found = true;
        }
    }
    if (!found) {
        printf("No users found with that name.\n");
    }
}

void search_users_by_interest(Graph* graph, const char* interest) {
    printf("Users interested in '%s':\n", interest);
    bool found = false;
    for (int i = 0; i < graph->num_users; i++) {
        if (strstr(graph->users[i].interests, interest)) {
            printf("%s\n", graph->users[i].name);
            found = true;
        }
    }
    if (!found) {
        printf("No users found interested in that.\n");
    }
}

void recommend_friends(Graph* graph, const char* name) {
    printf("Recommended friends for %s:\n", name);
    bool found = false;
    for (int i = 0; i < graph->num_users; i++) {
        if (strcmp(graph->users[i].name, name) == 0) {
            User* user = &graph->users[i];
            for (int j = 0; j < graph->num_users; j++) {
                User* potential_friend = &graph->users[j];
                if (strcmp(potential_friend->name, name) != 0 &&
                    !are_friends(user, potential_friend)) {
                    printf("%s\n", potential_friend->name);
                    found = true;
                }
            }
            break;
        }
    }
    if (!found) {
        printf("No recommended friends.\n");
    }
}


