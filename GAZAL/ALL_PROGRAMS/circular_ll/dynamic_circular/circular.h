struct Node {
    int data;
    struct Node *next;
};

struct Node *createCircularLinkedList(int size);
int sum_cll(struct Node *head);
