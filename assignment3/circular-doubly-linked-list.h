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
static NODE* newNode(NODE* prev, DATA data, NODE* next)
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
    // plist->tail = new;
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

// Prints the list
int print(LIST list)
{
    if (list.head == NULL) {
        printf("The list is empty. Can't be printed.\n");
        return -1;
    }

    NODE* pnode = list.head;
    printf("The list is: ");
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

static DATA removeIfSingle(LIST* plist)
{
    DATA retValue = plist->head->data;
    free(plist->head);

    plist->head = NULL;
    plist->tail = NULL;

    return retValue;
}

DATA removeFirst(LIST* plist)
{
    if (plist->head == NULL) {
        fprintf(stderr, "The list is empty. Can't be removed.\n");
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
        plist->tail->next = plist->head;
        free(delNode);

        printf("Removed from the list: %d\n", retValue);
        return retValue;
    }
}

int addLast(LIST* plist, DATA Data)
{
    if (plist->head == NULL) {
        return addIfSingle(plist, Data);
    }

    NODE* new = newNode(plist->tail, Data, plist->head);

    plist->tail->next = new;
    plist->head->prev = new;

    return 0;
}

int removeLast(LIST* plist)
{
    if (plist->head == NULL) {
        fprintf(stderr, "The list is already empty.\n");
        return -1;
    }

    if (plist->head == plist->tail) {
        return removeIfSingle(plist);
    }

    NODE* removedPtr = plist->tail;
    DATA removedData = removedPtr->data;

    plist->tail = removedPtr->prev;
    plist->tail->next = plist->head;
    plist->head->prev = plist->tail;

    free(removedPtr);

    printf("Removed from the list: %d\n", removedData);

    return removedData;
}