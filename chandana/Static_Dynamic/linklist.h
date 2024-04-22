struct Node{
	int data;
	struct Node* next;
};


struct Node* createNode(int data);
void append(struct Node** headRef,int data);
int sunNodes(struct Node* head);

