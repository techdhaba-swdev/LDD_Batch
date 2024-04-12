#include <stdio.h>

#define MAX 5

typedef struct {
    int arr[MAX];
    int size;
} LIST;

void insert(int j, int it, LIST *pl) {
    if (j < 1 || j > pl->size + 1) {
        printf("Invalid index\n");
        return;
    }

    for (int i = pl->size; i >= j; i--) {
        pl->arr[i] = pl->arr[i - 1];
    }

    pl->arr[j - 1] = it;
    pl->size++;
}

void delete(int j, LIST *pl) {
    if (j < 1 || j > pl->size) {
        printf("Invalid index\n");
        return;
    }

    for (int i = j - 1; i < pl->size - 1; i++) {
        pl->arr[i] = pl->arr[i + 1];
    }

    pl->size--;
}

int main() {
    LIST list;
    list.size = 0;

    printf("Enter 3 elements:\n");
    for (int i = 0; i < 3; i++) {
        scanf("%d", &list.arr[i]);
        list.size++;
    }

    printf("Enter the number to insert at index 1: ");
    int new_num;
    scanf("%d", &new_num);
    insert(1, new_num, &list);

    printf("Modified array after insertion:\n");
    for (int i = 0; i < list.size; i++) {
        printf("%d ", list.arr[i]);
    }
    printf("\n");

    printf("Enter the index of the element to delete: ");
    int index_to_delete;
    scanf("%d", &index_to_delete);
    delete(index_to_delete, &list);

    printf("Modified array after deletion:\n");
    for (int i = 0; i < list.size; i++) {
        printf("%d ", list.arr[i]);
    }
    printf("\n");

    return 0;
}


