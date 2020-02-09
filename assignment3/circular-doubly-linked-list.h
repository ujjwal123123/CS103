#include <stdio.h>
#include <stdlib.h>

typedef int DATA;

typedef struct node {
    struct node* prev;
    DATA data;
    struct node* next;
} NODE;

typedef struct list {
    NODE* head;
    NODE* tail;
} LIST;

// create new node
NODE* newNode(NODE* prev, DATA data, NODE* next)
{
    NODE* new = (NODE*)malloc(sizeof(NODE));

    new->prev = prev;
    new->data = data;
    new->next = next;

    return new;
}

static int addIfEmpty(LIST* plist, DATA Data)
{
    NODE* new = newNode(NULL, Data, NULL);
    new->next = new;
    new->prev = new;

    plist->head = new;
    plist->tail = new;

    return 0;
}

static int addIfSingle(LIST* plist, DATA Data)
{
    NODE* new = newNode(plist->tail, Data, plist->tail);

    plist->head = new;
    plist->tail->next = new;
    plist->tail->prev = new;

    return 0;
}

int addFirst(LIST* plist, DATA Data)
{
    if (plist->head == NULL) {
        return addIfEmpty(plist, Data);
    }

    else if (plist->head == plist->tail) {
        return addIfSingle(plist, Data);
    }

    else {
        NODE* new = newNode(plist->tail, Data, plist->head);

        plist->head->prev = new;
        plist->tail->next = new;
        plist->head = new;
    }

    return 0;
}

int print(LIST list)
{
    NODE* pnode = list.head;
    while (1) {
        printf("%d ", pnode->data);
        pnode = pnode->next;

        if (pnode == list.head)
            break;
    }
    printf("\n");

    return 0;
}

int printReverse(LIST list)
{
    NODE* pnode = list.tail;

    while (1) {
        printf("%d ", pnode->data);

        if (pnode == list.head)
            break;

        pnode = pnode->prev;
    }
    printf("\n");

    return 0;
}

int length(LIST list)
{
    int length = 0;

    NODE* pnode = list.head;

    while (1) {
        length++;

        pnode = pnode->next;

        if (pnode == list.head)
            break;
    }

    return length;
}

int removeIfSingle(LIST* plist)
{
    DATA retValue = plist->head->data;
    free(plist->head);

    plist->head = NULL;
    plist->tail = NULL;

    return retValue;
}

int removeFirst(LIST* plist)
{
    if (plist->head == NULL) {
        fprintf(stderr, "The list is empty\n");
        return -1;
    }

    else if (plist->head == plist->tail) {
        return removeIfSingle(plist);
    }

    else {
        DATA retValue = plist->head->data;
        NODE* delNode = plist->head;

        plist->head = plist->head->next;
        plist->head->prev = plist->tail;
        free(delNode);

        return retValue;
    }
}