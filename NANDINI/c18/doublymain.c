#include<stdio.h>
#include<stdlib.h>
#include"printd.h"

struct Node {
    int value;
    struct Node* next;
    struct Node* prev;
};

int main()
{
	struct Node* head = create_node(10);
    struct Node* second = create_node(20);
    struct Node* third = create_node(30);
    struct Node* fourth = create_node(40);
    struct Node* fifth = create_node(50);

    
    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;
    third->next = fourth;
    fourth->prev = third;
    fourth->next = fifth;
    fifth->prev = fourth;

    
    printf("Doubly Linked List Values: ");
    print_list(head);

    
    int sum = find_sum(head);
    printf("Sum of Values: %d\n", sum);

    
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
