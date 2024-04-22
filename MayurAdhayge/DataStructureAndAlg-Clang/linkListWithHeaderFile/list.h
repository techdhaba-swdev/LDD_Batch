typedef struct Node
{
int data;
struct Node *next;
}node;

struct Node* create_node(int data);
void insert_node(struct Node* root,int data);
int getmiddelOfLinkList(struct Node* root);
