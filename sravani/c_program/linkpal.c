//check i a singly ll is a palindrome
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct listNode{    //define
	int val;      //value stored in the node
	struct listNode *next; //pointer to the next node in the list
};
struct lisstNode* newNode(int val){  //to create new node
	struct listNode* node=(struct listNode*)malloc(sizeof(struct listNode));
	node->val = val;  //sets the value of the node
	node->next = NULL; //initially next pointeer is  null
	return node; //returns the newly created node
}
struct listNode* reverseList(struct listNode* head){
	struct listNode* prev = NULL;
	struct listNode* cur = head;
	struct listNode* next = NULL;
	while(cur != NULL){
		next = cur->next;  //store next node
		cur->next = prev; 
		prev = cur;
		cur = next;
	}
	return prev;
}
bool isPalindrome(struct listNode* head){
	if(head == NULL || head->next == NULL) //check if if ll is empty or has only one node
		return true; 
	struct listNode* slow = head;
	struct listNode* fast = head;
	while(fast -> next != NULL &&   fast->next->next != NULL){
		slow = slow->next;//moves one step ahead
		fast = fast->next->next; ////moves teo steps
	}
	slow->next=reverseList(slow->next);//reverse the 2nd half of the list
	slow = slow->next;
	while(slow != NULL){ //compare the value first half and reversed second half
		if(head->val != slow->val)
			return false;
		head = head->next;
		slow = slow->next;
	}
	return true;
}
int main(){
	struct listNode* head = newNode('m');
	head->next = newNode('a');
	head->next->next=newNode('d');
	head->next->next->next=newNode('a');
	head->next->next->next->next=newNode('m');
	if(isPalindrome(head))
		printf("Linked list is palindrome:\n");
	else
		printf("Linked list is not a Palindrome:\n");
	return 0;
}

