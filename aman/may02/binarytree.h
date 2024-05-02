#ifndef BINARYTREE_H
#define BINARYTREE_H
struct TreeNode{//structure for binary tree node
	int is_operator;//flag to indicate that node is operator or operand
	int value;//value od node
	char operator;//it is operator symbol if node is operator
	struct TreeNode* left;//left child
	struct TreeNode* right;//right child
};
struct TreeNode* createNode(int is_operator, int value, char operator);//function to create new binary tree node
struct TreeNode* buildTree(char* expression);//function to build binary tree from infix expression
int evaluateExpression(struct TreeNode* root);//function to evaluateexpression using binary tree
#endif//end
