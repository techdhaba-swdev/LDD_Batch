struct Node {
	int data;
	struct Node* next;
};

typedef struct Node Node;

Node* createList(int n);
void display(Node* head);


