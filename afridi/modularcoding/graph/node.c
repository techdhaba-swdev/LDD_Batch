#include <stdio.h>
#include <stdlib.h>
#include "node.h"

struct Node* createNode(int vertex) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}
