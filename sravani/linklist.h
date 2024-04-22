typedef struct Node{
	int a;
	struct Node *next;
}Node;
void insert(Node **head, int a);
int sumList(Node *head);
