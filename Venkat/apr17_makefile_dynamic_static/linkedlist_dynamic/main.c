#include <stdio.h>
#include "linklist.h"

int main() {
	 struct node *head = createLinkedlist();
         int sumofnodedata = sum(head);
         printf("sum of all nodes:%d\n",sumofnodedata);

         return 0;
}
