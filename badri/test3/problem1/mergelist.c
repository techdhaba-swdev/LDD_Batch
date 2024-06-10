#include "header.h"

// Function to merge two sorted linked lists
ListNode* sortedMerge(ListNode* a, ListNode* b) {
    ListNode* result = NULL;
    if (a == NULL) return b;
    if (b == NULL) return a;

    if (strcmp(a->data.name, b->data.name) <= 0) {
        result = a;
        result->next = sortedMerge(a->next, b);
    } else {
        result = b;
        result->next = sortedMerge(a, b->next);
    }
    return result;
}

