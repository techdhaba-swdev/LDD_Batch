void printList(struct Node *last){
	if(last==NULL){
		printf("List is empty\n");
		return ;
	}
	struct Node *temp = last->next;
	do{
		printf("%d",temp->next);
		temp=temp->next;
	}while(temp != last->next);
}
