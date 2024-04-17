

typedef struct Node {
    int data;
    struct Node *next;
} Node;

void insert(Node **head, int data);
int sumList(Node *head);

