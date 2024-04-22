struct Node {
    int data;
    struct Node* next;
};

void addNode(struct Node** head, int value);
int sumOfValues(struct Node* head);

