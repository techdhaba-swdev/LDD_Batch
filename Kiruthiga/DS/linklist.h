typedef struct Node{
int a;
struct Node *next;
}Node;
void addNode(Node **head, int a);
int sumList(Node *head);
