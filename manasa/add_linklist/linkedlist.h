#ifdef LINKLIST_H
#define LINKLIST_H
struct Node 
{
	int data;
	struct Node *next;
}
void insert(Node *head, int data);
int sumList(node *head);
#endif
