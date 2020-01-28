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

// // Reverse the elements in the list outplace
// NODE* reverseOutplace(NODE* pnode)
// {
//     // traverse to the end
//     while (pnode) {
//         if (pnode->next)
//             pnode = pnode->next;
//         else
//             break;
//     }

//     LIST reversedList = NULL;
//     while (pnode) {
//         if (pnode->prev) {
//             addFirst(&reversedList, pnode->data);
//             pnode = pnode->prev;
//         } else
//             break;
//     }

//     return reversedList;
// }