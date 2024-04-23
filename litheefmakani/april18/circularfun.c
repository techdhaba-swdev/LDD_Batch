struct Node{
	int data;
	struct Node *next;
};

struct Node* insertEnd(struct Node *last,int data){
	if(last == NULL){
		struct Node *newnode = (struct Node*) malloc(sizeof(struct Node));
		newNode->=data;
		newNode->next=newNode;
		return newnode;
	}else{
		struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
		newNode->data=data;
		newNode->next=last->next;
		last->next=newnode;
		return newNode;
	}
}
