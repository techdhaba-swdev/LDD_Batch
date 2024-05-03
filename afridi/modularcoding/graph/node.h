#ifndef NODE_H
#define NODE_H

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data);
struct Node* minValueNode(struct Node* node);

#endif /* NODE_H */
