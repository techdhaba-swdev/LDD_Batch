#include "main.h"

int main() {
	push(10);
	push(20);
	push(30);
        
	printf("is stack empty? %s\n",is_empty() ? "Yes" :"No");

	printf("popped value:%d\n",pop());
	printf("popped value:%d\n",pop());
	printf("popped value:%d\n",pop());

	printf("is stack empty? %s\n",is_empty() ? "Yes" :"No");


	return 0;
}
