struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data);
void insertAtBeginning(struct Node** headRef, int data);
void insertAtEnd(struct Node** headRef, int data);
void displayList(struct Node* head);