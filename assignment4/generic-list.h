#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    void* data;
    struct node* next;
} NODE;

typedef NODE* LIST;

static NODE* newNode(void* Data, NODE* next)
{
    NODE* new = (NODE*)malloc(sizeof(NODE));
    new->data = Data;
    new->next = next;
    return new;
}

static int addIfEmpty(LIST* plist, void* data)
{
    NODE* ppnode = *plist;
    ppnode = newNode(data, NULL);

    return 0;
}

int addLast(LIST* plist, void* data)
{
    if (!plist)
        return addIfEmpty(plist, data);

    NODE* pnode = *plist;
    while (pnode->next)
        pnode = pnode->next;

    pnode->next = newNode(data, NULL);

    return 0;
}

int addFirst(LIST* plist, void* data)
{
    if (!plist)
        return addIfEmpty(plist, data);

    NODE* new = newNode(data, *plist);

    *plist = new;

    return 0;
}

void printListGeneric(LIST list, void (*printData)(void*))
{
    for (NODE* pnode = list; pnode; pnode = pnode->next)
        printData(pnode->data);
}
