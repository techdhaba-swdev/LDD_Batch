struct node{
	int data;
	struct node*next;
};
struct node*createcircularll();
void append(struct node**head1,int data);
void display(struct node*head);
int sum(struct node* head);
