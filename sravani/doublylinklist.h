typedef struct Node{
        int a;
        struct Node *next;
	struct Node *prev;
}Node;
void insert(Node **head, int a);
int sumList(Node *head);
