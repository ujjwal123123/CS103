#include <stdio.h>
#include <stdlib.h>

typedef int DATA;

typedef struct node {
    struct node* prev;
    DATA data;
    struct node* next;
} NODE;

typedef NODE* LIST;

int addFirst(NODE** ppnode, DATA Data)
{
    NODE* newNode = (NODE*)malloc(sizeof(NODE));
    newNode->prev = NULL;
    newNode->data = Data;
    newNode->next = *ppnode;

    if (*ppnode == NULL)
        *ppnode = newNode;
    else {
        (*ppnode)->prev = newNode;
        (*ppnode) = newNode;
    }

    return 0;
}

int print(NODE* pnode)
{
    if (pnode == NULL) {
        fprintf(stderr, "The list is empty.\n");
        return -1;
    }

    // while (pnode) {
    //     printf("%d ", pnode->data);

    //     if (pnode->next)
    //         pnode = pnode->next;
    //     else
    //         break;
    // }

    while (pnode) {
        printf("%d ", pnode->data);
        pnode = pnode->next;
    }

    printf("\n");

    return 0;
}

int printBack(NODE* pnode)
{
    if (pnode == NULL) {
        fprintf(stderr, "The list is empty.\n");
        return -1;
    }

    // traverse to the last node
    while (pnode) {
        if (pnode->next)
            pnode = pnode->next;
        else
            break;
    }

    // start printing
    while (pnode) {
        printf("%d ", pnode->data);

        if (pnode->prev)
            pnode = pnode->prev;
        else
            break;
    }

    printf("\n");

    return 0;
}

int length(NODE* pnode)
{
    int length = 0;

    while (pnode) {
        length++;

        if (pnode->next)
            pnode = pnode->next;
        else
            break;
    }

    return length;
}

DATA removeFirst(NODE** ppnode)
{
    if (*ppnode == NULL) {
        fprintf(stderr, "Call to removeFirst failed. The list is already empty\n");
        return -1;
    }

    NODE* pointerToRemovedNode = (*ppnode);
    DATA retValue = (*ppnode)->data;

    *ppnode = (*ppnode)->next;
    free(pointerToRemovedNode);

    return retValue;
}

int addLast(NODE** ppnode, DATA Data)
{
    NODE* newNode = (NODE*)malloc(sizeof(NODE));
    newNode->data = Data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (*ppnode == NULL) {
        *ppnode = newNode;
        return 0;
    }

    // traverse to the last node
    NODE* pnode = *ppnode;
    while (pnode) {
        if (pnode->next)
            pnode = pnode->next;
        else
            break;
    }

    pnode->next = newNode;
    newNode->prev = pnode;

    return 0;
}

DATA removeLast(NODE** ppnode)
{
    if (length(*ppnode) == 0) {
        fprintf(stderr, "Call to remove last failed. The list is already empty.");
        return -1;
    }

    if (length(*ppnode) == 1) {
        return removeFirst(ppnode);
    }

    NODE* pnode = *ppnode;

    while (pnode->next->next)
        pnode = pnode->next;

    DATA retValue = pnode->next->data;
    free(pnode->next);
    pnode->next = NULL;

    return retValue;
}

DATA removePos(NODE** ppnode, int pos)
{
    if (pos == 0)
        return removeFirst(ppnode);

    else if (pos == length(*ppnode))
        return removeLast(ppnode);

    NODE* pnode = *ppnode;

    while (pnode && --pos) {
        if (pnode->next)
            pnode = pnode->next;
        else {
            fprintf(stderr, "List index out of bound\n");
            return -1;
        }
    }

    NODE* temp = pnode->next;
    pnode->next = temp->next;
    free(temp);

    return 0;
}

int addPos(NODE** ppnode, DATA Data, int pos)
{
    if (pos == 0)
        return addFirst(ppnode, Data);
    else if (pos == length(*ppnode))
        return addLast(ppnode, Data);

    NODE* pnode = *ppnode;

    while (pnode && --pos) {
        if (pnode->next)
            pnode = pnode->next;
        else {
            fprintf(stderr, "List index out of bound\n");
            return -1;
        }
    }

    NODE* newNode = (NODE*)malloc(sizeof(NODE));
    newNode->data = Data;
    newNode->next = pnode->next;
    newNode->prev = pnode;

    pnode->next->prev = newNode;
    pnode->next = newNode;

    return 0;
}

DATA getData(NODE* pnode, int pos)
{
    while (pnode && pos--) {
        if (pnode->next)
            pnode = pnode->next;
        else {
            fprintf(stderr, "List index out of bound\n");
            return -1;
        }
    }

    return pnode->data;
}

// Add data after the first occurrence of a given key value in the linked list
int addAfterKey(NODE** ppnode, DATA Data, DATA key)
{
    if (*ppnode == NULL) {
        fprintf(stderr, "The key was not found in the list\n");
        return -1;
    }

    NODE* pnode = *ppnode;

    int pos = 0;
    while (pnode->data != key) {
        if (pnode->next) {
            pnode = pnode->next;
            pos++;
        } else {
            fprintf(stderr, "The key was not found in the list\n");
            return -1;
        }
    }

    return addPos(ppnode, Data, pos + 1);
}

// Remove the first occurrence of a given data in the list
int removeByValue(NODE** ppnode, DATA key)
{
    if (*ppnode == NULL) {
        fprintf(stderr, "The key was not found in the list\n");
        return -1;
    }

    NODE* pnode = *ppnode;

    int pos = 0;
    while (pnode->data != key) {
        if (pnode->next) {
            pnode = pnode->next;
            pos++;
        } else {
            fprintf(stderr, "The key was not found in the list\n");
            return -1;
        }
    }

    return removePos(ppnode, pos);
}

// TODO: This function is not working
// Reverse the elements in the list outplace
LIST reverseOutplace(LIST pnode)
{
    LIST* pReversedList = (LIST*)malloc(sizeof(LIST));

    while (pnode) {
        addFirst(pReversedList, pnode->data);

        if (pnode->next)
            pnode = pnode->next;
        else
            break;
    }

    return *pReversedList;
}

// Reverse the elements in the list without creating a new list
int reverseInplace(NODE** ppnode)
{
    NODE* pnode = *ppnode;

    while (pnode) {
        // swap next and prev
        NODE* temp = pnode->next;
        pnode->next = pnode->prev;
        pnode->prev = temp;

        if (pnode->prev)
            pnode = pnode->prev;
        else {
            *ppnode = pnode;
            break;
        }
    }

    return 0;
}

// insert an element in a sorted list such that the final list is also sorted
int insertIntoSorted(NODE** ppnode, DATA Data)
{
    if (*ppnode == NULL)
        addFirst(ppnode, Data);

    NODE* pnode = *ppnode;
    int pos = 0;
    while (pnode->data < Data) {
        pos++;

        if (pnode->next) {
            pnode = pnode->next;
        } else {
            addLast(ppnode, Data);
            return 0;
        }
    }

    addPos(ppnode, Data, pos);

    return 0;
}

// change first list by appending second list to it
int mergeList(NODE* pnode1, NODE* pnode2)
{
    while (pnode1 && pnode1->next) {
        pnode1 = pnode1->next;
    }

    pnode1->next = pnode2;

    return 0;
}

// print list using recursion
int printRecursive(NODE* pnode)
{
    if (pnode) {
        printf("%d ", pnode->data);
        return printRecursive(pnode->next);
    }
    printf("\n");
    return 0;
}

// print list in reverse order using recursion
int printReverseRecursion(NODE* pnode)
{
    if (pnode == NULL)
        return 0;

    printReverseRecursion(pnode->next);

    printf("%d ", pnode->data);

    return 0;
}

// the linked list clockwise by n modulo l nodes, where l is the length of the list
int rotateList(NODE** ppnode, int offset)
{
    // convert this list into a circular list
    NODE* head = *ppnode;

    {
        NODE* pnode = *ppnode;
        while (pnode) {
            if (pnode->next)
                pnode = pnode->next;
            else
                break;
        }

        pnode->next = head;
    }

    {
        NODE* pnode = head;
        while (--offset) {
            pnode = pnode->next;
        }

        *ppnode = pnode->next;
        pnode->next = NULL;
    }
    return 0;
}

// sorts linked list using selection sort
int sort(NODE** ppnode)
{
    // handle trivial cases
    if (*ppnode == NULL || (*ppnode)->next == NULL)
        return 0;

    for (NODE* i = *ppnode; i != NULL; i = i->next) {
        NODE* min = i;

        for (NODE* j = i->next; j != NULL; j = j->next)
            if (j->data < min->data)
                min = j;

        // swap
        if (min != i) {
            DATA temp = i->data;
            i->data = min->data;
            min->data = temp;
        }
    }

    return 0;
}