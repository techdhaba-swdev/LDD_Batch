#include "header.h"

// Function to sort the linked list using merge sort
void mergeSort(ListNode** headRef) {
    ListNode* head = *headRef;
    ListNode* a;
    ListNode* b;

    if ((head == NULL) || (head->next == NULL)) {
        return;
    }

    splitList(head, &a, &b);

    mergeSort(&a);
    mergeSort(&b);

    *headRef = sortedMerge(a, b);
}

