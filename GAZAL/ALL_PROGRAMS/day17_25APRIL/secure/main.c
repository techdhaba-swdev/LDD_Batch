#include <stdio.h>
#include "ll.h"

int main() {
    struct LinkedList list;
    initLinkedList(&list);
    int numNodes, value;

    // Ask the user for the number of nodes
    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);

    // Ask the user to enter values for each node
    printf("Enter values for each node:\n");
    for (int i = 0; i < numNodes; i++) {
        printf("Node %d value: ", i + 1);
        scanf("%d", &value);
        addNode(&list, value);
    }

    // Print the sum of values
    printf("Sum of values: %d\n", sumLinkedList(&list));

    return 0;
}
