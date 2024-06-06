#include "mainlk.h"

int main(){

  

   int k=0;
   
   //Performing various operations on the linked list
   insertatbegin(12);
   insertatbegin(22);
   insertatend(30);
   insertatend(44);
   insertatbegin(50);
   insertafternode(head->next->next, 33);
   //Print the Linked list
   printf("Linked List: ");
   printList();
   
   //Deleting the nodes
   deleteatbegin();
   deleteatend();
   deletenode(12);
   
   printf("\nLinked List after deletion: ");

   // print list
   printList();

   //Insert new nodes
   insertatbegin(4);
   insertatbegin(16);
   
   printf("\nUpdated Linked List: ");
   
   printList();
   //Search for an element and print the results
   k = searchlist(16);
   
   if (k == 1){
      
	   printf("\nElement is found");
   } else {
    
	  printf("\nElement is not present in the list");
}

return 0;

}
