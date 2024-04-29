#include"main.h"
void main()
{
	LinkList* root=link_list_init();
	append(root,10);
	append(root,20);
	append(root,50);
	print_link_list(root);
	delete_node(root,10);
	print_link_list(root);

}
