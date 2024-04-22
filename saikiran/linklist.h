typedef struct Node{
	int data;
	struct Node* next;
}Node;

void insertlink(Node** head,int data);
int printList(Node* head);

