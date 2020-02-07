#include <stdio.h>
#include <stdlib.h>

typedef int DATA;

typedef struct node {
    DATA data;
    struct node* next;
} NODE;

typedef struct list {
    struct node* head;
    struct node* tail;
} LIST;

NODE* newNode(DATA Data, NODE* next)
{
    NODE* new = (NODE*)malloc(sizeof(NODE));
    new->data = Data;
    new->next = next;

    return new;
}

static int addEmpty(LIST* plist, DATA Data)
{
    NODE* new = newNode(Data, NULL);
    new->next = new;

    (*plist).head = new;
    (*plist).tail = new;

    return 0;
}

static int addIfSingle(LIST* plist, DATA Data)
{
    NODE* new = newNode(Data, (*plist).tail);
    (*plist).tail = (*plist).head;
    (*plist).head = new;
    return 0;
}

int addFirst(LIST* plist, DATA Data)
{
    if ((*plist).head == NULL)
        addEmpty(plist, Data);

    else if ((*plist).head == (*plist).tail)
        addIfSingle(plist, Data);

    else {
        NODE* new = newNode(Data, (*plist).head);
        (*plist).head = new;
        ((*plist).tail)->next = (*plist).head;
    }

    printf("%d added to the list\n", Data);

    return 0;
}

int printList(LIST list)
{
    if (list.head == NULL) {
        printf("The array is empty.\n");
        return 0;
    }

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

int length(LIST list)
{
    int length = 0;

    NODE* pnode = list.head;

    while (1) {
        pnode = pnode->next;
        length++;

        if (pnode == list.head) {
            break;
        }
    }

    return length;
}

static DATA removeIfSingle(LIST* plist)
{
    DATA retData = plist->head->data;
    free(plist->head);
    plist->head = NULL;
    plist->tail = NULL;

    return retData;
}

DATA removeFirst(LIST* plist)
{
    if (plist->head == NULL) {
        fprintf(stderr, "The list is empty\n");
        return -1;
    }

    else if (plist->head == plist->tail) {
        printf("The list only has one node\n");
        return removeIfSingle(plist);
    }

    else {
        DATA retData = plist->head->data;
        NODE* removedNode = plist->head;
        plist->head = plist->head->next;
        free(removedNode);

        return retData;
    }
}

int addLast(LIST* plist, DATA Data)
{
    if (plist->head == NULL)
        return addEmpty(plist, Data);

    else if (plist->head == plist->tail)
        return addIfSingle(plist, Data);

    else {
        plist->tail->next = newNode(Data, plist->head);
        plist->tail = plist->tail->next;

        return 0;
    }
}

DATA removeLast(LIST* plist)
{
    if (plist->head == NULL) {
        fprintf(stderr, "The list is empty\n");
        return -1;
    }

    else if (plist->head == plist->tail) {
        return removeIfSingle(plist);
    }

    else {
        NODE* pnode = plist->head;
        while (pnode->next != plist->tail) {
            pnode = pnode->next;
        }
        printf("Last element is %d\n", pnode->next->data);
        DATA retValue = pnode->next->data;
        free(pnode->next);
        plist->tail = pnode;
        plist->tail->next = plist->head;
        return retValue;
    }
}