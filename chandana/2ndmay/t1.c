#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "bst.h"

TreeNode* createNode(char data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

TreeNode* buildTreeHelper(char* expression, int start, int end) {
    if (start > end) return NULL;

    TreeNode* root = NULL;
    TreeNode* left = NULL;
    TreeNode* right = NULL;
    int index = -1;
    int priority = 0;

    for (int i = start; i <= end; i++) {
        if (expression[i] == '(') {
            int count = 1;
            i++;
            while (count != 0) {
                if (expression[i] == '(') count++;
                else if (expression[i] == ')') count--;
                i++;
            }
            i--;
        } else if (isdigit(expression[i])) {
            continue;
        } else {
            int currPriority = precedence(expression[i]);
            if (currPriority >= priority) {
                priority = currPriority;
                index = i;
            }
        }
    }

    if (index == -1) {
        if (expression[start] == '(' && expression[end] == ')') {
            return buildTreeHelper(expression, start + 1, end - 1);
        }
        root = createNode(expression[start]);
    } else {
        root = createNode(expression[index]);
        left = buildTreeHelper(expression, start, index - 1);
        right = buildTreeHelper(expression, index + 1, end);
        root->left = left;
        root->right = right;
    }

    return root;
}

TreeNode* buildTree(char* expression) {
    int len = 0;
    while (expression[len] != '\0') len++;
    return buildTreeHelper(expression, 0, len - 1);
}

int evaluate(TreeNode* root) {
    if (root == NULL) return 0;

    if (root->left == NULL && root->right == NULL) {
        return root->data - '0';
    }

    int leftValue = evaluate(root->left);
    int rightValue = evaluate(root->right);

    switch (root->data) {
        case '+':
            return leftValue + rightValue;
        case '-':
            return leftValue - rightValue;
        case '*':
            return leftValue * rightValue;
        case '/':
            return leftValue / rightValue;
        default:
            return 0;
    }
}

void inOrderTraversal(TreeNode* root){
	if(root==NULL) return;

	inOrderTraversal(root->left);
	printf("%c",root->data);
	inOrderTraversal(root->right);
}
