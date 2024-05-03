CC =gcc
CFLAGS = -I.
DEPS = header.h node.h
%.o : %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
tree : newnode.c insertnode.c inorder.c preorder.c postorder.c min.c max.c deletenode.c search.c height.c bt_bst.c main.c
	gcc -o tree newnode.c insertnode.c inorder.c preorder.c postorder.c min.c max.c deletenode.c search.c height.c bt_bst.c main.c

