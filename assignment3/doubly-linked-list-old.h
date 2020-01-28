#include <stdio.h>
#include <stdlib.h>

typedef int DATA;

typedef struct node {
    struct node* prev;
    DATA data;
    struct node* next;
} NODE;

typedef struct dlist {
    NODE* first;
    NODE* last;
} LIST;

int prepend(LIST* plist, DATA Data)
{
    NODE* new = (NODE*)malloc(sizeof(NODE));
    new->data = Data;
    new->prev = NULL;
    new->next = plist->first;

    if (plist->first == NULL) {
        plist->last = new;
    }

    plist->first = new;

    return 0;
}

int print(LIST list)
{
    if (list.first == NULL) {
        printf("The list is empty.\n");
        return 1;
    }

    NODE* pnode = list.first;

    while (pnode) {
        printf("%d ", pnode->data);

        if (pnode->next)
            pnode = pnode->next;
        else
            break;
    }

    printf("\n");
    return 0;
}
