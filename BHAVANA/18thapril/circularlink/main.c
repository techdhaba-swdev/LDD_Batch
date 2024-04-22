#include <stdio.h>
#include "circular_linked_list.h"

int main() {
    struct Node* head = NULL;

    printf("Enter 5 values to insert into the circular linked list:\n");
    for (int i = 0; i < 5; i++) {
        int data;
        scanf("%d", &data);
        insert(&head, data);
    }

    printf("\nCircular Linked List:\n");
    struct Node* temp = head;
    if (head != NULL) {
        do {
            printf("%d -> ", temp->data);
            temp = temp->next;
        } while (temp != head);
    }

    int total_sum = sum(head);
    printf("\n\nSum of all values in the circular linked list: %d\n", total_sum);

    return 0;
}
