#ifdef LINKLIST_H
#define LINKLIST_H
typedf struct Node
{
	int data;
	struct Node *next;
}Node;
void insert(Node *head, int data);
int sumList(node *head);
#endif
