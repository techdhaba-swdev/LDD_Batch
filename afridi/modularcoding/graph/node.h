#ifndef NODE_H
#define NODE_H

struct Node {
    int vertex;
    struct Node* next;
};

struct Node* createNode(int vertex);

#endif /* NODE_H */
