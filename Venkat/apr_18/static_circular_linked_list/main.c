#include <stdio.h>
#include "cirllist.h"

int main() {
    struct Node* head = NULL;
    int numNodes, value, sum;

    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);

    printf("Enter the values for each node:\n");
    for (int i = 0; i < numNodes; i++) {
        scanf("%d", &value);
        addNode(&head, value);
    }

    sum = sumOfValues(head);
    printf("Sum of values in the circular linked list: %d\n", sum);

    return 0;
}
