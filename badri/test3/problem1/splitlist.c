#include "header.h"
// Function to split a linked list into two halves
void splitList(ListNode* source, ListNode** front, ListNode** back) {
    ListNode* fast;
    ListNode* slow;
    slow = source;
    fast = source->next;

    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *front = source;
    *back = slow->next;
    slow->next = NULL;
}

